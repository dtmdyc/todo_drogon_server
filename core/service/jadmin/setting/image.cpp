#include "image.h"

#include "../../../strfns.h"
#include "../../../jsonfns.h"

Image::Image()
{
    t.m_table = sqlb::ObjectIdentifier("setting", "image", "a");

}

void Image::setupTable()
{
    t.m_query = sqlb::Query(t.m_table);

        //m_query.setRowIdColumn("id");
        t.m_query.selectedColumns() = {
            sqlb::SelectedColumn({"Id", "id", "", "a", PG_TYPES::INT8, true}),
            sqlb::SelectedColumn({"Collection", "image_collection_id", "", "a", PG_TYPES::INT8, true, 1, 1}),sqlb::SelectedColumn({"Name", "name", "", "c", PG_TYPES::TEXT, false}),
            sqlb::SelectedColumn({"Position", "position", "", "a", PG_TYPES::INT4, true}),
            sqlb::SelectedColumn({"Title", "title", "", "a", PG_TYPES::TEXT, true}),
            sqlb::SelectedColumn({"Url", "url", "", "a", PG_TYPES::TEXT, true}),
            sqlb::SelectedColumn({"Description", "description", "", "a", PG_TYPES::TEXT, true}),
            sqlb::SelectedColumn({"Name", "name", "", "a", PG_TYPES::TEXT, true}),
            sqlb::SelectedColumn({"Size", "size", "", "a", PG_TYPES::INT8, true}),
            sqlb::SelectedColumn({"Type", "type", "", "a", PG_TYPES::TEXT, true}),
            sqlb::SelectedColumn({"Version", "version", "", "a", PG_TYPES::TEXT, false}),
            //sqlb::SelectedColumn({"Created By", "create_user_id", "", "a", PG_TYPES::INT8, true, 1, 0, false}), sqlb::SelectedColumn({"u1_username", "username", "", "u1", PG_TYPES::TEXT, false, 0, 0, false}),
            //sqlb::SelectedColumn({"Updated By", "update_user_id", "", "a", PG_TYPES::INT8, true, 1, 0, false}), sqlb::SelectedColumn({"u2_username", "username", "", "u2", PG_TYPES::TEXT, false, 0, 0, false}),
            sqlb::SelectedColumn({"Create Time", "inserted_at", "", "a", PG_TYPES::TIMESTAMP, true, 0, 0, false}),
            sqlb::SelectedColumn({"Update Time", "updated_at", "", "a", PG_TYPES::TIMESTAMP, true, 0, 0, false}),
            };

        auto c = sqlb::ObjectIdentifier("setting", "image_collection", "c");
    //auto u1 = sqlb::ObjectIdentifier("entity", "entity_user", "u1");
    //auto u2 = sqlb::ObjectIdentifier("entity", "entity_user", "u2");

        t.m_query.joins() = {
            sqlb::Join("left", c, "c.id = a.image_collection_id"),
            //sqlb::Join("left", u1, "gt.create_user_id = u1.id"),
            //sqlb::Join("left", u2, "a.update_user_id = u2.id"),
};
}

json Image::handleEvent(json event, int next, json args)
{
    auto event_cmp = event[next].get<std::string>();
    if(event_cmp  == "data"){
        return allData(event, args);
    } else if (event_cmp  == "header") {
        return headerData(event, args);
    } else if (event_cmp  == "ins") {
        return ins(event, args);
    } else if (event_cmp  == "upd") {
        return upd(event, args);
    } else if (event_cmp  == "del") {
        return del(event, args);
    } else {
        return Json::nullValue;
    }
}

// this is normal images..
json Image::ins( json event, json args) {
    auto metal_purity_table = sqlb::ObjectIdentifier("setting", "image", "c");
    std::string t = "setting.image";
    std::string c = "image_collection_id, name, size, type, title, description, url, position";
    std::string strSqlTempImage = "SELECT name, size, type FROM setting.temp_image_id WHERE id = $1";
    std::string strSqlTempImageDel = "DELETE FROM setting.temp_image_id WHERE id = $1";

    std::string strSql = "INSERT INTO " + t + " (" + c + ") values(NULLIF($1,0), $2, $3, $4, $5, $6, $7, $8)";
    auto clientPtr = drogon::app().getDbClient("sce");
    auto transPtr = clientPtr->newTransaction();
    try {
        auto temp_id = args[0]["temp_id"].get<int>();
        if (temp_id != 0) {
            auto z = transPtr->execSqlSync(strSqlTempImage, temp_id);
            if (z.size() == 1) {
                transPtr->execSqlSync(strSql, args[0]["image_collection_id"].get<int>(), z[0]["name"].c_str(), z[0]["size"].as<int>(),z[0]["type"].c_str(), args[0]["title"].get<std::string>(), args[0]["description"].get<std::string>(), args[0]["url"].get<std::string>(), args[0]["position"].get<int>());
                transPtr->execSqlSync(strSqlTempImageDel, temp_id);
            }
        } else {
            json ret; ret[0] = simpleJsonSaveResult(event, false, "Please Upload Image"); return ret;
        }

        
        json ret; ret[0] = simpleJsonSaveResult(event, true, "Done"); return ret;
    } catch (const std::exception &e) {
        
        spdlog::error(e.what());
        json ret; ret[0] = simpleJsonSaveResult(event, false, e.what()); return ret;
    }
}
// this is normal images..
json Image::upd( json event, json args) {
    auto metal_purity_table = sqlb::ObjectIdentifier("setting", "image", "c");
    std::string t = "setting.image";
    std::string c = "image_collection_id, name, size, type, title, description, url, position";
    std::string strSqlTempImage = "SELECT name, size, type FROM setting.temp_image_id WHERE id = $1";
    std::string strSqlTempImageDel = "DELETE FROM setting.temp_image_id WHERE id = $1";

    if (args[0]["id"].get<long>()) {
        std::string strSql = "update " + t + " set (" + c + ", version) = ROW(NULLIF($2, 0), $3, $4, $5, $6, $7, $8, $9, version + 1) where id=$1" ;
        auto clientPtr = drogon::app().getDbClient("sce");
        auto transPtr = clientPtr->newTransaction();
        try {
            auto temp_id = args[0]["temp_id"].get<long>();
            if (temp_id != 0) {
                auto z = transPtr->execSqlSync(strSqlTempImage, temp_id);
                if (z.size() == 1) {
                    transPtr->execSqlSync(strSql, args[0]["id"].get<long>(), args[0]["image_collection_id"].get<long>(), z[0]["name"].c_str(), z[0]["size"].as<int>(),z[0]["type"].c_str(), args[0]["title"].get<std::string>(), args[0]["description"].get<std::string>(), args[0]["url"].get<std::string>(), args[0]["position"].get<int>());
                    transPtr->execSqlSync(strSqlTempImageDel, temp_id);
                }
            } else {
                transPtr->execSqlSync("UPDATE setting.image SET (title, description, url, position, version) = ROW($2, $3, $4, $5, version + 1) WHERE id = $1", args[0]["id"].get<long>(), args[0]["title"].get<std::string>(), args[0]["description"].get<std::string>(), args[0]["url"].get<std::string>(), args[0]["position"].get<int>());
            }
            

            json ret; ret[0] = simpleJsonSaveResult(event, true, "Done"); return ret;
        } catch (const std::exception &e) {
            
            spdlog::error(e.what());
            json ret; ret[0] = simpleJsonSaveResult(event, false, e.what()); return ret;
        }
    }
}

