#include "metal.h"

#include <utility>
#include "../../../strfns.h"
#include "../../../sql/dba.h"

#define ids2(s, array)                                 \
  std::string array = "{";                             \
  for (auto i : (s)) {                                 \
    array += std::to_string(i["id"].as<long>()) + ","; \
  }                                                    \
  if ((s).size() > 0) array.pop_back();                \
  array += "}";
namespace jadmin {
Metal::Metal(std::shared_ptr<websocket::JAdminContext> context_) : context(std::move(context_)) {
  query = sql::Query(sql::ObjectIdentifier("material", "metal", "m"));
  setupTable();
}

nlohmann::json Metal::handleEvent(nlohmann::json event, unsigned long next,
                                  nlohmann::json args) {
  auto event_cmp = event[next].get<std::string>();
  if (event_cmp == "data") {
    return query.allData(event, args);
  }
  if (event_cmp == "header") {
    return query.headerData(event, args);
  } else if (event_cmp == "ins") {
    return ins(event, args);
  } else if (event_cmp == "upd") {
    return upd(event, args);
  } else if (event_cmp == "del") {
    return query.del(event, args);
  } else {
    nlohmann::json ret;
    return ret;
  }
}

void Metal::setupTable() {
  // m_query.setRowIdColumn("id");
  query.setSelectedColumns({
      sql::SelectedColumn({"Id", "id", "", "m", PG_TYPES::INT8, false}),
      //        sql::SelectedColumn({"Rank", "rank", "", "m", PG_TYPES::INT4,
      //        false}),
      sql::SelectedColumn({"Code", "slug", "", "m", PG_TYPES::TEXT, true}),
      sql::SelectedColumn({"Name", "name", "", "m", PG_TYPES::TEXT, true}),
      sql::SelectedColumn({"Specific_density", "specific_density", "", "m",
                            PG_TYPES::DOUBLE, true}),
      sql::SelectedColumn({"Melting Point in C", "melting_point_in_c", "", "m",
                            PG_TYPES::DOUBLE, true}),
      sql::SelectedColumn(
          {"Currency_id", "currency_id", "", "m", PG_TYPES::INT8, true}),
      sql::SelectedColumn({"Price", "price", "", "m", PG_TYPES::DOUBLE, true}),
      sql::SelectedColumn(
          {"Created By", "create_user_id", "", "m", PG_TYPES::INT8, true, 1}),
      sql::SelectedColumn({"u1_username", "username", "", "u1", PG_TYPES::TEXT,
                            false, 0, 0, false}),
      sql::SelectedColumn(
          {"Updated By", "update_user_id", "", "m", PG_TYPES::INT8, true, 1}),
      sql::SelectedColumn({"u2_username", "username", "", "u2", PG_TYPES::TEXT,
                            false, 0, 0, false}),
      sql::SelectedColumn({"Create Time", "inserted_at", "", "m",
                            PG_TYPES::TIMESTAMP, true, 0, 0, false}),
      sql::SelectedColumn({"Update Time", "updated_at", "", "m",
                            PG_TYPES::TIMESTAMP, true, 0, 0, false}),
  });

  auto u1 = sql::ObjectIdentifier("entity", "entity_user", "u1");
  auto u2 = sql::ObjectIdentifier("entity", "entity_user", "u2");

  query.setJoins({

      sql::Join("left", u1, "m.create_user_id = u1.id"),
      sql::Join("left", u2, "m.update_user_id = u2.id"),
  });
}

nlohmann::json Metal::ins(nlohmann::json event, nlohmann::json args) {
  auto metal_table = sql::ObjectIdentifier("material", "metal", "m");

  std::string strSql =
      "INSERT INTO %1.%2 (slug, name, specific_density, price, "
      "melting_point_in_c) values($1, $2, $3, $4, $5)";
  ReplaceAll2(strSql, "%1", metal_table.schema());
  ReplaceAll2(strSql, "%2", metal_table.name());

  auto clientPtr = drogon::app().getDbClient("sce");
  auto transPtr = clientPtr->newTransaction();
  try {
    Dba::writeInTrans(transPtr, strSql, args[0]["slug"].get<std::string>(),
                      args[0]["name"].get<std::string>(),
                      args[0]["specific_density"].get<float>(),
                      args[0]["price"].get<float>(),
                      args[0]["melting_point_in_c"].get<float>());

    nlohmann::json ret;
    ret[0] = websocket::WsFns::successJsonObject(event, true, "Done");
    return ret;
  } catch (const std::exception &e) {
    SPDLOG_TRACE(e.what());
    nlohmann::json ret;
    ret[0] = websocket::WsFns::successJsonObject(event, false, e.what());
    return ret;
  }
}
nlohmann::json Metal::upd(nlohmann::json event, nlohmann::json args) {
  auto metal_table = sql::ObjectIdentifier("material", "metal", "m");

  if (args[0]["id"].get<long>()) {
    std::string strSql =
        "update %1.%2 set "
        "(slug, name, specific_density, price, melting_point_in_c)"
        " = ROW($2, $3, $4, $5, $6) where id=$1";
    ReplaceAll2(strSql, "%1", metal_table.schema());
    ReplaceAll2(strSql, "%2", metal_table.name());

    auto clientPtr = drogon::app().getDbClient("sce");
    auto transPtr = clientPtr->newTransaction();
    try {
      Dba::writeInTrans(transPtr, strSql, args[0]["id"].get<long>(),
                        args[0]["slug"].get<std::string>(),
                        args[0]["name"].get<std::string>(),
                        args[0]["specific_density"].get<float>(),
                        args[0]["price"].get<float>(),
                        args[0]["melting_point_in_c"].get<float>());
      // 1 purity_metal
      auto pr_update = R"(
                             update material.purity_metal pm
                             set (price) = row(pm.purity * m.price / 100)
                             from material.metal m
                             where
                             m.id = pm.metal_id and
                             pm.metal_id = $1
                             returning pm.purity_id;
                             )";
      auto pr =
          Dba::writeInTrans(transPtr, pr_update, args[0]["id"].get<long>());

      ids2(pr, id1)
          // 2. purity
          auto pr_update01 = R"(
                               update material.purity p
                               set (price) = row(p.purity * m.price / 100)
                               from material.metal m
                               where
                               m.id = p.metal_id and
                               p.metal_id = $1
                               returning p.id;
                               )";
      auto pr0 =
          Dba::writeInTrans(transPtr, pr_update01, args[0]["id"].get<long>());
      ids2(pr, id2)
          // 3. purity_tone
          auto pr_update2 = R"(
                              update material.purity_tone pt
                              set (price) = row(
                              (select SUM(pm.price)
                              FROM material.purity_metal pm
                              WHERE pt.purity_id = pm.purity_id and pt.tone_id = pt.tone_id)
                              +
                              (select p.price
                              FROM material.purity p
                              WHERE pt.purity_id = p.id and pt.tone_id = pt.tone_id)
                              )
                              where
                              pt.purity_id = ANY($1::bigint[]) or pt.purity_id = ANY($2::bigint[])
                              )";
      auto pr2 = Dba::writeInTrans(transPtr, pr_update2, id1, id2);

