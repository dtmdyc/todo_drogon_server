/**
 *
 *  AttributeHelpTexts.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "AttributeHelpTexts.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject4;

const std::string AttributeHelpTexts::Cols::_id = "id";
const std::string AttributeHelpTexts::Cols::_help_text = "help_text";
const std::string AttributeHelpTexts::Cols::_type = "type";
const std::string AttributeHelpTexts::Cols::_attribute_name = "attribute_name";
const std::string AttributeHelpTexts::Cols::_created_at = "created_at";
const std::string AttributeHelpTexts::Cols::_updated_at = "updated_at";
const std::string AttributeHelpTexts::primaryKeyName = "id";
const bool AttributeHelpTexts::hasPrimaryKey = true;
const std::string AttributeHelpTexts::tableName = "attribute_help_texts";

const std::vector<typename AttributeHelpTexts::MetaData> AttributeHelpTexts::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"help_text","std::string","text",0,0,0,1},
{"type","std::string","character varying",0,0,0,1},
{"attribute_name","std::string","character varying",0,0,0,1},
{"created_at","::trantor::Date","timestamp without time zone",0,0,0,1},
{"updated_at","::trantor::Date","timestamp without time zone",0,0,0,1}
};
const std::string &AttributeHelpTexts::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
AttributeHelpTexts::AttributeHelpTexts(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            _id=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["help_text"].isNull())
        {
            _helpText=std::make_shared<std::string>(r["help_text"].as<std::string>());
        }
        if(!r["type"].isNull())
        {
            _type=std::make_shared<std::string>(r["type"].as<std::string>());
        }
        if(!r["attribute_name"].isNull())
        {
            _attributeName=std::make_shared<std::string>(r["attribute_name"].as<std::string>());
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
        if(offset + 6 > r.size())
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
            _helpText=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _type=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            _attributeName=std::make_shared<std::string>(r[index].as<std::string>());
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
            _createdAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
        index = offset + 5;
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

AttributeHelpTexts::AttributeHelpTexts(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
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
        _helpText=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _type=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _attributeName=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
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
        _createdAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        auto timeStr = pJson[pMasqueradingVector[5]].asString();
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

AttributeHelpTexts::AttributeHelpTexts(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("help_text"))
    {
        _helpText=std::make_shared<std::string>(pJson["help_text"].asString());
    }
    if(pJson.isMember("type"))
    {
        _type=std::make_shared<std::string>(pJson["type"].asString());
    }
    if(pJson.isMember("attribute_name"))
    {
        _attributeName=std::make_shared<std::string>(pJson["attribute_name"].asString());
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

void AttributeHelpTexts::updateByMasqueradedJson(const Json::Value &pJson, 
                                                                                                     const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
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
        _helpText=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        _type=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        _attributeName=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
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
        _createdAt=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        _dirtyFlag[5] = true;
        auto timeStr = pJson[pMasqueradingVector[5]].asString();
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
                                                                    
void AttributeHelpTexts::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("help_text"))
    {
        _dirtyFlag[1] = true;
        _helpText=std::make_shared<std::string>(pJson["help_text"].asString());
    }
    if(pJson.isMember("type"))
    {
        _dirtyFlag[2] = true;
        _type=std::make_shared<std::string>(pJson["type"].asString());
    }
    if(pJson.isMember("attribute_name"))
    {
        _dirtyFlag[3] = true;
        _attributeName=std::make_shared<std::string>(pJson["attribute_name"].asString());
    }
    if(pJson.isMember("created_at"))
    {
        _dirtyFlag[4] = true;
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
        _dirtyFlag[5] = true;
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

const int32_t &AttributeHelpTexts::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &AttributeHelpTexts::getId() const noexcept
{
    return _id;
}
const typename AttributeHelpTexts::PrimaryKeyType & AttributeHelpTexts::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const std::string &AttributeHelpTexts::getValueOfHelpText() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_helpText)
        return *_helpText;
    return defaultValue;
}
const std::shared_ptr<std::string> &AttributeHelpTexts::getHelpText() const noexcept
{
    return _helpText;
}
void AttributeHelpTexts::setHelpText(const std::string &pHelpText) noexcept
{
    _helpText = std::make_shared<std::string>(pHelpText);
    _dirtyFlag[1] = true;
}
void AttributeHelpTexts::setHelpText(std::string &&pHelpText) noexcept
{
    _helpText = std::make_shared<std::string>(std::move(pHelpText));
    _dirtyFlag[1] = true;
}


const std::string &AttributeHelpTexts::getValueOfType() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_type)
        return *_type;
    return defaultValue;
}
const std::shared_ptr<std::string> &AttributeHelpTexts::getType() const noexcept
{
    return _type;
}
void AttributeHelpTexts::setType(const std::string &pType) noexcept
{
    _type = std::make_shared<std::string>(pType);
    _dirtyFlag[2] = true;
}
void AttributeHelpTexts::setType(std::string &&pType) noexcept
{
    _type = std::make_shared<std::string>(std::move(pType));
    _dirtyFlag[2] = true;
}


const std::string &AttributeHelpTexts::getValueOfAttributeName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_attributeName)
        return *_attributeName;
    return defaultValue;
}
const std::shared_ptr<std::string> &AttributeHelpTexts::getAttributeName() const noexcept
{
    return _attributeName;
}
void AttributeHelpTexts::setAttributeName(const std::string &pAttributeName) noexcept
{
    _attributeName = std::make_shared<std::string>(pAttributeName);
    _dirtyFlag[3] = true;
}
void AttributeHelpTexts::setAttributeName(std::string &&pAttributeName) noexcept
{
    _attributeName = std::make_shared<std::string>(std::move(pAttributeName));
    _dirtyFlag[3] = true;
}


const ::trantor::Date &AttributeHelpTexts::getValueOfCreatedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_createdAt)
        return *_createdAt;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &AttributeHelpTexts::getCreatedAt() const noexcept
{
    return _createdAt;
}
void AttributeHelpTexts::setCreatedAt(const ::trantor::Date &pCreatedAt) noexcept
{
    _createdAt = std::make_shared<::trantor::Date>(pCreatedAt);
    _dirtyFlag[4] = true;
}


const ::trantor::Date &AttributeHelpTexts::getValueOfUpdatedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_updatedAt)
        return *_updatedAt;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &AttributeHelpTexts::getUpdatedAt() const noexcept
{
    return _updatedAt;
}
void AttributeHelpTexts::setUpdatedAt(const ::trantor::Date &pUpdatedAt) noexcept
{
    _updatedAt = std::make_shared<::trantor::Date>(pUpdatedAt);
    _dirtyFlag[5] = true;
}


void AttributeHelpTexts::updateId(const uint64_t id)
{
}

const std::vector<std::string> &AttributeHelpTexts::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "help_text",
        "type",
        "attribute_name",
        "created_at",
        "updated_at"
    };
    return _inCols;
}

void AttributeHelpTexts::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(getHelpText())
    {
        binder << getValueOfHelpText();
    }
    else
    {
        binder << nullptr;
    }
    if(getType())
    {
        binder << getValueOfType();
    }
    else
    {
        binder << nullptr;
    }
    if(getAttributeName())
    {
        binder << getValueOfAttributeName();
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

const std::vector<std::string> AttributeHelpTexts::updateColumns() const
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

void AttributeHelpTexts::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
    {
        if(getHelpText())
        {
            binder << getValueOfHelpText();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[2])
    {
        if(getType())
        {
            binder << getValueOfType();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[3])
    {
        if(getAttributeName())
        {
            binder << getValueOfAttributeName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[4])
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
    if(_dirtyFlag[5])
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
Json::Value AttributeHelpTexts::toJson() const
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
    if(getHelpText())
    {
        ret["help_text"]=getValueOfHelpText();
    }
    else
    {
        ret["help_text"]=Json::Value();
    }
    if(getType())
    {
        ret["type"]=getValueOfType();
    }
    else
    {
        ret["type"]=Json::Value();
    }
    if(getAttributeName())
    {
        ret["attribute_name"]=getValueOfAttributeName();
    }
    else
    {
        ret["attribute_name"]=Json::Value();
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

Json::Value AttributeHelpTexts::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 6)
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
            if(getHelpText())
            {
                ret[pMasqueradingVector[1]]=getValueOfHelpText();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getType())
            {
                ret[pMasqueradingVector[2]]=getValueOfType();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getAttributeName())
            {
                ret[pMasqueradingVector[3]]=getValueOfAttributeName();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getCreatedAt())
            {
                ret[pMasqueradingVector[4]]=getCreatedAt()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getUpdatedAt())
            {
                ret[pMasqueradingVector[5]]=getUpdatedAt()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
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
    if(getHelpText())
    {
        ret["help_text"]=getValueOfHelpText();
    }
    else
    {
        ret["help_text"]=Json::Value();
    }
    if(getType())
    {
        ret["type"]=getValueOfType();
    }
    else
    {
        ret["type"]=Json::Value();
    }
    if(getAttributeName())
    {
        ret["attribute_name"]=getValueOfAttributeName();
    }
    else
    {
        ret["attribute_name"]=Json::Value();
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
