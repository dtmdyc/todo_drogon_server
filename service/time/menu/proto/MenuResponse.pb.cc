// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: time/menu/proto/MenuResponse.proto

#include "time/menu/proto/MenuResponse.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace timeservice {
class MenuResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<MenuResponse> _instance;
} _MenuResponse_default_instance_;
}  // namespace timeservice
static void InitDefaultsscc_info_MenuResponse_time_2fmenu_2fproto_2fMenuResponse_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::timeservice::_MenuResponse_default_instance_;
    new (ptr) ::timeservice::MenuResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::timeservice::MenuResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_MenuResponse_time_2fmenu_2fproto_2fMenuResponse_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_MenuResponse_time_2fmenu_2fproto_2fMenuResponse_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_time_2fmenu_2fproto_2fMenuResponse_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_time_2fmenu_2fproto_2fMenuResponse_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_time_2fmenu_2fproto_2fMenuResponse_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_time_2fmenu_2fproto_2fMenuResponse_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::timeservice::MenuResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::timeservice::MenuResponse, name_),
  PROTOBUF_FIELD_OFFSET(::timeservice::MenuResponse, json_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::timeservice::MenuResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::timeservice::_MenuResponse_default_instance_),
};

const char descriptor_table_protodef_time_2fmenu_2fproto_2fMenuResponse_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\"time/menu/proto/MenuResponse.proto\022\013ti"
  "meservice\"*\n\014MenuResponse\022\014\n\004name\030\001 \001(\t\022"
  "\014\n\004json\030\002 \001(\tb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto_sccs[1] = {
  &scc_info_MenuResponse_time_2fmenu_2fproto_2fMenuResponse_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto_once;
static bool descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto = {
  &descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto_initialized, descriptor_table_protodef_time_2fmenu_2fproto_2fMenuResponse_2eproto, "time/menu/proto/MenuResponse.proto", 101,
  &descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto_once, descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto_sccs, descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_time_2fmenu_2fproto_2fMenuResponse_2eproto::offsets,
  file_level_metadata_time_2fmenu_2fproto_2fMenuResponse_2eproto, 1, file_level_enum_descriptors_time_2fmenu_2fproto_2fMenuResponse_2eproto, file_level_service_descriptors_time_2fmenu_2fproto_2fMenuResponse_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_time_2fmenu_2fproto_2fMenuResponse_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_time_2fmenu_2fproto_2fMenuResponse_2eproto), true);
namespace timeservice {

// ===================================================================

void MenuResponse::InitAsDefaultInstance() {
}
class MenuResponse::_Internal {
 public:
};

MenuResponse::MenuResponse()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:timeservice.MenuResponse)
}
MenuResponse::MenuResponse(const MenuResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  json_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_json().empty()) {
    json_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.json_);
  }
  // @@protoc_insertion_point(copy_constructor:timeservice.MenuResponse)
}

void MenuResponse::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_MenuResponse_time_2fmenu_2fproto_2fMenuResponse_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  json_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

MenuResponse::~MenuResponse() {
  // @@protoc_insertion_point(destructor:timeservice.MenuResponse)
  SharedDtor();
}

void MenuResponse::SharedDtor() {
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  json_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void MenuResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const MenuResponse& MenuResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_MenuResponse_time_2fmenu_2fproto_2fMenuResponse_2eproto.base);
  return *internal_default_instance();
}


void MenuResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:timeservice.MenuResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  json_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* MenuResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(_internal_mutable_name(), ptr, ctx, "timeservice.MenuResponse.name");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string json = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(_internal_mutable_json(), ptr, ctx, "timeservice.MenuResponse.json");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* MenuResponse::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:timeservice.MenuResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "timeservice.MenuResponse.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // string json = 2;
  if (this->json().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_json().data(), static_cast<int>(this->_internal_json().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "timeservice.MenuResponse.json");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_json(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:timeservice.MenuResponse)
  return target;
}

size_t MenuResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:timeservice.MenuResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string json = 2;
  if (this->json().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_json());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MenuResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:timeservice.MenuResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const MenuResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<MenuResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:timeservice.MenuResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:timeservice.MenuResponse)
    MergeFrom(*source);
  }
}

void MenuResponse::MergeFrom(const MenuResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:timeservice.MenuResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  if (from.json().size() > 0) {

    json_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.json_);
  }
}

void MenuResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:timeservice.MenuResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MenuResponse::CopyFrom(const MenuResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:timeservice.MenuResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MenuResponse::IsInitialized() const {
  return true;
}

void MenuResponse::InternalSwap(MenuResponse* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  json_.Swap(&other->json_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata MenuResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace timeservice
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::timeservice::MenuResponse* Arena::CreateMaybeMessage< ::timeservice::MenuResponse >(Arena* arena) {
  return Arena::CreateInternal< ::timeservice::MenuResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
