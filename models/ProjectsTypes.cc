/**
 *
 *  ProjectsTypes.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "ProjectsTypes.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject4;

const std::string ProjectsTypes::Cols::_project_id = "project_id";
const std::string ProjectsTypes::Cols::_type_id = "type_id";
const std::string ProjectsTypes::primaryKeyName = "";
const bool ProjectsTypes::hasPrimaryKey = false;
const std::string ProjectsTypes::tableName = "projects_types";

const std::vector<typename ProjectsTypes::MetaData> ProjectsTypes::_metaData={
{"project_id","int32_t","integer",4,0,0,1},
{"type_id","int32_t","integer",4,0,0,1}
};
const std::string &ProjectsTypes::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
ProjectsTypes::ProjectsTypes(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["project_id"].isNull())
        {
            _projectId=std::make_shared<int32_t>(r["project_id"].as<int32_t>());
        }
        if(!r["type_id"].isNull())
        {
            _typeId=std::make_shared<int32_t>(r["type_id"].as<int32_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 2 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            _projectId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            _typeId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

ProjectsTypes::ProjectsTypes(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        _projectId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        _typeId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
}

ProjectsTypes::ProjectsTypes(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("project_id"))
    {
        _projectId=std::make_shared<int32_t>((int32_t)pJson["project_id"].asInt64());
    }
    if(pJson.isMember("type_id"))
    {
        _typeId=std::make_shared<int32_t>((int32_t)pJson["type_id"].asInt64());
    }
}

void ProjectsTypes::updateByMasqueradedJson(const Json::Value &pJson, 
                                                                                                     const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        _dirtyFlag[0] = true;
        _projectId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        _dirtyFlag[1] = true;
        _typeId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
}
                                                                    
void ProjectsTypes::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("project_id"))
    {
        _dirtyFlag[0] = true;
        _projectId=std::make_shared<int32_t>((int32_t)pJson["project_id"].asInt64());
    }
    if(pJson.isMember("type_id"))
    {
        _dirtyFlag[1] = true;
        _typeId=std::make_shared<int32_t>((int32_t)pJson["type_id"].asInt64());
    }
}

const int32_t &ProjectsTypes::getValueOfProjectId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_projectId)
        return *_projectId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &ProjectsTypes::getProjectId() const noexcept
{
    return _projectId;
}
void ProjectsTypes::setProjectId(const int32_t &pProjectId) noexcept
{
    _projectId = std::make_shared<int32_t>(pProjectId);
    _dirtyFlag[0] = true;
}


const int32_t &ProjectsTypes::getValueOfTypeId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_typeId)
        return *_typeId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &ProjectsTypes::getTypeId() const noexcept
{
    return _typeId;
}
void ProjectsTypes::setTypeId(const int32_t &pTypeId) noexcept
{
    _typeId = std::make_shared<int32_t>(pTypeId);
    _dirtyFlag[1] = true;
}


void ProjectsTypes::updateId(const uint64_t id)
{
}

const std::vector<std::string> &ProjectsTypes::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "project_id",
        "type_id"
    };
    return _inCols;
}

void ProjectsTypes::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(getProjectId())
    {
        binder << getValueOfProjectId();
    }
    else
    {
        binder << nullptr;
    }
    if(getTypeId())
    {
        binder << getValueOfTypeId();
    }
    else
    {
        binder << nullptr;
    }
}

const std::vector<std::string> ProjectsTypes::updateColumns() const
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

void ProjectsTypes::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[0])
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
    if(_dirtyFlag[1])
    {
        if(getTypeId())
        {
            binder << getValueOfTypeId();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value ProjectsTypes::toJson() const
{
    Json::Value ret;
    if(getProjectId())
    {
        ret["project_id"]=getValueOfProjectId();
    }
    else
    {
        ret["project_id"]=Json::Value();
    }
    if(getTypeId())
    {
        ret["type_id"]=getValueOfTypeId();
    }
    else
    {
        ret["type_id"]=Json::Value();
    }
    return ret;
}

Json::Value ProjectsTypes::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 2)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getProjectId())
            {
                ret[pMasqueradingVector[0]]=getValueOfProjectId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getTypeId())
            {
                ret[pMasqueradingVector[1]]=getValueOfTypeId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getProjectId())
    {
        ret["project_id"]=getValueOfProjectId();
    }
    else
    {
        ret["project_id"]=Json::Value();
    }
    if(getTypeId())
    {
        ret["type_id"]=getValueOfTypeId();
    }
    else
    {
        ret["type_id"]=Json::Value();
    }
    return ret;
}
