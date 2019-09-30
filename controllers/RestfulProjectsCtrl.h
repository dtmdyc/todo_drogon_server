/**
 *
 *  RestfulProjectsCtrl.h
 *  This file is generated by drogon_ctl
 *
 */

#pragma once

#include <drogon/HttpController.h>
#include "RestfulProjectsCtrlBase.h"

#include "Projects.h"
using namespace drogon;

using namespace drogon_model::openproject6;

/**
 * @brief this class is created by the drogon_ctl command.
 * this class is a restful API controller for reading and writing the projects table.
 */

class RestfulProjectsCtrl: public drogon::HttpController<RestfulProjectsCtrl>, public RestfulProjectsCtrlBase
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(RestfulProjectsCtrl::getOne,"/projects/{1}",Get,Options);
    ADD_METHOD_TO(RestfulProjectsCtrl::updateOne,"/projects/{1}",Put,Options);
    ADD_METHOD_TO(RestfulProjectsCtrl::deleteOne,"/projects/{1}",Delete,Options);
    ADD_METHOD_TO(RestfulProjectsCtrl::get,"/projects",Get,Options);
    ADD_METHOD_TO(RestfulProjectsCtrl::create,"/projects",Post,Options);
    //ADD_METHOD_TO(RestfulProjectsCtrl::update,"/projects",Put,Options);
    METHOD_LIST_END
    
    /**
     * Uncomment the following methods to customize for business logic.
     */
     /*
    void getOne(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                Projects::PrimaryKeyType &&id);
    void updateOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   Projects::PrimaryKeyType &&id);
    void deleteOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   Projects::PrimaryKeyType &&id);
    void get(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void create(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback);
    */
};