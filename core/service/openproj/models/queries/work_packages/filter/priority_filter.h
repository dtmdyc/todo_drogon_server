#pragma once
#include "work_package_filter.h"
namespace openproj {
namespace Queries {
namespace WorkPackages {
namespace Filter {
class PriorityFilter  : openproj::Queries::WorkPackages::Filter::WorkPackageFilter {
   void allowed_values() {
//    priorities.map { |s| [s.name, s.id.to_s] }
  }

//   void available?() {
//    priorities.exists?
//  }

   void type() {
//    :list
  }

   void key() {
//    :priority_id
  }

//   void ar_object_filter?() {
//    true
//  }

   void value_objects() {
//    value_ints = values.map(&:to_i)

//    priorities.select { |p| value_ints.include? p.id }
  }

  private:

   void priorities() {
//    this->priorities ||= IssuePriority.active
  }
};
}
}
}
}

