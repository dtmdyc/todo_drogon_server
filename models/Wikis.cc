/**
 *
 *  Wikis.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Wikis.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject6;

const std::string Wikis::Cols::_id = "id";
const std::string Wikis::Cols::_project_id = "project_id";
const std::string Wikis::Cols::_start_page = "start_page";
const std::string Wikis::Cols::_status = "status";
const std::string Wikis::Cols::_created_at = "created_at";
const std::string Wikis::Cols::_updated_at = "updated_at";
const std::string Wikis::primaryKeyName = "id";
const bool Wikis::hasPrimaryKey = true;
const std::string Wikis::tableName = "wikis";

const std::vector<typename Wikis::MetaData> Wikis::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"project_id","int32_t","integer",4,0,0,1},
{"start_page","std::string","character varying",0,0,0,1},
{"status","int32_t","integer",4,0,0,1},
{"created_at","::trantor::Date","timestamp without time zone",0,0,0,1},
{"updated_at","::trantor::Date","timestamp without time zone",0,0,0,1}
};
const std::string &Wikis::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
Wikis::Wikis(const Row &r, const ssize_t indexOffset) noexcept
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
        if(!r["start_page"].isNull())
        {
            _startPage=std::make_shared<std::string>(r["start_page"].as<std::string>());
        }
        if(!r["status"].isNull())
        {
            _status=std::make_shared<int32_t>(r["status"].as<int32_t>());
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
            _projectId=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            _startPage=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            _status=std::make_shared<int32_t>(r[index].as<int32_t>());
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

Wikis::Wikis(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
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
            _startPage=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            _status=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        _dirtyFlag[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
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
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        _dirtyFlag[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
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
}

Wikis::Wikis(const Json::Value &pJson) noexcept(false)
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
    if(pJson.isMember("start_page"))
    {
        _dirtyFlag[2]=true;
        if(!pJson["start_page"].isNull())
        {
            _startPage=std::make_shared<std::string>(pJson["start_page"].asString());
        }
    }
    if(pJson.isMember("status"))
    {
        _dirtyFlag[3]=true;
        if(!pJson["status"].isNull())
        {
            _status=std::make_shared<int32_t>((int32_t)pJson["status"].asInt64());
        }
    }
    if(pJson.isMember("created_at"))
    {
        _dirtyFlag[4]=true;
        if(!pJson["created_at"].isNull())
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
    }
    if(pJson.isMember("updated_at"))
    {
        _dirtyFlag[5]=true;
        if(!pJson["updated_at"].isNull())
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
}

void Wikis::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
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
            _startPage=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            _status=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[3]].asInt64());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        _dirtyFlag[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
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
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        _dirtyFlag[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
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
}
                                                                    
void Wikis::updateByJson(const Json::Value &pJson) noexcept(false)
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
    if(pJson.isMember("start_page"))
    {
        _dirtyFlag[2] = true;
        if(!pJson["start_page"].isNull())
        {
            _startPage=std::make_shared<std::string>(pJson["start_page"].asString());
        }
    }
    if(pJson.isMember("status"))
    {
        _dirtyFlag[3] = true;
        if(!pJson["status"].isNull())
        {
            _status=std::make_shared<int32_t>((int32_t)pJson["status"].asInt64());
        }
    }
    if(pJson.isMember("created_at"))
    {
        _dirtyFlag[4] = true;
        if(!pJson["created_at"].isNull())
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
    }
    if(pJson.isMember("updated_at"))
    {
        _dirtyFlag[5] = true;
        if(!pJson["updated_at"].isNull())
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
}

const int32_t &Wikis::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Wikis::getId() const noexcept
{
    return _id;
}
const typename Wikis::PrimaryKeyType & Wikis::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const int32_t &Wikis::getValueOfProjectId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_projectId)
        return *_projectId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Wikis::getProjectId() const noexcept
{
    return _projectId;
}
void Wikis::setProjectId(const int32_t &pProjectId) noexcept
{
    _projectId = std::make_shared<int32_t>(pProjectId);
    _dirtyFlag[1] = true;
}


const std::string &Wikis::getValueOfStartPage() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_startPage)
        return *_startPage;
    return defaultValue;
}
const std::shared_ptr<std::string> &Wikis::getStartPage() const noexcept
{
    return _startPage;
}
void Wikis::setStartPage(const std::string &pStartPage) noexcept
{
    _startPage = std::make_shared<std::string>(pStartPage);
    _dirtyFlag[2] = true;
}
void Wikis::setStartPage(std::string &&pStartPage) noexcept
{
    _startPage = std::make_shared<std::string>(std::move(pStartPage));
    _dirtyFlag[2] = true;
}


const int32_t &Wikis::getValueOfStatus() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_status)
        return *_status;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Wikis::getStatus() const noexcept
{
    return _status;
}
void Wikis::setStatus(const int32_t &pStatus) noexcept
{
    _status = std::make_shared<int32_t>(pStatus);
    _dirtyFlag[3] = true;
}


const ::trantor::Date &Wikis::getValueOfCreatedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_createdAt)
        return *_createdAt;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Wikis::getCreatedAt() const noexcept
{
    return _createdAt;
}
void Wikis::setCreatedAt(const ::trantor::Date &pCreatedAt) noexcept
{
    _createdAt = std::make_shared<::trantor::Date>(pCreatedAt);
    _dirtyFlag[4] = true;
}


const ::trantor::Date &Wikis::getValueOfUpdatedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_updatedAt)
        return *_updatedAt;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Wikis::getUpdatedAt() const noexcept
{
    return _updatedAt;
}
void Wikis::setUpdatedAt(const ::trantor::Date &pUpdatedAt) noexcept
{
    _updatedAt = std::make_shared<::trantor::Date>(pUpdatedAt);
    _dirtyFlag[5] = true;
}


void Wikis::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Wikis::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "project_id",
        "start_page",
        "status",
        "created_at",
        "updated_at"
    };
    return _inCols;
}

void Wikis::outputArgs(drogon::orm::internal::SqlBinder &binder) const
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
        if(getStartPage())
        {
            binder << getValueOfStartPage();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[3])
    {
        if(getStatus())
        {
            binder << getValueOfStatus();
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

const std::vector<std::string> Wikis::updateColumns() const
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

void Wikis::updateArgs(drogon::orm::internal::SqlBinder &binder) const
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
        if(getStartPage())
        {
            binder << getValueOfStartPage();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[3])
    {
        if(getStatus())
        {
            binder << getValueOfStatus();
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
Json::Value Wikis::toJson() const
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
    if(getStartPage())
    {
        ret["start_page"]=getValueOfStartPage();
    }
    else
    {
        ret["start_page"]=Json::Value();
    }
    if(getStatus())
    {
        ret["status"]=getValueOfStatus();
    }
    else
    {
        ret["status"]=Json::Value();
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

Json::Value Wikis::toMasqueradedJson(
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
            if(getStartPage())
            {
                ret[pMasqueradingVector[2]]=getValueOfStartPage();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getStatus())
            {
                ret[pMasqueradingVector[3]]=getValueOfStatus();
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
    if(getProjectId())
    {
        ret["project_id"]=getValueOfProjectId();
    }
    else
    {
        ret["project_id"]=Json::Value();
    }
    if(getStartPage())
    {
        ret["start_page"]=getValueOfStartPage();
    }
    else
    {
        ret["start_page"]=Json::Value();
    }
    if(getStatus())
    {
        ret["status"]=getValueOfStatus();
    }
    else
    {
        ret["status"]=Json::Value();
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

bool Wikis::validateJsonForCreation(const Json::Value &pJson, std::string &err)
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
    else
    {
        err="The project_id column cannot be null";
        return false;
    }
    if(pJson.isMember("start_page"))
    {
        if(!validJsonOfField(2, "start_page", pJson["start_page"], err, true))
            return false;
    }
    else
    {
        err="The start_page column cannot be null";
        return false;
    }
    if(pJson.isMember("status"))
    {
        if(!validJsonOfField(3, "status", pJson["status"], err, true))
            return false;
    }
    if(pJson.isMember("created_at"))
    {
        if(!validJsonOfField(4, "created_at", pJson["created_at"], err, true))
            return false;
    }
    else
    {
        err="The created_at column cannot be null";
        return false;
    }
    if(pJson.isMember("updated_at"))
    {
        if(!validJsonOfField(5, "updated_at", pJson["updated_at"], err, true))
            return false;
    }
    else
    {
        err="The updated_at column cannot be null";
        return false;
    }
    return true;
}
bool Wikis::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                               const std::vector<std::string> &pMasqueradingVector,
                                               std::string &err)
{
    if(pMasqueradingVector.size() != 6)
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
    if(!pMasqueradingVector[4].empty())
    {
        if(pJson.isMember(pMasqueradingVector[4]))
        {
            if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                return false;
        }
        else
        {
            err="The " + pMasqueradingVector[4] + " column cannot be null";
            return false;
        }
    }
    if(!pMasqueradingVector[5].empty())
    {
        if(pJson.isMember(pMasqueradingVector[5]))
        {
            if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                return false;
        }
        else
        {
            err="The " + pMasqueradingVector[5] + " column cannot be null";
            return false;
        }
    }
    return true;
}
bool Wikis::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
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
    if(pJson.isMember("start_page"))
    {
        if(!validJsonOfField(2, "start_page", pJson["start_page"], err, false))
            return false;
    }
    if(pJson.isMember("status"))
    {
        if(!validJsonOfField(3, "status", pJson["status"], err, false))
            return false;
    }
    if(pJson.isMember("created_at"))
    {
        if(!validJsonOfField(4, "created_at", pJson["created_at"], err, false))
            return false;
    }
    if(pJson.isMember("updated_at"))
    {
        if(!validJsonOfField(5, "updated_at", pJson["updated_at"], err, false))
            return false;
    }
    return true;
}
bool Wikis::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                             const std::vector<std::string> &pMasqueradingVector,
                                             std::string &err)
{
    if(pMasqueradingVector.size() != 6)
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
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
            return false;
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
            return false;
    }
    return true;
}
bool Wikis::validJsonOfField(size_t index,
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
            if(!pJson.isString() && !pJson.isNull())
            {
                err="Type error in the "+fieldName+"field";
                return false;                
            }
            break;
        case 3:
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
        case 4:
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
        case 5:
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