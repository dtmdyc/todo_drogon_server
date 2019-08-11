#include "image.h"

Image::Image(const WebSocketConnectionPtr& wsConnPtr): wsConnPtr(wsConnPtr)
{

}

void Image::setupTable()
{
    t.m_table = sqlb::ObjectIdentifier("setting", "image", "a");
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

HANDLEEVENT(Image)

HEADERDATA(Image)
ALLDATA(Image)
