/**
 *
 *  RestfulQueriesCtrl.h
 *  This file is generated by drogon_ctl
 *
 */

#pragma once

#include <drogon/HttpController.h>
#include "RestfulQueriesCtrlBase.h"

#include "Queries.h"
using namespace drogon;

using namespace drogon_model::openproject6;

/**
 * @brief this class is created by the drogon_ctl command.
 * this class is a restful API controller for reading and writing the queries table.
 */

class RestfulQueriesCtrl: public drogon::HttpController<RestfulQueriesCtrl>, public RestfulQueriesCtrlBase
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(RestfulQueriesCtrl::getOne,"/queries/{1}",Get,Options);
    ADD_METHOD_TO(RestfulQueriesCtrl::updateOne,"/queries/{1}",Put,Options);
    ADD_METHOD_TO(RestfulQueriesCtrl::deleteOne,"/queries/{1}",Delete,Options);
    ADD_METHOD_TO(RestfulQueriesCtrl::get,"/queries",Get,Options);
    ADD_METHOD_TO(RestfulQueriesCtrl::create,"/queries",Post,Options);
    //ADD_METHOD_TO(RestfulQueriesCtrl::update,"/queries",Put,Options);
    METHOD_LIST_END
    
    /**
     * Uncomment the following methods to customize for business logic.
     */
     /*
    void getOne(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                Queries::PrimaryKeyType &&id);
    void updateOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   Queries::PrimaryKeyType &&id);
    void deleteOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   Queries::PrimaryKeyType &&id);
    void get(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void create(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback);
    */
};