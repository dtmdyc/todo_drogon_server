/**
 *
 *  RestfulCostQueriesCtrl.h
 *  This file is generated by drogon_ctl
 *
 */

#pragma once

#include <drogon/HttpController.h>
#include "RestfulCostQueriesCtrlBase.h"

#include "CostQueries.h"
using namespace drogon;

using namespace drogon_model::openproject6;

/**
 * @brief this class is created by the drogon_ctl command.
 * this class is a restful API controller for reading and writing the cost_queries table.
 */

class RestfulCostQueriesCtrl: public drogon::HttpController<RestfulCostQueriesCtrl>, public RestfulCostQueriesCtrlBase
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(RestfulCostQueriesCtrl::getOne,"/costqueries/{1}",Get,Options);
    ADD_METHOD_TO(RestfulCostQueriesCtrl::updateOne,"/costqueries/{1}",Put,Options);
    ADD_METHOD_TO(RestfulCostQueriesCtrl::deleteOne,"/costqueries/{1}",Delete,Options);
    ADD_METHOD_TO(RestfulCostQueriesCtrl::get,"/costqueries",Get,Options);
    ADD_METHOD_TO(RestfulCostQueriesCtrl::create,"/costqueries",Post,Options);
    //ADD_METHOD_TO(RestfulCostQueriesCtrl::update,"/costqueries",Put,Options);
    METHOD_LIST_END
    
    /**
     * Uncomment the following methods to customize for business logic.
     */
     /*
    void getOne(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                CostQueries::PrimaryKeyType &&id);
    void updateOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   CostQueries::PrimaryKeyType &&id);
    void deleteOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   CostQueries::PrimaryKeyType &&id);
    void get(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void create(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback);
    */
};