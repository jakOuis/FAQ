// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: faq_hook.proto
#include "pch.h"
#include "faq_hook.pb.h"

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
extern PROTOBUF_INTERNAL_EXPORT_faq_5fhook_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SQLiteField_faq_5fhook_2eproto;
namespace faq {
class SQLiteQueryStringDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SQLiteQueryString> _instance;
} _SQLiteQueryString_default_instance_;
class SQLiteQueryDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SQLiteQuery> _instance;
} _SQLiteQuery_default_instance_;
class SQLiteFieldDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SQLiteField> _instance;
} _SQLiteField_default_instance_;
}  // namespace faq
static void InitDefaultsscc_info_SQLiteField_faq_5fhook_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::faq::_SQLiteField_default_instance_;
    new (ptr) ::faq::SQLiteField();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SQLiteField_faq_5fhook_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_SQLiteField_faq_5fhook_2eproto}, {}};

static void InitDefaultsscc_info_SQLiteQuery_faq_5fhook_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::faq::_SQLiteQuery_default_instance_;
    new (ptr) ::faq::SQLiteQuery();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_SQLiteQuery_faq_5fhook_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_SQLiteQuery_faq_5fhook_2eproto}, {
      &scc_info_SQLiteField_faq_5fhook_2eproto.base,}};

static void InitDefaultsscc_info_SQLiteQueryString_faq_5fhook_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::faq::_SQLiteQueryString_default_instance_;
    new (ptr) ::faq::SQLiteQueryString();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SQLiteQueryString_faq_5fhook_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_SQLiteQueryString_faq_5fhook_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_faq_5fhook_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_faq_5fhook_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_faq_5fhook_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_faq_5fhook_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::faq::SQLiteQueryString, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::faq::SQLiteQueryString, sql_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::faq::SQLiteQuery, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::faq::SQLiteQuery, fields_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::faq::SQLiteField, _internal_metadata_),
  ~0u,  // no _extensions_
  PROTOBUF_FIELD_OFFSET(::faq::SQLiteField, _oneof_case_[0]),
  ~0u,  // no _weak_field_map_
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  ::PROTOBUF_NAMESPACE_ID::internal::kInvalidFieldOffsetTag,
  PROTOBUF_FIELD_OFFSET(::faq::SQLiteField, value_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::faq::SQLiteQueryString)},
  { 6, -1, sizeof(::faq::SQLiteQuery)},
  { 12, -1, sizeof(::faq::SQLiteField)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::faq::_SQLiteQueryString_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::faq::_SQLiteQuery_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::faq::_SQLiteField_default_instance_),
};

const char descriptor_table_protodef_faq_5fhook_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016faq_hook.proto\022\003faq\" \n\021SQLiteQueryStri"
  "ng\022\013\n\003sql\030\001 \001(\t\"/\n\013SQLiteQuery\022 \n\006fields"
  "\030\001 \003(\0132\020.faq.SQLiteField\"i\n\013SQLiteField\022"
  "\r\n\003int\030\001 \001(\005H\000\022\017\n\005int64\030\002 \001(\003H\000\022\020\n\006strin"
  "g\030\003 \001(\tH\000\022\016\n\004blog\030\004 \001(\014H\000\022\017\n\005float\030\005 \001(\002"
  "H\000B\007\n\005value2B\n\tFaQSQLite\0225\n\005Query\022\026.faq."
  "SQLiteQueryString\032\020.faq.SQLiteQuery\"\0000\001b"
  "\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_faq_5fhook_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_faq_5fhook_2eproto_sccs[3] = {
  &scc_info_SQLiteField_faq_5fhook_2eproto.base,
  &scc_info_SQLiteQuery_faq_5fhook_2eproto.base,
  &scc_info_SQLiteQueryString_faq_5fhook_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_faq_5fhook_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_faq_5fhook_2eproto = {
  false, false, descriptor_table_protodef_faq_5fhook_2eproto, "faq_hook.proto", 287,
  &descriptor_table_faq_5fhook_2eproto_once, descriptor_table_faq_5fhook_2eproto_sccs, descriptor_table_faq_5fhook_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_faq_5fhook_2eproto::offsets,
  file_level_metadata_faq_5fhook_2eproto, 3, file_level_enum_descriptors_faq_5fhook_2eproto, file_level_service_descriptors_faq_5fhook_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_faq_5fhook_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_faq_5fhook_2eproto)), true);
