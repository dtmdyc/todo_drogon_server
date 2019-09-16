#include "./auth.h"

#include <utility>
#include "../../../sql/dba.h"
#include "./session.h"

#include "core/service/openproj/controllers/account_controller.h"
#include "core/service/openproj/controllers/activities_controller.h"
#include "core/service/openproj/controllers/admin_controller.h"
#include "core/service/openproj/controllers/announcements_controller.h"
#include "core/service/openproj/controllers/application_controller.h"
#include "core/service/openproj/controllers/attribute_help_texts_controller.h"
#include "core/service/openproj/controllers/auth_sources_controller.h"
#include "core/service/openproj/controllers/authentication_controller.h"
#include "core/service/openproj/controllers/categories_controller.h"
#include "core/service/openproj/controllers/colors_controller.h"

#include "core/service/openproj/controllers/concerns/auth_source_sso.h"
#include "core/service/openproj/controllers/concerns/authentication_stages.h"
#include "core/service/openproj/controllers/concerns/layout.h"
#include "core/service/openproj/controllers/concerns/omniauth_login.h"
#include "core/service/openproj/controllers/concerns/password_confirmation.h"
#include "core/service/openproj/controllers/concerns/redirect_after_login.h"
#include "core/service/openproj/controllers/concerns/user_consent.h"
#include "core/service/openproj/controllers/concerns/user_invitation.h"
#include "core/service/openproj/controllers/concerns/user_limits.h"
#include "core/service/openproj/controllers/concerns/user_password_change.h"

#include "core/service/openproj/controllers/copy_projects_controller.h"
#include "core/service/openproj/controllers/custom_actions_controller.h"
#include "core/service/openproj/controllers/custom_fields_controller.h"
#include "core/service/openproj/controllers/custom_styles_controller.h"
#include "core/service/openproj/controllers/enterprises_controller.h"
#include "core/service/openproj/controllers/enumerations_controller.h"
#include "core/service/openproj/controllers/forums_controller.h"
#include "core/service/openproj/controllers/groups_controller.h"
#include "core/service/openproj/controllers/help_controller.h"
#include "core/service/openproj/controllers/highlighting_controller.h"
#include "core/service/openproj/controllers/homescreen_controller.h"
#include "core/service/openproj/controllers/journals_controller.h"
#include "core/service/openproj/controllers/ldap_auth_sources_controller.h"
#include "core/service/openproj/controllers/members_controller.h"
#include "core/service/openproj/controllers/messages_controller.h"
#include "core/service/openproj/controllers/my_controller.h"

#include "core/service/openproj/controllers/news/comments_controller.h"
#include "core/service/openproj/controllers/news_controller.h"

#include "core/service/openproj/controllers/oauth/applications_controller.h"
#include "core/service/openproj/controllers/oauth/auth_base_controller.h"
#include "core/service/openproj/controllers/oauth/grants_controller.h"

#include "core/service/openproj/controllers/onboarding_controller.h"
#include "core/service/openproj/controllers/project_enumerations_controller.h"
#include "core/service/openproj/controllers/project_settings_controller.h"
#include "core/service/openproj/controllers/projects_controller.h"
#include "core/service/openproj/controllers/repositories_controller.h"
#include "core/service/openproj/controllers/roles_controller.h"
#include "core/service/openproj/controllers/search_controller.h"
#include "core/service/openproj/controllers/settings_controller.h"
#include "core/service/openproj/controllers/statuses_controller.h"
#include "core/service/openproj/controllers/sys_controller.h"

#include "core/service/openproj/controllers/time_entries/reports_controller.h"

#include "core/service/openproj/controllers/timelog_controller.h"
#include "core/service/openproj/controllers/types_controller.h"

#include "core/service/openproj/controllers/users/memberships_controller.h"
#include "core/service/openproj/controllers/users_controller.h"
#include "core/service/openproj/controllers/users_settings_controller.h"
#include "core/service/openproj/controllers/versions_controller.h"
#include "core/service/openproj/controllers/watchers_controller.h"
#include "core/service/openproj/controllers/wiki_controller.h"
#include "core/service/openproj/controllers/wiki_menu_items_controller.h"
#include "core/service/openproj/controllers/workflows_controller.h"

