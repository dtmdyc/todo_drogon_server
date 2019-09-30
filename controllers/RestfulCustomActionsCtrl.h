/**
 *
 *  RestfulCustomActionsCtrl.h
 *  This file is generated by drogon_ctl
 *
 */

#pragma once

#include <drogon/HttpController.h>
#include "RestfulCustomActionsCtrlBase.h"

#include "CustomActions.h"
using namespace drogon;

using namespace drogon_model::openproject6;

/**
 * @brief this class is created by the drogon_ctl command.
 * this class is a restful API controller for reading and writing the custom_actions table.
 */

class RestfulCustomActionsCtrl: public drogon::HttpController<RestfulCustomActionsCtrl>, public RestfulCustomActionsCtrlBase
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(RestfulCustomActionsCtrl::getOne,"/customactions/{1}",Get,Options);
    ADD_METHOD_TO(RestfulCustomActionsCtrl::updateOne,"/customactions/{1}",Put,Options);
    ADD_METHOD_TO(RestfulCustomActionsCtrl::deleteOne,"/customactions/{1}",Delete,Options);
    ADD_METHOD_TO(RestfulCustomActionsCtrl::get,"/customactions",Get,Options);
    ADD_METHOD_TO(RestfulCustomActionsCtrl::create,"/customactions",Post,Options);
    //ADD_METHOD_TO(RestfulCustomActionsCtrl::update,"/customactions",Put,Options);
    METHOD_LIST_END
    
    /**
     * Uncomment the following methods to customize for business logic.
     */
     /*
    void getOne(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                CustomActions::PrimaryKeyType &&id);
    void updateOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   CustomActions::PrimaryKeyType &&id);
    void deleteOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   CustomActions::PrimaryKeyType &&id);
    void get(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void create(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback);
    */
};