/**
 *
 *  CustomizableJournals.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "CustomizableJournals.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject6;

const std::string CustomizableJournals::Cols::_id = "id";
const std::string CustomizableJournals::Cols::_journal_id = "journal_id";
const std::string CustomizableJournals::Cols::_custom_field_id = "custom_field_id";
const std::string CustomizableJournals::Cols::_value = "value";
const std::string CustomizableJournals::primaryKeyName = "id";
const bool CustomizableJournals::hasPrimaryKey = true;
const std::string CustomizableJournals::tableName = "customizable_journals";

const std::vector<typename CustomizableJournals::MetaData> CustomizableJournals::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"journal_id","int32_t","integer",4,0,0,1},
{"custom_field_id","int32_t","integer",4,0,0,1},
{"value","std::string","text",0,0,0,0}
};
const std::string &CustomizableJournals::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
CustomizableJournals::CustomizableJournals(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            _id=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["journal_id"].isNull())
        {
            _journalId=std::make_shared<int32_t>(r["journal_id"].as<int32_t>());
        }
        if(!r["custom_field_id"].isNull())
        {
            _customFieldId=std::make_shared<int32_t>(r["custom_field_id"].as<int32_t>());
        }
        if(!r["value"].isNull())
        {
            _value=std::make_shared<std::string>(r["value"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 4 > r.size())
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
            _journalId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _customFieldId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            _value=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

CustomizableJournals::CustomizableJournals(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        _dirtyFlag[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            _id=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        _dirtyFlag[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            _journalId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            _customFieldId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            _value=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
}

CustomizableJournals::CustomizableJournals(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _dirtyFlag[0]=true;
        if(!pJson["id"].isNull())
        {
            _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("journal_id"))
    {
        _dirtyFlag[1]=true;
        if(!pJson["journal_id"].isNull())
        {
            _journalId=std::make_shared<int32_t>((int32_t)pJson["journal_id"].asInt64());
        }
    }
    if(pJson.isMember("custom_field_id"))
    {
        _dirtyFlag[2]=true;
        if(!pJson["custom_field_id"].isNull())
        {
            _customFieldId=std::make_shared<int32_t>((int32_t)pJson["custom_field_id"].asInt64());
        }
    }
    if(pJson.isMember("value"))
    {
        _dirtyFlag[3]=true;
        if(!pJson["value"].isNull())
        {
            _value=std::make_shared<std::string>(pJson["value"].asString());
        }
    }
}

void CustomizableJournals::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            _id=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        _dirtyFlag[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            _journalId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            _customFieldId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            _value=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
}
                                                                    
void CustomizableJournals::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("journal_id"))
    {
        _dirtyFlag[1] = true;
        if(!pJson["journal_id"].isNull())
        {
            _journalId=std::make_shared<int32_t>((int32_t)pJson["journal_id"].asInt64());
        }
    }
    if(pJson.isMember("custom_field_id"))
    {
        _dirtyFlag[2] = true;
        if(!pJson["custom_field_id"].isNull())
        {
            _customFieldId=std::make_shared<int32_t>((int32_t)pJson["custom_field_id"].asInt64());
        }
    }
    if(pJson.isMember("value"))
    {
        _dirtyFlag[3] = true;
        if(!pJson["value"].isNull())
        {
            _value=std::make_shared<std::string>(pJson["value"].asString());
        }
    }
}

const int32_t &CustomizableJournals::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &CustomizableJournals::getId() const noexcept
{
    return _id;
}
const typename CustomizableJournals::PrimaryKeyType & CustomizableJournals::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const int32_t &CustomizableJournals::getValueOfJournalId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_journalId)
        return *_journalId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &CustomizableJournals::getJournalId() const noexcept
{
    return _journalId;
}
void CustomizableJournals::setJournalId(const int32_t &pJournalId) noexcept
{
    _journalId = std::make_shared<int32_t>(pJournalId);
    _dirtyFlag[1] = true;
}


const int32_t &CustomizableJournals::getValueOfCustomFieldId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_customFieldId)
        return *_customFieldId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &CustomizableJournals::getCustomFieldId() const noexcept
{
    return _customFieldId;
}
void CustomizableJournals::setCustomFieldId(const int32_t &pCustomFieldId) noexcept
{
    _customFieldId = std::make_shared<int32_t>(pCustomFieldId);
    _dirtyFlag[2] = true;
}


const std::string &CustomizableJournals::getValueOfValue() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_value)
        return *_value;
    return defaultValue;
}
const std::shared_ptr<std::string> &CustomizableJournals::getValue() const noexcept
{
    return _value;
}
void CustomizableJournals::setValue(const std::string &pValue) noexcept
{
    _value = std::make_shared<std::string>(pValue);
    _dirtyFlag[3] = true;
}
void CustomizableJournals::setValue(std::string &&pValue) noexcept
{
    _value = std::make_shared<std::string>(std::move(pValue));
    _dirtyFlag[3] = true;
}


void CustomizableJournals::updateId(const uint64_t id)
{
}

const std::vector<std::string> &CustomizableJournals::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "journal_id",
        "custom_field_id",
        "value"
    };
    return _inCols;
}

void CustomizableJournals::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
    {
        if(getJournalId())
        {
            binder << getValueOfJournalId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[2])
    {
        if(getCustomFieldId())
        {
            binder << getValueOfCustomFieldId();
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
}

const std::vector<std::string> CustomizableJournals::updateColumns() const
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

void CustomizableJournals::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
    {
        if(getJournalId())
        {
            binder << getValueOfJournalId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[2])
    {
        if(getCustomFieldId())
        {
            binder << getValueOfCustomFieldId();
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
}
Json::Value CustomizableJournals::toJson() const
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
    if(getJournalId())
    {
        ret["journal_id"]=getValueOfJournalId();
    }
    else
    {
        ret["journal_id"]=Json::Value();
    }
    if(getCustomFieldId())
    {
        ret["custom_field_id"]=getValueOfCustomFieldId();
    }
    else
    {
        ret["custom_field_id"]=Json::Value();
    }
    if(getValue())
    {
        ret["value"]=getValueOfValue();
    }
    else
    {
        ret["value"]=Json::Value();
    }
    return ret;
}

Json::Value CustomizableJournals::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 4)
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
            if(getJournalId())
            {
                ret[pMasqueradingVector[1]]=getValueOfJournalId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getCustomFieldId())
            {
                ret[pMasqueradingVector[2]]=getValueOfCustomFieldId();
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
    if(getJournalId())
    {
        ret["journal_id"]=getValueOfJournalId();
    }
    else
    {
        ret["journal_id"]=Json::Value();
    }
    if(getCustomFieldId())
    {
        ret["custom_field_id"]=getValueOfCustomFieldId();
    }
    else
    {
        ret["custom_field_id"]=Json::Value();
    }
    if(getValue())
    {
        ret["value"]=getValueOfValue();
    }
    else
    {
        ret["value"]=Json::Value();
    }
    return ret;
}

bool CustomizableJournals::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("journal_id"))
    {
        if(!validJsonOfField(1, "journal_id", pJson["journal_id"], err, true))
            return false;
    }
    else
    {
        err="The journal_id column cannot be null";
        return false;
    }
    if(pJson.isMember("custom_field_id"))
    {
        if(!validJsonOfField(2, "custom_field_id", pJson["custom_field_id"], err, true))
            return false;
    }
    else
    {
        err="The custom_field_id column cannot be null";
        return false;
    }
    if(pJson.isMember("value"))
    {
        if(!validJsonOfField(3, "value", pJson["value"], err, true))
            return false;
    }
    return true;
}
bool CustomizableJournals::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                              const std::vector<std::string> &pMasqueradingVector,
                                                              std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    if(!pMasqueradingVector[0].empty())
    {
        if(pJson.isMember(pMasqueradingVector[0]))
        {
            if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                return false;
        }
    }
    if(!pMasqueradingVector[1].empty())
    {
        if(pJson.isMember(pMasqueradingVector[1]))
        {
            if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                return false;
        }
        else
        {
            err="The " + pMasqueradingVector[1] + " column cannot be null";
            return false;
        }
    }
    if(!pMasqueradingVector[2].empty())
    {
        if(pJson.isMember(pMasqueradingVector[2]))
        {
            if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                return false;
        }
        else
        {
            err="The " + pMasqueradingVector[2] + " column cannot be null";
            return false;
        }
    }
    if(!pMasqueradingVector[3].empty())
    {
        if(pJson.isMember(pMasqueradingVector[3]))
        {
            if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                return false;
        }
    }
    return true;
}
bool CustomizableJournals::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("journal_id"))
    {
        if(!validJsonOfField(1, "journal_id", pJson["journal_id"], err, false))
            return false;
    }
    if(pJson.isMember("custom_field_id"))
    {
        if(!validJsonOfField(2, "custom_field_id", pJson["custom_field_id"], err, false))
            return false;
    }
    if(pJson.isMember("value"))
    {
        if(!validJsonOfField(3, "value", pJson["value"], err, false))
            return false;
    }
    return true;
}
bool CustomizableJournals::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                            const std::vector<std::string> &pMasqueradingVector,
                                                            std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
            return false;
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
            return false;
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
            return false;
    }
    return true;
}
bool CustomizableJournals::validJsonOfField(size_t index,
                                            const std::string &fieldName,
                                            const Json::Value &pJson, 
                                            std::string &err, 
                                            bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }        
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+"field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+"field";
                return false;
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+"field";
                return false;
            }
            break;
        case 3:
            if(!pJson.isString() && !pJson.isNull())
            {
                err="Type error in the "+fieldName+"field";
                return false;                
            }
            break;
     
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}