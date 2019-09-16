#pragma once
#include "../../../queries/work_packages/filter/work_package_filter.h"
// Filter for all work packages that are (or are not) duplicated by work packages with the provided values.

namespace openproj {
namespace Queries {
namespace WorkPackages {
namespace Filter {
class DuplicatedFilter  :
  openproj::Queries::WorkPackages::Filter::WorkPackageFilter {

  // include ::Queries::WorkPackages::Filter::FilterOnDirectedRelationsMixin

   void relation_type() {
//    ::Relation::TYPE_DUPLICATED
  }

  private:

   void relation_filter() {
//    { from_id: values }
  }

   void relation_select() {
//    :to_id
  }
};
}
}
}
}

