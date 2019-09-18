/**
 *
 *  WebhooksEvents.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "WebhooksEvents.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject4;

const std::string WebhooksEvents::Cols::_id = "id";
const std::string WebhooksEvents::Cols::_name = "name";
const std::string WebhooksEvents::Cols::_webhooks_webhook_id = "webhooks_webhook_id";
const std::string WebhooksEvents::primaryKeyName = "id";
const bool WebhooksEvents::hasPrimaryKey = true;
const std::string WebhooksEvents::tableName = "webhooks_events";

const std::vector<typename WebhooksEvents::MetaData> WebhooksEvents::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"name","std::string","character varying",0,0,0,0},
{"webhooks_webhook_id","int32_t","integer",4,0,0,0}
};
const std::string &WebhooksEvents::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
WebhooksEvents::WebhooksEvents(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            _id=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["name"].isNull())
        {
            _name=std::make_shared<std::string>(r["name"].as<std::string>());
        }
        if(!r["webhooks_webhook_id"].isNull())
        {
            _webhooksWebhookId=std::make_shared<int32_t>(r["webhooks_webhook_id"].as<int32_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 3 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            _id=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            _name=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _webhooksWebhookId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

WebhooksEvents::WebhooksEvents(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        _name=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _webhooksWebhookId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
    }
}

WebhooksEvents::WebhooksEvents(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("name"))
    {
        _name=std::make_shared<std::string>(pJson["name"].asString());
    }
    if(pJson.isMember("webhooks_webhook_id"))
    {
        _webhooksWebhookId=std::make_shared<int32_t>((int32_t)pJson["webhooks_webhook_id"].asInt64());
    }
}

void WebhooksEvents::updateByMasqueradedJson(const Json::Value &pJson, 
                                                                                                     const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        _dirtyFlag[1] = true;
        _name=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        _webhooksWebhookId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
    }
}
                                                                    
void WebhooksEvents::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("name"))
    {
        _dirtyFlag[1] = true;
        _name=std::make_shared<std::string>(pJson["name"].asString());
    }
    if(pJson.isMember("webhooks_webhook_id"))
    {
        _dirtyFlag[2] = true;
        _webhooksWebhookId=std::make_shared<int32_t>((int32_t)pJson["webhooks_webhook_id"].asInt64());
    }
}

const int32_t &WebhooksEvents::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &WebhooksEvents::getId() const noexcept
{
    return _id;
}
const typename WebhooksEvents::PrimaryKeyType & WebhooksEvents::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const std::string &WebhooksEvents::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_name)
        return *_name;
    return defaultValue;
}
const std::shared_ptr<std::string> &WebhooksEvents::getName() const noexcept
{
    return _name;
}
void WebhooksEvents::setName(const std::string &pName) noexcept
{
    _name = std::make_shared<std::string>(pName);
    _dirtyFlag[1] = true;
}
void WebhooksEvents::setName(std::string &&pName) noexcept
{
    _name = std::make_shared<std::string>(std::move(pName));
    _dirtyFlag[1] = true;
}


const int32_t &WebhooksEvents::getValueOfWebhooksWebhookId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_webhooksWebhookId)
        return *_webhooksWebhookId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &WebhooksEvents::getWebhooksWebhookId() const noexcept
{
    return _webhooksWebhookId;
}
void WebhooksEvents::setWebhooksWebhookId(const int32_t &pWebhooksWebhookId) noexcept
{
    _webhooksWebhookId = std::make_shared<int32_t>(pWebhooksWebhookId);
    _dirtyFlag[2] = true;
}


void WebhooksEvents::updateId(const uint64_t id)
{
}

const std::vector<std::string> &WebhooksEvents::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "name",
        "webhooks_webhook_id"
    };
    return _inCols;
}

void WebhooksEvents::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(getName())
    {
        binder << getValueOfName();
    }
    else
    {
        binder << nullptr;
    }
    if(getWebhooksWebhookId())
    {
        binder << getValueOfWebhooksWebhookId();
    }
    else
    {
        binder << nullptr;
    }
}

const std::vector<std::string> WebhooksEvents::updateColumns() const
{
    std::vector<std::string> ret;
    for(size_t i=0;i<sizeof(_dirtyFlag);i++)
    {
        if(_dirtyFlag[i])
        {
            ret.push_back(getColumnName(i));
        }
    }
    return ret;
}

void WebhooksEvents::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[2])
    {
        if(getWebhooksWebhookId())
        {
            binder << getValueOfWebhooksWebhookId();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value WebhooksEvents::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getWebhooksWebhookId())
    {
        ret["webhooks_webhook_id"]=getValueOfWebhooksWebhookId();
    }
    else
    {
        ret["webhooks_webhook_id"]=Json::Value();
    }
    return ret;
}

Json::Value WebhooksEvents::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 3)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[1]]=getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getWebhooksWebhookId())
            {
                ret[pMasqueradingVector[2]]=getValueOfWebhooksWebhookId();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getWebhooksWebhookId())
    {
        ret["webhooks_webhook_id"]=getValueOfWebhooksWebhookId();
    }
    else
    {
        ret["webhooks_webhook_id"]=Json::Value();
    }
    return ret;
}