#include "core/service/openproj/controllers/work_packages/auto_completes_controller.h"
#include "core/service/openproj/controllers/work_packages/bulk_controller.h"
#include "core/service/openproj/controllers/work_packages/calendars_controller.h"
#include "core/service/openproj/controllers/work_packages/moves_controller.h"
#include "core/service/openproj/controllers/work_packages/reports_controller.h"
//#include
//"core/service/openproj/controllers/work_packages/settings_controller.h"

#include "core/service/openproj/controllers/work_packages_controller.h"

#include "core/service/openproj/helpers/accessibility_helper.h"
#include "core/service/openproj/helpers/accounts_helper.h"
#include "core/service/openproj/helpers/additional_url_helpers.h"
#include "core/service/openproj/helpers/admin_helper.h"
#include "core/service/openproj/helpers/angular_helper.h"
#include "core/service/openproj/helpers/announcements_helper.h"
#include "core/service/openproj/helpers/application_helper.h"
#include "core/service/openproj/helpers/attachments_helper.h"
#include "core/service/openproj/helpers/attribute_help_texts_helper.h"
#include "core/service/openproj/helpers/augmenting_helper.h"
#include "core/service/openproj/helpers/authentication_stage_path_helper.h"
#include "core/service/openproj/helpers/avatar_helper.h"
#include "core/service/openproj/helpers/breadcrumb_helper.h"
#include "core/service/openproj/helpers/browser_helper.h"
#include "core/service/openproj/helpers/calendars_helper.h"
#include "core/service/openproj/helpers/cells_helper.h"
#include "core/service/openproj/helpers/colors_helper.h"
#include "core/service/openproj/helpers/content_for_helper.h"
#include "core/service/openproj/helpers/crowdin_helper.h"
#include "core/service/openproj/helpers/custom_fields_helper.h"
#include "core/service/openproj/helpers/error_message_helper.h"
#include "core/service/openproj/helpers/errors_helper.h"
#include "core/service/openproj/helpers/frontend_asset_helper.h"
#include "core/service/openproj/helpers/groups_helper.h"
#include "core/service/openproj/helpers/hide_sections_helper.h"
#include "core/service/openproj/helpers/highlighting_helper.h"
#include "core/service/openproj/helpers/homescreen_helper.h"
#include "core/service/openproj/helpers/hook_helper.h"
#include "core/service/openproj/helpers/icons_helper.h"
#include "core/service/openproj/helpers/issues_helper.h"
#include "core/service/openproj/helpers/messages_helper.h"
#include "core/service/openproj/helpers/meta_tags_helper.h"
#include "core/service/openproj/helpers/no_results_helper.h"
#include "core/service/openproj/helpers/oauth_helper.h"
#include "core/service/openproj/helpers/omniauth_helper.h"
#include "core/service/openproj/helpers/open_project_error_helper.h"
#include "core/service/openproj/helpers/pagination_helper.h"
#include "core/service/openproj/helpers/password_helper.h"
#include "core/service/openproj/helpers/projects_helper.h"
#include "core/service/openproj/helpers/queries_helper.h"
#include "core/service/openproj/helpers/query_menu_items_helper.h"
#include "core/service/openproj/helpers/relations_helper.h"
#include "core/service/openproj/helpers/removed_js_helpers_helper.h"
#include "core/service/openproj/helpers/reorder_links_helper.h"
#include "core/service/openproj/helpers/reports_helper.h"
#include "core/service/openproj/helpers/repositories_helper.h"
#include "core/service/openproj/helpers/roles_helper.h"
#include "core/service/openproj/helpers/search_helper.h"
#include "core/service/openproj/helpers/security_badge_helper.h"
#include "core/service/openproj/helpers/settings_helper.h"
#include "core/service/openproj/helpers/sort_helper.h"
#include "core/service/openproj/helpers/static_links_helper.h"
#include "core/service/openproj/helpers/tabs_helper.h"
#include "core/service/openproj/helpers/text_formatting_helper.h"
#include "core/service/openproj/helpers/timelog_helper.h"
#include "core/service/openproj/helpers/toolbar_helper.h"
#include "core/service/openproj/helpers/types_helper.h"
#include "core/service/openproj/helpers/user_consent_helper.h"
#include "core/service/openproj/helpers/users_helper.h"
#include "core/service/openproj/helpers/versions_helper.h"
#include "core/service/openproj/helpers/warning_bar_helper.h"
#include "core/service/openproj/helpers/watchers_helper.h"
#include "core/service/openproj/helpers/wiki_helper.h"
#include "core/service/openproj/helpers/work_packages_filter_helper.h"
#include "core/service/openproj/helpers/work_packages_helper.h"

