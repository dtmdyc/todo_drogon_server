/**
 *
 *  MemberRoles.h
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
namespace openproject4 
{
class MemberRoles
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _member_id;
        static const std::string _role_id;
        static const std::string _inherited_from;
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
    explicit MemberRoles(const Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit MemberRoles(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
     MemberRoles(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    MemberRoles() = default;
    
    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson, 
                                                                          const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int32_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getId() const noexcept;

    /**  For column member_id  */
    ///Get the value of the column member_id, returns the default value if the column is null
    const int32_t &getValueOfMemberId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getMemberId() const noexcept;
    ///Set the value of the column member_id
    void setMemberId(const int32_t &pMemberId) noexcept;

    /**  For column role_id  */
    ///Get the value of the column role_id, returns the default value if the column is null
    const int32_t &getValueOfRoleId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getRoleId() const noexcept;
    ///Set the value of the column role_id
    void setRoleId(const int32_t &pRoleId) noexcept;

    /**  For column inherited_from  */
    ///Get the value of the column inherited_from, returns the default value if the column is null
    const int32_t &getValueOfInheritedFrom() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getInheritedFrom() const noexcept;
    ///Set the value of the column inherited_from
    void setInheritedFrom(const int32_t &pInheritedFrom) noexcept;


    static size_t getColumnNumber() noexcept {  return 4;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;

  private:
    friend Mapper<MemberRoles>;
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> _id;
    std::shared_ptr<int32_t> _memberId;
    std::shared_ptr<int32_t> _roleId;
    std::shared_ptr<int32_t> _inheritedFrom;
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
    bool _dirtyFlag[4]={ false };
};
} // namespace openproject4
} // namespace drogon_model
