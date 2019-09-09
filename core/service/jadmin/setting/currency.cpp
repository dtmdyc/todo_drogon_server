#include "currency.h"

#include <utility>
using namespace jadmin;

Currency::Currency(JAdminContextPtr context_) : context(std::move(context_)) {
  query = sqlb::Query(sqlb::ObjectIdentifier("setting", "currency", "c"));
  setupTable();
}

nlohmann::json Currency::handleEvent(nlohmann::json event, unsigned long next,
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

void Currency::setupTable() {
  // m_query.setRowIdColumn("id");
  query.setSelectedColumns({
      sqlb::SelectedColumn({"Id", "id", "", "c", PG_TYPES::INT8, false}),
      sqlb::SelectedColumn({"Code", "slug", "", "c", PG_TYPES::TEXT, true}),
      sqlb::SelectedColumn({"Name", "name", "", "c", PG_TYPES::TEXT, true}),
      sqlb::SelectedColumn({"Symbol", "symbol", "", "c", PG_TYPES::TEXT, true}),
      sqlb::SelectedColumn(
          {"Rounding", "rounding", "", "c", PG_TYPES::DOUBLE, true}),
      sqlb::SelectedColumn({"Active", "active", "", "c", PG_TYPES::BOOL, true}),
  });

  // auto m = sqlb::ObjectIdentifier("material", "metal", "m");
  // auto u1 = sqlb::ObjectIdentifier("entity", "entity_user", "u1");
  // auto u2 = sqlb::ObjectIdentifier("entity", "entity_user", "u2");

  query.setJoins({
      // sqlb::Join("left", m, "a.material_id = m.id"),
      // sqlb::Join("left", u1, "gt.create_user_id = u1.id"),
      // sqlb::Join("left", u2, "a.update_user_id = u2.id"),
  });
}

nlohmann::json Currency::ins(nlohmann::json event, nlohmann::json args) {
  return query.insBase(
      event, args, "slug, name, symbol, rounding, active", "$1, $2, $3, $4, $5",
      args[0]["slug"].get<std::string>(), args[0]["name"].get<std::string>(),
      args[0]["symbol"].get<std::string>(), args[0]["rounding"].get<float>(),
      args[0]["active"].get<bool>());
}

nlohmann::json Currency::upd(nlohmann::json event, nlohmann::json args) {
  return query.updBase(
      event, args, "slug, name, symbol, rounding, active", "$1, $2, $3, $4, $5",
      args[0]["slug"].get<std::string>(), args[0]["name"].get<std::string>(),
      args[0]["symbol"].get<std::string>(), args[0]["rounding"].get<float>(),
      args[0]["active"].get<bool>());
}
