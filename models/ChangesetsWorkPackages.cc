/**
 *
 *  ChangesetsWorkPackages.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "ChangesetsWorkPackages.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject4;

const std::string ChangesetsWorkPackages::Cols::_changeset_id = "changeset_id";
const std::string ChangesetsWorkPackages::Cols::_work_package_id = "work_package_id";
const std::string ChangesetsWorkPackages::primaryKeyName = "";
const bool ChangesetsWorkPackages::hasPrimaryKey = false;
const std::string ChangesetsWorkPackages::tableName = "changesets_work_packages";

const std::vector<typename ChangesetsWorkPackages::MetaData> ChangesetsWorkPackages::_metaData={
{"changeset_id","int32_t","integer",4,0,0,1},
{"work_package_id","int32_t","integer",4,0,0,1}
};
const std::string &ChangesetsWorkPackages::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
ChangesetsWorkPackages::ChangesetsWorkPackages(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["changeset_id"].isNull())
        {
            _changesetId=std::make_shared<int32_t>(r["changeset_id"].as<int32_t>());
        }
        if(!r["work_package_id"].isNull())
        {
            _workPackageId=std::make_shared<int32_t>(r["work_package_id"].as<int32_t>());
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
            _changesetId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            _workPackageId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

ChangesetsWorkPackages::ChangesetsWorkPackages(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        _changesetId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        _workPackageId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
}

ChangesetsWorkPackages::ChangesetsWorkPackages(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("changeset_id"))
    {
        _changesetId=std::make_shared<int32_t>((int32_t)pJson["changeset_id"].asInt64());
    }
    if(pJson.isMember("work_package_id"))
    {
        _workPackageId=std::make_shared<int32_t>((int32_t)pJson["work_package_id"].asInt64());
    }
}

void ChangesetsWorkPackages::updateByMasqueradedJson(const Json::Value &pJson, 
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
        _changesetId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        _dirtyFlag[1] = true;
        _workPackageId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
}
                                                                    
void ChangesetsWorkPackages::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("changeset_id"))
    {
        _dirtyFlag[0] = true;
        _changesetId=std::make_shared<int32_t>((int32_t)pJson["changeset_id"].asInt64());
    }
    if(pJson.isMember("work_package_id"))
    {
        _dirtyFlag[1] = true;
        _workPackageId=std::make_shared<int32_t>((int32_t)pJson["work_package_id"].asInt64());
    }
}

const int32_t &ChangesetsWorkPackages::getValueOfChangesetId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_changesetId)
        return *_changesetId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &ChangesetsWorkPackages::getChangesetId() const noexcept
{
    return _changesetId;
}
void ChangesetsWorkPackages::setChangesetId(const int32_t &pChangesetId) noexcept
{
    _changesetId = std::make_shared<int32_t>(pChangesetId);
    _dirtyFlag[0] = true;
}


const int32_t &ChangesetsWorkPackages::getValueOfWorkPackageId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_workPackageId)
        return *_workPackageId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &ChangesetsWorkPackages::getWorkPackageId() const noexcept
{
    return _workPackageId;
}
void ChangesetsWorkPackages::setWorkPackageId(const int32_t &pWorkPackageId) noexcept
{
    _workPackageId = std::make_shared<int32_t>(pWorkPackageId);
    _dirtyFlag[1] = true;
}


void ChangesetsWorkPackages::updateId(const uint64_t id)
{
}

const std::vector<std::string> &ChangesetsWorkPackages::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "changeset_id",
        "work_package_id"
    };
    return _inCols;
}

void ChangesetsWorkPackages::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(getChangesetId())
    {
        binder << getValueOfChangesetId();
    }
    else
    {
        binder << nullptr;
    }
    if(getWorkPackageId())
    {
        binder << getValueOfWorkPackageId();
    }
    else
    {
        binder << nullptr;
    }
}

const std::vector<std::string> ChangesetsWorkPackages::updateColumns() const
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

void ChangesetsWorkPackages::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[0])
    {
        if(getChangesetId())
        {
            binder << getValueOfChangesetId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[1])
    {
        if(getWorkPackageId())
        {
            binder << getValueOfWorkPackageId();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value ChangesetsWorkPackages::toJson() const
{
    Json::Value ret;
    if(getChangesetId())
    {
        ret["changeset_id"]=getValueOfChangesetId();
    }
    else
    {
        ret["changeset_id"]=Json::Value();
    }
    if(getWorkPackageId())
    {
        ret["work_package_id"]=getValueOfWorkPackageId();
    }
    else
    {
        ret["work_package_id"]=Json::Value();
    }
    return ret;
}

Json::Value ChangesetsWorkPackages::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 2)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getChangesetId())
            {
                ret[pMasqueradingVector[0]]=getValueOfChangesetId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getWorkPackageId())
            {
                ret[pMasqueradingVector[1]]=getValueOfWorkPackageId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getChangesetId())
    {
        ret["changeset_id"]=getValueOfChangesetId();
    }
    else
    {
        ret["changeset_id"]=Json::Value();
    }
    if(getWorkPackageId())
    {
        ret["work_package_id"]=getValueOfWorkPackageId();
    }
    else
    {
        ret["work_package_id"]=Json::Value();
    }
    return ret;
}