namespace faq {

// ===================================================================

class SQLiteQueryString::_Internal {
 public:
};

SQLiteQueryString::SQLiteQueryString(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:faq.SQLiteQueryString)
}
SQLiteQueryString::SQLiteQueryString(const SQLiteQueryString& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  sql_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_sql().empty()) {
    sql_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_sql(), 
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:faq.SQLiteQueryString)
}

void SQLiteQueryString::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_SQLiteQueryString_faq_5fhook_2eproto.base);
  sql_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

SQLiteQueryString::~SQLiteQueryString() {
  // @@protoc_insertion_point(destructor:faq.SQLiteQueryString)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SQLiteQueryString::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  sql_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void SQLiteQueryString::ArenaDtor(void* object) {
  SQLiteQueryString* _this = reinterpret_cast< SQLiteQueryString* >(object);
  (void)_this;
}
void SQLiteQueryString::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SQLiteQueryString::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const SQLiteQueryString& SQLiteQueryString::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SQLiteQueryString_faq_5fhook_2eproto.base);
  return *internal_default_instance();
}


void SQLiteQueryString::Clear() {
// @@protoc_insertion_point(message_clear_start:faq.SQLiteQueryString)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  sql_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SQLiteQueryString::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string sql = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_sql();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "faq.SQLiteQueryString.sql"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
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

::PROTOBUF_NAMESPACE_ID::uint8* SQLiteQueryString::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:faq.SQLiteQueryString)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string sql = 1;
  if (this->sql().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_sql().data(), static_cast<int>(this->_internal_sql().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "faq.SQLiteQueryString.sql");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_sql(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:faq.SQLiteQueryString)
  return target;
}

size_t SQLiteQueryString::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:faq.SQLiteQueryString)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string sql = 1;
  if (this->sql().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_sql());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SQLiteQueryString::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:faq.SQLiteQueryString)
  GOOGLE_DCHECK_NE(&from, this);
  const SQLiteQueryString* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SQLiteQueryString>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:faq.SQLiteQueryString)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:faq.SQLiteQueryString)
    MergeFrom(*source);
  }
}

void SQLiteQueryString::MergeFrom(const SQLiteQueryString& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:faq.SQLiteQueryString)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.sql().size() > 0) {
    _internal_set_sql(from._internal_sql());
  }
}

void SQLiteQueryString::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:faq.SQLiteQueryString)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SQLiteQueryString::CopyFrom(const SQLiteQueryString& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:faq.SQLiteQueryString)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SQLiteQueryString::IsInitialized() const {
  return true;
}

void SQLiteQueryString::InternalSwap(SQLiteQueryString* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  sql_.Swap(&other->sql_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata SQLiteQueryString::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class SQLiteQuery::_Internal {
 public:
};

SQLiteQuery::SQLiteQuery(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  fields_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:faq.SQLiteQuery)
}
SQLiteQuery::SQLiteQuery(const SQLiteQuery& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      fields_(from.fields_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:faq.SQLiteQuery)
}

void SQLiteQuery::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_SQLiteQuery_faq_5fhook_2eproto.base);
}

SQLiteQuery::~SQLiteQuery() {
  // @@protoc_insertion_point(destructor:faq.SQLiteQuery)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SQLiteQuery::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void SQLiteQuery::ArenaDtor(void* object) {
  SQLiteQuery* _this = reinterpret_cast< SQLiteQuery* >(object);
  (void)_this;
}
void SQLiteQuery::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SQLiteQuery::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const SQLiteQuery& SQLiteQuery::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SQLiteQuery_faq_5fhook_2eproto.base);
  return *internal_default_instance();
}


