#pragma once
#include "../../../queries/work_packages/filter/work_package_filter.h"
namespace openproj {
namespace Queries {
namespace WorkPackages {
namespace Filter {
class CommentFilter : public openproj::Queries::WorkPackages::Filter::WorkPackageFilter {
  // include Queries::WorkPackages::Filter::TextFilterOnJoinMixin

   void type() {
//    :text
  }

   void join_condition() {
//    <<-SQL
//     #{join_table_alias}.journable_id = #{WorkPackage.table_name}.id
//	   AND #{join_table_alias}.journable_type = '#{WorkPackage.name}'
//     AND #{notes_condition}
//    SQL
  }

  private:

   void join_table() {
//    Journal.table_name
  }

   void notes_condition() {
//    Queries::Operators::Contains.sql_for_field(values, join_table_alias, 'notes')
  }
};
}
}
}
}

