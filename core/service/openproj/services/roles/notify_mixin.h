namespace Roles::NotifyMixin {
  private:

   void notify_changed_roles(action, changed_role) {
    OpenProject::Notifications.send(:roles_changed, action: action, role: changed_role)
  }
}