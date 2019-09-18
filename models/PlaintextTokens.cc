/**
 *
 *  PlaintextTokens.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "PlaintextTokens.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject4;

const std::string PlaintextTokens::Cols::_id = "id";
const std::string PlaintextTokens::Cols::_user_id = "user_id";
const std::string PlaintextTokens::Cols::_action = "action";
const std::string PlaintextTokens::Cols::_value = "value";
const std::string PlaintextTokens::Cols::_created_on = "created_on";
const std::string PlaintextTokens::primaryKeyName = "id";
const bool PlaintextTokens::hasPrimaryKey = true;
const std::string PlaintextTokens::tableName = "plaintext_tokens";

const std::vector<typename PlaintextTokens::MetaData> PlaintextTokens::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"user_id","int32_t","integer",4,0,0,1},
{"action","std::string","character varying",30,0,0,1},
{"value","std::string","character varying",40,0,0,1},
{"created_on","::trantor::Date","timestamp without time zone",0,0,0,1}
};
const std::string &PlaintextTokens::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
PlaintextTokens::PlaintextTokens(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            _id=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["user_id"].isNull())
        {
            _userId=std::make_shared<int32_t>(r["user_id"].as<int32_t>());
        }
        if(!r["action"].isNull())
        {
            _action=std::make_shared<std::string>(r["action"].as<std::string>());
        }
        if(!r["value"].isNull())
        {
            _value=std::make_shared<std::string>(r["value"].as<std::string>());
        }
        if(!r["created_on"].isNull())
        {
            auto timeStr = r["created_on"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = timelocal(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 5 > r.size())
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
            _userId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _action=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            _value=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            auto timeStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
            size_t t = timelocal(&stm);
            size_t decimalNum = 0;
            if(*p=='.')
            {
                std::string decimals(p+1,&timeStr[timeStr.length()]);
                while(decimals.length()<6)
                {
                    decimals += "0";
                }
                decimalNum = (size_t)atol(decimals.c_str());
            }
            _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }

}

PlaintextTokens::PlaintextTokens(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
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
        _userId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _action=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _value=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        auto timeStr = pJson[pMasqueradingVector[4]].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
        size_t t = timelocal(&stm);
        size_t decimalNum = 0;
        if(*p=='.')
        {
            std::string decimals(p+1,&timeStr[timeStr.length()]);
            while(decimals.length()<6)
            {
                decimals += "0";
            }
            decimalNum = (size_t)atol(decimals.c_str());
        }
        _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
}

PlaintextTokens::PlaintextTokens(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("user_id"))
    {
        _userId=std::make_shared<int32_t>((int32_t)pJson["user_id"].asInt64());
    }
    if(pJson.isMember("action"))
    {
        _action=std::make_shared<std::string>(pJson["action"].asString());
    }
    if(pJson.isMember("value"))
    {
        _value=std::make_shared<std::string>(pJson["value"].asString());
    }
    if(pJson.isMember("created_on"))
    {
        auto timeStr = pJson["created_on"].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
        size_t t = timelocal(&stm);
        size_t decimalNum = 0;
        if(*p=='.')
        {
            std::string decimals(p+1,&timeStr[timeStr.length()]);
            while(decimals.length()<6)
            {
                decimals += "0";
            }
            decimalNum = (size_t)atol(decimals.c_str());
        }
        _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
}

void PlaintextTokens::updateByMasqueradedJson(const Json::Value &pJson, 
                                                                                                     const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 5)
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
        _userId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        _action=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        _value=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        _dirtyFlag[4] = true;
        auto timeStr = pJson[pMasqueradingVector[4]].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
        size_t t = timelocal(&stm);
        size_t decimalNum = 0;
        if(*p=='.')
        {
            std::string decimals(p+1,&timeStr[timeStr.length()]);
            while(decimals.length()<6)
            {
                decimals += "0";
            }
            decimalNum = (size_t)atol(decimals.c_str());
        }
        _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
}
                                                                    
void PlaintextTokens::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("user_id"))
    {
        _dirtyFlag[1] = true;
        _userId=std::make_shared<int32_t>((int32_t)pJson["user_id"].asInt64());
    }
    if(pJson.isMember("action"))
    {
        _dirtyFlag[2] = true;
        _action=std::make_shared<std::string>(pJson["action"].asString());
    }
    if(pJson.isMember("value"))
    {
        _dirtyFlag[3] = true;
        _value=std::make_shared<std::string>(pJson["value"].asString());
    }
    if(pJson.isMember("created_on"))
    {
        _dirtyFlag[4] = true;
        auto timeStr = pJson["created_on"].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        auto p = strptime(timeStr.c_str(),"%Y-%m-%d %H:%M:%S",&stm);
        size_t t = timelocal(&stm);
        size_t decimalNum = 0;
        if(*p=='.')
        {
            std::string decimals(p+1,&timeStr[timeStr.length()]);
            while(decimals.length()<6)
            {
                decimals += "0";
            }
            decimalNum = (size_t)atol(decimals.c_str());
        }
        _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
}

const int32_t &PlaintextTokens::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &PlaintextTokens::getId() const noexcept
{
    return _id;
}
const typename PlaintextTokens::PrimaryKeyType & PlaintextTokens::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const int32_t &PlaintextTokens::getValueOfUserId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_userId)
        return *_userId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &PlaintextTokens::getUserId() const noexcept
{
    return _userId;
}
void PlaintextTokens::setUserId(const int32_t &pUserId) noexcept
{
    _userId = std::make_shared<int32_t>(pUserId);
    _dirtyFlag[1] = true;
}


const std::string &PlaintextTokens::getValueOfAction() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_action)
        return *_action;
    return defaultValue;
}
const std::shared_ptr<std::string> &PlaintextTokens::getAction() const noexcept
{
    return _action;
}
void PlaintextTokens::setAction(const std::string &pAction) noexcept
{
    _action = std::make_shared<std::string>(pAction);
    _dirtyFlag[2] = true;
}
void PlaintextTokens::setAction(std::string &&pAction) noexcept
{
    _action = std::make_shared<std::string>(std::move(pAction));
    _dirtyFlag[2] = true;
}


const std::string &PlaintextTokens::getValueOfValue() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_value)
        return *_value;
    return defaultValue;
}
const std::shared_ptr<std::string> &PlaintextTokens::getValue() const noexcept
{
    return _value;
}
void PlaintextTokens::setValue(const std::string &pValue) noexcept
{
    _value = std::make_shared<std::string>(pValue);
    _dirtyFlag[3] = true;
}
void PlaintextTokens::setValue(std::string &&pValue) noexcept
{
    _value = std::make_shared<std::string>(std::move(pValue));
    _dirtyFlag[3] = true;
}


const ::trantor::Date &PlaintextTokens::getValueOfCreatedOn() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_createdOn)
        return *_createdOn;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &PlaintextTokens::getCreatedOn() const noexcept
{
    return _createdOn;
}
void PlaintextTokens::setCreatedOn(const ::trantor::Date &pCreatedOn) noexcept
{
    _createdOn = std::make_shared<::trantor::Date>(pCreatedOn);
    _dirtyFlag[4] = true;
}


void PlaintextTokens::updateId(const uint64_t id)
{
}

const std::vector<std::string> &PlaintextTokens::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "user_id",
        "action",
        "value",
        "created_on"
    };
    return _inCols;
}

void PlaintextTokens::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(getUserId())
    {
        binder << getValueOfUserId();
    }
    else
    {
        binder << nullptr;
    }
    if(getAction())
    {
        binder << getValueOfAction();
    }
    else
    {
        binder << nullptr;
    }
    if(getValue())
    {
        binder << getValueOfValue();
    }
    else
    {
        binder << nullptr;
    }
    if(getCreatedOn())
    {
        binder << getValueOfCreatedOn();
    }
    else
    {
        binder << nullptr;
    }
}

const std::vector<std::string> PlaintextTokens::updateColumns() const
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

void PlaintextTokens::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
    {
        if(getUserId())
        {
            binder << getValueOfUserId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[2])
    {
        if(getAction())
        {
            binder << getValueOfAction();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[3])
    {
        if(getValue())
        {
            binder << getValueOfValue();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[4])
    {
        if(getCreatedOn())
        {
            binder << getValueOfCreatedOn();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value PlaintextTokens::toJson() const
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
    if(getUserId())
    {
        ret["user_id"]=getValueOfUserId();
    }
    else
    {
        ret["user_id"]=Json::Value();
    }
    if(getAction())
    {
        ret["action"]=getValueOfAction();
    }
    else
    {
        ret["action"]=Json::Value();
    }
    if(getValue())
    {
        ret["value"]=getValueOfValue();
    }
    else
    {
        ret["value"]=Json::Value();
    }
    if(getCreatedOn())
    {
        ret["created_on"]=getCreatedOn()->toDbStringLocal();
    }
    else
    {
        ret["created_on"]=Json::Value();
    }
    return ret;
}

Json::Value PlaintextTokens::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 5)
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
            if(getUserId())
            {
                ret[pMasqueradingVector[1]]=getValueOfUserId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getAction())
            {
                ret[pMasqueradingVector[2]]=getValueOfAction();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getValue())
            {
                ret[pMasqueradingVector[3]]=getValueOfValue();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getCreatedOn())
            {
                ret[pMasqueradingVector[4]]=getCreatedOn()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
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
    if(getUserId())
    {
        ret["user_id"]=getValueOfUserId();
    }
    else
    {
        ret["user_id"]=Json::Value();
    }
    if(getAction())
    {
        ret["action"]=getValueOfAction();
    }
    else
    {
        ret["action"]=Json::Value();
    }
    if(getValue())
    {
        ret["value"]=getValueOfValue();
    }
    else
    {
        ret["value"]=Json::Value();
    }
    if(getCreatedOn())
    {
        ret["created_on"]=getCreatedOn()->toDbStringLocal();
    }
    else
    {
        ret["created_on"]=Json::Value();
    }
    return ret;
}