void SQLiteQuery::Clear() {
// @@protoc_insertion_point(message_clear_start:faq.SQLiteQuery)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  fields_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SQLiteQuery::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // repeated .faq.SQLiteField fields = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_fields(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
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

::PROTOBUF_NAMESPACE_ID::uint8* SQLiteQuery::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:faq.SQLiteQuery)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .faq.SQLiteField fields = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_fields_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, this->_internal_fields(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:faq.SQLiteQuery)
  return target;
}

size_t SQLiteQuery::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:faq.SQLiteQuery)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .faq.SQLiteField fields = 1;
  total_size += 1UL * this->_internal_fields_size();
  for (const auto& msg : this->fields_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SQLiteQuery::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:faq.SQLiteQuery)
  GOOGLE_DCHECK_NE(&from, this);
  const SQLiteQuery* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SQLiteQuery>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:faq.SQLiteQuery)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:faq.SQLiteQuery)
    MergeFrom(*source);
  }
}

void SQLiteQuery::MergeFrom(const SQLiteQuery& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:faq.SQLiteQuery)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  fields_.MergeFrom(from.fields_);
}

void SQLiteQuery::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:faq.SQLiteQuery)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SQLiteQuery::CopyFrom(const SQLiteQuery& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:faq.SQLiteQuery)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SQLiteQuery::IsInitialized() const {
  return true;
}

void SQLiteQuery::InternalSwap(SQLiteQuery* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  fields_.InternalSwap(&other->fields_);
}

::PROTOBUF_NAMESPACE_ID::Metadata SQLiteQuery::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

class SQLiteField::_Internal {
 public:
};

SQLiteField::SQLiteField(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:faq.SQLiteField)
}
SQLiteField::SQLiteField(const SQLiteField& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  clear_has_value();
  switch (from.value_case()) {
    case kInt: {
      _internal_set_int_(from._internal_int_());
      break;
    }
    case kInt64: {
      _internal_set_int64(from._internal_int64());
      break;
    }
    case kString: {
      _internal_set_string(from._internal_string());
      break;
    }
    case kBlog: {
      _internal_set_blog(from._internal_blog());
      break;
    }
    case kFloat: {
      _internal_set_float_(from._internal_float_());
      break;
    }
    case VALUE_NOT_SET: {
      break;
    }
  }
  // @@protoc_insertion_point(copy_constructor:faq.SQLiteField)
}

void SQLiteField::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_SQLiteField_faq_5fhook_2eproto.base);
  clear_has_value();
}

SQLiteField::~SQLiteField() {
  // @@protoc_insertion_point(destructor:faq.SQLiteField)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void SQLiteField::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (has_value()) {
    clear_value();
  }
}

void SQLiteField::ArenaDtor(void* object) {
  SQLiteField* _this = reinterpret_cast< SQLiteField* >(object);
  (void)_this;
}
void SQLiteField::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void SQLiteField::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const SQLiteField& SQLiteField::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SQLiteField_faq_5fhook_2eproto.base);
  return *internal_default_instance();
}


void SQLiteField::clear_value() {
// @@protoc_insertion_point(one_of_clear_start:faq.SQLiteField)
  switch (value_case()) {
    case kInt: {
      // No need to clear
      break;
    }
    case kInt64: {
      // No need to clear
      break;
    }
    case kString: {
      value_.string_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
      break;
    }
    case kBlog: {
      value_.blog_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
      break;
    }
    case kFloat: {
      // No need to clear
      break;
    }
    case VALUE_NOT_SET: {
      break;
    }
  }
  _oneof_case_[0] = VALUE_NOT_SET;
}


