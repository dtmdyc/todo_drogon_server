/**
 *
 *  Attachments.h
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
class Attachments
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _container_id;
        static const std::string _container_type;
        static const std::string _filename;
        static const std::string _disk_filename;
        static const std::string _filesize;
        static const std::string _content_type;
        static const std::string _digest;
        static const std::string _downloads;
        static const std::string _author_id;
        static const std::string _created_at;
        static const std::string _description;
        static const std::string _file;
        static const std::string _fulltext;
        static const std::string _fulltext_tsv;
        static const std::string _file_tsv;
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
    explicit Attachments(const Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Attachments(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
     Attachments(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Attachments() = default;
    
    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson, 
                                                                          const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int32_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getId() const noexcept;

    /**  For column container_id  */
    ///Get the value of the column container_id, returns the default value if the column is null
    const int32_t &getValueOfContainerId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getContainerId() const noexcept;
    ///Set the value of the column container_id
    void setContainerId(const int32_t &pContainerId) noexcept;

    /**  For column container_type  */
    ///Get the value of the column container_type, returns the default value if the column is null
    const std::string &getValueOfContainerType() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getContainerType() const noexcept;
    ///Set the value of the column container_type
    void setContainerType(const std::string &pContainerType) noexcept;
    void setContainerType(std::string &&pContainerType) noexcept;

    /**  For column filename  */
    ///Get the value of the column filename, returns the default value if the column is null
    const std::string &getValueOfFilename() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFilename() const noexcept;
    ///Set the value of the column filename
    void setFilename(const std::string &pFilename) noexcept;
    void setFilename(std::string &&pFilename) noexcept;

    /**  For column disk_filename  */
    ///Get the value of the column disk_filename, returns the default value if the column is null
    const std::string &getValueOfDiskFilename() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getDiskFilename() const noexcept;
    ///Set the value of the column disk_filename
    void setDiskFilename(const std::string &pDiskFilename) noexcept;
    void setDiskFilename(std::string &&pDiskFilename) noexcept;

    /**  For column filesize  */
    ///Get the value of the column filesize, returns the default value if the column is null
    const int32_t &getValueOfFilesize() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getFilesize() const noexcept;
    ///Set the value of the column filesize
    void setFilesize(const int32_t &pFilesize) noexcept;

    /**  For column content_type  */
    ///Get the value of the column content_type, returns the default value if the column is null
    const std::string &getValueOfContentType() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getContentType() const noexcept;
    ///Set the value of the column content_type
    void setContentType(const std::string &pContentType) noexcept;
    void setContentType(std::string &&pContentType) noexcept;

    /**  For column digest  */
    ///Get the value of the column digest, returns the default value if the column is null
    const std::string &getValueOfDigest() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getDigest() const noexcept;
    ///Set the value of the column digest
    void setDigest(const std::string &pDigest) noexcept;
    void setDigest(std::string &&pDigest) noexcept;

    /**  For column downloads  */
    ///Get the value of the column downloads, returns the default value if the column is null
    const int32_t &getValueOfDownloads() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getDownloads() const noexcept;
    ///Set the value of the column downloads
    void setDownloads(const int32_t &pDownloads) noexcept;

    /**  For column author_id  */
    ///Get the value of the column author_id, returns the default value if the column is null
    const int32_t &getValueOfAuthorId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getAuthorId() const noexcept;
    ///Set the value of the column author_id
    void setAuthorId(const int32_t &pAuthorId) noexcept;

    /**  For column created_at  */
    ///Get the value of the column created_at, returns the default value if the column is null
    const ::trantor::Date &getValueOfCreatedAt() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getCreatedAt() const noexcept;
    ///Set the value of the column created_at
    void setCreatedAt(const ::trantor::Date &pCreatedAt) noexcept;

    /**  For column description  */
    ///Get the value of the column description, returns the default value if the column is null
    const std::string &getValueOfDescription() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getDescription() const noexcept;
    ///Set the value of the column description
    void setDescription(const std::string &pDescription) noexcept;
    void setDescription(std::string &&pDescription) noexcept;

    /**  For column file  */
    ///Get the value of the column file, returns the default value if the column is null
    const std::string &getValueOfFile() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFile() const noexcept;
    ///Set the value of the column file
    void setFile(const std::string &pFile) noexcept;
    void setFile(std::string &&pFile) noexcept;

    /**  For column fulltext  */
    ///Get the value of the column fulltext, returns the default value if the column is null
    const std::string &getValueOfFulltext() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFulltext() const noexcept;
    ///Set the value of the column fulltext
    void setFulltext(const std::string &pFulltext) noexcept;
    void setFulltext(std::string &&pFulltext) noexcept;

    /**  For column fulltext_tsv  */
    ///Get the value of the column fulltext_tsv, returns the default value if the column is null
    const std::string &getValueOfFulltextTsv() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFulltextTsv() const noexcept;
    ///Set the value of the column fulltext_tsv
    void setFulltextTsv(const std::string &pFulltextTsv) noexcept;
    void setFulltextTsv(std::string &&pFulltextTsv) noexcept;

    /**  For column file_tsv  */
    ///Get the value of the column file_tsv, returns the default value if the column is null
    const std::string &getValueOfFileTsv() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFileTsv() const noexcept;
    ///Set the value of the column file_tsv
    void setFileTsv(const std::string &pFileTsv) noexcept;
    void setFileTsv(std::string &&pFileTsv) noexcept;

    /**  For column updated_at  */
    ///Get the value of the column updated_at, returns the default value if the column is null
    const ::trantor::Date &getValueOfUpdatedAt() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<::trantor::Date> &getUpdatedAt() const noexcept;
    ///Set the value of the column updated_at
    void setUpdatedAt(const ::trantor::Date &pUpdatedAt) noexcept;


    static size_t getColumnNumber() noexcept {  return 17;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;

  private:
    friend Mapper<Attachments>;
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> _id;
    std::shared_ptr<int32_t> _containerId;
    std::shared_ptr<std::string> _containerType;
    std::shared_ptr<std::string> _filename;
    std::shared_ptr<std::string> _diskFilename;
    std::shared_ptr<int32_t> _filesize;
    std::shared_ptr<std::string> _contentType;
    std::shared_ptr<std::string> _digest;
    std::shared_ptr<int32_t> _downloads;
    std::shared_ptr<int32_t> _authorId;
    std::shared_ptr<::trantor::Date> _createdAt;
    std::shared_ptr<std::string> _description;
    std::shared_ptr<std::string> _file;
    std::shared_ptr<std::string> _fulltext;
    std::shared_ptr<std::string> _fulltextTsv;
    std::shared_ptr<std::string> _fileTsv;
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
    bool _dirtyFlag[17]={ false };
};
} // namespace openproject4
} // namespace drogon_model
