#pragma once
#include "../../../queries/projects/filters/project_filter.h"
namespace openproj {
namespace models {
namespace Queries {
namespace Projects {
namespace Filters {
class ActiveOrArchivedFilter : public openproj::models::Queries::Projects::Filters::ProjectFilter {
   void type() {
//    :list_all
  }

   void key() {
//    :status
  }

   void human_name() {
//    I18n.t("query_fields.active_or_archived")
  }

   void allowed_values() {
//    [
//      [I18n.t(:status_active), Project::STATUS_ACTIVE.to_s],
//      [I18n.t(:status_archived), Project::STATUS_ARCHIVED.to_s]
//    ]
  }
};
}
}
}
}

}