#pragma once
#include "../../../queries/work_packages/columns/relation_column.h"
namespace openproj {
namespace models {
namespace Queries {
namespace WorkPackages {
namespace Columns {
class RelationToTypeColumn : public openproj::models::Queries::WorkPackages::Columns::RelationColumn {
//   RelationToTypeColumn(type) {
//    super

//    set_name! type
//    this->type = type
//  }

//   void set_name!(type) {
//    this->name = "relations_to_type_#{type.id}".to_sym
//  }

   void caption() {
//    I18n.t(:'activerecord.attributes.query.relations_to_type_column',
//           type: type.name)
  }

//   void instances(context = nil) {
//    if ( !granted_by_enterprise_token) {
//      []
//    } else if ( context) {
//      context.types
//    else
//      Type.all
//    }.map { |type| new(type) }
//  }
};
}
}
}
}
}