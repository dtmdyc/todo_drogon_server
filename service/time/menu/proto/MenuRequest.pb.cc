// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: time/menu/proto/MenuRequest.proto

#include "time/menu/proto/MenuRequest.pb.h"

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
class MenuRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<MenuRequest> _instance;
} _MenuRequest_default_instance_;
}  // namespace timeservice
static void InitDefaultsscc_info_MenuRequest_time_2fmenu_2fproto_2fMenuRequest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::timeservice::_MenuRequest_default_instance_;
    new (ptr) ::timeservice::MenuRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::timeservice::MenuRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_MenuRequest_time_2fmenu_2fproto_2fMenuRequest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_MenuRequest_time_2fmenu_2fproto_2fMenuRequest_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_time_2fmenu_2fproto_2fMenuRequest_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_time_2fmenu_2fproto_2fMenuRequest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_time_2fmenu_2fproto_2fMenuRequest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_time_2fmenu_2fproto_2fMenuRequest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::timeservice::MenuRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::timeservice::MenuRequest, name_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::timeservice::MenuRequest)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::timeservice::_MenuRequest_default_instance_),
};

const char descriptor_table_protodef_time_2fmenu_2fproto_2fMenuRequest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n!time/menu/proto/MenuRequest.proto\022\013tim"
  "eservice\"\033\n\013MenuRequest\022\014\n\004name\030\001 \001(\tb\006p"
  "roto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto_sccs[1] = {
  &scc_info_MenuRequest_time_2fmenu_2fproto_2fMenuRequest_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto_once;
static bool descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto = {
  &descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto_initialized, descriptor_table_protodef_time_2fmenu_2fproto_2fMenuRequest_2eproto, "time/menu/proto/MenuRequest.proto", 85,
  &descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto_once, descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto_sccs, descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_time_2fmenu_2fproto_2fMenuRequest_2eproto::offsets,
  file_level_metadata_time_2fmenu_2fproto_2fMenuRequest_2eproto, 1, file_level_enum_descriptors_time_2fmenu_2fproto_2fMenuRequest_2eproto, file_level_service_descriptors_time_2fmenu_2fproto_2fMenuRequest_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_time_2fmenu_2fproto_2fMenuRequest_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_time_2fmenu_2fproto_2fMenuRequest_2eproto), true);
namespace timeservice {

// ===================================================================

void MenuRequest::InitAsDefaultInstance() {
}
class MenuRequest::_Internal {
 public:
};

MenuRequest::MenuRequest()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:timeservice.MenuRequest)
}
MenuRequest::MenuRequest(const MenuRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
  // @@protoc_insertion_point(copy_constructor:timeservice.MenuRequest)
}

void MenuRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_MenuRequest_time_2fmenu_2fproto_2fMenuRequest_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

MenuRequest::~MenuRequest() {
  // @@protoc_insertion_point(destructor:timeservice.MenuRequest)
  SharedDtor();
}

void MenuRequest::SharedDtor() {
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void MenuRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const MenuRequest& MenuRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_MenuRequest_time_2fmenu_2fproto_2fMenuRequest_2eproto.base);
  return *internal_default_instance();
}


void MenuRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:timeservice.MenuRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

const char* MenuRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(_internal_mutable_name(), ptr, ctx, "timeservice.MenuRequest.name");
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

::PROTOBUF_NAMESPACE_ID::uint8* MenuRequest::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:timeservice.MenuRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "timeservice.MenuRequest.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:timeservice.MenuRequest)
  return target;
}

size_t MenuRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:timeservice.MenuRequest)
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

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MenuRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:timeservice.MenuRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const MenuRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<MenuRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:timeservice.MenuRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:timeservice.MenuRequest)
    MergeFrom(*source);
  }
}

void MenuRequest::MergeFrom(const MenuRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:timeservice.MenuRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {

    name_.AssignWithDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.name_);
  }
}

void MenuRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:timeservice.MenuRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MenuRequest::CopyFrom(const MenuRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:timeservice.MenuRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MenuRequest::IsInitialized() const {
  return true;
}

void MenuRequest::InternalSwap(MenuRequest* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata MenuRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace timeservice
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::timeservice::MenuRequest* Arena::CreateMaybeMessage< ::timeservice::MenuRequest >(Arena* arena) {
  return Arena::CreateInternal< ::timeservice::MenuRequest >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>