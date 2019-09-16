#include "priority.h"

#include <utility>

namespace jewel {
namespace service {
Priority::Priority(std::shared_ptr<websocket::jewel::JAdminContext> context_)
    : context(std::move(context_)) {
  query = sql::Query(sql::ObjectIdentifier("account", "priority", "a"));
  setupTable();
}

nlohmann::json Priority::handleEvent(nlohmann::json event, unsigned long next,
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

void Priority::setupTable() {
  // m_query.setRowIdColumn("id");
  query.setSelectedColumns({
      sql::SelectedColumn({"Id", "id", "", "a", sql::PG_TYPES::INT8, false}),
      sql::SelectedColumn(
          {"Rank", "rank", "", "a", sql::PG_TYPES::INT4, false}),
      sql::SelectedColumn({"Code", "slug", "", "a", sql::PG_TYPES::TEXT, true}),
      sql::SelectedColumn({"Name", "name", "", "a", sql::PG_TYPES::TEXT, true}),
      //            sql::SelectedColumn({"Description", "description", "", "a",
      //            sql::PG_TYPES::TEXT, true}),
      sql::SelectedColumn({"Created By", "create_user_id", "", "a",
                           sql::PG_TYPES::INT8, true, 1, 0, false}),
      sql::SelectedColumn({"u1_username", "username", "", "u1",
                           sql::PG_TYPES::TEXT, false, 0, 0, false}),
      sql::SelectedColumn({"Updated By", "update_user_id", "", "a",
                           sql::PG_TYPES::INT8, true, 1, 0, false}),
      sql::SelectedColumn({"u2_username", "username", "", "u2",
                           sql::PG_TYPES::TEXT, false, 0, 0, false}),
      sql::SelectedColumn({"Create Time", "inserted_at", "", "a",
                           sql::PG_TYPES::TIMESTAMP, true, 0, 0, false}),
      sql::SelectedColumn({"Update Time", "updated_at", "", "a",
                           sql::PG_TYPES::TIMESTAMP, true, 0, 0, false}),
  });

  auto u1 = sql::ObjectIdentifier("entity", "entity_user", "u1");
  auto u2 = sql::ObjectIdentifier("entity", "entity_user", "u2");

  query.setJoins({
      sql::Join("left", u1, "a.create_user_id = u1.id"),
      sql::Join("left", u2, "a.update_user_id = u2.id"),
  });
}
nlohmann::json Priority::ins(nlohmann::json event, nlohmann::json args) {
  return query.insBase(
      event, args, "rank, slug, name", "$1, $2, $3", args[0]["rank"].get<int>(),
      args[0]["slug"].get<std::string>(), args[0]["name"].get<std::string>());
}

nlohmann::json Priority::upd(nlohmann::json event, nlohmann::json args) {
  return query.updBase(
      event, args, "rank, slug, name", "$1, $2, $3", args[0]["rank"].get<int>(),
      args[0]["slug"].get<std::string>(), args[0]["name"].get<std::string>());
}
}  // namespace service
}  // namespace jadmin
