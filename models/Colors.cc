/**
 *
 *  Colors.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Colors.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject4;

const std::string Colors::Cols::_id = "id";
const std::string Colors::Cols::_name = "name";
const std::string Colors::Cols::_hexcode = "hexcode";
const std::string Colors::Cols::_created_at = "created_at";
const std::string Colors::Cols::_updated_at = "updated_at";
const std::string Colors::primaryKeyName = "id";
const bool Colors::hasPrimaryKey = true;
const std::string Colors::tableName = "colors";

const std::vector<typename Colors::MetaData> Colors::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"name","std::string","character varying",0,0,0,1},
{"hexcode","std::string","character varying",0,0,0,1},
{"created_at","::trantor::Date","timestamp without time zone",0,0,0,0},
{"updated_at","::trantor::Date","timestamp without time zone",0,0,0,0}
};
const std::string &Colors::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
Colors::Colors(const Row &r, const ssize_t indexOffset) noexcept
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
        if(!r["hexcode"].isNull())
        {
            _hexcode=std::make_shared<std::string>(r["hexcode"].as<std::string>());
        }
        if(!r["created_at"].isNull())
        {
            auto timeStr = r["created_at"].as<std::string>();
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
            _createdAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
        if(!r["updated_at"].isNull())
        {
            auto timeStr = r["updated_at"].as<std::string>();
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
            _updatedAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
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
            _name=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _hexcode=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
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
            _createdAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
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
            _updatedAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
    }

}

Colors::Colors(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
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
        _name=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _hexcode=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        auto timeStr = pJson[pMasqueradingVector[3]].asString();
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
        _createdAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
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
        _updatedAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
}

Colors::Colors(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("name"))
    {
        _name=std::make_shared<std::string>(pJson["name"].asString());
    }
    if(pJson.isMember("hexcode"))
    {
        _hexcode=std::make_shared<std::string>(pJson["hexcode"].asString());
    }
    if(pJson.isMember("created_at"))
    {
        auto timeStr = pJson["created_at"].asString();
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
        _createdAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(pJson.isMember("updated_at"))
    {
        auto timeStr = pJson["updated_at"].asString();
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
        _updatedAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
}

void Colors::updateByMasqueradedJson(const Json::Value &pJson, 
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
        _name=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        _hexcode=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        auto timeStr = pJson[pMasqueradingVector[3]].asString();
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
        _createdAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
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
        _updatedAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
}
                                                                    
void Colors::updateByJson(const Json::Value &pJson) noexcept(false)
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
    if(pJson.isMember("hexcode"))
    {
        _dirtyFlag[2] = true;
        _hexcode=std::make_shared<std::string>(pJson["hexcode"].asString());
    }
    if(pJson.isMember("created_at"))
    {
        _dirtyFlag[3] = true;
        auto timeStr = pJson["created_at"].asString();
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
        _createdAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(pJson.isMember("updated_at"))
    {
        _dirtyFlag[4] = true;
        auto timeStr = pJson["updated_at"].asString();
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
        _updatedAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
}

const int32_t &Colors::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Colors::getId() const noexcept
{
    return _id;
}
const typename Colors::PrimaryKeyType & Colors::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const std::string &Colors::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_name)
        return *_name;
    return defaultValue;
}
const std::shared_ptr<std::string> &Colors::getName() const noexcept
{
    return _name;
}
void Colors::setName(const std::string &pName) noexcept
{
    _name = std::make_shared<std::string>(pName);
    _dirtyFlag[1] = true;
}
void Colors::setName(std::string &&pName) noexcept
{
    _name = std::make_shared<std::string>(std::move(pName));
    _dirtyFlag[1] = true;
}


const std::string &Colors::getValueOfHexcode() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_hexcode)
        return *_hexcode;
    return defaultValue;
}
const std::shared_ptr<std::string> &Colors::getHexcode() const noexcept
{
    return _hexcode;
}
void Colors::setHexcode(const std::string &pHexcode) noexcept
{
    _hexcode = std::make_shared<std::string>(pHexcode);
    _dirtyFlag[2] = true;
}
void Colors::setHexcode(std::string &&pHexcode) noexcept
{
    _hexcode = std::make_shared<std::string>(std::move(pHexcode));
    _dirtyFlag[2] = true;
}


const ::trantor::Date &Colors::getValueOfCreatedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_createdAt)
        return *_createdAt;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Colors::getCreatedAt() const noexcept
{
    return _createdAt;
}
void Colors::setCreatedAt(const ::trantor::Date &pCreatedAt) noexcept
{
    _createdAt = std::make_shared<::trantor::Date>(pCreatedAt);
    _dirtyFlag[3] = true;
}


const ::trantor::Date &Colors::getValueOfUpdatedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_updatedAt)
        return *_updatedAt;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Colors::getUpdatedAt() const noexcept
{
    return _updatedAt;
}
void Colors::setUpdatedAt(const ::trantor::Date &pUpdatedAt) noexcept
{
    _updatedAt = std::make_shared<::trantor::Date>(pUpdatedAt);
    _dirtyFlag[4] = true;
}


void Colors::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Colors::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "name",
        "hexcode",
        "created_at",
        "updated_at"
    };
    return _inCols;
}

void Colors::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(getName())
    {
        binder << getValueOfName();
    }
    else
    {
        binder << nullptr;
    }
    if(getHexcode())
    {
        binder << getValueOfHexcode();
    }
    else
    {
        binder << nullptr;
    }
    if(getCreatedAt())
    {
        binder << getValueOfCreatedAt();
    }
    else
    {
        binder << nullptr;
    }
    if(getUpdatedAt())
    {
        binder << getValueOfUpdatedAt();
    }
    else
    {
        binder << nullptr;
    }
}

const std::vector<std::string> Colors::updateColumns() const
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

void Colors::updateArgs(drogon::orm::internal::SqlBinder &binder) const
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
        if(getHexcode())
        {
            binder << getValueOfHexcode();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[3])
    {
        if(getCreatedAt())
        {
            binder << getValueOfCreatedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[4])
    {
        if(getUpdatedAt())
        {
            binder << getValueOfUpdatedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Colors::toJson() const
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
    if(getHexcode())
    {
        ret["hexcode"]=getValueOfHexcode();
    }
    else
    {
        ret["hexcode"]=Json::Value();
    }
    if(getCreatedAt())
    {
        ret["created_at"]=getCreatedAt()->toDbStringLocal();
    }
    else
    {
        ret["created_at"]=Json::Value();
    }
    if(getUpdatedAt())
    {
        ret["updated_at"]=getUpdatedAt()->toDbStringLocal();
    }
    else
    {
        ret["updated_at"]=Json::Value();
    }
    return ret;
}

Json::Value Colors::toMasqueradedJson(
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
            if(getHexcode())
            {
                ret[pMasqueradingVector[2]]=getValueOfHexcode();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getCreatedAt())
            {
                ret[pMasqueradingVector[3]]=getCreatedAt()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getUpdatedAt())
            {
                ret[pMasqueradingVector[4]]=getUpdatedAt()->toDbStringLocal();
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
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getHexcode())
    {
        ret["hexcode"]=getValueOfHexcode();
    }
    else
    {
        ret["hexcode"]=Json::Value();
    }
    if(getCreatedAt())
    {
        ret["created_at"]=getCreatedAt()->toDbStringLocal();
    }
    else
    {
        ret["created_at"]=Json::Value();
    }
    if(getUpdatedAt())
    {
        ret["updated_at"]=getUpdatedAt()->toDbStringLocal();
    }
    else
    {
        ret["updated_at"]=Json::Value();
    }
    return ret;
}
