/**
 *
 *  MemberRoles.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "MemberRoles.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject6;

const std::string MemberRoles::Cols::_id = "id";
const std::string MemberRoles::Cols::_member_id = "member_id";
const std::string MemberRoles::Cols::_role_id = "role_id";
const std::string MemberRoles::Cols::_inherited_from = "inherited_from";
const std::string MemberRoles::primaryKeyName = "id";
const bool MemberRoles::hasPrimaryKey = true;
const std::string MemberRoles::tableName = "member_roles";

const std::vector<typename MemberRoles::MetaData> MemberRoles::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"member_id","int32_t","integer",4,0,0,1},
{"role_id","int32_t","integer",4,0,0,1},
{"inherited_from","int32_t","integer",4,0,0,0}
};
const std::string &MemberRoles::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
MemberRoles::MemberRoles(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            _id=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["member_id"].isNull())
        {
            _memberId=std::make_shared<int32_t>(r["member_id"].as<int32_t>());
        }
        if(!r["role_id"].isNull())
        {
            _roleId=std::make_shared<int32_t>(r["role_id"].as<int32_t>());
        }
        if(!r["inherited_from"].isNull())
        {
            _inheritedFrom=std::make_shared<int32_t>(r["inherited_from"].as<int32_t>());
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
            _memberId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _roleId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            _inheritedFrom=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

MemberRoles::MemberRoles(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
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
            _memberId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            _roleId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            _inheritedFrom=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}

MemberRoles::MemberRoles(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _dirtyFlag[0]=true;
        if(!pJson["id"].isNull())
        {
            _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("member_id"))
    {
        _dirtyFlag[1]=true;
        if(!pJson["member_id"].isNull())
        {
            _memberId=std::make_shared<int32_t>((int32_t)pJson["member_id"].asInt64());
        }
    }
    if(pJson.isMember("role_id"))
    {
        _dirtyFlag[2]=true;
        if(!pJson["role_id"].isNull())
        {
            _roleId=std::make_shared<int32_t>((int32_t)pJson["role_id"].asInt64());
        }
    }
    if(pJson.isMember("inherited_from"))
    {
        _dirtyFlag[3]=true;
        if(!pJson["inherited_from"].isNull())
        {
            _inheritedFrom=std::make_shared<int32_t>((int32_t)pJson["inherited_from"].asInt64());
        }
    }
}

void MemberRoles::updateByMasqueradedJson(const Json::Value &pJson,
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
            _memberId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            _roleId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            _inheritedFrom=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
}
                                                                    
void MemberRoles::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("member_id"))
    {
        _dirtyFlag[1] = true;
        if(!pJson["member_id"].isNull())
        {
            _memberId=std::make_shared<int32_t>((int32_t)pJson["member_id"].asInt64());
        }
    }
    if(pJson.isMember("role_id"))
    {
        _dirtyFlag[2] = true;
        if(!pJson["role_id"].isNull())
        {
            _roleId=std::make_shared<int32_t>((int32_t)pJson["role_id"].asInt64());
        }
    }
    if(pJson.isMember("inherited_from"))
    {
        _dirtyFlag[3] = true;
        if(!pJson["inherited_from"].isNull())
        {
            _inheritedFrom=std::make_shared<int32_t>((int32_t)pJson["inherited_from"].asInt64());
        }
    }
}

const int32_t &MemberRoles::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &MemberRoles::getId() const noexcept
{
    return _id;
}
const typename MemberRoles::PrimaryKeyType & MemberRoles::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const int32_t &MemberRoles::getValueOfMemberId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_memberId)
        return *_memberId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &MemberRoles::getMemberId() const noexcept
{
    return _memberId;
}
void MemberRoles::setMemberId(const int32_t &pMemberId) noexcept
{
    _memberId = std::make_shared<int32_t>(pMemberId);
    _dirtyFlag[1] = true;
}


const int32_t &MemberRoles::getValueOfRoleId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_roleId)
        return *_roleId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &MemberRoles::getRoleId() const noexcept
{
    return _roleId;
}
void MemberRoles::setRoleId(const int32_t &pRoleId) noexcept
{
    _roleId = std::make_shared<int32_t>(pRoleId);
    _dirtyFlag[2] = true;
}


const int32_t &MemberRoles::getValueOfInheritedFrom() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_inheritedFrom)
        return *_inheritedFrom;
    return defaultValue;
}
const std::shared_ptr<int32_t> &MemberRoles::getInheritedFrom() const noexcept
{
    return _inheritedFrom;
}
void MemberRoles::setInheritedFrom(const int32_t &pInheritedFrom) noexcept
{
    _inheritedFrom = std::make_shared<int32_t>(pInheritedFrom);
    _dirtyFlag[3] = true;
}


void MemberRoles::updateId(const uint64_t id)
{
}

const std::vector<std::string> &MemberRoles::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "member_id",
        "role_id",
        "inherited_from"
    };
    return _inCols;
}

void MemberRoles::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
    {
        if(getMemberId())
        {
            binder << getValueOfMemberId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[2])
    {
        if(getRoleId())
        {
            binder << getValueOfRoleId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[3])
    {
        if(getInheritedFrom())
        {
            binder << getValueOfInheritedFrom();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> MemberRoles::updateColumns() const
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

void MemberRoles::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(_dirtyFlag[1])
    {
        if(getMemberId())
        {
            binder << getValueOfMemberId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[2])
    {
        if(getRoleId())
        {
            binder << getValueOfRoleId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[3])
    {
        if(getInheritedFrom())
        {
            binder << getValueOfInheritedFrom();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value MemberRoles::toJson() const
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
    if(getMemberId())
    {
        ret["member_id"]=getValueOfMemberId();
    }
    else
    {
        ret["member_id"]=Json::Value();
    }
    if(getRoleId())
    {
        ret["role_id"]=getValueOfRoleId();
    }
    else
    {
        ret["role_id"]=Json::Value();
    }
    if(getInheritedFrom())
    {
        ret["inherited_from"]=getValueOfInheritedFrom();
    }
    else
    {
        ret["inherited_from"]=Json::Value();
    }
    return ret;
}

Json::Value MemberRoles::toMasqueradedJson(
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
            if(getMemberId())
            {
                ret[pMasqueradingVector[1]]=getValueOfMemberId();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getRoleId())
            {
                ret[pMasqueradingVector[2]]=getValueOfRoleId();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getInheritedFrom())
            {
                ret[pMasqueradingVector[3]]=getValueOfInheritedFrom();
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
    if(getMemberId())
    {
        ret["member_id"]=getValueOfMemberId();
    }
    else
    {
        ret["member_id"]=Json::Value();
    }
    if(getRoleId())
    {
        ret["role_id"]=getValueOfRoleId();
    }
    else
    {
        ret["role_id"]=Json::Value();
    }
    if(getInheritedFrom())
    {
        ret["inherited_from"]=getValueOfInheritedFrom();
    }
    else
    {
        ret["inherited_from"]=Json::Value();
    }
    return ret;
}

bool MemberRoles::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("member_id"))
    {
        if(!validJsonOfField(1, "member_id", pJson["member_id"], err, true))
            return false;
    }
    else
    {
        err="The member_id column cannot be null";
        return false;
    }
    if(pJson.isMember("role_id"))
    {
        if(!validJsonOfField(2, "role_id", pJson["role_id"], err, true))
            return false;
    }
    else
    {
        err="The role_id column cannot be null";
        return false;
    }
    if(pJson.isMember("inherited_from"))
    {
        if(!validJsonOfField(3, "inherited_from", pJson["inherited_from"], err, true))
            return false;
    }
    return true;
}
bool MemberRoles::validateMasqueradedJsonForCreation(const Json::Value &pJson,
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
bool MemberRoles::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
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
    if(pJson.isMember("member_id"))
    {
        if(!validJsonOfField(1, "member_id", pJson["member_id"], err, false))
            return false;
    }
    if(pJson.isMember("role_id"))
    {
        if(!validJsonOfField(2, "role_id", pJson["role_id"], err, false))
            return false;
    }
    if(pJson.isMember("inherited_from"))
    {
        if(!validJsonOfField(3, "inherited_from", pJson["inherited_from"], err, false))
            return false;
    }
    return true;
}
bool MemberRoles::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
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
bool MemberRoles::validJsonOfField(size_t index,
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
            if(!pJson.isInt())
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