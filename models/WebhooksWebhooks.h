/**
 *
 *  WebhooksWebhooks.h
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
class WebhooksWebhooks
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _name;
        static const std::string _url;
        static const std::string _description;
        static const std::string _secret;
        static const std::string _enabled;
        static const std::string _all_projects;
        static const std::string _created_at;
        static const std::string _updated_at;
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
    explicit WebhooksWebhooks(const Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit WebhooksWebhooks(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
     WebhooksWebhooks(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    WebhooksWebhooks() = default;
    
    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson, 
                                                                          const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int32_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getId() const noexcept;

    /**  For column name  */
    ///Get the value of the column name, returns the default value if the column is null
    const std::string &getValueOfName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getName() const noexcept;
    ///Set the value of the column name
    void setName(const std::string &pName) noexcept;
    void setName(std::string &&pName) noexcept;

    /**  For column url  */
    ///Get the value of the column url, returns the default value if the column is null
    const std::string &getValueOfUrl() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getUrl() const noexcept;
    ///Set the value of the column url
    void setUrl(const std::string &pUrl) noexcept;
    void setUrl(std::string &&pUrl) noexcept;

    /**  For column description  */
    ///Get the value of the column description, returns the default value if the column is null
    const std::string &getValueOfDescription() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getDescription() const noexcept;
    ///Set the value of the column description
    void setDescription(const std::string &pDescription) noexcept;
    void setDescription(std::string &&pDescription) noexcept;

    /**  For column secret  */
    ///Get the value of the column secret, returns the default value if the column is null
    const std::string &getValueOfSecret() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getSecret() const noexcept;
    ///Set the value of the column secret
    void setSecret(const std::string &pSecret) noexcept;
    void setSecret(std::string &&pSecret) noexcept;

    /**  For column enabled  */
    ///Get the value of the column enabled, returns the default value if the column is null
    const bool &getValueOfEnabled() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<bool> &getEnabled() const noexcept;
    ///Set the value of the column enabled
    void setEnabled(const bool &pEnabled) noexcept;

    /**  For column all_projects  */
    ///Get the value of the column all_projects, returns the default value if the column is null
    const bool &getValueOfAllProjects() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<bool> &getAllProjects() const noexcept;
    ///Set the value of the column all_projects
    void setAllProjects(const bool &pAllProjects) noexcept;

    /**  For column created_at  */
    ///Get the value of the column created_at, returns the default value if the column is null
    const ::trantor::Date &getValueOfCreatedAt() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getCreatedAt() const noexcept;
    ///Set the value of the column created_at
    void setCreatedAt(const ::trantor::Date &pCreatedAt) noexcept;

    /**  For column updated_at  */
    ///Get the value of the column updated_at, returns the default value if the column is null
    const ::trantor::Date &getValueOfUpdatedAt() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getUpdatedAt() const noexcept;
    ///Set the value of the column updated_at
    void setUpdatedAt(const ::trantor::Date &pUpdatedAt) noexcept;


    static size_t getColumnNumber() noexcept {  return 9;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;

  private:
    friend Mapper<WebhooksWebhooks>;
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> _id;
    std::shared_ptr<std::string> _name;
    std::shared_ptr<std::string> _url;
    std::shared_ptr<std::string> _description;
    std::shared_ptr<std::string> _secret;
    std::shared_ptr<bool> _enabled;
    std::shared_ptr<bool> _allProjects;
    std::shared_ptr<::trantor::Date> _createdAt;
    std::shared_ptr<::trantor::Date> _updatedAt;
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
};
} // namespace openproject4
} // namespace drogon_model
