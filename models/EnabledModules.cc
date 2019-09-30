/**
 *
 *  EnabledModules.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "EnabledModules.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject6;

const std::string EnabledModules::Cols::_id = "id";
const std::string EnabledModules::Cols::_project_id = "project_id";
const std::string EnabledModules::Cols::_name = "name";
const std::string EnabledModules::primaryKeyName = "id";
const bool EnabledModules::hasPrimaryKey = true;
const std::string EnabledModules::tableName = "enabled_modules";

const std::vector<typename EnabledModules::MetaData> EnabledModules::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"project_id","int32_t","integer",4,0,0,0},
{"name","std::string","character varying",0,0,0,1}
};
const std::string &EnabledModules::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
EnabledModules::EnabledModules(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            _id=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["project_id"].isNull())
        {
            _projectId=std::make_shared<int32_t>(r["project_id"].as<int32_t>());
        }
        if(!r["name"].isNull())
        {
            _name=std::make_shared<std::string>(r["name"].as<std::string>());
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
            _projectId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _name=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

EnabledModules::EnabledModules(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
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
            _projectId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            _name=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
}

EnabledModules::EnabledModules(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _dirtyFlag[0]=true;
        if(!pJson["id"].isNull())
        {
            _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("project_id"))
    {
        _dirtyFlag[1]=true;
        if(!pJson["project_id"].isNull())
        {
            _projectId=std::make_shared<int32_t>((int32_t)pJson["project_id"].asInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        _dirtyFlag[2]=true;
        if(!pJson["name"].isNull())
        {
            _name=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
}

void EnabledModules::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 3)
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
            _projectId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            _name=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
}
                                                                    
void EnabledModules::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("project_id"))
    {
        _dirtyFlag[1] = true;
        if(!pJson["project_id"].isNull())
        {
            _projectId=std::make_shared<int32_t>((int32_t)pJson["project_id"].asInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        _dirtyFlag[2] = true;
        if(!pJson["name"].isNull())
        {
            _name=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
}

const int32_t &EnabledModules::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &EnabledModules::getId() const noexcept
{
    return _id;
}
const typename EnabledModules::PrimaryKeyType & EnabledModules::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const int32_t &EnabledModules::getValueOfProjectId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_projectId)
        return *_projectId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &EnabledModules::getProjectId() const noexcept
{
    return _projectId;
}
void EnabledModules::setProjectId(const int32_t &pProjectId) noexcept
{
    _projectId = std::make_shared<int32_t>(pProjectId);
    _dirtyFlag[1] = true;
}


const std::string &EnabledModules::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_name)
        return *_name;
    return defaultValue;
}
const std::shared_ptr<std::string> &EnabledModules::getName() const noexcept
{
    return _name;
}
void EnabledModules::setName(const std::string &pName) noexcept
{
    _name = std::make_shared<std::string>(pName);
    _dirtyFlag[2] = true;
}
void EnabledModules::setName(std::string &&pName) noexcept
{
    _name = std::make_shared<std::string>(std::move(pName));
    _dirtyFlag[2] = true;
}


void EnabledModules::updateId(const uint64_t id)
{
}

const std::vector<std::string> &EnabledModules::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "project_id",
        "name"
    };
    return _inCols;
}

void EnabledModules::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
    {
        if(getProjectId())
        {
            binder << getValueOfProjectId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[2])
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
}

const std::vector<std::string> EnabledModules::updateColumns() const
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

void EnabledModules::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
    {
        if(getProjectId())
        {
            binder << getValueOfProjectId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[2])
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
}
Json::Value EnabledModules::toJson() const
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
    if(getProjectId())
    {
        ret["project_id"]=getValueOfProjectId();
    }
    else
    {
        ret["project_id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    return ret;
}

Json::Value EnabledModules::toMasqueradedJson(
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
            if(getProjectId())
            {
                ret[pMasqueradingVector[1]]=getValueOfProjectId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[2]]=getValueOfName();
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
    if(getProjectId())
    {
        ret["project_id"]=getValueOfProjectId();
    }
    else
    {
        ret["project_id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    return ret;
}

bool EnabledModules::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("project_id"))
    {
        if(!validJsonOfField(1, "project_id", pJson["project_id"], err, true))
            return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(2, "name", pJson["name"], err, true))
            return false;
    }
    else
    {
        err="The name column cannot be null";
        return false;
    }
    return true;
}
bool EnabledModules::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                                        const std::vector<std::string> &pMasqueradingVector,
                                                        std::string &err)
{
    if(pMasqueradingVector.size() != 3)
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
    return true;
}
bool EnabledModules::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
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
    if(pJson.isMember("project_id"))
    {
        if(!validJsonOfField(1, "project_id", pJson["project_id"], err, false))
            return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(2, "name", pJson["name"], err, false))
            return false;
    }
    return true;
}
bool EnabledModules::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                                      const std::vector<std::string> &pMasqueradingVector,
                                                      std::string &err)
{
    if(pMasqueradingVector.size() != 3)
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
    return true;
}
bool EnabledModules::validJsonOfField(size_t index,
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