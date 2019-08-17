#include "addresstype.h"
#include "../../strfns.h"
#include "../../jsonfns.h"

AddressType::AddressType(const WebSocketConnectionPtr& wsConnPtr_): BaseService(wsConnPtr_)
{

    t.m_table = sqlb::ObjectIdentifier("entity", "address_type", "a");
}

void AddressType::setupTable()
{
    t.m_query = sqlb::Query(t.m_table);
    //m_query.setRowIdColumn("id");
    t.m_query.selectedColumns() = {
        sqlb::SelectedColumn({"Id", "id", "", "a", PG_TYPES::INT8, true}),
        sqlb::SelectedColumn({"Name", "name", "", "a", PG_TYPES::TEXT, true}),
        sqlb::SelectedColumn({"Create Time", "inserted_at", "", "a", PG_TYPES::TIMESTAMP, true, 0, 0, false}),
        sqlb::SelectedColumn({"Update Time", "updated_at", "", "a", PG_TYPES::TIMESTAMP, true, 0, 0, false}),
        };
}



Json::Value AddressType::save( Json::Value event, Json::Value args) {
if (args["id"].asInt()) {
    std::string strSql = "update entity.address_type set (name) = ROW($2) where id=$1";
    pqxx::work txn{DD};
    try {
        txn.exec_params(strSql, args["id"].asInt(), args["name"].asString());
        txn.commit();
        Json::Value ret; ret[0] = simpleJsonSaveResult(event, true, "Done"); return ret;
    } catch (const std::exception &e) {
        txn.abort();
        std::cerr << e.what() << std::endl;
        Json::Value ret; ret[0] = simpleJsonSaveResult(event, false, e.what()); return ret;
    }
} else {
    std::string strSql = "INSERT INTO entity.address_type (name) values($1)";
    pqxx::work txn{DD};
    try {
        txn.exec_params(strSql, args["name"].asString());
        txn.commit();
        Json::Value ret; ret[0] = simpleJsonSaveResult(event, true, "Done"); return ret;
    } catch (const std::exception &e) {
        txn.abort();
        std::cerr << e.what() << std::endl;
        Json::Value ret; ret[0] = simpleJsonSaveResult(event, false, e.what()); return ret;
    }
}
}