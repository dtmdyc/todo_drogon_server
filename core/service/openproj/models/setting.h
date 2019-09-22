#pragma once
#include <drogon/drogon.h>
#include <yaml-cpp/yaml.h>
#include "activerecord.h"
#include "iostream"
namespace openproj {
namespace models {
class Setting : public ActiveRecord::Base {
 public:
  YAML::Node available_settings;
  Setting() {
    try {
      available_settings = YAML::LoadFile("./config/settings.yml");
    } catch (YAML::BadFile &e) {
      LOG_DEBUG << e.what();
    }
  }
  //  DATE_FORMATS = [
  //    "%Y-%m-%d",
  //    "%d/%m/%Y",
  //    "%d.%m.%Y",
  //    "%d-%m-%Y",
  //    "%m/%d/%Y",
  //    "%d %b %Y",
  //    "%d %B %Y",
  //    "%b %d, %Y",
  //    "%B %d, %Y"
  //  ]

  //  TIME_FORMATS = [
  //    "%H:%M",
  //    "%I:%M %p"
  //  ]

  //  ENCODINGS = %w(US-ASCII
  //                 windows-1250
  //                 windows-1251
  //                 windows-1252
  //                 windows-1253
  //                 windows-1254
  //                 windows-1255
  //                 windows-1256
  //                 windows-1257
  //                 windows-1258
  //                 windows-31j
  //                 ISO-2022-JP
  //                 ISO-2022-KR
  //                 ISO-8859-1
  //                 ISO-8859-2
  //                 ISO-8859-3
  //                 ISO-8859-4
  //                 ISO-8859-5
  //                 ISO-8859-6
  //                 ISO-8859-7
  //                 ISO-8859-8
  //                 ISO-8859-9
  //                 ISO-8859-13
  //                 ISO-8859-15
  //                 KOI8-R
  //                 UTF-8
  //                 UTF-16
  //                 UTF-16BE
  //                 UTF-16LE
  //                 EUC-JP
  //                 Shift_JIS
  //                 CP932
  //                 GB18030
  //                 GBK
  //                 ISCII91
  //                 EUC-KR
  //                 Big5
  //                 Big5-HKSCS
  //                 TIS-620)

  //  cattr_accessor :available_settings

  //   void create_setting(name, value = nil) {
  //    static int available_settings[name] = value
  //  }

  //   void create_setting_accessors(name) {
  //    if ( [:installation_uuid].include?(name.to_sym)) { return ;}
  //    // Defines getter and setter for each setting
  //    // Then setting values can be read using: Setting.some_setting_name
  //    // or set using Setting.some_setting_name = "some value"
  //    src = <<-END_SRC
  //       void #{name}() {
  //        // when running too early, there is no settings table. do nothing
  //        if ( settings_table_exists_yet?) { self[:#{name}] ;}
  //      }

  //       void #{name}?() {
  //        // when running too early, there is no settings table. do nothing
  //        return unless settings_table_exists_yet?
  //        value = self[:#{name}]
  //        ActiveRecord::TypeN::Boolean.new.cast(value)
  //      }

  //       void #{name}=(value) {
  //        if ( settings_table_exists_yet?) {
  //          self[:#{name}] = value
  //        else
  //          logger.warn "Trying to save a setting named "#{name}" while there
  //          is no "setting" table yet. This setting will not be saved!" nil //
  //          when runnung too early, there is no settings table. do nothing
  //        }
  //      }
  //    END_SRC
  //    class_eval src, __FILE__, __LINE__
  //  }

  //  available_settings =
  //  YAML::load(File.open(Rails.root.join("config/settings.yml")))

  //  // Defines getter and setter for each setting
  //  // Then setting values can be read using: Setting.some_setting_name
  //  // or set using Setting.some_setting_name = "some value"
  //  available_settings.each { |name, _params|
  //    create_setting_accessors(name)
  //  }

  //  // validates_uniqueness_of :name
  //  // validates_inclusion_of :name, in: lambda { |_setting|
  //  available_settings.keys } // lambda, because this->available_settings
  //  changes at runtime
  //  // validates_numericality_of :value, only_integer: true, if (: Proc.new {
  //  |setting| available_settings[setting.name]["format"] == "int" }) {

  //   void value() {
  //    this->class.deserialize(name, read_attribute(:value))
  //  }

  //   void value=(v) {
  //    write_attribute(:value, formatted_value(v))
  //  }

  //   void formatted_value(value) {
  //    return value unless value.present?

  //    default = available_settings[name]

  //    if ( default["serialized"]) {
  //      return value.to_yaml
  //    }

  //    value.to_s
  //  }

  //  // Returns the value of the setting named name
  //   void [](name) {
  //    filtered_cached_or_default(name)
  //  }

  //   void []=(name, v) {
  //    old_setting = cached_or_default(name)
  //    new_setting = find_or_initialize_by(name: name)
  //    new_setting.value = v

