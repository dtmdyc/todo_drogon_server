// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: time/auth/user/logout/proto/auth_user_LogoutRequest.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_time_2fauth_2fuser_2flogout_2fproto_2fauth_5fuser_5fLogoutRequest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_time_2fauth_2fuser_2flogout_2fproto_2fauth_5fuser_5fLogoutRequest_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3010000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3010000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_time_2fauth_2fuser_2flogout_2fproto_2fauth_5fuser_5fLogoutRequest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_time_2fauth_2fuser_2flogout_2fproto_2fauth_5fuser_5fLogoutRequest_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_time_2fauth_2fuser_2flogout_2fproto_2fauth_5fuser_5fLogoutRequest_2eproto;
namespace timeservice {
class LogoutRequest;
class LogoutRequestDefaultTypeInternal;
extern LogoutRequestDefaultTypeInternal _LogoutRequest_default_instance_;
}  // namespace timeservice
PROTOBUF_NAMESPACE_OPEN
template<> ::timeservice::LogoutRequest* Arena::CreateMaybeMessage<::timeservice::LogoutRequest>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace timeservice {

// ===================================================================

class LogoutRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:timeservice.LogoutRequest) */ {
 public:
  LogoutRequest();
  virtual ~LogoutRequest();

  LogoutRequest(const LogoutRequest& from);
  LogoutRequest(LogoutRequest&& from) noexcept
    : LogoutRequest() {
    *this = ::std::move(from);
  }

  inline LogoutRequest& operator=(const LogoutRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline LogoutRequest& operator=(LogoutRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const LogoutRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LogoutRequest* internal_default_instance() {
    return reinterpret_cast<const LogoutRequest*>(
               &_LogoutRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(LogoutRequest& a, LogoutRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(LogoutRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline LogoutRequest* New() const final {
    return CreateMaybeMessage<LogoutRequest>(nullptr);
  }

  LogoutRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<LogoutRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const LogoutRequest& from);
  void MergeFrom(const LogoutRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LogoutRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "timeservice.LogoutRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_time_2fauth_2fuser_2flogout_2fproto_2fauth_5fuser_5fLogoutRequest_2eproto);
    return ::descriptor_table_time_2fauth_2fuser_2flogout_2fproto_2fauth_5fuser_5fLogoutRequest_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUseridFieldNumber = 1,
    kTokenFieldNumber = 2,
  };
  // string userid = 1;
  void clear_userid();
  const std::string& userid() const;
  void set_userid(const std::string& value);
  void set_userid(std::string&& value);
  void set_userid(const char* value);
  void set_userid(const char* value, size_t size);
  std::string* mutable_userid();
  std::string* release_userid();
  void set_allocated_userid(std::string* userid);
  private:
  const std::string& _internal_userid() const;
  void _internal_set_userid(const std::string& value);
  std::string* _internal_mutable_userid();
  public:

  // string token = 2;
  void clear_token();
  const std::string& token() const;
  void set_token(const std::string& value);
  void set_token(std::string&& value);
  void set_token(const char* value);
  void set_token(const char* value, size_t size);
  std::string* mutable_token();
  std::string* release_token();
  void set_allocated_token(std::string* token);
  private:
  const std::string& _internal_token() const;
  void _internal_set_token(const std::string& value);
  std::string* _internal_mutable_token();
  public:

  // @@protoc_insertion_point(class_scope:timeservice.LogoutRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr userid_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr token_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_time_2fauth_2fuser_2flogout_2fproto_2fauth_5fuser_5fLogoutRequest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// LogoutRequest

// string userid = 1;
inline void LogoutRequest::clear_userid() {
  userid_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& LogoutRequest::userid() const {
  // @@protoc_insertion_point(field_get:timeservice.LogoutRequest.userid)
  return _internal_userid();
}
inline void LogoutRequest::set_userid(const std::string& value) {
  _internal_set_userid(value);
  // @@protoc_insertion_point(field_set:timeservice.LogoutRequest.userid)
}
inline std::string* LogoutRequest::mutable_userid() {
  // @@protoc_insertion_point(field_mutable:timeservice.LogoutRequest.userid)
  return _internal_mutable_userid();
}
inline const std::string& LogoutRequest::_internal_userid() const {
  return userid_.GetNoArena();
}
inline void LogoutRequest::_internal_set_userid(const std::string& value) {
  
  userid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void LogoutRequest::set_userid(std::string&& value) {
  
  userid_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:timeservice.LogoutRequest.userid)
}
inline void LogoutRequest::set_userid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  userid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:timeservice.LogoutRequest.userid)
}
inline void LogoutRequest::set_userid(const char* value, size_t size) {
  
  userid_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:timeservice.LogoutRequest.userid)
}
inline std::string* LogoutRequest::_internal_mutable_userid() {
  
  return userid_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* LogoutRequest::release_userid() {
  // @@protoc_insertion_point(field_release:timeservice.LogoutRequest.userid)
  
  return userid_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void LogoutRequest::set_allocated_userid(std::string* userid) {
  if (userid != nullptr) {
    
  } else {
    
  }
  userid_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), userid);
  // @@protoc_insertion_point(field_set_allocated:timeservice.LogoutRequest.userid)
}

// string token = 2;
inline void LogoutRequest::clear_token() {
  token_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& LogoutRequest::token() const {
  // @@protoc_insertion_point(field_get:timeservice.LogoutRequest.token)
  return _internal_token();
}
inline void LogoutRequest::set_token(const std::string& value) {
  _internal_set_token(value);
  // @@protoc_insertion_point(field_set:timeservice.LogoutRequest.token)
}
inline std::string* LogoutRequest::mutable_token() {
  // @@protoc_insertion_point(field_mutable:timeservice.LogoutRequest.token)
  return _internal_mutable_token();
}
inline const std::string& LogoutRequest::_internal_token() const {
  return token_.GetNoArena();
}
inline void LogoutRequest::_internal_set_token(const std::string& value) {
  
  token_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void LogoutRequest::set_token(std::string&& value) {
  
  token_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:timeservice.LogoutRequest.token)
}
inline void LogoutRequest::set_token(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  token_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:timeservice.LogoutRequest.token)
}
inline void LogoutRequest::set_token(const char* value, size_t size) {
  
  token_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:timeservice.LogoutRequest.token)
}
inline std::string* LogoutRequest::_internal_mutable_token() {
  
  return token_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* LogoutRequest::release_token() {
  // @@protoc_insertion_point(field_release:timeservice.LogoutRequest.token)
  
  return token_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void LogoutRequest::set_allocated_token(std::string* token) {
  if (token != nullptr) {
    
  } else {
    
  }
  token_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), token);
  // @@protoc_insertion_point(field_set_allocated:timeservice.LogoutRequest.token)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace timeservice

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_time_2fauth_2fuser_2flogout_2fproto_2fauth_5fuser_5fLogoutRequest_2eproto