#include "core/service/openproj/mailers/base_mailer.h"
#include "core/service/openproj/mailers/project_mailer.h"
#include "core/service/openproj/mailers/user_mailer.h"

// models 467 files

#include "core/service/openproj/policies/base_policy.h"
#include "core/service/openproj/policies/query_policy.h"
#include "core/service/openproj/policies/redirect_policy.h"
#include "core/service/openproj/policies/version_policy.h"
#include "core/service/openproj/policies/work_package_policy.h"

#include "core/service/openproj/policies/scm/authorization_policy.h"
#include "core/service/openproj/policies/scm/git_authorization_policy.h"
#include "core/service/openproj/policies/scm/subversion_authorization_policy.h"

// seeders 42 files

#include "core/service/openproj/services/add_attachment_service.h"
#include "core/service/openproj/services/add_work_package_note_service.h"

#include "core/service/openproj/services/api/v3/params_to_query_service.h"
#include "core/service/openproj/services/api/v3/parse_query_params_service.h"
#include "core/service/openproj/services/api/v3/parse_resource_params_service.h"
#include "core/service/openproj/services/api/v3/update_query_from_v3_params_service.h"
#include "core/service/openproj/services/api/v3/work_package_collection_from_query_params_service.h"
#include "core/service/openproj/services/api/v3/work_package_collection_from_query_service.h"

#include "core/service/openproj/services/attachments/set_replacements.h"

#include "core/service/openproj/services/authorization.h"
#include "core/service/openproj/services/authorization/abstract_query.h"
#include "core/service/openproj/services/authorization/abstract_user_query.h"
#include "core/service/openproj/services/authorization/enterprise_service.h"
#include "core/service/openproj/services/authorization/project_query.h"
#include "core/service/openproj/services/authorization/query_transformation.h"
#include "core/service/openproj/services/authorization/query_transformation_visitor.h"
#include "core/service/openproj/services/authorization/query_transformations.h"
#include "core/service/openproj/services/authorization/query_transformations_order.h"
#include "core/service/openproj/services/authorization/user_allowed_query.h"
#include "core/service/openproj/services/authorization/user_allowed_service.h"
#include "core/service/openproj/services/authorization/user_global_roles_query.h"
#include "core/service/openproj/services/authorization/user_project_roles_query.h"
#include "core/service/openproj/services/authorization/user_roles_query.h"
#include "core/service/openproj/services/authorization_service.h"
#include "core/service/openproj/services/base_project_service.h"

#include "core/service/openproj/services/base_services/create.h"
#include "core/service/openproj/services/base_services/delete.h"
#include "core/service/openproj/services/base_services/set_attributes.h"
#include "core/service/openproj/services/base_services/update.h"
#include "core/service/openproj/services/base_type_service.h"

#include "core/service/openproj/services/changesets/log_time_service.h"

#include "core/service/openproj/services/concerns/contracted.h"
#include "core/service/openproj/services/create_type_service.h"

#include "core/service/openproj/services/custom_actions/base_service.h"
#include "core/service/openproj/services/custom_actions/create_service.h"
#include "core/service/openproj/services/custom_actions/update_service.h"
#include "core/service/openproj/services/custom_actions/update_work_package_service.h"

#include "core/service/openproj/services/members/create_service.h"
#include "core/service/openproj/services/members/delete_service.h"
#include "core/service/openproj/services/members/edit_membership_service.h"
#include "core/service/openproj/services/members/set_attributes_service.h"
#include "core/service/openproj/services/members/update_service.h"

