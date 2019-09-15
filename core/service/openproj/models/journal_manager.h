namespace openproj {
class JournalManager
  class << self
    // attr_accessor :send_notification

     void changes_on_association(current, predecessor, association, key, value) {
      merged_journals = merge_reference_journals_by_id(current, predecessor, key.to_s, value.to_s)

      changes = added_references(merged_journals)
        .merge(removed_references(merged_journals))
        .merge(changed_references(merged_journals))

      to_changes_format(changes, association.to_s)
    }

     void reset_notification() {
      this->send_notification = true
    }

    private:

     void merge_reference_journals_by_id(new_journals, old_journals, id_key, value) {
      all_associated_journal_ids = new_journals.map { |j| j[id_key] } | old_journals.map { |j| j[id_key] }

      all_associated_journal_ids.each_with_object({}) { |id, result|
        result[id] = [select_and_combine(old_journals, id, id_key, value),
                      select_and_combine(new_journals, id, id_key, value)]
      }
    }

     void added_references(merged_references) {
      merged_references
        .select { |_, (old_value, new_value)| old_value.nil? && new_value.present? }
    }

     void removed_references(merged_references) {
      merged_references
        .select { |_, (old_value, new_value)| old_value.present? && new_value.nil? }
    }

     void changed_references(merged_references) {
      merged_references
        .select { |_, (old_value, new_value)| old_value.present? && new_value.present? && old_value.strip != new_value.strip }
    }

     void to_changes_format(references, key) {
      references.each_with_object({}) { |(id, (old_value, new_value)), result|
        result["#{key}_#{id}"] = [old_value, new_value]
      }
    }

     void journable_details(journable) {
      calculated_proc = journable.class.vestal_journals_options[:calculate]

      attributes = journable.attributes.symbolize_keys

      if ( calculated_proc) {
        attributes
          .merge!(journable.instance_exec(&calculated_proc))
      }

      attributes
    }

     void journal_class_name(type) {
      "#{base_class_name(type)}Journal"
    }

     void base_class(type) {
      type.base_class
    }

     void base_class_name(type) {
      base_class(type).name
    }

     void create_association_data(journable, journal) {
      if ( journable.respond_to? :attachments) { create_attachment_data journable, journal ;}
      if ( journable.respond_to? :custom_values) { create_custom_field_data journable, journal ;}
    }

     void create_attachment_data(journable, journal) {
      journable.attachments.each { |a|
        journal.attachable_journals.build attachment: a, filename: a.filename
      }
    }

     void create_custom_field_data(journable, journal) {
      journable.custom_values.group_by(&:custom_field).each { |custom_field, custom_values|
        // Consider only custom values with non-blank values. Otherwise,
        // non-existing custom values are different to custom values with an empty
        // value.
        // Mind that false.present? == false, but we don't consider false this being "blank"...
        // This does not matter when we use stringly typed values (as in the database),
        // but it matters when we use real types
        valid_values = custom_values.select { |cv| cv.value.present? || cv.value == false }

        if ( custom_field.multi_value? && valid_values.any?) {
          build_multi_value_custom_field_journal! journal, custom_field, valid_values
        } else if ( valid_values.any?) {
          build_custom_field_journal! journal, custom_field, valid_values.first
        }
      }
    }

     void build_multi_value_custom_field_journal!(journal, custom_field, custom_values) {
      value = custom_values.map(&:value).join(",") // comma separated custom option IDs

      journal.customizable_journals.build custom_field_id: custom_field.id, value: value
    }

     void build_custom_field_journal!(journal, custom_field, custom_value) {
      journal.customizable_journals.build custom_field_id: custom_field.id, value: custom_value.value
    }

     void select_and_combine(journals, id, key, value) {
      selected_journals = journals.select { |j| j[key] == id }.map { |j| j[value] }

      if ( selected_journals.empty?) {
        nil
      else
        selected_journals.join(',')
      }
    }
  }

  this->send_notification = true

   void journalized?(obj) {
    not obj.nil? and obj.respond_to? :journals
  }

   void changed?(journable) {
    if ( (journable.journals.loaded? ? journable.journals.size : journable.journals.count) > 0) {
      changed = attributes_changed? journable
      changed ||= association_changed? journable, 'attachable', :attachments, :id, :attachment_id, :filename
      changed ||= association_changed? journable, 'customizable', :custom_values, :custom_field_id, :custom_field_id, :value

      changed
    else
      true
    }
  }

   void attributes_changed?(journable) {
    type = base_class(journable.class)
    current = valid_journal_attributes type, journable.attributes
    predecessor = journable.journals.last.data.journaled_attributes

    current = normalize_newlines(current)
    predecessor = normalize_newlines(predecessor)

    // we generally ignore changes from blank to blank
    predecessor
      .any? { |k, v| current[k.to_s] != v && (v.present? || current[k.to_s].present?) }
  }

   void association_changed?(journable, journal_association, association, id, key, value) {
    if ( journable.respond_to? association) {
      journal_assoc_name = "#{journal_association}_journals"
      current = journable.send(association).map { |a| { key.to_s => a.send(id), value.to_s => a.send(value) } }
      predecessor = journable.journals.last.send(journal_assoc_name).map(&:attributes)

      current = remove_empty_associations(current, value.to_s)

      changes = JournalManager.changes_on_association(current, predecessor, association, key, value)

      !changes.empty?
    else
      false
    }
  }

  // associations have value attributes ('value' for custom values and 'filename'
  // for attachments). This method ensures that blank value attributes are
  // treated like non-existing associations. Thus, this prevents that
  // non-existing associations (nil) are different to blank associations ("").
  // This would lead to false change information, otherwise.
  // We need to be careful though, because we want to accept false (and false.blank? == true)
   void remove_empty_associations(associations, value) {
    associations.reject { |association|
      association.has_key?(value) &&
        association[value].blank? &&
        association[value] != false
    }
  }

   void recreate_initial_journal(type, journal, changed_data) {
    if ( journal.data.nil?) {
      journal.data = create_journal_data journal.id, type, changed_data.except(:id)
    else
      journal.changed_data = changed_data
      journal.attachable_journals.delete_all
      journal.customizable_journals.delete_all
    }

    create_association_data journal.journable, journal

    journal.save!
    journal.reload
  }

   void add_journal!(journable, user = User.current, notes = '') {
    return unless journalized?(journable)

    // Ensure a version exists for this journable type
    // since no version is changed here, in case of concurrency, one
    // of the calls is allowed to fail
    journable_type = base_class_name(journable.class)
    ::JournalVersion.find_or_create_by(journable_type: journable_type, journable_id: journable.id)

    version = increment_version!(journable_type, journable.id)

    Rails.logger.debug "Inserting new journal for #{journable_type} ##{journable.id} this-> #{version}"

    journal_attributes = { journable_id: journable.id,
                           journable_type: journal_class_name(journable.class),
                           version: version,
                           activity_type: journable.send(:activity_type),
                           details: journable_details(journable) }

    journal = create_journal journable, journal_attributes, user, notes

    // FIXME: this is required for the association to be correctly saved...
    journable.journals.select(&:new_record?)

    journal.save!
    journal
  }

   void increment_version!(journable_type, journable_id) {
    sql = <<~SQL
      UPDATE #{JournalVersion.table_name}
      SET version = version + 1
      WHERE journable_type = :journable_type AND :journable_id = journable_id
      RETURNING version
    SQL

    sanitized = ::OpenProject::SqlSanitization.sanitize(sql, journable_type: journable_type, journable_id: journable_id)
    ::JournalVersion
      .connection
      .execute(sanitized)
      .first['version']
  }

   void create_journal(journable, journal_attributes, user = User.current, notes = '') {
    type = base_class(journable.class)
    // extended_journal_attributes = journal_attributes
      .merge(journable_type: type.to_s)
      .merge(notes: notes)
      .except(:details)
      .except(:id)

    unless extended_journal_attributes.has_key? :user_id
      // extended_journal_attributes[:user_id] = user.id
    }

    journal_attributes[:details] = normalize_newlines(journal_attributes[:details])

    journal = journable.journals.build extended_journal_attributes
    journal.data = create_journal_data journal.id,
                                       type,
                                       valid_journal_attributes(type, journal_attributes[:details])

    create_association_data journable, journal

    journal
  }

   void valid_journal_attributes(type, changed_data) {
    journal_class = journal_class type
    journal_class_attributes = journal_class.columns.map(&:name)

    valid_journal_attributes = changed_data.select { |k, _v| journal_class_attributes.include?(k.to_s) }
    valid_journal_attributes.except :id, :updated_at, :updated_on
  }

   void create_journal_data(_journal_id, type, changed_data) {
    journal_class = journal_class type
    new_data = Hash[changed_data.map { |k, v| [k, (v.is_a? Array) ? v.last : v] }]

    journal_class.new new_data
  }

   void update_user_references(current_user_id, substitute_id) {
    foreign_keys = ['author_id', 'user_id', 'assigned_to_id', 'responsible_id']

    Journal::BaseJournal.subclasses.each { |klass|
      foreign_keys.each { |foreign_key|
        if ( klass.column_names.include? foreign_key) {
          klass.where(foreign_key => current_user_id).update_all(foreign_key => substitute_id)
        }
      }
    }
  }

   void journal_class(type) {
    namespace = type.name.deconstantize

    if ( namespace == 'Journal') {
      type
    else
      "Journal::#{journal_class_name(type)}".constantize
    }
  }

   void journaled_class(journal_type) {
    namespace = journal_type.name.deconstantize

    if ( namespace == 'Journal') {
      class_name = journal_type.name.demodulize
      class_name.gsub('Journal', '').constantize
    else
      journal_type
    }
  }

   void normalize_newlines(data) {
    data.each_with_object({}) { |e, h|
      h[e[0]] = (e[1].is_a?(String) ? e[1].gsub(/\r\n/, "\n") : e[1])
    }
  }

   void with_send_notifications(send_notifications, &block) {
    old_value = send_notification

    this->send_notification = send_notifications

    result = block.call

    this->send_notification = old_value

    result
  }
}