  //    // Keep the current cache key,
  //    // since updated_on will change after .save
  //    old_cache_key = cache_key

  //    if ( new_setting.save) {
  //      new_value = new_setting.value

  //      // Delete the cache
  //      clear_cache(old_cache_key)

  //      // fire callbacks for name and pass as much information as possible
  //      fire_callbacks(name, new_value, old_setting)

  //      new_value
  //    else
  //      old_setting
  //    }
  //  }

  //  // Check whether a setting was defined
  //   void exists?(name) {
  //    available_settings.has_key?(name)
  //  }

  //   void installation_uuid() {
  //    if ( settings_table_exists_yet?) {
  //      // we avoid the default getters and setters since the cache messes
  //      things up setting = find_or_initialize_by(name: "installation_uuid")
  //      if ( setting.value.blank?) {
  //        setting.value = generate_installation_uuid
  //        setting.save!
  //      }
  //      setting.value
  //    else
  //      "unknown"
  //    }
  //  }

  //   void generate_installation_uuid() {
  //    if ( Rails.env.test?) {
  //      "test"
  //    else
  //      SecureRandom.uuid
  //    }
  //  }

  //  [:emails_header, :emails_footer].each { |mail|
  //    src = <<-END_SRC
  //     void localized_#{mail}() {
  //      I18n.fallbacks[I18n.locale].each { |lang|
  //        text = self[:#{mail}][lang.to_s]
  //        return text unless text.blank?
  //      }
  //      ""
  //    }
  //    END_SRC
  //    class_eval src, __FILE__, __LINE__
  //  }

  // Helper that returns an array based on per_page_options setting
  //   void per_page_options_array() {
  //    per_page_options
  //      .split(%r{[\s,]})
  //      .map(&:to_i)
  //      .select(&:positive?)
  //      .sort
  //  }

  //   void clear_cache(key = cache_key) {
  //    Rails.cache.delete(key)
  //    RequestStore.delete :cached_settings
  //    RequestStore.delete :settings_updated_on
  //  }

 private:
  // Returns the Setting instance for the setting named name
  // and allows to filter the returned value
  //   void filtered_cached_or_default(name) {
  //    name = name.to_s
  //    raise "There"s no setting named #{name}" unless exists? name

  //    value = cached_or_default(name)

  //    case name
  //    when "work_package_list_default_highlighting_mode"
  //      value = "none" unless EnterpriseToken.allows_to?
  //      :conditional_highlighting
  //    }

  //    value
  //  }

  // Returns the Setting instance for the setting named name
  // (record found in cache or default value)
  //   void cached_or_default(name) {
  //    name = name.to_s
  //    raise "There"s no setting named #{name}" unless exists? name

  //    value = cached_settings.fetch(name) {
  //    available_settings[name]["default"] } deserialize(name, value)
  //  }

  // Returns the settings from two levels of cache
  // 1. The current rack request using RequestStore
  // 2. Rails.cache serialized settings hash
  //
  // Unless one cache hits, it plucks from the database
  // Returns a hash of setting => (possibly serialized) value
  void cached_settings() {
    //    RequestStore.fetch(:cached_settings) {
    //      Rails.cache.fetch(cache_key) {
    //        Hash[Setting.pluck(:name, :value)]
    //      }
    //    }
  }

  void cache_key() {
    //    RequestStore.store[:settings_updated_on] ||=
    //    Setting.maximum(:updated_on) most_recent_settings_change =
    //    (RequestStore.store[:settings_updated_on] || Time.now.utc).to_i
    //    "/openproject/settings/all/#{most_recent_settings_change}"
  }

  //   void settings_table_exists_yet?() {
  //    // Check whether the settings table already exists. This makes plugins
  //    // patching core classes not break things when settings are accessed.
  //    // I"m not sure this is a good idea, but that"s the way it is right now,
  //    // and caching this improves performance significantly for actions
  //    // accessing settings a lot.
  //    this->settings_table_exists_yet ||=
  //    connection.data_source_exists?(table_name)
  //  }

  // Unserialize a serialized settings value
  //   void deserialize(name, v) {
  //    default = available_settings[name]

  //    if ( default["serialized"] && v.is_a?(String)) {
  //      YAML::load(v)
  //    } else if ( v.present?) {
  //      read_formatted_setting v, default["format"]
  //    else
  //      v
  //    }
  //  }

  //   void read_formatted_setting(value, format) {
  //    case format
  //    when "boolean"
  //      ActiveRecord::TypeN::Boolean.new.cast(value)
  //    when "symbol"
  //      value.to_sym
  //    when "int"
  //      value.to_i
  //    when "date"
  //      Date.parse value
  //    when "datetime"
  //      DateTime.parse value
  //    else
  //      value
  //    }
  //  }

  //  require_dependency "setting/callbacks"
  // extend Callbacks

  //  require_dependency "setting/aliases"
  // extend Aliases
};
}  // namespace models

}  // namespace openproj