#include "core/service/openproj/services/oauth/persist_application_service.h"
#include "core/service/openproj/services/params_to_query_service.h"
#include "core/service/openproj/services/parse_schema_filter_params_service.h"

#include "core/service/openproj/services/projects/delete_project_service.h"
#include "core/service/openproj/services/projects/set_attributes_service.h"
#include "core/service/openproj/services/projects/update_service.h"

#include "core/service/openproj/services/queries/create_query_service.h"
#include "core/service/openproj/services/queries/query_service.h"
#include "core/service/openproj/services/queries/update_query_service.h"

#include "core/service/openproj/services/relations/base_service.h"
#include "core/service/openproj/services/relations/create_service.h"
#include "core/service/openproj/services/relations/update_service.h"

#include "core/service/openproj/services/reports/assignee_report.h"
#include "core/service/openproj/services/reports/author_report.h"
#include "core/service/openproj/services/reports/category_report.h"
#include "core/service/openproj/services/reports/priority_report.h"
#include "core/service/openproj/services/reports/report.h"
#include "core/service/openproj/services/reports/reports_service.h"
#include "core/service/openproj/services/reports/responsible_report.h"
#include "core/service/openproj/services/reports/subproject_report.h"
#include "core/service/openproj/services/reports/type_report.h"
#include "core/service/openproj/services/reports/version_report.h"

#include "core/service/openproj/services/roles/create_service.h"
#include "core/service/openproj/services/roles/notify_mixin.h"
#include "core/service/openproj/services/roles/set_attributes_service.h"
#include "core/service/openproj/services/roles/update_service.h"

#include "core/service/openproj/services/scm/base_repository_service.h"
#include "core/service/openproj/services/scm/checkout_instructions_service.h"
#include "core/service/openproj/services/scm/create_managed_repository_service.h"
#include "core/service/openproj/services/scm/delete_managed_repository_service.h"
#include "core/service/openproj/services/scm/repository_factory_service.h"
#include "core/service/openproj/services/service_result.h"

#include "core/service/openproj/services/sessions/base_service.h"
#include "core/service/openproj/services/sessions/drop_other_sessions_service.h"
#include "core/service/openproj/services/sessions/initialize_session_service.h"
#include "core/service/openproj/services/set_localization_service.h"

#include "core/service/openproj/services/settings/update_service.h"

#include "core/service/openproj/services/shared/block_service.h"
#include "core/service/openproj/services/shared/service_context.h"

#include "core/service/openproj/services/time_entries/create_service.h"
#include "core/service/openproj/services/time_entries/delete_service.h"
#include "core/service/openproj/services/time_entries/set_attributes_service.h"
#include "core/service/openproj/services/time_entries/update_service.h"
#include "core/service/openproj/services/update_projects_types_service.h"
#include "core/service/openproj/services/update_query_from_params_service.h"
#include "core/service/openproj/services/update_type_service.h"
#include "core/service/openproj/services/update_user_email_settings_service.h"

#include "core/service/openproj/services/user_search_service.h"
#include "core/service/openproj/services/users/change_password_service.h"
#include "core/service/openproj/services/users/create_user_service.h"
#include "core/service/openproj/services/users/delete_service.h"
#include "core/service/openproj/services/users/update_service.h"
#include "core/service/openproj/services/users/update_user_service.h"

#include "core/service/openproj/services/versions/create_service.h"
#include "core/service/openproj/services/versions/delete_service.h"
#include "core/service/openproj/services/versions/set_attributes_service.h"
#include "core/service/openproj/services/versions/update_service.h"

#include "core/service/openproj/services/workflows/bulk_update_service.h"

#include "core/service/openproj/services/work_packages/bulk/update_service.h"
#include "core/service/openproj/services/work_packages/copy_service.h"
#include "core/service/openproj/services/work_packages/create_service.h"
#include "core/service/openproj/services/work_packages/delete_service.h"
#include "core/service/openproj/services/work_packages/move_service.h"
#include "core/service/openproj/services/work_packages/reschedule_service.h"
#include "core/service/openproj/services/work_packages/schedule_dependency.h"
#include "core/service/openproj/services/work_packages/set_attributes_service.h"
#include "core/service/openproj/services/work_packages/set_schedule_service.h"

