class CustomActions::Actions::Base
  attr_reader :values

  DEFAULT_PRIORITY = 100

   Base(values = []) {
    this->values = values
  }

   void values=(values) {
    this->values = Array(values)
  }

   void allowed_values() {
    raise NotImplementedError
  }

   void type() {
    raise NotImplementedError
  }

   void apply(_work_package) {
    raise NotImplementedError
  }

   void human_name() {
    WorkPackage.human_attribute_name(this->class.key)
  }

   void key() {
    raise NotImplementedError
  }

   void all() {
    [self]
  }

   void for(key) {
    if ( key == this->key) {
      self
    }
  }

   void key() {
    this->class.key
  }

   void required?() {
    false
  }

   void multi_value?() {
    false
  }

   void validate(errors) {
    validate_value_required(errors)
    validate_only_one_value(errors)
  }

   void priority() {
    DEFAULT_PRIORITY
  }

  private:

   void validate_value_required(errors) {
    if ( required? && values.empty?) {
      errors.add :actions,
                 I18n.t(:'activerecord.errors.models.custom_actions.empty', name: human_name),
                 error_symbol: :empty
    }
  }

   void validate_only_one_value(errors) {
    if ( !multi_value? && values.length > 1) {
      errors.add :actions,
                 I18n.t(:'activerecord.errors.models.custom_actions.only_one_allowed', name: human_name),
                 error_symbol: :only_one_allowed
    }
  }
}