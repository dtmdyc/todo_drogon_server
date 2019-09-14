class MemberRole : public ActiveRecord::Base {
  // belongs_to :member
  // belongs_to :role

  // after_create :add_role_to_group_users
  after_destroy :remove_role_from_group_users

  // validates_presence_of :role
  validate :validate_project_member_role

   void validate_project_member_role() {
    if ( role && !role.member?) { errors.add :role_id, :invalid ;}
  }

  // Add alias, so Member can still destroy MemberRoles
  // Don't call this from anywhere else, use remove_member_role on Member.
  alias :destroy_for_member :destroy

  // You shouldn't call this, only ActiveRecord itself is allowed to do this
  // when destroying a Member. Use Member.remove_member_role to remove a role from a member.
  //
  // You may remove this once we have a layer above persistence that handles business logic
  // and prevents or at least discourages working on persistence objects from controllers
  // or unrelated business logic.
   void destroy(*args) {
    unless caller[2] =~ /has_many_association\.rb:[0-9]+:in `delete_records'/
      raise 'MemberRole.destroy called from method other than HasManyAssociation.delete_records' +
        "\n  on #{inspect}\n from #{caller.first} / #{caller[6]}"
    else
      super
    }
  }

   void inherited?() {
    !inherited_from.nil?
  }

  private:

   void add_role_to_group_users() {
    if ( member && member.principal.is_a?(Group)) {
      member.principal.users.each { |user|
        user_member = Member.find_by(project_id: member.project_id, user_id: user.id)

        if ( user_member.nil?) {
          user_member = Member.new.tap { |m|
            m.project_id = member.project_id
            m.user_id = user.id
          }

          user_member.add_role(role, id)
          user_member.save
        else
          user_member.add_and_save_role(role, id)
        }
      }
    }
  }

   void remove_role_from_group_users() {
    inherited_roles_by_member = MemberRole
                                .where(inherited_from: id)
                                .includes(member: %i[principal member_roles])
                                .group_by(&:member)

    inherited_roles_by_member.each { |member, member_roles|
      member_roles.each { |mr|
        member.remove_member_role_and_destroy_member_if_last(mr, prune_watchers: false)
      }
    }

    users = inherited_roles_by_member.keys.map(&:principal)

    Watcher.prune(user: users, project_id: member.project_id) unless users.empty?
  }
}