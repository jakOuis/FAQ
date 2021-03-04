// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: faq_hook.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_faq_5fhook_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_faq_5fhook_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_faq_5fhook_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_faq_5fhook_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_faq_5fhook_2eproto;
namespace faq {
class SQLiteField;
class SQLiteFieldDefaultTypeInternal;
extern SQLiteFieldDefaultTypeInternal _SQLiteField_default_instance_;
class SQLiteQuery;
class SQLiteQueryDefaultTypeInternal;
extern SQLiteQueryDefaultTypeInternal _SQLiteQuery_default_instance_;
class SQLiteQueryString;
class SQLiteQueryStringDefaultTypeInternal;
extern SQLiteQueryStringDefaultTypeInternal _SQLiteQueryString_default_instance_;
}  // namespace faq
PROTOBUF_NAMESPACE_OPEN
template<> ::faq::SQLiteField* Arena::CreateMaybeMessage<::faq::SQLiteField>(Arena*);
template<> ::faq::SQLiteQuery* Arena::CreateMaybeMessage<::faq::SQLiteQuery>(Arena*);
template<> ::faq::SQLiteQueryString* Arena::CreateMaybeMessage<::faq::SQLiteQueryString>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace faq {

// ===================================================================

class SQLiteQueryString PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:faq.SQLiteQueryString) */ {
 public:
  inline SQLiteQueryString() : SQLiteQueryString(nullptr) {}
  virtual ~SQLiteQueryString();

  SQLiteQueryString(const SQLiteQueryString& from);
  SQLiteQueryString(SQLiteQueryString&& from) noexcept
    : SQLiteQueryString() {
    *this = ::std::move(from);
  }

  inline SQLiteQueryString& operator=(const SQLiteQueryString& from) {
    CopyFrom(from);
    return *this;
  }
  inline SQLiteQueryString& operator=(SQLiteQueryString&& from) noexcept {
    if (GetArena() == from.GetArena()) {
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
  static const SQLiteQueryString& default_instance();

  static inline const SQLiteQueryString* internal_default_instance() {
    return reinterpret_cast<const SQLiteQueryString*>(
               &_SQLiteQueryString_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SQLiteQueryString& a, SQLiteQueryString& b) {
    a.Swap(&b);
  }
  inline void Swap(SQLiteQueryString* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SQLiteQueryString* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SQLiteQueryString* New() const final {
    return CreateMaybeMessage<SQLiteQueryString>(nullptr);
  }

  SQLiteQueryString* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SQLiteQueryString>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SQLiteQueryString& from);
  void MergeFrom(const SQLiteQueryString& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SQLiteQueryString* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "faq.SQLiteQueryString";
  }
  protected:
  explicit SQLiteQueryString(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_faq_5fhook_2eproto);
    return ::descriptor_table_faq_5fhook_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSqlFieldNumber = 1,
  };
  // string sql = 1;
  void clear_sql();
  const std::string& sql() const;
  void set_sql(const std::string& value);
  void set_sql(std::string&& value);
  void set_sql(const char* value);
  void set_sql(const char* value, size_t size);
  std::string* mutable_sql();
  std::string* release_sql();
  void set_allocated_sql(std::string* sql);
  private:
  const std::string& _internal_sql() const;
  void _internal_set_sql(const std::string& value);
  std::string* _internal_mutable_sql();
  public:

  // @@protoc_insertion_point(class_scope:faq.SQLiteQueryString)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sql_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_faq_5fhook_2eproto;
};
// -------------------------------------------------------------------

class SQLiteQuery PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:faq.SQLiteQuery) */ {
 public:
  inline SQLiteQuery() : SQLiteQuery(nullptr) {}
  virtual ~SQLiteQuery();

  SQLiteQuery(const SQLiteQuery& from);
  SQLiteQuery(SQLiteQuery&& from) noexcept
    : SQLiteQuery() {
    *this = ::std::move(from);
  }