#include "core/service/openproj/services/work_packages/shared/update_ancestors.h"
#include "core/service/openproj/services/work_packages/shared/update_attributes.h"
#include "core/service/openproj/services/work_packages/update_ancestors_service.h"
#include "core/service/openproj/services/work_packages/update_service.h"

//---
#include "core/service/openproj/uploaders/file_uploader.h"
#include "core/service/openproj/uploaders/fog_file_uploader.h"
#include "core/service/openproj/uploaders/local_file_uploader.h"

#include "core/service/openproj/validators/url_validator.h"

#include "core/service/openproj/workers/application_job.h"
#include "core/service/openproj/workers/attachments/cleanup_uncontainered_job.h"
#include "core/service/openproj/workers/copy_project_job.h"
#include "core/service/openproj/workers/delete_user_job.h"
#include "core/service/openproj/workers/deliver_invitation_job.h"
#include "core/service/openproj/workers/deliver_notification_job.h"
#include "core/service/openproj/workers/deliver_watcher_notification_job.h"
#include "core/service/openproj/workers/deliver_work_package_notification_job.h"
#include "core/service/openproj/workers/enqueue_work_package_notification_job.h"
#include "core/service/openproj/workers/extract_fulltext_job.h"
#include "core/service/openproj/workers/mail_user_job.h"
#include "core/service/openproj/workers/oauth/cleanup_job.h"
#include "core/service/openproj/workers/projects/delete_project_job.h"
#include "core/service/openproj/workers/rake_job.h"
#include "core/service/openproj/workers/scm/create_local_repository_job.h"
#include "core/service/openproj/workers/scm/create_remote_repository_job.h"
#include "core/service/openproj/workers/scm/delete_local_repository_job.h"
#include "core/service/openproj/workers/scm/delete_remote_repository_job.h"
#include "core/service/openproj/workers/scm/relocate_repository_job.h"
#include "core/service/openproj/workers/scm/remote_repository_job.h"
#include "core/service/openproj/workers/scm/storage_updater_job.h"

