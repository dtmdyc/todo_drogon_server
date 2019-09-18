/**
 *
 *  Versions.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Versions.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::openproject4;

const std::string Versions::Cols::_id = "id";
const std::string Versions::Cols::_project_id = "project_id";
const std::string Versions::Cols::_name = "name";
const std::string Versions::Cols::_description = "description";
const std::string Versions::Cols::_effective_date = "effective_date";
const std::string Versions::Cols::_created_on = "created_on";
const std::string Versions::Cols::_updated_on = "updated_on";
const std::string Versions::Cols::_wiki_page_title = "wiki_page_title";
const std::string Versions::Cols::_status = "status";
const std::string Versions::Cols::_sharing = "sharing";
const std::string Versions::Cols::_start_date = "start_date";
const std::string Versions::primaryKeyName = "id";
const bool Versions::hasPrimaryKey = true;
const std::string Versions::tableName = "versions";

const std::vector<typename Versions::MetaData> Versions::_metaData={
{"id","int32_t","integer",4,1,1,1},
{"project_id","int32_t","integer",4,0,0,1},
{"name","std::string","character varying",0,0,0,1},
{"description","std::string","character varying",0,0,0,0},
{"effective_date","::trantor::Date","date",0,0,0,0},
{"created_on","::trantor::Date","timestamp without time zone",0,0,0,0},
{"updated_on","::trantor::Date","timestamp without time zone",0,0,0,0},
{"wiki_page_title","std::string","character varying",0,0,0,0},
{"status","std::string","character varying",0,0,0,0},
{"sharing","std::string","character varying",0,0,0,1},
{"start_date","::trantor::Date","date",0,0,0,0}
};
const std::string &Versions::getColumnName(size_t index) noexcept(false)
{
    assert(index < _metaData.size());
    return _metaData[index]._colName;
}
Versions::Versions(const Row &r, const ssize_t indexOffset) noexcept
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
        if(!r["description"].isNull())
        {
            _description=std::make_shared<std::string>(r["description"].as<std::string>());
        }
        if(!r["effective_date"].isNull())
        {
            auto daysStr = r["effective_date"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            long t = timelocal(&stm);
            _effectiveDate=std::make_shared<::trantor::Date>(t*1000000);
        }
        if(!r["created_on"].isNull())
        {
            auto timeStr = r["created_on"].as<std::string>();
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
            _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
        if(!r["updated_on"].isNull())
        {
            auto timeStr = r["updated_on"].as<std::string>();
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
            _updatedOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
        if(!r["wiki_page_title"].isNull())
        {
            _wikiPageTitle=std::make_shared<std::string>(r["wiki_page_title"].as<std::string>());
        }
        if(!r["status"].isNull())
        {
            _status=std::make_shared<std::string>(r["status"].as<std::string>());
        }
        if(!r["sharing"].isNull())
        {
            _sharing=std::make_shared<std::string>(r["sharing"].as<std::string>());
        }
        if(!r["start_date"].isNull())
        {
            auto daysStr = r["start_date"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            long t = timelocal(&stm);
            _startDate=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 11 > r.size())
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
        index = offset + 3;
        if(!r[index].isNull())
        {
            _description=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            auto daysStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            long t = timelocal(&stm);
            _effectiveDate=std::make_shared<::trantor::Date>(t*1000000);
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
            _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
        index = offset + 6;
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
            _updatedOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
        }
        index = offset + 7;
        if(!r[index].isNull())
        {
            _wikiPageTitle=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 8;
        if(!r[index].isNull())
        {
            _status=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 9;
        if(!r[index].isNull())
        {
            _sharing=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 10;
        if(!r[index].isNull())
        {
            auto daysStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            long t = timelocal(&stm);
            _startDate=std::make_shared<::trantor::Date>(t*1000000);
        }
    }

}

Versions::Versions(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 11)
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
        _projectId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _name=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _description=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        auto daysStr = pJson[pMasqueradingVector[4]].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
        long t = timelocal(&stm);
        _effectiveDate=std::make_shared<::trantor::Date>(t*1000000);
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
        _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        auto timeStr = pJson[pMasqueradingVector[6]].asString();
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
        _updatedOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        _wikiPageTitle=std::make_shared<std::string>(pJson[pMasqueradingVector[7]].asString());
    }
    if(!pMasqueradingVector[8].empty() && pJson.isMember(pMasqueradingVector[8]))
    {
        _status=std::make_shared<std::string>(pJson[pMasqueradingVector[8]].asString());
    }
    if(!pMasqueradingVector[9].empty() && pJson.isMember(pMasqueradingVector[9]))
    {
        _sharing=std::make_shared<std::string>(pJson[pMasqueradingVector[9]].asString());
    }
    if(!pMasqueradingVector[10].empty() && pJson.isMember(pMasqueradingVector[10]))
    {
        auto daysStr = pJson[pMasqueradingVector[10]].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
        long t = timelocal(&stm);
        _startDate=std::make_shared<::trantor::Date>(t*1000000);
    }
}

Versions::Versions(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("project_id"))
    {
        _projectId=std::make_shared<int32_t>((int32_t)pJson["project_id"].asInt64());
    }
    if(pJson.isMember("name"))
    {
        _name=std::make_shared<std::string>(pJson["name"].asString());
    }
    if(pJson.isMember("description"))
    {
        _description=std::make_shared<std::string>(pJson["description"].asString());
    }
    if(pJson.isMember("effective_date"))
    {
        auto daysStr = pJson["effective_date"].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
        long t = timelocal(&stm);
        _effectiveDate=std::make_shared<::trantor::Date>(t*1000000);
    }
    if(pJson.isMember("created_on"))
    {
        auto timeStr = pJson["created_on"].asString();
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
        _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(pJson.isMember("updated_on"))
    {
        auto timeStr = pJson["updated_on"].asString();
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
        _updatedOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(pJson.isMember("wiki_page_title"))
    {
        _wikiPageTitle=std::make_shared<std::string>(pJson["wiki_page_title"].asString());
    }
    if(pJson.isMember("status"))
    {
        _status=std::make_shared<std::string>(pJson["status"].asString());
    }
    if(pJson.isMember("sharing"))
    {
        _sharing=std::make_shared<std::string>(pJson["sharing"].asString());
    }
    if(pJson.isMember("start_date"))
    {
        auto daysStr = pJson["start_date"].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
        long t = timelocal(&stm);
        _startDate=std::make_shared<::trantor::Date>(t*1000000);
    }
}

void Versions::updateByMasqueradedJson(const Json::Value &pJson, 
                                                                                                     const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 11)
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
        _projectId=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[1]].asInt64());
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        _dirtyFlag[2] = true;
        _name=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        _dirtyFlag[3] = true;
        _description=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        _dirtyFlag[4] = true;
        auto daysStr = pJson[pMasqueradingVector[4]].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
        long t = timelocal(&stm);
        _effectiveDate=std::make_shared<::trantor::Date>(t*1000000);
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
        _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(!pMasqueradingVector[6].empty() && pJson.isMember(pMasqueradingVector[6]))
    {
        _dirtyFlag[6] = true;
        auto timeStr = pJson[pMasqueradingVector[6]].asString();
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
        _updatedOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(!pMasqueradingVector[7].empty() && pJson.isMember(pMasqueradingVector[7]))
    {
        _dirtyFlag[7] = true;
        _wikiPageTitle=std::make_shared<std::string>(pJson[pMasqueradingVector[7]].asString());
    }
    if(!pMasqueradingVector[8].empty() && pJson.isMember(pMasqueradingVector[8]))
    {
        _dirtyFlag[8] = true;
        _status=std::make_shared<std::string>(pJson[pMasqueradingVector[8]].asString());
    }
    if(!pMasqueradingVector[9].empty() && pJson.isMember(pMasqueradingVector[9]))
    {
        _dirtyFlag[9] = true;
        _sharing=std::make_shared<std::string>(pJson[pMasqueradingVector[9]].asString());
    }
    if(!pMasqueradingVector[10].empty() && pJson.isMember(pMasqueradingVector[10]))
    {
        _dirtyFlag[10] = true;
        auto daysStr = pJson[pMasqueradingVector[10]].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
        long t = timelocal(&stm);
        _startDate=std::make_shared<::trantor::Date>(t*1000000);
    }
}
                                                                    
void Versions::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        _id=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
    }
    if(pJson.isMember("project_id"))
    {
        _dirtyFlag[1] = true;
        _projectId=std::make_shared<int32_t>((int32_t)pJson["project_id"].asInt64());
    }
    if(pJson.isMember("name"))
    {
        _dirtyFlag[2] = true;
        _name=std::make_shared<std::string>(pJson["name"].asString());
    }
    if(pJson.isMember("description"))
    {
        _dirtyFlag[3] = true;
        _description=std::make_shared<std::string>(pJson["description"].asString());
    }
    if(pJson.isMember("effective_date"))
    {
        _dirtyFlag[4] = true;
        auto daysStr = pJson["effective_date"].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
        long t = timelocal(&stm);
        _effectiveDate=std::make_shared<::trantor::Date>(t*1000000);
    }
    if(pJson.isMember("created_on"))
    {
        _dirtyFlag[5] = true;
        auto timeStr = pJson["created_on"].asString();
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
        _createdOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(pJson.isMember("updated_on"))
    {
        _dirtyFlag[6] = true;
        auto timeStr = pJson["updated_on"].asString();
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
        _updatedOn=std::make_shared<::trantor::Date>(t*1000000+decimalNum);
    }
    if(pJson.isMember("wiki_page_title"))
    {
        _dirtyFlag[7] = true;
        _wikiPageTitle=std::make_shared<std::string>(pJson["wiki_page_title"].asString());
    }
    if(pJson.isMember("status"))
    {
        _dirtyFlag[8] = true;
        _status=std::make_shared<std::string>(pJson["status"].asString());
    }
    if(pJson.isMember("sharing"))
    {
        _dirtyFlag[9] = true;
        _sharing=std::make_shared<std::string>(pJson["sharing"].asString());
    }
    if(pJson.isMember("start_date"))
    {
        _dirtyFlag[10] = true;
        auto daysStr = pJson["start_date"].asString();
        struct tm stm;
        memset(&stm,0,sizeof(stm));
        strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
        long t = timelocal(&stm);
        _startDate=std::make_shared<::trantor::Date>(t*1000000);
    }
}

const int32_t &Versions::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_id)
        return *_id;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Versions::getId() const noexcept
{
    return _id;
}
const typename Versions::PrimaryKeyType & Versions::getPrimaryKey() const
{
    assert(_id);
    return *_id;
}

const int32_t &Versions::getValueOfProjectId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(_projectId)
        return *_projectId;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Versions::getProjectId() const noexcept
{
    return _projectId;
}
void Versions::setProjectId(const int32_t &pProjectId) noexcept
{
    _projectId = std::make_shared<int32_t>(pProjectId);
    _dirtyFlag[1] = true;
}


const std::string &Versions::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_name)
        return *_name;
    return defaultValue;
}
const std::shared_ptr<std::string> &Versions::getName() const noexcept
{
    return _name;
}
void Versions::setName(const std::string &pName) noexcept
{
    _name = std::make_shared<std::string>(pName);
    _dirtyFlag[2] = true;
}
void Versions::setName(std::string &&pName) noexcept
{
    _name = std::make_shared<std::string>(std::move(pName));
    _dirtyFlag[2] = true;
}


const std::string &Versions::getValueOfDescription() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_description)
        return *_description;
    return defaultValue;
}
const std::shared_ptr<std::string> &Versions::getDescription() const noexcept
{
    return _description;
}
void Versions::setDescription(const std::string &pDescription) noexcept
{
    _description = std::make_shared<std::string>(pDescription);
    _dirtyFlag[3] = true;
}
void Versions::setDescription(std::string &&pDescription) noexcept
{
    _description = std::make_shared<std::string>(std::move(pDescription));
    _dirtyFlag[3] = true;
}


const ::trantor::Date &Versions::getValueOfEffectiveDate() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_effectiveDate)
        return *_effectiveDate;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Versions::getEffectiveDate() const noexcept
{
    return _effectiveDate;
}
void Versions::setEffectiveDate(const ::trantor::Date &pEffectiveDate) noexcept
{
    _effectiveDate = std::make_shared<::trantor::Date>(pEffectiveDate.roundDay());
    _dirtyFlag[4] = true;
}


const ::trantor::Date &Versions::getValueOfCreatedOn() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_createdOn)
        return *_createdOn;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Versions::getCreatedOn() const noexcept
{
    return _createdOn;
}
void Versions::setCreatedOn(const ::trantor::Date &pCreatedOn) noexcept
{
    _createdOn = std::make_shared<::trantor::Date>(pCreatedOn);
    _dirtyFlag[5] = true;
}


const ::trantor::Date &Versions::getValueOfUpdatedOn() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_updatedOn)
        return *_updatedOn;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Versions::getUpdatedOn() const noexcept
{
    return _updatedOn;
}
void Versions::setUpdatedOn(const ::trantor::Date &pUpdatedOn) noexcept
{
    _updatedOn = std::make_shared<::trantor::Date>(pUpdatedOn);
    _dirtyFlag[6] = true;
}


const std::string &Versions::getValueOfWikiPageTitle() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_wikiPageTitle)
        return *_wikiPageTitle;
    return defaultValue;
}
const std::shared_ptr<std::string> &Versions::getWikiPageTitle() const noexcept
{
    return _wikiPageTitle;
}
void Versions::setWikiPageTitle(const std::string &pWikiPageTitle) noexcept
{
    _wikiPageTitle = std::make_shared<std::string>(pWikiPageTitle);
    _dirtyFlag[7] = true;
}
void Versions::setWikiPageTitle(std::string &&pWikiPageTitle) noexcept
{
    _wikiPageTitle = std::make_shared<std::string>(std::move(pWikiPageTitle));
    _dirtyFlag[7] = true;
}


const std::string &Versions::getValueOfStatus() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_status)
        return *_status;
    return defaultValue;
}
const std::shared_ptr<std::string> &Versions::getStatus() const noexcept
{
    return _status;
}
void Versions::setStatus(const std::string &pStatus) noexcept
{
    _status = std::make_shared<std::string>(pStatus);
    _dirtyFlag[8] = true;
}
void Versions::setStatus(std::string &&pStatus) noexcept
{
    _status = std::make_shared<std::string>(std::move(pStatus));
    _dirtyFlag[8] = true;
}


const std::string &Versions::getValueOfSharing() const noexcept
{
    const static std::string defaultValue = std::string();
    if(_sharing)
        return *_sharing;
    return defaultValue;
}
const std::shared_ptr<std::string> &Versions::getSharing() const noexcept
{
    return _sharing;
}
void Versions::setSharing(const std::string &pSharing) noexcept
{
    _sharing = std::make_shared<std::string>(pSharing);
    _dirtyFlag[9] = true;
}
void Versions::setSharing(std::string &&pSharing) noexcept
{
    _sharing = std::make_shared<std::string>(std::move(pSharing));
    _dirtyFlag[9] = true;
}


const ::trantor::Date &Versions::getValueOfStartDate() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(_startDate)
        return *_startDate;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Versions::getStartDate() const noexcept
{
    return _startDate;
}
void Versions::setStartDate(const ::trantor::Date &pStartDate) noexcept
{
    _startDate = std::make_shared<::trantor::Date>(pStartDate.roundDay());
    _dirtyFlag[10] = true;
}


void Versions::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Versions::insertColumns() noexcept
{
    static const std::vector<std::string> _inCols={
        "project_id",
        "name",
        "description",
        "effective_date",
        "created_on",
        "updated_on",
        "wiki_page_title",
        "status",
        "sharing",
        "start_date"
    };
    return _inCols;
}

void Versions::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(getProjectId())
    {
        binder << getValueOfProjectId();
    }
    else
    {
        binder << nullptr;
    }
    if(getName())
    {
        binder << getValueOfName();
    }
    else
    {
        binder << nullptr;
    }
    if(getDescription())
    {
        binder << getValueOfDescription();
    }
    else
    {
        binder << nullptr;
    }
    if(getEffectiveDate())
    {
        binder << getValueOfEffectiveDate();
    }
    else
    {
        binder << nullptr;
    }
    if(getCreatedOn())
    {
        binder << getValueOfCreatedOn();
    }
    else
    {
        binder << nullptr;
    }
    if(getUpdatedOn())
    {
        binder << getValueOfUpdatedOn();
    }
    else
    {
        binder << nullptr;
    }
    if(getWikiPageTitle())
    {
        binder << getValueOfWikiPageTitle();
    }
    else
    {
        binder << nullptr;
    }
    if(getStatus())
    {
        binder << getValueOfStatus();
    }
    else
    {
        binder << nullptr;
    }
    if(getSharing())
    {
        binder << getValueOfSharing();
    }
    else
    {
        binder << nullptr;
    }
    if(getStartDate())
    {
        binder << getValueOfStartDate();
    }
    else
    {
        binder << nullptr;
    }
}

const std::vector<std::string> Versions::updateColumns() const
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

void Versions::updateArgs(drogon::orm::internal::SqlBinder &binder) const
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
    if(_dirtyFlag[3])
    {
        if(getDescription())
        {
            binder << getValueOfDescription();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[4])
    {
        if(getEffectiveDate())
        {
            binder << getValueOfEffectiveDate();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[5])
    {
        if(getCreatedOn())
        {
            binder << getValueOfCreatedOn();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[6])
    {
        if(getUpdatedOn())
        {
            binder << getValueOfUpdatedOn();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[7])
    {
        if(getWikiPageTitle())
        {
            binder << getValueOfWikiPageTitle();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[8])
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
    if(_dirtyFlag[9])
    {
        if(getSharing())
        {
            binder << getValueOfSharing();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(_dirtyFlag[10])
    {
        if(getStartDate())
        {
            binder << getValueOfStartDate();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Versions::toJson() const
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
    if(getDescription())
    {
        ret["description"]=getValueOfDescription();
    }
    else
    {
        ret["description"]=Json::Value();
    }
    if(getEffectiveDate())
    {
        ret["effective_date"]=getEffectiveDate()->toDbStringLocal();
    }
    else
    {
        ret["effective_date"]=Json::Value();
    }
    if(getCreatedOn())
    {
        ret["created_on"]=getCreatedOn()->toDbStringLocal();
    }
    else
    {
        ret["created_on"]=Json::Value();
    }
    if(getUpdatedOn())
    {
        ret["updated_on"]=getUpdatedOn()->toDbStringLocal();
    }
    else
    {
        ret["updated_on"]=Json::Value();
    }
    if(getWikiPageTitle())
    {
        ret["wiki_page_title"]=getValueOfWikiPageTitle();
    }
    else
    {
        ret["wiki_page_title"]=Json::Value();
    }
    if(getStatus())
    {
        ret["status"]=getValueOfStatus();
    }
    else
    {
        ret["status"]=Json::Value();
    }
    if(getSharing())
    {
        ret["sharing"]=getValueOfSharing();
    }
    else
    {
        ret["sharing"]=Json::Value();
    }
    if(getStartDate())
    {
        ret["start_date"]=getStartDate()->toDbStringLocal();
    }
    else
    {
        ret["start_date"]=Json::Value();
    }
    return ret;
}

Json::Value Versions::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 11)
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
        if(!pMasqueradingVector[3].empty())
        {
            if(getDescription())
            {
                ret[pMasqueradingVector[3]]=getValueOfDescription();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getEffectiveDate())
            {
                ret[pMasqueradingVector[4]]=getEffectiveDate()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getCreatedOn())
            {
                ret[pMasqueradingVector[5]]=getCreatedOn()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[6].empty())
        {
            if(getUpdatedOn())
            {
                ret[pMasqueradingVector[6]]=getUpdatedOn()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[6]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[7].empty())
        {
            if(getWikiPageTitle())
            {
                ret[pMasqueradingVector[7]]=getValueOfWikiPageTitle();
            }
            else
            {
                ret[pMasqueradingVector[7]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[8].empty())
        {
            if(getStatus())
            {
                ret[pMasqueradingVector[8]]=getValueOfStatus();
            }
            else
            {
                ret[pMasqueradingVector[8]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[9].empty())
        {
            if(getSharing())
            {
                ret[pMasqueradingVector[9]]=getValueOfSharing();
            }
            else
            {
                ret[pMasqueradingVector[9]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[10].empty())
        {
            if(getStartDate())
            {
                ret[pMasqueradingVector[10]]=getStartDate()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[10]]=Json::Value();
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
    if(getDescription())
    {
        ret["description"]=getValueOfDescription();
    }
    else
    {
        ret["description"]=Json::Value();
    }
    if(getEffectiveDate())
    {
        ret["effective_date"]=getEffectiveDate()->toDbStringLocal();
    }
    else
    {
        ret["effective_date"]=Json::Value();
    }
    if(getCreatedOn())
    {
        ret["created_on"]=getCreatedOn()->toDbStringLocal();
    }
    else
    {
        ret["created_on"]=Json::Value();
    }
    if(getUpdatedOn())
    {
        ret["updated_on"]=getUpdatedOn()->toDbStringLocal();
    }
    else
    {
        ret["updated_on"]=Json::Value();
    }
    if(getWikiPageTitle())
    {
        ret["wiki_page_title"]=getValueOfWikiPageTitle();
    }
    else
    {
        ret["wiki_page_title"]=Json::Value();
    }
    if(getStatus())
    {
        ret["status"]=getValueOfStatus();
    }
    else
    {
        ret["status"]=Json::Value();
    }
    if(getSharing())
    {
        ret["sharing"]=getValueOfSharing();
    }
    else
    {
        ret["sharing"]=Json::Value();
    }
    if(getStartDate())
    {
        ret["start_date"]=getStartDate()->toDbStringLocal();
    }
    else
    {
        ret["start_date"]=Json::Value();
    }
    return ret;
}
