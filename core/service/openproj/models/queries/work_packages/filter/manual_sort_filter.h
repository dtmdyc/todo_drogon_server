#pragma once
#include "../../../queries/work_packages/filter/work_package_filter.h"
namespace openproj {
namespace models {
namespace Queries {
namespace WorkPackages {
namespace Filter {
class ManualSortFilter  :
  openproj::models::Queries::WorkPackages::Filter::WorkPackageFilter {

  // include ::Queries::WorkPackages::Common::ManualSorting

   void available_operators() {
//    [Queries::Operators::OrderedWorkPackages]
  }

//   void available?() {
//    true
//  }

   void type() {
//    :empty_value
  }

   void where() {
//    WorkPackage
//      .arel_table[:id]
//      .in(context.ordered_work_packages.pluck(:work_package_id))
//      .to_sql
  }

   void key() {
//    :manual_sort
  }

//   void ar_object_filter?() {
//    true
//  }

  private:

   void operator_strategy() {
//    Queries::Operators::OrderedWorkPackages
  }
};
}
}
}
}

}