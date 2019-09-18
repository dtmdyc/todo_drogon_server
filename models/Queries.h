/**
 *
 *  Queries.h
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
class Queries
{
  public:
    struct Cols
    {
        static const std::string _id;
        static const std::string _project_id;
        static const std::string _name;
        static const std::string _filters;
        static const std::string _user_id;
        static const std::string _is_public;
        static const std::string _column_names;
        static const std::string _sort_criteria;
        static const std::string _group_by;
        static const std::string _display_sums;
        static const std::string _timeline_visible;
        static const std::string _show_hierarchies;
        static const std::string _timeline_zoom_level;
        static const std::string _timeline_labels;
        static const std::string _highlighting_mode;
        static const std::string _highlighted_attributes;
        static const std::string _hidden;
        static const std::string _created_at;
        static const std::string _updated_at;
        static const std::string _display_representation;
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
    explicit Queries(const Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Queries(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
     Queries(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Queries() = default;
    
    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson, 
                                                                          const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    /**  For column id  */
    ///Get the value of the column id, returns the default value if the column is null
    const int32_t &getValueOfId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getId() const noexcept;

    /**  For column project_id  */
    ///Get the value of the column project_id, returns the default value if the column is null
    const int32_t &getValueOfProjectId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getProjectId() const noexcept;
    ///Set the value of the column project_id
    void setProjectId(const int32_t &pProjectId) noexcept;

    /**  For column name  */
    ///Get the value of the column name, returns the default value if the column is null
    const std::string &getValueOfName() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getName() const noexcept;
    ///Set the value of the column name
    void setName(const std::string &pName) noexcept;
    void setName(std::string &&pName) noexcept;

    /**  For column filters  */
    ///Get the value of the column filters, returns the default value if the column is null
    const std::string &getValueOfFilters() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getFilters() const noexcept;
    ///Set the value of the column filters
    void setFilters(const std::string &pFilters) noexcept;
    void setFilters(std::string &&pFilters) noexcept;

    /**  For column user_id  */
    ///Get the value of the column user_id, returns the default value if the column is null
    const int32_t &getValueOfUserId() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getUserId() const noexcept;
    ///Set the value of the column user_id
    void setUserId(const int32_t &pUserId) noexcept;

    /**  For column is_public  */
    ///Get the value of the column is_public, returns the default value if the column is null
    const bool &getValueOfIsPublic() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<bool> &getIsPublic() const noexcept;
    ///Set the value of the column is_public
    void setIsPublic(const bool &pIsPublic) noexcept;

    /**  For column column_names  */
    ///Get the value of the column column_names, returns the default value if the column is null
    const std::string &getValueOfColumnNames() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getColumnNames() const noexcept;
    ///Set the value of the column column_names
    void setColumnNames(const std::string &pColumnNames) noexcept;
    void setColumnNames(std::string &&pColumnNames) noexcept;

    /**  For column sort_criteria  */
    ///Get the value of the column sort_criteria, returns the default value if the column is null
    const std::string &getValueOfSortCriteria() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getSortCriteria() const noexcept;
    ///Set the value of the column sort_criteria
    void setSortCriteria(const std::string &pSortCriteria) noexcept;
    void setSortCriteria(std::string &&pSortCriteria) noexcept;

    /**  For column group_by  */
    ///Get the value of the column group_by, returns the default value if the column is null
    const std::string &getValueOfGroupBy() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getGroupBy() const noexcept;
    ///Set the value of the column group_by
    void setGroupBy(const std::string &pGroupBy) noexcept;
    void setGroupBy(std::string &&pGroupBy) noexcept;

    /**  For column display_sums  */
    ///Get the value of the column display_sums, returns the default value if the column is null
    const bool &getValueOfDisplaySums() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<bool> &getDisplaySums() const noexcept;
    ///Set the value of the column display_sums
    void setDisplaySums(const bool &pDisplaySums) noexcept;

    /**  For column timeline_visible  */
    ///Get the value of the column timeline_visible, returns the default value if the column is null
    const bool &getValueOfTimelineVisible() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<bool> &getTimelineVisible() const noexcept;
    ///Set the value of the column timeline_visible
    void setTimelineVisible(const bool &pTimelineVisible) noexcept;

    /**  For column show_hierarchies  */
    ///Get the value of the column show_hierarchies, returns the default value if the column is null
    const bool &getValueOfShowHierarchies() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<bool> &getShowHierarchies() const noexcept;
    ///Set the value of the column show_hierarchies
    void setShowHierarchies(const bool &pShowHierarchies) noexcept;

    /**  For column timeline_zoom_level  */
    ///Get the value of the column timeline_zoom_level, returns the default value if the column is null
    const int32_t &getValueOfTimelineZoomLevel() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getTimelineZoomLevel() const noexcept;
    ///Set the value of the column timeline_zoom_level
    void setTimelineZoomLevel(const int32_t &pTimelineZoomLevel) noexcept;

    /**  For column timeline_labels  */
    ///Get the value of the column timeline_labels, returns the default value if the column is null
    const std::string &getValueOfTimelineLabels() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getTimelineLabels() const noexcept;
    ///Set the value of the column timeline_labels
    void setTimelineLabels(const std::string &pTimelineLabels) noexcept;
    void setTimelineLabels(std::string &&pTimelineLabels) noexcept;

    /**  For column highlighting_mode  */
    ///Get the value of the column highlighting_mode, returns the default value if the column is null
    const std::string &getValueOfHighlightingMode() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getHighlightingMode() const noexcept;
    ///Set the value of the column highlighting_mode
    void setHighlightingMode(const std::string &pHighlightingMode) noexcept;
    void setHighlightingMode(std::string &&pHighlightingMode) noexcept;

    /**  For column highlighted_attributes  */
    ///Get the value of the column highlighted_attributes, returns the default value if the column is null
    const std::string &getValueOfHighlightedAttributes() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getHighlightedAttributes() const noexcept;
    ///Set the value of the column highlighted_attributes
    void setHighlightedAttributes(const std::string &pHighlightedAttributes) noexcept;
    void setHighlightedAttributes(std::string &&pHighlightedAttributes) noexcept;

    /**  For column hidden  */
    ///Get the value of the column hidden, returns the default value if the column is null
    const bool &getValueOfHidden() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<bool> &getHidden() const noexcept;
    ///Set the value of the column hidden
    void setHidden(const bool &pHidden) noexcept;

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

    /**  For column display_representation  */
    ///Get the value of the column display_representation, returns the default value if the column is null
    const std::string &getValueOfDisplayRepresentation() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getDisplayRepresentation() const noexcept;
    ///Set the value of the column display_representation
    void setDisplayRepresentation(const std::string &pDisplayRepresentation) noexcept;
    void setDisplayRepresentation(std::string &&pDisplayRepresentation) noexcept;


    static size_t getColumnNumber() noexcept {  return 20;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;

  private:
    friend Mapper<Queries>;
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<int32_t> _id;
    std::shared_ptr<int32_t> _projectId;
    std::shared_ptr<std::string> _name;
    std::shared_ptr<std::string> _filters;
    std::shared_ptr<int32_t> _userId;
    std::shared_ptr<bool> _isPublic;
    std::shared_ptr<std::string> _columnNames;
    std::shared_ptr<std::string> _sortCriteria;
    std::shared_ptr<std::string> _groupBy;
    std::shared_ptr<bool> _displaySums;
    std::shared_ptr<bool> _timelineVisible;
    std::shared_ptr<bool> _showHierarchies;
    std::shared_ptr<int32_t> _timelineZoomLevel;
    std::shared_ptr<std::string> _timelineLabels;
    std::shared_ptr<std::string> _highlightingMode;
    std::shared_ptr<std::string> _highlightedAttributes;
    std::shared_ptr<bool> _hidden;
    std::shared_ptr<::trantor::Date> _createdAt;
    std::shared_ptr<::trantor::Date> _updatedAt;
    std::shared_ptr<std::string> _displayRepresentation;
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
    bool _dirtyFlag[20]={ false };
};
} // namespace openproject4
} // namespace drogon_model