namespace todo {
namespace service {
Auth::Auth(std::shared_ptr<websocket::todo::TodoContext> context_)
    : context(std::move(context_)) {
  setupTable();
}

void Auth::setupTable() {}

nlohmann::json Auth::handleEvent(nlohmann::json event, unsigned long next,
                                 nlohmann::json args) {
  auto event_cmp = event[next].get<std::string>();
  if (event_cmp == "login") {
    nlohmann::json res = {{}, {}};
    if (args.is_object() && args["user"].is_string() &&
        args["pass"].is_string()) {
      auto isauthorised =
          "select (u.expiry > now()) as isexpired, u.disabled from music.user "
          "as u WHERE "
          "username = $1";
      auto r = sql::Dba::read(isauthorised, args["user"].get<std::string>());
      if (r.empty()) {
        return {websocket::WsFns::successJsonObject(event, false, "Error")};
      } else if (!r[0]["isexpired"].isNull() && r[0]["isexpired"].as<bool>()) {
        return {websocket::WsFns::successJsonObject(event, false, "Expired")};
      } else if (r[0]["disabled"].as<bool>()) {
        return {websocket::WsFns::successJsonObject(event, false, "Locked")};
      }

      auto [session_id, user_id] = login(args["user"].get<std::string>(),
                                         args["pass"].get<std::string>());
      res[0][1] = session_id;
      if (session_id) {
        context->setSessionId(session_id);
        context->setUserId(user_id);
        context->setUser();
        res[0] = websocket::WsFns::successJsonObject(event, true, "Done");
        res[1] = {{"auth", "set_cookie", 0}, session_id};
        return res;
      }
    }
    return {websocket::WsFns::successJsonObject(event, false, "Error")};
  }
  if (event_cmp == "logout") {
    auto r = logout();
    if (r) {
      return {websocket::WsFns::successJsonObject(event, true, "Done")};
    }
    return {websocket::WsFns::successJsonObject(event, false, "UnAuthorised")};
  } else if (event_cmp == "file_meta_data") {
    return saveFileMeta(event, args);
  } else if (event_cmp == "ins") {
    return query.ins(event, args);
  } else if (event_cmp == "upd") {
    return query.upd(event, args);
  } else if (event_cmp == "del") {
    return query.del(event, args);
  } else {
    return nullptr;
  }
}
// Save Image meta on server temporary
nlohmann::json Auth::saveFileMeta(const nlohmann::json& event,
                                  nlohmann::json args) {
  if (!args.is_array() || args.size() <= 3) {
    nlohmann::json ret;
    ret[0] =
        websocket::WsFns::successJsonObject(event, false, "No Valid arguments");
    return ret;
  }
  long c = context->sessionId();

  // auto strSql = "INSERT INTO music.temp_file_meta ( session_id, event, name,
  // size, type ) VALUES( $1, $2, $3, $4, $5 )";
  auto strSql = fmt::format(
      "INSERT INTO music.temp_file_meta ( session_id, event, name, size, type "
      ") VALUES( {0}, '{1}','{2}', {3}, '{4}' )",
      c, args[0].dump(), args[1].get<std::string>(), args[2].get<long>(),
      args[3].get<std::string>());
  try {
    auto clientPtr = drogon::app().getDbClient("sce");
    auto transPtr = clientPtr->newTransaction();
    auto r = sql::Dba::writeInTrans(transPtr, strSql);
    // auto r = sql::Dba::writeInTrans(transPtr, strSql, c, args[0].dump(),
    // args[1].get<std::string>(), args[2].get<long>(),
    // args[3].get<std::string>());
    nlohmann::json ret;
    ret[0] = websocket::WsFns::successJsonObject(event, true, "Done");
    return ret;
  } catch (const std::exception& e) {
    SPDLOG_TRACE(e.what());
    nlohmann::json ret;
    ret[0] = websocket::WsFns::successJsonObject(event, false, "Error");
    return ret;
  }
}

bool Auth::logout(long key, bool relogin) {
  // If no key is passed try to find the session id
  key = key ? key : context->sessionId();

  // Nuke the cookie before all else
  auto r = Session::destroy(key);
  if (r) {
    context->setSessionId(0);
    return true;
  }
  return false;
  // if ((!relogin) && AmpConfig::get('logout_redirect')) {
  // target = AmpConfig::get('logout_redirect');
  //} else {
  // target = AmpConfig::get('web_path') . '/login.php';
  //}

  // Do a quick check to see if this is an AJAXed logout request
  // if so use the iframe to redirect
  // if (defined('AJAX_INCLUDE')) {
  // ob_end_clean();
  // ob_start();

  // xoutput_headers();

  // results            = array();
  // results['rfc3514'] = '<script type="text/javascript">reloadRedirect("' .
  // target . '")</script>'; echo xoutput_from_array(results);
  //} else {
  /* Redirect them to the login page */
  // header('Location: ' . target);
  //}
}

std::tuple<long, long> Auth::login(const std::string& username,
                                   const std::string& password, bool allow_ui) {
  long session_id = 0;
  long user_id = 0;
  if (!password.empty() && !username.empty()) {
    try {
      auto sql =
          "SELECT id, password FROM music.user WHERE username = $1 and "
          "password = $2";
      auto clientPtr = drogon::app().getDbClient("sce");
      auto transPtr = clientPtr->newTransaction();
      auto r = sql::Dba::writeInTrans(transPtr, sql, username, password);

      if (r.size() == 1) {
        user_id = r[0]["id"].as<long>();
        auto sqlSession =
            "INSERT INTO music.session (user_id, expire, value) VALUES ($1, "
            "$2, $3) returning id";
        auto rs = sql::Dba::writeInTrans(transPtr, sqlSession, user_id, 0L, "");
        session_id = rs[0]["id"].as<long>();
      }
    } catch (const std::exception& e) {
      SPDLOG_TRACE(e.what());
    }
  }
  return {session_id, user_id};
}
}  // namespace service
}  // namespace todo
