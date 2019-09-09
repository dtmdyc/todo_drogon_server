#include "accountheading.h"

#include <utility>
using namespace jadmin;
AccountHeading::AccountHeading(JAdminContextPtr context_)
    : context(std::move(context_)) {
  query =
      sqlb::Query(sqlb::ObjectIdentifier("account", "account_heading", "a"));
  setupTable();
}

nlohmann::json AccountHeading::handleEvent(nlohmann::json event,
                                           unsigned long next,
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
void AccountHeading::setupTable() {
  // m_query.setRowIdColumn("id");
  query.setSelectedColumns({
      sqlb::SelectedColumn({"Id", "id", "", "a", PG_TYPES::INT8, false}),
      sqlb::SelectedColumn({"Acc No", "accno", "", "a", PG_TYPES::TEXT, true}),
      sqlb::SelectedColumn({"Name", "name", "", "a", PG_TYPES::TEXT, true}),
  });

  // auto pg = sqlb::ObjectIdentifier("part", "part_category", "pg");
  // auto u1 = sqlb::ObjectIdentifier("entity", "entity_user", "u1");
  // auto u2 = sqlb::ObjectIdentifier("entity", "entity_user", "u2");

  query.setJoins({
      // sqlb::Join("left", c, "p.color_id = c.id"),
      // sqlb::Join("left", pg, "p.part_group_id = pg.id"),
      // sqlb::Join("left", u1, "gt.create_user_id = u1.id"),
      // sqlb::Join("left", u2, "a.update_user_id = u2.id"),
  });
}
nlohmann::json AccountHeading::ins(nlohmann::json event, nlohmann::json args) {
  return query.insBase(event, args, "name, accno", "$1, $2",
                       args[0]["name"].get<std::string>(),
                       args[0]["accno"].get<std::string>());
}

nlohmann::json AccountHeading::upd(nlohmann::json event, nlohmann::json args) {
  return query.updBase(event, args, "name, accno", "$1, $2",
                       args[0]["name"].get<std::string>(),
                       args[0]["accno"].get<std::string>());
}