      auto pr_update3 = R"(
                              update product.product p
                              set (volume) = row(
                              p.weight / (
                              (select SUM(purity.purity * m.specific_density / 100)
                              FROM material.purity purity left join material.metal m on m.id = purity.metal_id
                              WHERE purity.id = p.purity_id)
                              +
                              (select SUM(pm.purity * m.specific_density / 100)
                              FROM material.purity_metal pm left join material.metal m on m.id = pm.metal_id
                              WHERE pm.purity_id = p.purity_id and pm.tone_id = p.tone_id)

                              )

                              )
                              where
                              p.purity_id = ANY($1::bigint[]) or p.purity_id = ANY($2::bigint[]) returning p.post_id
                              )";
      auto product_update = Dba::writeInTrans(transPtr, pr_update3, id1, id2);
      ids2(product_update, id3)

          auto pr_update4 = R"(
                              UPDATE product.purity_tone pt
                              SET (weight, price) = row(pr.volume * (sub_q0.sum_val + sub_q.sum_val), pr.volume * (sub_q0.sum_val + sub_q.sum_val) * (mpt.price))
                              FROM
                              (
                              select purity.id, (purity.purity * m.specific_density / 100) as sum_val
                              FROM material.purity purity left join material.metal m on m.id = purity.metal_id
                              ) AS sub_q0,
                              (
                              select pm.purity_id, pm.tone_id, SUM(pm.purity * m.specific_density / 100) as sum_val
                              FROM material.purity_metal pm left join material.metal m on m.id = pm.metal_id
                              group by pm.purity_id, pm.tone_id
                              ) AS sub_q, product.product pr, material.purity_tone mpt
                              where
                              sub_q0.id = pt.purity_id
                              and sub_q.purity_id = pt.purity_id and sub_q.tone_id = pt.tone_id
                              and pr.post_id = pt.post_id -- to get volume from pr
                              and mpt.purity_id = pt.purity_id and mpt.tone_id = pt.tone_id -- to get price from mpt
                              and (pt.purity_id = ANY($1::bigint[]) or pt.purity_id = ANY($2::bigint[]) or pt.post_id = ANY($3::bigint[]) )
                              --returning pt.post_id, pt.purity_id, pt.weight, pt.price
                              )";

      auto pr4 = Dba::writeInTrans(transPtr, pr_update4, id1, id2, id3);

      nlohmann::json ret;
      ret[0] = websocket::WsFns::successJsonObject(event, true, "Done");
      return ret;
    } catch (const std::exception &e) {
      SPDLOG_TRACE(e.what());
      nlohmann::json ret;
      ret[0] = websocket::WsFns::successJsonObject(event, false, e.what());
      return ret;
    }
  }
  nlohmann::json ret;
  ret[0] = websocket::WsFns::successJsonObject(event, false, "Not Valid Structure");
  return ret;
}
}  // namespace jadmin
