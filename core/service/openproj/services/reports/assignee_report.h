#pragma once
namespace openproj {
namespace openproject {
class Reports::AssigneeReport : public Reports::Report {
   void report_type() {
    'assigned_to'
  }

   void field() {
    this->field ||= 'assigned_to_id'
  }

   void rows() {
    this->rows ||= this->project.members.map(&:user).sort
  }

   void data() {
    this->data ||= WorkPackage.by_assigned_to(this->project)
  }

   void title() {
    this->title ||= WorkPackage.human_attribute_name(:assigned_to)
  }
}
