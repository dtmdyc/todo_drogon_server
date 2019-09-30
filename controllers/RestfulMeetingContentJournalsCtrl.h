/**
 *
 *  RestfulMeetingContentJournalsCtrl.h
 *  This file is generated by drogon_ctl
 *
 */

#pragma once

#include <drogon/HttpController.h>
#include "RestfulMeetingContentJournalsCtrlBase.h"

#include "MeetingContentJournals.h"
using namespace drogon;

using namespace drogon_model::openproject6;

/**
 * @brief this class is created by the drogon_ctl command.
 * this class is a restful API controller for reading and writing the meeting_content_journals table.
 */

class RestfulMeetingContentJournalsCtrl: public drogon::HttpController<RestfulMeetingContentJournalsCtrl>, public RestfulMeetingContentJournalsCtrlBase
{
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(RestfulMeetingContentJournalsCtrl::getOne,"/meetingcontentjournals/{1}",Get,Options);
    ADD_METHOD_TO(RestfulMeetingContentJournalsCtrl::updateOne,"/meetingcontentjournals/{1}",Put,Options);
    ADD_METHOD_TO(RestfulMeetingContentJournalsCtrl::deleteOne,"/meetingcontentjournals/{1}",Delete,Options);
    ADD_METHOD_TO(RestfulMeetingContentJournalsCtrl::get,"/meetingcontentjournals",Get,Options);
    ADD_METHOD_TO(RestfulMeetingContentJournalsCtrl::create,"/meetingcontentjournals",Post,Options);
    //ADD_METHOD_TO(RestfulMeetingContentJournalsCtrl::update,"/meetingcontentjournals",Put,Options);
    METHOD_LIST_END
    
    /**
     * Uncomment the following methods to customize for business logic.
     */
     /*
    void getOne(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback,
                MeetingContentJournals::PrimaryKeyType &&id);
    void updateOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   MeetingContentJournals::PrimaryKeyType &&id);
    void deleteOne(const HttpRequestPtr &req,
                   std::function<void(const HttpResponsePtr &)> &&callback,
                   MeetingContentJournals::PrimaryKeyType &&id);
    void get(const HttpRequestPtr &req,
             std::function<void(const HttpResponsePtr &)> &&callback);
    void create(const HttpRequestPtr &req,
                std::function<void(const HttpResponsePtr &)> &&callback);
    */
};