  inline SQLiteQuery& operator=(const SQLiteQuery& from) {
    CopyFrom(from);
    return *this;
  }
  inline SQLiteQuery& operator=(SQLiteQuery&& from) noexcept {
    if (GetArena() == from.GetArena()) {
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
  static const SQLiteQuery& default_instance();

  static inline const SQLiteQuery* internal_default_instance() {
    return reinterpret_cast<const SQLiteQuery*>(
               &_SQLiteQuery_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(SQLiteQuery& a, SQLiteQuery& b) {
    a.Swap(&b);
  }
  inline void Swap(SQLiteQuery* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SQLiteQuery* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SQLiteQuery* New() const final {
    return CreateMaybeMessage<SQLiteQuery>(nullptr);
  }

  SQLiteQuery* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SQLiteQuery>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SQLiteQuery& from);
  void MergeFrom(const SQLiteQuery& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SQLiteQuery* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "faq.SQLiteQuery";
  }
  protected:
  explicit SQLiteQuery(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_faq_5fhook_2eproto);
    return ::descriptor_table_faq_5fhook_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFieldsFieldNumber = 1,
  };
  // repeated .faq.SQLiteField fields = 1;
  int fields_size() const;
  private:
  int _internal_fields_size() const;
  public:
  void clear_fields();
  ::faq::SQLiteField* mutable_fields(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::faq::SQLiteField >*
      mutable_fields();
  private:
  const ::faq::SQLiteField& _internal_fields(int index) const;
  ::faq::SQLiteField* _internal_add_fields();
  public:
  const ::faq::SQLiteField& fields(int index) const;
  ::faq::SQLiteField* add_fields();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::faq::SQLiteField >&
      fields() const;

  // @@protoc_insertion_point(class_scope:faq.SQLiteQuery)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::faq::SQLiteField > fields_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_faq_5fhook_2eproto;
};
// -------------------------------------------------------------------

class SQLiteField PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:faq.SQLiteField) */ {
 public:
  inline SQLiteField() : SQLiteField(nullptr) {}
  virtual ~SQLiteField();

  SQLiteField(const SQLiteField& from);
  SQLiteField(SQLiteField&& from) noexcept
    : SQLiteField() {
    *this = ::std::move(from);
  }

  inline SQLiteField& operator=(const SQLiteField& from) {
    CopyFrom(from);
    return *this;
  }
  inline SQLiteField& operator=(SQLiteField&& from) noexcept {
    if (GetArena() == from.GetArena()) {
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
  static const SQLiteField& default_instance();

  enum ValueCase {
    kInt = 1,
    kInt64 = 2,
    kString = 3,
    kBlog = 4,
    kFloat = 5,
    VALUE_NOT_SET = 0,
  };

  static inline const SQLiteField* internal_default_instance() {
    return reinterpret_cast<const SQLiteField*>(
               &_SQLiteField_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(SQLiteField& a, SQLiteField& b) {
    a.Swap(&b);
  }
  inline void Swap(SQLiteField* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SQLiteField* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SQLiteField* New() const final {
    return CreateMaybeMessage<SQLiteField>(nullptr);
  }

  SQLiteField* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SQLiteField>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SQLiteField& from);
  void MergeFrom(const SQLiteField& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(SQLiteField* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "faq.SQLiteField";
  }
  protected:
  explicit SQLiteField(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_faq_5fhook_2eproto);
    return ::descriptor_table_faq_5fhook_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIntFieldNumber = 1,
    kInt64FieldNumber = 2,
    kStringFieldNumber = 3,
    kBlogFieldNumber = 4,
    kFloatFieldNumber = 5,
  };
  // int32 int = 1;
  private:
  bool _internal_has_int_() const;
  public:
  void clear_int_();
  ::PROTOBUF_NAMESPACE_ID::int32 int_() const;
  void set_int_(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_int_() const;
  void _internal_set_int_(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int64 int64 = 2;
  private:
  bool _internal_has_int64() const;
  public:
  void clear_int64();
  ::PROTOBUF_NAMESPACE_ID::int64 int64() const;
  void set_int64(::PROTOBUF_NAMESPACE_ID::int64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int64 _internal_int64() const;
  void _internal_set_int64(::PROTOBUF_NAMESPACE_ID::int64 value);
  public:

  // string string = 3;
  private:
  bool _internal_has_string() const;
  public:
  void clear_string();
  const std::string& string() const;
  void set_string(const std::string& value);
  void set_string(std::string&& value);
  void set_string(const char* value);
  void set_string(const char* value, size_t size);
  std::string* mutable_string();
  std::string* release_string();
  void set_allocated_string(std::string* string);
  private:
  const std::string& _internal_string() const;
  void _internal_set_string(const std::string& value);
  std::string* _internal_mutable_string();
  public:

  // bytes blog = 4;
  private:
  bool _internal_has_blog() const;
  public:
  void clear_blog();
  const std::string& blog() const;
  void set_blog(const std::string& value);
  void set_blog(std::string&& value);
  void set_blog(const char* value);
  void set_blog(const void* value, size_t size);
  std::string* mutable_blog();
  std::string* release_blog();
  void set_allocated_blog(std::string* blog);
  private:
  const std::string& _internal_blog() const;
  void _internal_set_blog(const std::string& value);
  std::string* _internal_mutable_blog();
  public:

  // float float = 5;
  private:
  bool _internal_has_float_() const;
  public:
  void clear_float_();
  float float_() const;
  void set_float_(float value);
  private:
  float _internal_float_() const;
  void _internal_set_float_(float value);
  public:

  void clear_value();
  ValueCase value_case() const;
  // @@protoc_insertion_point(class_scope:faq.SQLiteField)
 private:
  class _Internal;
  void set_has_int_();
  void set_has_int64();
  void set_has_string();
  void set_has_blog();
  void set_has_float_();

  inline bool has_value() const;
  inline void clear_has_value();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  union ValueUnion {
    ValueUnion() {}
    ::PROTOBUF_NAMESPACE_ID::int32 int__;
    ::PROTOBUF_NAMESPACE_ID::int64 int64_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr string_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr blog_;
    float float__;
  } value_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_faq_5fhook_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SQLiteQueryString

// string sql = 1;
inline void SQLiteQueryString::clear_sql() {
  sql_.ClearToEmpty();
}
inline const std::string& SQLiteQueryString::sql() const {
  // @@protoc_insertion_point(field_get:faq.SQLiteQueryString.sql)
  return _internal_sql();
}
inline void SQLiteQueryString::set_sql(const std::string& value) {
  _internal_set_sql(value);
  // @@protoc_insertion_point(field_set:faq.SQLiteQueryString.sql)
}
inline std::string* SQLiteQueryString::mutable_sql() {
  // @@protoc_insertion_point(field_mutable:faq.SQLiteQueryString.sql)
  return _internal_mutable_sql();
}
inline const std::string& SQLiteQueryString::_internal_sql() const {
  return sql_.Get();
}
inline void SQLiteQueryString::_internal_set_sql(const std::string& value) {
  
  sql_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SQLiteQueryString::set_sql(std::string&& value) {
  
  sql_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:faq.SQLiteQueryString.sql)
}
inline void SQLiteQueryString::set_sql(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  sql_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:faq.SQLiteQueryString.sql)
}
inline void SQLiteQueryString::set_sql(const char* value,
    size_t size) {
  
  sql_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:faq.SQLiteQueryString.sql)
}
inline std::string* SQLiteQueryString::_internal_mutable_sql() {
  
  return sql_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SQLiteQueryString::release_sql() {
  // @@protoc_insertion_point(field_release:faq.SQLiteQueryString.sql)
  return sql_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SQLiteQueryString::set_allocated_sql(std::string* sql) {
  if (sql != nullptr) {
    
  } else {
    
  }
  sql_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sql,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:faq.SQLiteQueryString.sql)
}

// -------------------------------------------------------------------

// SQLiteQuery

// repeated .faq.SQLiteField fields = 1;
inline int SQLiteQuery::_internal_fields_size() const {
  return fields_.size();
}
inline int SQLiteQuery::fields_size() const {
  return _internal_fields_size();
}
inline void SQLiteQuery::clear_fields() {
  fields_.Clear();
}
inline ::faq::SQLiteField* SQLiteQuery::mutable_fields(int index) {
  // @@protoc_insertion_point(field_mutable:faq.SQLiteQuery.fields)
  return fields_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::faq::SQLiteField >*
SQLiteQuery::mutable_fields() {
  // @@protoc_insertion_point(field_mutable_list:faq.SQLiteQuery.fields)
  return &fields_;
}
inline const ::faq::SQLiteField& SQLiteQuery::_internal_fields(int index) const {
  return fields_.Get(index);
}
inline const ::faq::SQLiteField& SQLiteQuery::fields(int index) const {
  // @@protoc_insertion_point(field_get:faq.SQLiteQuery.fields)
  return _internal_fields(index);
}
inline ::faq::SQLiteField* SQLiteQuery::_internal_add_fields() {
  return fields_.Add();
}
inline ::faq::SQLiteField* SQLiteQuery::add_fields() {
  // @@protoc_insertion_point(field_add:faq.SQLiteQuery.fields)
  return _internal_add_fields();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::faq::SQLiteField >&
SQLiteQuery::fields() const {
  // @@protoc_insertion_point(field_list:faq.SQLiteQuery.fields)
  return fields_;
}

// -------------------------------------------------------------------

// SQLiteField

// int32 int = 1;
inline bool SQLiteField::_internal_has_int_() const {
  return value_case() == kInt;
}
inline void SQLiteField::set_has_int_() {
  _oneof_case_[0] = kInt;
}
inline void SQLiteField::clear_int_() {
  if (_internal_has_int_()) {
    value_.int__ = 0;
    clear_has_value();
  }
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SQLiteField::_internal_int_() const {
  if (_internal_has_int_()) {
    return value_.int__;
  }
  return 0;
}
inline void SQLiteField::_internal_set_int_(::PROTOBUF_NAMESPACE_ID::int32 value) {
  if (!_internal_has_int_()) {
    clear_value();
    set_has_int_();
  }
  value_.int__ = value;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SQLiteField::int_() const {
  // @@protoc_insertion_point(field_get:faq.SQLiteField.int)
  return _internal_int_();
}
inline void SQLiteField::set_int_(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_int_(value);
  // @@protoc_insertion_point(field_set:faq.SQLiteField.int)
}

// int64 int64 = 2;
inline bool SQLiteField::_internal_has_int64() const {
  return value_case() == kInt64;
}
inline void SQLiteField::set_has_int64() {
  _oneof_case_[0] = kInt64;
}
inline void SQLiteField::clear_int64() {
  if (_internal_has_int64()) {
    value_.int64_ = PROTOBUF_LONGLONG(0);
    clear_has_value();
  }
}
inline ::PROTOBUF_NAMESPACE_ID::int64 SQLiteField::_internal_int64() const {
  if (_internal_has_int64()) {
    return value_.int64_;
  }
  return PROTOBUF_LONGLONG(0);
}
inline void SQLiteField::_internal_set_int64(::PROTOBUF_NAMESPACE_ID::int64 value) {
  if (!_internal_has_int64()) {
    clear_value();
    set_has_int64();
  }
  value_.int64_ = value;
}
inline ::PROTOBUF_NAMESPACE_ID::int64 SQLiteField::int64() const {
  // @@protoc_insertion_point(field_get:faq.SQLiteField.int64)
  return _internal_int64();
}
inline void SQLiteField::set_int64(::PROTOBUF_NAMESPACE_ID::int64 value) {
  _internal_set_int64(value);
  // @@protoc_insertion_point(field_set:faq.SQLiteField.int64)
}

// string string = 3;
inline bool SQLiteField::_internal_has_string() const {
  return value_case() == kString;
}
inline void SQLiteField::set_has_string() {
  _oneof_case_[0] = kString;
}
inline void SQLiteField::clear_string() {
  if (_internal_has_string()) {
    value_.string_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
    clear_has_value();
  }
}
inline const std::string& SQLiteField::string() const {
  // @@protoc_insertion_point(field_get:faq.SQLiteField.string)
  return _internal_string();
}
inline void SQLiteField::set_string(const std::string& value) {
  _internal_set_string(value);
  // @@protoc_insertion_point(field_set:faq.SQLiteField.string)
}
inline std::string* SQLiteField::mutable_string() {
  // @@protoc_insertion_point(field_mutable:faq.SQLiteField.string)
  return _internal_mutable_string();
}
inline const std::string& SQLiteField::_internal_string() const {
  if (_internal_has_string()) {
    return value_.string_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void SQLiteField::_internal_set_string(const std::string& value) {
  if (!_internal_has_string()) {
    clear_value();
    set_has_string();
    value_.string_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.string_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SQLiteField::set_string(std::string&& value) {
  // @@protoc_insertion_point(field_set:faq.SQLiteField.string)
  if (!_internal_has_string()) {
    clear_value();
    set_has_string();
    value_.string_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.string_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:faq.SQLiteField.string)
}
inline void SQLiteField::set_string(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  if (!_internal_has_string()) {
    clear_value();
    set_has_string();
    value_.string_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.string_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{},
      ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:faq.SQLiteField.string)
}
inline void SQLiteField::set_string(const char* value,
                             size_t size) {
  if (!_internal_has_string()) {
    clear_value();
    set_has_string();
    value_.string_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.string_.Set(
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size),
      GetArena());
  // @@protoc_insertion_point(field_set_pointer:faq.SQLiteField.string)
}
inline std::string* SQLiteField::_internal_mutable_string() {
  if (!_internal_has_string()) {
    clear_value();
    set_has_string();
    value_.string_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  return value_.string_.Mutable(
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SQLiteField::release_string() {
  // @@protoc_insertion_point(field_release:faq.SQLiteField.string)
  if (_internal_has_string()) {
    clear_has_value();
    return value_.string_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  } else {
    return nullptr;
  }
}
inline void SQLiteField::set_allocated_string(std::string* string) {
  if (has_value()) {
    clear_value();
  }
  if (string != nullptr) {
    set_has_string();
    value_.string_.UnsafeSetDefault(string);
    ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena();
    if (arena != nullptr) {
      arena->Own(string);
    }
  }
  // @@protoc_insertion_point(field_set_allocated:faq.SQLiteField.string)
}

// bytes blog = 4;
inline bool SQLiteField::_internal_has_blog() const {
  return value_case() == kBlog;
}
inline void SQLiteField::set_has_blog() {
  _oneof_case_[0] = kBlog;
}
inline void SQLiteField::clear_blog() {
  if (_internal_has_blog()) {
    value_.blog_.Destroy(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
    clear_has_value();
  }
}
inline const std::string& SQLiteField::blog() const {
  // @@protoc_insertion_point(field_get:faq.SQLiteField.blog)
  return _internal_blog();
}
inline void SQLiteField::set_blog(const std::string& value) {
  _internal_set_blog(value);
  // @@protoc_insertion_point(field_set:faq.SQLiteField.blog)
}
inline std::string* SQLiteField::mutable_blog() {
  // @@protoc_insertion_point(field_mutable:faq.SQLiteField.blog)
  return _internal_mutable_blog();
}
inline const std::string& SQLiteField::_internal_blog() const {
  if (_internal_has_blog()) {
    return value_.blog_.Get();
  }
  return ::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void SQLiteField::_internal_set_blog(const std::string& value) {
  if (!_internal_has_blog()) {
    clear_value();
    set_has_blog();
    value_.blog_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.blog_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void SQLiteField::set_blog(std::string&& value) {
  // @@protoc_insertion_point(field_set:faq.SQLiteField.blog)
  if (!_internal_has_blog()) {
    clear_value();
    set_has_blog();
    value_.blog_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.blog_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:faq.SQLiteField.blog)
}
inline void SQLiteField::set_blog(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  if (!_internal_has_blog()) {
    clear_value();
    set_has_blog();
    value_.blog_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.blog_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{},
      ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:faq.SQLiteField.blog)
}
inline void SQLiteField::set_blog(const void* value,
                             size_t size) {
  if (!_internal_has_blog()) {
    clear_value();
    set_has_blog();
    value_.blog_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  value_.blog_.Set(
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size),
      GetArena());
  // @@protoc_insertion_point(field_set_pointer:faq.SQLiteField.blog)
}
inline std::string* SQLiteField::_internal_mutable_blog() {
  if (!_internal_has_blog()) {
    clear_value();
    set_has_blog();
    value_.blog_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  return value_.blog_.Mutable(
      ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* SQLiteField::release_blog() {
  // @@protoc_insertion_point(field_release:faq.SQLiteField.blog)
  if (_internal_has_blog()) {
    clear_has_value();
    return value_.blog_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  } else {
    return nullptr;
  }
}
inline void SQLiteField::set_allocated_blog(std::string* blog) {
  if (has_value()) {
    clear_value();
  }
  if (blog != nullptr) {
    set_has_blog();
    value_.blog_.UnsafeSetDefault(blog);
    ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena();
    if (arena != nullptr) {
      arena->Own(blog);
    }
  }
  // @@protoc_insertion_point(field_set_allocated:faq.SQLiteField.blog)
}

// float float = 5;
inline bool SQLiteField::_internal_has_float_() const {
  return value_case() == kFloat;
}
inline void SQLiteField::set_has_float_() {
  _oneof_case_[0] = kFloat;
}
inline void SQLiteField::clear_float_() {
  if (_internal_has_float_()) {
    value_.float__ = 0;
    clear_has_value();
  }
}
inline float SQLiteField::_internal_float_() const {
  if (_internal_has_float_()) {
    return value_.float__;
  }
  return 0;
}
inline void SQLiteField::_internal_set_float_(float value) {
  if (!_internal_has_float_()) {
    clear_value();
    set_has_float_();
  }
  value_.float__ = value;
}
inline float SQLiteField::float_() const {
  // @@protoc_insertion_point(field_get:faq.SQLiteField.float)
  return _internal_float_();
}
inline void SQLiteField::set_float_(float value) {
  _internal_set_float_(value);
  // @@protoc_insertion_point(field_set:faq.SQLiteField.float)
}

inline bool SQLiteField::has_value() const {
  return value_case() != VALUE_NOT_SET;
}
inline void SQLiteField::clear_has_value() {
  _oneof_case_[0] = VALUE_NOT_SET;
}
inline SQLiteField::ValueCase SQLiteField::value_case() const {
  return SQLiteField::ValueCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace faq

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_faq_5fhook_2eproto
