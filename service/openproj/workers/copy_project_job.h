#pragma once
#include "application_job.h"
#include "caf/all.hpp"
namespace openproj {
namespace worker {
class CopyProjectJob : public caf::event_based_actor, public ApplicationJob {
public:
  // include OpenProject::LocaleHelper

//  attr_reader :user_id,
//              :source_project_id,
//              :target_project_params,
//              :associations_to_copy,
//              :send_mails

//   CopyProjectJob(user_id:, source_project_id:, target_project_params:,
//                 associations_to_copy:, send_mails: false)
//    this->user_id               = user_id
//    this->source_project_id     = source_project_id
//    this->target_project_params = target_project_params.with_indifferent_access
//    this->associations_to_copy  = associations_to_copy
//    this->send_mails            = send_mails
//  }

   void perform() {
//    User.current = user
//    target_project_name = target_project_params[:name]

//    target_project, errors = with_locale_for(user) {
//      create_project_copy(source_project,
//                          target_project_params,
//                          associations_to_copy,
//                          send_mails)
//    }

//    if ( target_project) {
//      ProjectMailer.copy_project_succeeded(user, source_project, target_project, errors).deliver_now
//    else
//      ProjectMailer.copy_project_failed(user, source_project, target_project_name, errors).deliver_now
//    }

//  rescue StandardError => e
//    logger.error { "Failed to finish copy project job: #{e} #{e.message}" }
//    errors = [I18n.t("copy_project.failed_internal")]
//    ProjectMailer.copy_project_failed(user, source_project, target_project_name, errors).deliver_now
  }

  private:

   void user() {
//    this->user ||= User.find user_id
  }

   void source_project() {
//    this->project ||= Project.find source_project_id
  }

//   void create_project_copy(source_project,
//                          target_project_params,
//                          associations_to_copy,
//                          send_mails)
//    target_project = nil
//    errors         = []

//    ProjectMailer.with_deliveries(send_mails) {
//      parent_id = target_project_params[:parent_id]

//      target_project = Project.copy_attributes(source_project)
//      target_project.attributes = target_project_params

//      if ( validate_parent_id(target_project, parent_id) && target_project.save) {
//        target_project.set_allowed_parent!(parent_id) if ( parent_id) {

//        target_project.copy_associations(source_project, only: associations_to_copy)

//        // Project was created
//        // But some objects might not have been copied due to validation failures
//        error_objects = (target_project.compiled_errors.flatten + [target_project.errors]).flatten
//        error_objects.each { |error_object|
//          base = error_object.instance_variable_get(:this->base)
//          error_prefix = base.is_a?(Project) ? "" : "#{base.class.model_name.human} "#{base}": "

//          error_object.full_messages.flatten.each { |error|
//            errors << error_prefix + error
//          }
//        }
//      else
//        errors         = target_project.errors.full_messages
//        target_project = nil
//        logger.error("Copying project fails with validation errors: #{errors.join("\n")}")
//      }
//    }
//  rescue ActiveRecord::RecordNotFound => e
//    logger.error("Entity missing: #{e.message} #{e.backtrace.join("\n")}")
//  rescue StandardError => e
//    logger.error("Encountered an error when trying to copy project "\
//                 ""#{source_project_id}" : #{e.message} #{e.backtrace.join("\n")}")
//  ensure
//    unless errors.empty?
//      logger.error("Encountered an errors while trying to copy related objects for "\
//                   "project "#{source_project_id}": #{errors.inspect}")
//    }

//    return target_project, errors
//  }

  // Validates parent_id param according to user"s permissions
  // TODO: move it to Project model in a validation that depends on User.current
//   void validate_parent_id(project, parent_id) {
//    if ( User.current.admin?) { return true ;}

//    if ( parent_id || project.new_record?) {
//      parent = parent_id.blank? ? nil : Project.find_by(id: parent_id.to_i)

//      unless project.allowed_parents.include?(parent)
//        project.errors.add :parent_id, :invalid

//        return false
//      }
//    }

//    true
//  }

   void logger() {
//    Delayed::Worker.logger
  }
};
}
}
