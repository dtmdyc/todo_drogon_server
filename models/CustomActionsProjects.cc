/**
 *
 *  CustomActionsProjects.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "CustomActionsProjects.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject6;

const std::string CustomActionsProjects::Cols::_id = "id";
const std::string CustomActionsProjects::Cols::_project_id = "project_id";
const std::string CustomActionsProjects::Cols::_custom_action_id = "custom_action_id";
const std::string CustomActionsProjects::primaryKeyName = "id";
const bool CustomActionsProjects::hasPrimaryKey = true;
const std::string CustomActionsProjects::tableName = "custom_actions_projects";

const std::vector<typename CustomActionsProjects::MetaData> CustomActionsProjects::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"project_id","int64_t","bigint",8,0,0,0},
{"custom_action_id","int64_t","bigint",8,0,0,0}
};
const std::string &CustomActionsProjects::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
CustomActionsProjects::CustomActionsProjects(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            _id=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["project_id"].isNull())
        {
            _projectId=std::make_shared<int64_t>(r["project_id"].as<int64_t>());
        }
        if(!r["custom_action_id"].isNull())
        {
            _customActionId=std::make_shared<int64_t>(r["custom_action_id"].as<int64_t>());
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
            _projectId=std::make_shared<int64_t>(r[index].as<int64_t>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _customActionId=std::make_shared<int64_t>(r[index].as<int64_t>());
        }
    }

}

CustomActionsProjects::CustomActionsProjects(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
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
            _projectId=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            _customActionId=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
}

CustomActionsProjects::CustomActionsProjects(const Json::Value &pJson) noexcept(false)
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
            _projectId=std::make_shared<int64_t>((int64_t)pJson["project_id"].asInt64());
        }
    }
    if(pJson.isMember("custom_action_id"))
    {
        _dirtyFlag[2]=true;
        if(!pJson["custom_action_id"].isNull())
        {
            _customActionId=std::make_shared<int64_t>((int64_t)pJson["custom_action_id"].asInt64());
        }
    }
}

void CustomActionsProjects::updateByMasqueradedJson(const Json::Value &pJson,
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
            _projectId=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            _customActionId=std::make_shared<int64_t>((int64_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
}
                                                                    
void CustomActionsProjects::updateByJson(const Json::Value &pJson) noexcept(false)
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
            _projectId=std::make_shared<int64_t>((int64_t)pJson["project_id"].asInt64());
        }
    }
    if(pJson.isMember("custom_action_id"))
    {
        _dirtyFlag[2] = true;
        if(!pJson["custom_action_id"].isNull())
        {
            _customActionId=std::make_shared<int64_t>((int64_t)pJson["custom_action_id"].asInt64());
        }
    }
}

const int32_t &CustomActionsProjects::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &CustomActionsProjects::getId() const noexcept
{
    return _id;
}
const typename CustomActionsProjects::PrimaryKeyType & CustomActionsProjects::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const int64_t &CustomActionsProjects::getValueOfProjectId() const noexcept
{
    const static int64_t defaultValue = int64_t();
    if(_projectId)
        return *_projectId;
    return defaultValue;
}
const std::shared_ptr<int64_t> &CustomActionsProjects::getProjectId() const noexcept
{
    return _projectId;
}
void CustomActionsProjects::setProjectId(const int64_t &pProjectId) noexcept
{
    _projectId = std::make_shared<int64_t>(pProjectId);
    _dirtyFlag[1] = true;
}


const int64_t &CustomActionsProjects::getValueOfCustomActionId() const noexcept
{
    const static int64_t defaultValue = int64_t();
    if(_customActionId)
        return *_customActionId;
    return defaultValue;
}
const std::shared_ptr<int64_t> &CustomActionsProjects::getCustomActionId() const noexcept
{
    return _customActionId;
}
void CustomActionsProjects::setCustomActionId(const int64_t &pCustomActionId) noexcept
{
    _customActionId = std::make_shared<int64_t>(pCustomActionId);
    _dirtyFlag[2] = true;
}


void CustomActionsProjects::updateId(const uint64_t id)
{
}

const std::vector<std::string> &CustomActionsProjects::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "project_id",
        "custom_action_id"
    };
    return _inCols;
}

void CustomActionsProjects::outputArgs(drogon::orm::internal::SqlBinder &binder) const
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
        if(getCustomActionId())
        {
            binder << getValueOfCustomActionId();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> CustomActionsProjects::updateColumns() const
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

void CustomActionsProjects::updateArgs(drogon::orm::internal::SqlBinder &binder) const
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
        if(getCustomActionId())
        {
            binder << getValueOfCustomActionId();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value CustomActionsProjects::toJson() const
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
        ret["project_id"]=(Json::Int64)getValueOfProjectId();
    }
    else
    {
        ret["project_id"]=Json::Value();
    }
    if(getCustomActionId())
    {
        ret["custom_action_id"]=(Json::Int64)getValueOfCustomActionId();
    }
    else
    {
        ret["custom_action_id"]=Json::Value();
    }
    return ret;
}

Json::Value CustomActionsProjects::toMasqueradedJson(
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
                ret[pMasqueradingVector[1]]=(Json::Int64)getValueOfProjectId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getCustomActionId())
            {
                ret[pMasqueradingVector[2]]=(Json::Int64)getValueOfCustomActionId();
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
        ret["project_id"]=(Json::Int64)getValueOfProjectId();
    }
    else
    {
        ret["project_id"]=Json::Value();
    }
    if(getCustomActionId())
    {
        ret["custom_action_id"]=(Json::Int64)getValueOfCustomActionId();
    }
    else
    {
        ret["custom_action_id"]=Json::Value();
    }
    return ret;
}

bool CustomActionsProjects::validateJsonForCreation(const Json::Value &pJson, std::string &err)
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
    if(pJson.isMember("custom_action_id"))
    {
        if(!validJsonOfField(2, "custom_action_id", pJson["custom_action_id"], err, true))
            return false;
    }
    return true;
}
bool CustomActionsProjects::validateMasqueradedJsonForCreation(const Json::Value &pJson,
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
    }
    return true;
}
bool CustomActionsProjects::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
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
    if(pJson.isMember("custom_action_id"))
    {
        if(!validJsonOfField(2, "custom_action_id", pJson["custom_action_id"], err, false))
            return false;
    }
    return true;
}
bool CustomActionsProjects::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
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
bool CustomActionsProjects::validJsonOfField(size_t index,
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
            if(!pJson.isInt64())
            {
                err="Type error in the "+fieldName+"field";
                return false;
            }
            break;
        case 2:
            if(!pJson.isInt64())
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