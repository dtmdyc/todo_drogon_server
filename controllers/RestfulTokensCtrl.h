/**
 *
 *  RestfulTokensCtrl.h
 *  This file is generated by drogon_ctl
 *
 */

#pragma once

#include <drogon/HttpController.h>
#include "RestfulTokensCtrlBase.h"

#include "Tokens.h"
using namespace drogon;

using namespace drogon_model::openproject6;

/**
 * @brief this class is created by the drogon_ctl command.
 * this class is a restful API controller for reading and writing the tokens table.
 */

class RestfulTokensCtrl: public drogon::HttpController<RestfulTokensCtrl>, public RestfulTokensCtrlBase
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(RestfulTokensCtrl::getOne,"/tokens/{1}",Get,Options);
    ADD_METHOD_TO(RestfulTokensCtrl::updateOne,"/tokens/{1}",Put,Options);
    ADD_METHOD_TO(RestfulTokensCtrl::deleteOne,"/tokens/{1}",Delete,Options);
    ADD_METHOD_TO(RestfulTokensCtrl::get,"/tokens",Get,Options);
    ADD_METHOD_TO(RestfulTokensCtrl::create,"/tokens",Post,Options);
    //ADD_METHOD_TO(RestfulTokensCtrl::update,"/tokens",Put,Options);
    METHOD_LIST_END
    
    /**
     * Uncomment the following methods to customize for business logic.
     */
     /*
    void getOne(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                Tokens::PrimaryKeyType &&id);
    void updateOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   Tokens::PrimaryKeyType &&id);
    void deleteOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   Tokens::PrimaryKeyType &&id);
    void get(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void create(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback);
    */
};