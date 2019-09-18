/**
 *
 *  Changes.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Changes.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject4;

const std::string Changes::Cols::_id = "id";
const std::string Changes::Cols::_changeset_id = "changeset_id";
const std::string Changes::Cols::_action = "action";
const std::string Changes::Cols::_path = "path";
const std::string Changes::Cols::_from_path = "from_path";
const std::string Changes::Cols::_from_revision = "from_revision";
const std::string Changes::Cols::_revision = "revision";
const std::string Changes::Cols::_branch = "branch";
const std::string Changes::primaryKeyName = "id";
const bool Changes::hasPrimaryKey = true;
const std::string Changes::tableName = "changes";

const std::vector<typename Changes::MetaData> Changes::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"changeset_id","int32_t","integer",4,0,0,1},
{"action","std::string","character varying",1,0,0,1},
{"path","std::string","text",0,0,0,1},
{"from_path","std::string","text",0,0,0,0},
{"from_revision","std::string","character varying",0,0,0,0},
{"revision","std::string","character varying",0,0,0,0},
{"branch","std::string","character varying",0,0,0,0}
};
const std::string &Changes::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
Changes::Changes(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            _id=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["changeset_id"].isNull())
        {
            _changesetId=std::make_shared<int32_t>(r["changeset_id"].as<int32_t>());
        }
        if(!r["action"].isNull())
        {
            _action=std::make_shared<std::string>(r["action"].as<std::string>());
        }
        if(!r["path"].isNull())
        {
            _path=std::make_shared<std::string>(r["path"].as<std::string>());
        }
        if(!r["from_path"].isNull())
        {
            _fromPath=std::make_shared<std::string>(r["from_path"].as<std::string>());
        }
        if(!r["from_revision"].isNull())
        {
            _fromRevision=std::make_shared<std::string>(r["from_revision"].as<std::string>());
        }
        if(!r["revision"].isNull())
        {
            _revision=std::make_shared<std::string>(r["revision"].as<std::string>());
        }
        if(!r["branch"].isNull())
        {
            _branch=std::make_shared<std::string>(r["branch"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 8 > r.size())
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
            _changesetId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _action=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            _path=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            _fromPath=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            _fromRevision=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 6;
        if(!r[index].isNull())
        {
            _revision=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 7;
        if(!r[index].isNull())
        {
            _branch=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

Changes::Changes(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 8)
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
        _changesetId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _action=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _path=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        _fromPath=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        _fromRevision=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        _revision=std::make_shared<std::string>(pJson[pMasqueradingVector[6]].asString());
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        _branch=std::make_shared<std::string>(pJson[pMasqueradingVector[7]].asString());
    }
}

Changes::Changes(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("changeset_id"))
    {
        _changesetId=std::make_shared<int32_t>((int32_t)pJson["changeset_id"].asInt64());
    }
    if(pJson.isMember("action"))
    {
        _action=std::make_shared<std::string>(pJson["action"].asString());
    }
    if(pJson.isMember("path"))
    {
        _path=std::make_shared<std::string>(pJson["path"].asString());
    }
    if(pJson.isMember("from_path"))
    {
        _fromPath=std::make_shared<std::string>(pJson["from_path"].asString());
    }
    if(pJson.isMember("from_revision"))
    {
        _fromRevision=std::make_shared<std::string>(pJson["from_revision"].asString());
    }
    if(pJson.isMember("revision"))
    {
        _revision=std::make_shared<std::string>(pJson["revision"].asString());
    }
    if(pJson.isMember("branch"))
    {
        _branch=std::make_shared<std::string>(pJson["branch"].asString());
    }
}

void Changes::updateByMasqueradedJson(const Json::Value &pJson, 
                                                                                                     const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 8)
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
        _changesetId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        _action=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        _path=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        _dirtyFlag[4] = true;
        _fromPath=std::make_shared<std::string>(pJson[pMasqueradingVector[4]].asString());
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        _dirtyFlag[5] = true;
        _fromRevision=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        _dirtyFlag[6] = true;
        _revision=std::make_shared<std::string>(pJson[pMasqueradingVector[6]].asString());
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        _dirtyFlag[7] = true;
        _branch=std::make_shared<std::string>(pJson[pMasqueradingVector[7]].asString());
    }
}
                                                                    
void Changes::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("changeset_id"))
    {
        _dirtyFlag[1] = true;
        _changesetId=std::make_shared<int32_t>((int32_t)pJson["changeset_id"].asInt64());
    }
    if(pJson.isMember("action"))
    {
        _dirtyFlag[2] = true;
        _action=std::make_shared<std::string>(pJson["action"].asString());
    }
    if(pJson.isMember("path"))
    {
        _dirtyFlag[3] = true;
        _path=std::make_shared<std::string>(pJson["path"].asString());
    }
    if(pJson.isMember("from_path"))
    {
        _dirtyFlag[4] = true;
        _fromPath=std::make_shared<std::string>(pJson["from_path"].asString());
    }
    if(pJson.isMember("from_revision"))
    {
        _dirtyFlag[5] = true;
        _fromRevision=std::make_shared<std::string>(pJson["from_revision"].asString());
    }
    if(pJson.isMember("revision"))
    {
        _dirtyFlag[6] = true;
        _revision=std::make_shared<std::string>(pJson["revision"].asString());
    }
    if(pJson.isMember("branch"))
    {
        _dirtyFlag[7] = true;
        _branch=std::make_shared<std::string>(pJson["branch"].asString());
    }
}

const int32_t &Changes::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Changes::getId() const noexcept
{
    return _id;
}
const typename Changes::PrimaryKeyType & Changes::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const int32_t &Changes::getValueOfChangesetId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_changesetId)
        return *_changesetId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Changes::getChangesetId() const noexcept
{
    return _changesetId;
}
void Changes::setChangesetId(const int32_t &pChangesetId) noexcept
{
    _changesetId = std::make_shared<int32_t>(pChangesetId);
    _dirtyFlag[1] = true;
}


const std::string &Changes::getValueOfAction() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_action)
        return *_action;
    return defaultValue;
}
const std::shared_ptr<std::string> &Changes::getAction() const noexcept
{
    return _action;
}
void Changes::setAction(const std::string &pAction) noexcept
{
    _action = std::make_shared<std::string>(pAction);
    _dirtyFlag[2] = true;
}
void Changes::setAction(std::string &&pAction) noexcept
{
    _action = std::make_shared<std::string>(std::move(pAction));
    _dirtyFlag[2] = true;
}


const std::string &Changes::getValueOfPath() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_path)
        return *_path;
    return defaultValue;
}
const std::shared_ptr<std::string> &Changes::getPath() const noexcept
{
    return _path;
}
void Changes::setPath(const std::string &pPath) noexcept
{
    _path = std::make_shared<std::string>(pPath);
    _dirtyFlag[3] = true;
}
void Changes::setPath(std::string &&pPath) noexcept
{
    _path = std::make_shared<std::string>(std::move(pPath));
    _dirtyFlag[3] = true;
}


const std::string &Changes::getValueOfFromPath() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_fromPath)
        return *_fromPath;
    return defaultValue;
}
const std::shared_ptr<std::string> &Changes::getFromPath() const noexcept
{
    return _fromPath;
}
void Changes::setFromPath(const std::string &pFromPath) noexcept
{
    _fromPath = std::make_shared<std::string>(pFromPath);
    _dirtyFlag[4] = true;
}
void Changes::setFromPath(std::string &&pFromPath) noexcept
{
    _fromPath = std::make_shared<std::string>(std::move(pFromPath));
    _dirtyFlag[4] = true;
}


const std::string &Changes::getValueOfFromRevision() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_fromRevision)
        return *_fromRevision;
    return defaultValue;
}
const std::shared_ptr<std::string> &Changes::getFromRevision() const noexcept
{
    return _fromRevision;
}
void Changes::setFromRevision(const std::string &pFromRevision) noexcept
{
    _fromRevision = std::make_shared<std::string>(pFromRevision);
    _dirtyFlag[5] = true;
}
void Changes::setFromRevision(std::string &&pFromRevision) noexcept
{
    _fromRevision = std::make_shared<std::string>(std::move(pFromRevision));
    _dirtyFlag[5] = true;
}


const std::string &Changes::getValueOfRevision() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_revision)
        return *_revision;
    return defaultValue;
}
const std::shared_ptr<std::string> &Changes::getRevision() const noexcept
{
    return _revision;
}
void Changes::setRevision(const std::string &pRevision) noexcept
{
    _revision = std::make_shared<std::string>(pRevision);
    _dirtyFlag[6] = true;
}
void Changes::setRevision(std::string &&pRevision) noexcept
{
    _revision = std::make_shared<std::string>(std::move(pRevision));
    _dirtyFlag[6] = true;
}


const std::string &Changes::getValueOfBranch() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_branch)
        return *_branch;
    return defaultValue;
}
const std::shared_ptr<std::string> &Changes::getBranch() const noexcept
{
    return _branch;
}
void Changes::setBranch(const std::string &pBranch) noexcept
{
    _branch = std::make_shared<std::string>(pBranch);
    _dirtyFlag[7] = true;
}
void Changes::setBranch(std::string &&pBranch) noexcept
{
    _branch = std::make_shared<std::string>(std::move(pBranch));
    _dirtyFlag[7] = true;
}


void Changes::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Changes::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "changeset_id",
        "action",
        "path",
        "from_path",
        "from_revision",
        "revision",
        "branch"
    };
    return _inCols;
}

void Changes::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(getChangesetId())
    {
        binder << getValueOfChangesetId();
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
    if(getPath())
    {
        binder << getValueOfPath();
    }
    else
    {
        binder << nullptr;
    }
    if(getFromPath())
    {
        binder << getValueOfFromPath();
    }
    else
    {
        binder << nullptr;
    }
    if(getFromRevision())
    {
        binder << getValueOfFromRevision();
    }
    else
    {
        binder << nullptr;
    }
    if(getRevision())
    {
        binder << getValueOfRevision();
    }
    else
    {
        binder << nullptr;
    }
    if(getBranch())
    {
        binder << getValueOfBranch();
    }
    else
    {
        binder << nullptr;
    }
}

const std::vector<std::string> Changes::updateColumns() const
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

void Changes::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
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
        if(getPath())
        {
            binder << getValueOfPath();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[4])
    {
        if(getFromPath())
        {
            binder << getValueOfFromPath();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[5])
    {
        if(getFromRevision())
        {
            binder << getValueOfFromRevision();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[6])
    {
        if(getRevision())
        {
            binder << getValueOfRevision();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[7])
    {
        if(getBranch())
        {
            binder << getValueOfBranch();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Changes::toJson() const
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
    if(getChangesetId())
    {
        ret["changeset_id"]=getValueOfChangesetId();
    }
    else
    {
        ret["changeset_id"]=Json::Value();
    }
    if(getAction())
    {
        ret["action"]=getValueOfAction();
    }
    else
    {
        ret["action"]=Json::Value();
    }
    if(getPath())
    {
        ret["path"]=getValueOfPath();
    }
    else
    {
        ret["path"]=Json::Value();
    }
    if(getFromPath())
    {
        ret["from_path"]=getValueOfFromPath();
    }
    else
    {
        ret["from_path"]=Json::Value();
    }
    if(getFromRevision())
    {
        ret["from_revision"]=getValueOfFromRevision();
    }
    else
    {
        ret["from_revision"]=Json::Value();
    }
    if(getRevision())
    {
        ret["revision"]=getValueOfRevision();
    }
    else
    {
        ret["revision"]=Json::Value();
    }
    if(getBranch())
    {
        ret["branch"]=getValueOfBranch();
    }
    else
    {
        ret["branch"]=Json::Value();
    }
    return ret;
}

Json::Value Changes::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 8)
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
            if(getChangesetId())
            {
                ret[pMasqueradingVector[1]]=getValueOfChangesetId();
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
            if(getPath())
            {
                ret[pMasqueradingVector[3]]=getValueOfPath();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getFromPath())
            {
                ret[pMasqueradingVector[4]]=getValueOfFromPath();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getFromRevision())
            {
                ret[pMasqueradingVector[5]]=getValueOfFromRevision();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[6].empty())
        {
            if(getRevision())
            {
                ret[pMasqueradingVector[6]]=getValueOfRevision();
            }
            else
            {
                ret[pMasqueradingVector[6]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[7].empty())
        {
            if(getBranch())
            {
                ret[pMasqueradingVector[7]]=getValueOfBranch();
            }
            else
            {
                ret[pMasqueradingVector[7]]=Json::Value();
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
    if(getChangesetId())
    {
        ret["changeset_id"]=getValueOfChangesetId();
    }
    else
    {
        ret["changeset_id"]=Json::Value();
    }
    if(getAction())
    {
        ret["action"]=getValueOfAction();
    }
    else
    {
        ret["action"]=Json::Value();
    }
    if(getPath())
    {
        ret["path"]=getValueOfPath();
    }
    else
    {
        ret["path"]=Json::Value();
    }
    if(getFromPath())
    {
        ret["from_path"]=getValueOfFromPath();
    }
    else
    {
        ret["from_path"]=Json::Value();
    }
    if(getFromRevision())
    {
        ret["from_revision"]=getValueOfFromRevision();
    }
    else
    {
        ret["from_revision"]=Json::Value();
    }
    if(getRevision())
    {
        ret["revision"]=getValueOfRevision();
    }
    else
    {
        ret["revision"]=Json::Value();
    }
    if(getBranch())
    {
        ret["branch"]=getValueOfBranch();
    }
    else
    {
        ret["branch"]=Json::Value();
    }
    return ret;
}
