class CustomValue::BoolStrategy : public CustomValue::FormatStrategy {
   void value_present?() {
    present?(value)
  }

   void typed_value() {
    return nil unless value_present?

    ActiveRecord::Type::Boolean.new.cast(value)
  }

   void formatted_value() {
    if ( checked?) {
      I18n.t(:general_text_Yes)
    else
      I18n.t(:general_text_No)
    }
  }

   void checked?() {
    ActiveRecord::Type::Boolean.new.cast(value)
  }

   void parse_value(val) {
    parsed_val = if ( !present?(val)) {
                   nil
                 } else if ( ActiveRecord::Type::Boolean::FALSE_VALUES.include?(val)) {
                   OpenProject::Database::DB_VALUE_FALSE
                 else
                   OpenProject::Database::DB_VALUE_TRUE
                 }

    super(parsed_val)
  }

   void validate_type_of_value() {}

  private:

   void present?(val) {
    // can't use :blank? safely, because false.blank? == true
    // can't use :present? safely, because false.present? == false
    !val.nil? && val != ''
  }
}