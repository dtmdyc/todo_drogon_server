/**
 *
 *  RestfulSessionsCtrl.h
 *  This file is generated by drogon_ctl
 *
 */

#pragma once

#include <drogon/HttpController.h>
#include "RestfulSessionsCtrlBase.h"

#include "Sessions.h"
using namespace drogon;

using namespace drogon_model::openproject6;

/**
 * @brief this class is created by the drogon_ctl command.
 * this class is a restful API controller for reading and writing the sessions table.
 */

class RestfulSessionsCtrl: public drogon::HttpController<RestfulSessionsCtrl>, public RestfulSessionsCtrlBase
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(RestfulSessionsCtrl::getOne,"/sessions/{1}",Get,Options);
    ADD_METHOD_TO(RestfulSessionsCtrl::updateOne,"/sessions/{1}",Put,Options);
    ADD_METHOD_TO(RestfulSessionsCtrl::deleteOne,"/sessions/{1}",Delete,Options);
    ADD_METHOD_TO(RestfulSessionsCtrl::get,"/sessions",Get,Options);
    ADD_METHOD_TO(RestfulSessionsCtrl::create,"/sessions",Post,Options);
    //ADD_METHOD_TO(RestfulSessionsCtrl::update,"/sessions",Put,Options);
    METHOD_LIST_END
    
    /**
     * Uncomment the following methods to customize for business logic.
     */
     /*
    void getOne(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                Sessions::PrimaryKeyType &&id);
    void updateOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   Sessions::PrimaryKeyType &&id);
    void deleteOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   Sessions::PrimaryKeyType &&id);
    void get(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void create(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback);
    */
};