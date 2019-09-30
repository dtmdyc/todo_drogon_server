/**
 *
 *  Changesets.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

using namespace drogon::orm;

namespace drogon_model
{
namespace openproject6 
{
class Changesets
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _repository_id;
        static const std::string _revision;
        static const std::string _committer;
        static const std::string _committed_on;
        static const std::string _comments;
        static const std::string _commit_date;
        static const std::string _scmid;
        static const std::string _user_id;
    };

    const static int primaryKeyNumber;
    const static std::string tableName;
    const static bool hasPrimaryKey;
    const static std::string primaryKeyName;
    typedef int32_t PrimaryKeyType;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names, 
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all 
     * columns by an asterisk), please set the offset to -1.
     */
    explicit Changesets(const Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Changesets(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    Changesets(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Changesets() = default;
    
    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    bool validateMasqueradedJsonForCreation(const Json::Value &,
                                            const std::vector<std::string> &pMasqueradingVector,
                                            std::string &err);
    bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson, 
                          std::string &err, 
                          bool isForCreation);

    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int32_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getId() const noexcept;

    /**  For column repository_id  */
    ///Get the value of the column repository_id, returns the default value if the column is null
    const int32_t &getValueOfRepositoryId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getRepositoryId() const noexcept;
    ///Set the value of the column repository_id
    void setRepositoryId(const int32_t &pRepositoryId) noexcept;

    /**  For column revision  */
    ///Get the value of the column revision, returns the default value if the column is null
    const std::string &getValueOfRevision() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getRevision() const noexcept;
    ///Set the value of the column revision
    void setRevision(const std::string &pRevision) noexcept;
    void setRevision(std::string &&pRevision) noexcept;

    /**  For column committer  */
    ///Get the value of the column committer, returns the default value if the column is null
    const std::string &getValueOfCommitter() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getCommitter() const noexcept;
    ///Set the value of the column committer
    void setCommitter(const std::string &pCommitter) noexcept;
    void setCommitter(std::string &&pCommitter) noexcept;

    /**  For column committed_on  */
    ///Get the value of the column committed_on, returns the default value if the column is null
    const ::trantor::Date &getValueOfCommittedOn() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getCommittedOn() const noexcept;
    ///Set the value of the column committed_on
    void setCommittedOn(const ::trantor::Date &pCommittedOn) noexcept;

    /**  For column comments  */
    ///Get the value of the column comments, returns the default value if the column is null
    const std::string &getValueOfComments() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getComments() const noexcept;
    ///Set the value of the column comments
    void setComments(const std::string &pComments) noexcept;
    void setComments(std::string &&pComments) noexcept;

    /**  For column commit_date  */
    ///Get the value of the column commit_date, returns the default value if the column is null
    const ::trantor::Date &getValueOfCommitDate() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getCommitDate() const noexcept;
    ///Set the value of the column commit_date
    void setCommitDate(const ::trantor::Date &pCommitDate) noexcept;

    /**  For column scmid  */
    ///Get the value of the column scmid, returns the default value if the column is null
    const std::string &getValueOfScmid() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getScmid() const noexcept;
    ///Set the value of the column scmid
    void setScmid(const std::string &pScmid) noexcept;
    void setScmid(std::string &&pScmid) noexcept;

    /**  For column user_id  */
    ///Get the value of the column user_id, returns the default value if the column is null
    const int32_t &getValueOfUserId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getUserId() const noexcept;
    ///Set the value of the column user_id
    void setUserId(const int32_t &pUserId) noexcept;


    static size_t getColumnNumber() noexcept {  return 9;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;

  private:
    friend Mapper<Changesets>;
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> _id;
    std::shared_ptr<int32_t> _repositoryId;
    std::shared_ptr<std::string> _revision;
    std::shared_ptr<std::string> _committer;
    std::shared_ptr<::trantor::Date> _committedOn;
    std::shared_ptr<std::string> _comments;
    std::shared_ptr<::trantor::Date> _commitDate;
    std::shared_ptr<std::string> _scmid;
    std::shared_ptr<int32_t> _userId;
    struct MetaData
    {
        const std::string _colName;
        const std::string _colType;
        const std::string _colDatabaseType;
        const ssize_t _colLength;
        const bool _isAutoVal;
        const bool _isPrimaryKey;
        const bool _notNull;
    };
    static const std::vector<MetaData> _metaData;
    bool _dirtyFlag[9]={ false };

  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where id = $1";
        return sql;                   
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where id = $1";
        return sql;                   
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
            sql += "id,";
            ++parametersCount;
        if(_dirtyFlag[1])
        {
            sql += "repository_id,";
            ++parametersCount;
        }
        if(_dirtyFlag[2])
        {
            sql += "revision,";
            ++parametersCount;
        }
        if(_dirtyFlag[3])
        {
            sql += "committer,";
            ++parametersCount;
        }
        if(_dirtyFlag[4])
        {
            sql += "committed_on,";
            ++parametersCount;
        }
        if(_dirtyFlag[5])
        {
            sql += "comments,";
            ++parametersCount;
        }
        if(_dirtyFlag[6])
        {
            sql += "commit_date,";
            ++parametersCount;
        }
        if(_dirtyFlag[7])
        {
            sql += "scmid,";
            ++parametersCount;
        }
        if(_dirtyFlag[8])
        {
            sql += "user_id,";
            ++parametersCount;
        }
        needSelection=true;
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";
        
        int placeholder=1;
        char placeholderStr[64];
        size_t n=0;
        sql +="default,";
        if(_dirtyFlag[1])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(_dirtyFlag[2])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(_dirtyFlag[3])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(_dirtyFlag[4])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(_dirtyFlag[5])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(_dirtyFlag[6])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(_dirtyFlag[7])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(_dirtyFlag[8])
        {
            n = sprintf(placeholderStr,"$%d,",placeholder++);
            sql.append(placeholderStr, n);
        } 
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        if(needSelection)
        {
            sql.append(") returning *");
        }
        else
        {
            sql.append(1, ')');
        }
        LOG_TRACE << sql;
        return sql;   
    }
};
} // namespace openproject6
} // namespace drogon_model