void SQLiteField::Clear() {
// @@protoc_insertion_point(message_clear_start:faq.SQLiteField)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  clear_value();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* SQLiteField::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 int = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _internal_set_int_(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int64 int64 = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          _internal_set_int64(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string string = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_string();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "faq.SQLiteField.string"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bytes blog = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 34)) {
          auto str = _internal_mutable_blog();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // float float = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 45)) {
          _internal_set_float_(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr));
          ptr += sizeof(float);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
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

::PROTOBUF_NAMESPACE_ID::uint8* SQLiteField::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:faq.SQLiteField)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 int = 1;
  if (_internal_has_int_()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_int_(), target);
  }

  // int64 int64 = 2;
  if (_internal_has_int64()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(2, this->_internal_int64(), target);
  }

  // string string = 3;
  if (_internal_has_string()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_string().data(), static_cast<int>(this->_internal_string().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "faq.SQLiteField.string");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_string(), target);
  }

  // bytes blog = 4;
  if (_internal_has_blog()) {
    target = stream->WriteBytesMaybeAliased(
        4, this->_internal_blog(), target);
  }

  // float float = 5;
  if (_internal_has_float_()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFloatToArray(5, this->_internal_float_(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:faq.SQLiteField)
  return target;
}

size_t SQLiteField::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:faq.SQLiteField)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  switch (value_case()) {
    // int32 int = 1;
    case kInt: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
          this->_internal_int_());
      break;
    }
    // int64 int64 = 2;
    case kInt64: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
          this->_internal_int64());
      break;
    }
    // string string = 3;
    case kString: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
          this->_internal_string());
      break;
    }
    // bytes blog = 4;
    case kBlog: {
      total_size += 1 +
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
          this->_internal_blog());
      break;
    }
    // float float = 5;
    case kFloat: {
      total_size += 1 + 4;
      break;
    }
    case VALUE_NOT_SET: {
      break;
    }
  }
  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void SQLiteField::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:faq.SQLiteField)
  GOOGLE_DCHECK_NE(&from, this);
  const SQLiteField* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SQLiteField>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:faq.SQLiteField)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:faq.SQLiteField)
    MergeFrom(*source);
  }
}

void SQLiteField::MergeFrom(const SQLiteField& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:faq.SQLiteField)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  switch (from.value_case()) {
    case kInt: {
      _internal_set_int_(from._internal_int_());
      break;
    }
    case kInt64: {
      _internal_set_int64(from._internal_int64());
      break;
    }
    case kString: {
      _internal_set_string(from._internal_string());
      break;
    }
    case kBlog: {
      _internal_set_blog(from._internal_blog());
      break;
    }
    case kFloat: {
      _internal_set_float_(from._internal_float_());
      break;
    }
    case VALUE_NOT_SET: {
      break;
    }
  }
}

void SQLiteField::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:faq.SQLiteField)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SQLiteField::CopyFrom(const SQLiteField& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:faq.SQLiteField)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SQLiteField::IsInitialized() const {
  return true;
}

void SQLiteField::InternalSwap(SQLiteField* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(value_, other->value_);
  swap(_oneof_case_[0], other->_oneof_case_[0]);
}

::PROTOBUF_NAMESPACE_ID::Metadata SQLiteField::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace faq
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::faq::SQLiteQueryString* Arena::CreateMaybeMessage< ::faq::SQLiteQueryString >(Arena* arena) {
  return Arena::CreateMessageInternal< ::faq::SQLiteQueryString >(arena);
}
template<> PROTOBUF_NOINLINE ::faq::SQLiteQuery* Arena::CreateMaybeMessage< ::faq::SQLiteQuery >(Arena* arena) {
  return Arena::CreateMessageInternal< ::faq::SQLiteQuery >(arena);
}
template<> PROTOBUF_NOINLINE ::faq::SQLiteField* Arena::CreateMaybeMessage< ::faq::SQLiteField >(Arena* arena) {
  return Arena::CreateMessageInternal< ::faq::SQLiteField >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
