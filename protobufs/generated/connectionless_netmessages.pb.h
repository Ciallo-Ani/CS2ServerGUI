// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: connectionless_netmessages.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_connectionless_5fnetmessages_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_connectionless_5fnetmessages_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021008 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "netmessages.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_connectionless_5fnetmessages_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_connectionless_5fnetmessages_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_connectionless_5fnetmessages_2eproto;
class C2S_CONNECTION_Message;
struct C2S_CONNECTION_MessageDefaultTypeInternal;
extern C2S_CONNECTION_MessageDefaultTypeInternal _C2S_CONNECTION_Message_default_instance_;
class C2S_CONNECT_Message;
struct C2S_CONNECT_MessageDefaultTypeInternal;
extern C2S_CONNECT_MessageDefaultTypeInternal _C2S_CONNECT_Message_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::C2S_CONNECTION_Message* Arena::CreateMaybeMessage<::C2S_CONNECTION_Message>(Arena*);
template<> ::C2S_CONNECT_Message* Arena::CreateMaybeMessage<::C2S_CONNECT_Message>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class C2S_CONNECT_Message final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:C2S_CONNECT_Message) */ {
 public:
  inline C2S_CONNECT_Message() : C2S_CONNECT_Message(nullptr) {}
  ~C2S_CONNECT_Message() override;
  explicit PROTOBUF_CONSTEXPR C2S_CONNECT_Message(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  C2S_CONNECT_Message(const C2S_CONNECT_Message& from);
  C2S_CONNECT_Message(C2S_CONNECT_Message&& from) noexcept
    : C2S_CONNECT_Message() {
    *this = ::std::move(from);
  }

  inline C2S_CONNECT_Message& operator=(const C2S_CONNECT_Message& from) {
    CopyFrom(from);
    return *this;
  }
  inline C2S_CONNECT_Message& operator=(C2S_CONNECT_Message&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const C2S_CONNECT_Message& default_instance() {
    return *internal_default_instance();
  }
  static inline const C2S_CONNECT_Message* internal_default_instance() {
    return reinterpret_cast<const C2S_CONNECT_Message*>(
               &_C2S_CONNECT_Message_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(C2S_CONNECT_Message& a, C2S_CONNECT_Message& b) {
    a.Swap(&b);
  }
  inline void Swap(C2S_CONNECT_Message* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(C2S_CONNECT_Message* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  C2S_CONNECT_Message* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<C2S_CONNECT_Message>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const C2S_CONNECT_Message& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const C2S_CONNECT_Message& from) {
    C2S_CONNECT_Message::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(C2S_CONNECT_Message* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "C2S_CONNECT_Message";
  }
  protected:
  explicit C2S_CONNECT_Message(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSplitplayersFieldNumber = 7,
    kEncryptedPasswordFieldNumber = 6,
    kAuthSteamFieldNumber = 8,
    kChallengeContextFieldNumber = 9,
    kHostVersionFieldNumber = 1,
    kAuthProtocolFieldNumber = 2,
    kReservationCookieFieldNumber = 4,
    kChallengeNumberFieldNumber = 3,
    kLowViolenceFieldNumber = 5,
  };
  // repeated .CCLCMsg_SplitPlayerConnect splitplayers = 7;
  int splitplayers_size() const;
  private:
  int _internal_splitplayers_size() const;
  public:
  void clear_splitplayers();
  ::CCLCMsg_SplitPlayerConnect* mutable_splitplayers(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::CCLCMsg_SplitPlayerConnect >*
      mutable_splitplayers();
  private:
  const ::CCLCMsg_SplitPlayerConnect& _internal_splitplayers(int index) const;
  ::CCLCMsg_SplitPlayerConnect* _internal_add_splitplayers();
  public:
  const ::CCLCMsg_SplitPlayerConnect& splitplayers(int index) const;
  ::CCLCMsg_SplitPlayerConnect* add_splitplayers();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::CCLCMsg_SplitPlayerConnect >&
      splitplayers() const;

  // optional bytes encrypted_password = 6;
  bool has_encrypted_password() const;
  private:
  bool _internal_has_encrypted_password() const;
  public:
  void clear_encrypted_password();
  const std::string& encrypted_password() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_encrypted_password(ArgT0&& arg0, ArgT... args);
  std::string* mutable_encrypted_password();
  PROTOBUF_NODISCARD std::string* release_encrypted_password();
  void set_allocated_encrypted_password(std::string* encrypted_password);
  private:
  const std::string& _internal_encrypted_password() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_encrypted_password(const std::string& value);
  std::string* _internal_mutable_encrypted_password();
  public:

  // optional bytes auth_steam = 8;
  bool has_auth_steam() const;
  private:
  bool _internal_has_auth_steam() const;
  public:
  void clear_auth_steam();
  const std::string& auth_steam() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_auth_steam(ArgT0&& arg0, ArgT... args);
  std::string* mutable_auth_steam();
  PROTOBUF_NODISCARD std::string* release_auth_steam();
  void set_allocated_auth_steam(std::string* auth_steam);
  private:
  const std::string& _internal_auth_steam() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_auth_steam(const std::string& value);
  std::string* _internal_mutable_auth_steam();
  public:

  // optional string challenge_context = 9;
  bool has_challenge_context() const;
  private:
  bool _internal_has_challenge_context() const;
  public:
  void clear_challenge_context();
  const std::string& challenge_context() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_challenge_context(ArgT0&& arg0, ArgT... args);
  std::string* mutable_challenge_context();
  PROTOBUF_NODISCARD std::string* release_challenge_context();
  void set_allocated_challenge_context(std::string* challenge_context);
  private:
  const std::string& _internal_challenge_context() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_challenge_context(const std::string& value);
  std::string* _internal_mutable_challenge_context();
  public:

  // optional uint32 host_version = 1;
  bool has_host_version() const;
  private:
  bool _internal_has_host_version() const;
  public:
  void clear_host_version();
  uint32_t host_version() const;
  void set_host_version(uint32_t value);
  private:
  uint32_t _internal_host_version() const;
  void _internal_set_host_version(uint32_t value);
  public:

  // optional uint32 auth_protocol = 2;
  bool has_auth_protocol() const;
  private:
  bool _internal_has_auth_protocol() const;
  public:
  void clear_auth_protocol();
  uint32_t auth_protocol() const;
  void set_auth_protocol(uint32_t value);
  private:
  uint32_t _internal_auth_protocol() const;
  void _internal_set_auth_protocol(uint32_t value);
  public:

  // optional fixed64 reservation_cookie = 4;
  bool has_reservation_cookie() const;
  private:
  bool _internal_has_reservation_cookie() const;
  public:
  void clear_reservation_cookie();
  uint64_t reservation_cookie() const;
  void set_reservation_cookie(uint64_t value);
  private:
  uint64_t _internal_reservation_cookie() const;
  void _internal_set_reservation_cookie(uint64_t value);
  public:

  // optional uint32 challenge_number = 3;
  bool has_challenge_number() const;
  private:
  bool _internal_has_challenge_number() const;
  public:
  void clear_challenge_number();
  uint32_t challenge_number() const;
  void set_challenge_number(uint32_t value);
  private:
  uint32_t _internal_challenge_number() const;
  void _internal_set_challenge_number(uint32_t value);
  public:

  // optional bool low_violence = 5;
  bool has_low_violence() const;
  private:
  bool _internal_has_low_violence() const;
  public:
  void clear_low_violence();
  bool low_violence() const;
  void set_low_violence(bool value);
  private:
  bool _internal_low_violence() const;
  void _internal_set_low_violence(bool value);
  public:

  // @@protoc_insertion_point(class_scope:C2S_CONNECT_Message)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::CCLCMsg_SplitPlayerConnect > splitplayers_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr encrypted_password_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr auth_steam_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr challenge_context_;
    uint32_t host_version_;
    uint32_t auth_protocol_;
    uint64_t reservation_cookie_;
    uint32_t challenge_number_;
    bool low_violence_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_connectionless_5fnetmessages_2eproto;
};
// -------------------------------------------------------------------

class C2S_CONNECTION_Message final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:C2S_CONNECTION_Message) */ {
 public:
  inline C2S_CONNECTION_Message() : C2S_CONNECTION_Message(nullptr) {}
  ~C2S_CONNECTION_Message() override;
  explicit PROTOBUF_CONSTEXPR C2S_CONNECTION_Message(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  C2S_CONNECTION_Message(const C2S_CONNECTION_Message& from);
  C2S_CONNECTION_Message(C2S_CONNECTION_Message&& from) noexcept
    : C2S_CONNECTION_Message() {
    *this = ::std::move(from);
  }

  inline C2S_CONNECTION_Message& operator=(const C2S_CONNECTION_Message& from) {
    CopyFrom(from);
    return *this;
  }
  inline C2S_CONNECTION_Message& operator=(C2S_CONNECTION_Message&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const C2S_CONNECTION_Message& default_instance() {
    return *internal_default_instance();
  }
  static inline const C2S_CONNECTION_Message* internal_default_instance() {
    return reinterpret_cast<const C2S_CONNECTION_Message*>(
               &_C2S_CONNECTION_Message_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(C2S_CONNECTION_Message& a, C2S_CONNECTION_Message& b) {
    a.Swap(&b);
  }
  inline void Swap(C2S_CONNECTION_Message* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(C2S_CONNECTION_Message* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  C2S_CONNECTION_Message* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<C2S_CONNECTION_Message>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const C2S_CONNECTION_Message& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const C2S_CONNECTION_Message& from) {
    C2S_CONNECTION_Message::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(C2S_CONNECTION_Message* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "C2S_CONNECTION_Message";
  }
  protected:
  explicit C2S_CONNECTION_Message(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAddonNameFieldNumber = 1,
  };
  // optional string addon_name = 1;
  bool has_addon_name() const;
  private:
  bool _internal_has_addon_name() const;
  public:
  void clear_addon_name();
  const std::string& addon_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_addon_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_addon_name();
  PROTOBUF_NODISCARD std::string* release_addon_name();
  void set_allocated_addon_name(std::string* addon_name);
  private:
  const std::string& _internal_addon_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_addon_name(const std::string& value);
  std::string* _internal_mutable_addon_name();
  public:

  // @@protoc_insertion_point(class_scope:C2S_CONNECTION_Message)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr addon_name_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_connectionless_5fnetmessages_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// C2S_CONNECT_Message

// optional uint32 host_version = 1;
inline bool C2S_CONNECT_Message::_internal_has_host_version() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool C2S_CONNECT_Message::has_host_version() const {
  return _internal_has_host_version();
}
inline void C2S_CONNECT_Message::clear_host_version() {
  _impl_.host_version_ = 0u;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline uint32_t C2S_CONNECT_Message::_internal_host_version() const {
  return _impl_.host_version_;
}
inline uint32_t C2S_CONNECT_Message::host_version() const {
  // @@protoc_insertion_point(field_get:C2S_CONNECT_Message.host_version)
  return _internal_host_version();
}
inline void C2S_CONNECT_Message::_internal_set_host_version(uint32_t value) {
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.host_version_ = value;
}
inline void C2S_CONNECT_Message::set_host_version(uint32_t value) {
  _internal_set_host_version(value);
  // @@protoc_insertion_point(field_set:C2S_CONNECT_Message.host_version)
}

// optional uint32 auth_protocol = 2;
inline bool C2S_CONNECT_Message::_internal_has_auth_protocol() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool C2S_CONNECT_Message::has_auth_protocol() const {
  return _internal_has_auth_protocol();
}
inline void C2S_CONNECT_Message::clear_auth_protocol() {
  _impl_.auth_protocol_ = 0u;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline uint32_t C2S_CONNECT_Message::_internal_auth_protocol() const {
  return _impl_.auth_protocol_;
}
inline uint32_t C2S_CONNECT_Message::auth_protocol() const {
  // @@protoc_insertion_point(field_get:C2S_CONNECT_Message.auth_protocol)
  return _internal_auth_protocol();
}
inline void C2S_CONNECT_Message::_internal_set_auth_protocol(uint32_t value) {
  _impl_._has_bits_[0] |= 0x00000010u;
  _impl_.auth_protocol_ = value;
}
inline void C2S_CONNECT_Message::set_auth_protocol(uint32_t value) {
  _internal_set_auth_protocol(value);
  // @@protoc_insertion_point(field_set:C2S_CONNECT_Message.auth_protocol)
}

// optional uint32 challenge_number = 3;
inline bool C2S_CONNECT_Message::_internal_has_challenge_number() const {
  bool value = (_impl_._has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool C2S_CONNECT_Message::has_challenge_number() const {
  return _internal_has_challenge_number();
}
inline void C2S_CONNECT_Message::clear_challenge_number() {
  _impl_.challenge_number_ = 0u;
  _impl_._has_bits_[0] &= ~0x00000040u;
}
inline uint32_t C2S_CONNECT_Message::_internal_challenge_number() const {
  return _impl_.challenge_number_;
}
inline uint32_t C2S_CONNECT_Message::challenge_number() const {
  // @@protoc_insertion_point(field_get:C2S_CONNECT_Message.challenge_number)
  return _internal_challenge_number();
}
inline void C2S_CONNECT_Message::_internal_set_challenge_number(uint32_t value) {
  _impl_._has_bits_[0] |= 0x00000040u;
  _impl_.challenge_number_ = value;
}
inline void C2S_CONNECT_Message::set_challenge_number(uint32_t value) {
  _internal_set_challenge_number(value);
  // @@protoc_insertion_point(field_set:C2S_CONNECT_Message.challenge_number)
}

// optional fixed64 reservation_cookie = 4;
inline bool C2S_CONNECT_Message::_internal_has_reservation_cookie() const {
  bool value = (_impl_._has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool C2S_CONNECT_Message::has_reservation_cookie() const {
  return _internal_has_reservation_cookie();
}
inline void C2S_CONNECT_Message::clear_reservation_cookie() {
  _impl_.reservation_cookie_ = uint64_t{0u};
  _impl_._has_bits_[0] &= ~0x00000020u;
}
inline uint64_t C2S_CONNECT_Message::_internal_reservation_cookie() const {
  return _impl_.reservation_cookie_;
}
inline uint64_t C2S_CONNECT_Message::reservation_cookie() const {
  // @@protoc_insertion_point(field_get:C2S_CONNECT_Message.reservation_cookie)
  return _internal_reservation_cookie();
}
inline void C2S_CONNECT_Message::_internal_set_reservation_cookie(uint64_t value) {
  _impl_._has_bits_[0] |= 0x00000020u;
  _impl_.reservation_cookie_ = value;
}
inline void C2S_CONNECT_Message::set_reservation_cookie(uint64_t value) {
  _internal_set_reservation_cookie(value);
  // @@protoc_insertion_point(field_set:C2S_CONNECT_Message.reservation_cookie)
}

// optional bool low_violence = 5;
inline bool C2S_CONNECT_Message::_internal_has_low_violence() const {
  bool value = (_impl_._has_bits_[0] & 0x00000080u) != 0;
  return value;
}
inline bool C2S_CONNECT_Message::has_low_violence() const {
  return _internal_has_low_violence();
}
inline void C2S_CONNECT_Message::clear_low_violence() {
  _impl_.low_violence_ = false;
  _impl_._has_bits_[0] &= ~0x00000080u;
}
inline bool C2S_CONNECT_Message::_internal_low_violence() const {
  return _impl_.low_violence_;
}
inline bool C2S_CONNECT_Message::low_violence() const {
  // @@protoc_insertion_point(field_get:C2S_CONNECT_Message.low_violence)
  return _internal_low_violence();
}
inline void C2S_CONNECT_Message::_internal_set_low_violence(bool value) {
  _impl_._has_bits_[0] |= 0x00000080u;
  _impl_.low_violence_ = value;
}
inline void C2S_CONNECT_Message::set_low_violence(bool value) {
  _internal_set_low_violence(value);
  // @@protoc_insertion_point(field_set:C2S_CONNECT_Message.low_violence)
}

// optional bytes encrypted_password = 6;
inline bool C2S_CONNECT_Message::_internal_has_encrypted_password() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool C2S_CONNECT_Message::has_encrypted_password() const {
  return _internal_has_encrypted_password();
}
inline void C2S_CONNECT_Message::clear_encrypted_password() {
  _impl_.encrypted_password_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& C2S_CONNECT_Message::encrypted_password() const {
  // @@protoc_insertion_point(field_get:C2S_CONNECT_Message.encrypted_password)
  return _internal_encrypted_password();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void C2S_CONNECT_Message::set_encrypted_password(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.encrypted_password_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:C2S_CONNECT_Message.encrypted_password)
}
inline std::string* C2S_CONNECT_Message::mutable_encrypted_password() {
  std::string* _s = _internal_mutable_encrypted_password();
  // @@protoc_insertion_point(field_mutable:C2S_CONNECT_Message.encrypted_password)
  return _s;
}
inline const std::string& C2S_CONNECT_Message::_internal_encrypted_password() const {
  return _impl_.encrypted_password_.Get();
}
inline void C2S_CONNECT_Message::_internal_set_encrypted_password(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.encrypted_password_.Set(value, GetArenaForAllocation());
}
inline std::string* C2S_CONNECT_Message::_internal_mutable_encrypted_password() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.encrypted_password_.Mutable(GetArenaForAllocation());
}
inline std::string* C2S_CONNECT_Message::release_encrypted_password() {
  // @@protoc_insertion_point(field_release:C2S_CONNECT_Message.encrypted_password)
  if (!_internal_has_encrypted_password()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.encrypted_password_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.encrypted_password_.IsDefault()) {
    _impl_.encrypted_password_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void C2S_CONNECT_Message::set_allocated_encrypted_password(std::string* encrypted_password) {
  if (encrypted_password != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.encrypted_password_.SetAllocated(encrypted_password, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.encrypted_password_.IsDefault()) {
    _impl_.encrypted_password_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:C2S_CONNECT_Message.encrypted_password)
}

// repeated .CCLCMsg_SplitPlayerConnect splitplayers = 7;
inline int C2S_CONNECT_Message::_internal_splitplayers_size() const {
  return _impl_.splitplayers_.size();
}
inline int C2S_CONNECT_Message::splitplayers_size() const {
  return _internal_splitplayers_size();
}
inline ::CCLCMsg_SplitPlayerConnect* C2S_CONNECT_Message::mutable_splitplayers(int index) {
  // @@protoc_insertion_point(field_mutable:C2S_CONNECT_Message.splitplayers)
  return _impl_.splitplayers_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::CCLCMsg_SplitPlayerConnect >*
C2S_CONNECT_Message::mutable_splitplayers() {
  // @@protoc_insertion_point(field_mutable_list:C2S_CONNECT_Message.splitplayers)
  return &_impl_.splitplayers_;
}
inline const ::CCLCMsg_SplitPlayerConnect& C2S_CONNECT_Message::_internal_splitplayers(int index) const {
  return _impl_.splitplayers_.Get(index);
}
inline const ::CCLCMsg_SplitPlayerConnect& C2S_CONNECT_Message::splitplayers(int index) const {
  // @@protoc_insertion_point(field_get:C2S_CONNECT_Message.splitplayers)
  return _internal_splitplayers(index);
}
inline ::CCLCMsg_SplitPlayerConnect* C2S_CONNECT_Message::_internal_add_splitplayers() {
  return _impl_.splitplayers_.Add();
}
inline ::CCLCMsg_SplitPlayerConnect* C2S_CONNECT_Message::add_splitplayers() {
  ::CCLCMsg_SplitPlayerConnect* _add = _internal_add_splitplayers();
  // @@protoc_insertion_point(field_add:C2S_CONNECT_Message.splitplayers)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::CCLCMsg_SplitPlayerConnect >&
C2S_CONNECT_Message::splitplayers() const {
  // @@protoc_insertion_point(field_list:C2S_CONNECT_Message.splitplayers)
  return _impl_.splitplayers_;
}

// optional bytes auth_steam = 8;
inline bool C2S_CONNECT_Message::_internal_has_auth_steam() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool C2S_CONNECT_Message::has_auth_steam() const {
  return _internal_has_auth_steam();
}
inline void C2S_CONNECT_Message::clear_auth_steam() {
  _impl_.auth_steam_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& C2S_CONNECT_Message::auth_steam() const {
  // @@protoc_insertion_point(field_get:C2S_CONNECT_Message.auth_steam)
  return _internal_auth_steam();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void C2S_CONNECT_Message::set_auth_steam(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000002u;
 _impl_.auth_steam_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:C2S_CONNECT_Message.auth_steam)
}
inline std::string* C2S_CONNECT_Message::mutable_auth_steam() {
  std::string* _s = _internal_mutable_auth_steam();
  // @@protoc_insertion_point(field_mutable:C2S_CONNECT_Message.auth_steam)
  return _s;
}
inline const std::string& C2S_CONNECT_Message::_internal_auth_steam() const {
  return _impl_.auth_steam_.Get();
}
inline void C2S_CONNECT_Message::_internal_set_auth_steam(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.auth_steam_.Set(value, GetArenaForAllocation());
}
inline std::string* C2S_CONNECT_Message::_internal_mutable_auth_steam() {
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.auth_steam_.Mutable(GetArenaForAllocation());
}
inline std::string* C2S_CONNECT_Message::release_auth_steam() {
  // @@protoc_insertion_point(field_release:C2S_CONNECT_Message.auth_steam)
  if (!_internal_has_auth_steam()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* p = _impl_.auth_steam_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.auth_steam_.IsDefault()) {
    _impl_.auth_steam_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void C2S_CONNECT_Message::set_allocated_auth_steam(std::string* auth_steam) {
  if (auth_steam != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.auth_steam_.SetAllocated(auth_steam, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.auth_steam_.IsDefault()) {
    _impl_.auth_steam_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:C2S_CONNECT_Message.auth_steam)
}

// optional string challenge_context = 9;
inline bool C2S_CONNECT_Message::_internal_has_challenge_context() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool C2S_CONNECT_Message::has_challenge_context() const {
  return _internal_has_challenge_context();
}
inline void C2S_CONNECT_Message::clear_challenge_context() {
  _impl_.challenge_context_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline const std::string& C2S_CONNECT_Message::challenge_context() const {
  // @@protoc_insertion_point(field_get:C2S_CONNECT_Message.challenge_context)
  return _internal_challenge_context();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void C2S_CONNECT_Message::set_challenge_context(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000004u;
 _impl_.challenge_context_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:C2S_CONNECT_Message.challenge_context)
}
inline std::string* C2S_CONNECT_Message::mutable_challenge_context() {
  std::string* _s = _internal_mutable_challenge_context();
  // @@protoc_insertion_point(field_mutable:C2S_CONNECT_Message.challenge_context)
  return _s;
}
inline const std::string& C2S_CONNECT_Message::_internal_challenge_context() const {
  return _impl_.challenge_context_.Get();
}
inline void C2S_CONNECT_Message::_internal_set_challenge_context(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.challenge_context_.Set(value, GetArenaForAllocation());
}
inline std::string* C2S_CONNECT_Message::_internal_mutable_challenge_context() {
  _impl_._has_bits_[0] |= 0x00000004u;
  return _impl_.challenge_context_.Mutable(GetArenaForAllocation());
}
inline std::string* C2S_CONNECT_Message::release_challenge_context() {
  // @@protoc_insertion_point(field_release:C2S_CONNECT_Message.challenge_context)
  if (!_internal_has_challenge_context()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000004u;
  auto* p = _impl_.challenge_context_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.challenge_context_.IsDefault()) {
    _impl_.challenge_context_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void C2S_CONNECT_Message::set_allocated_challenge_context(std::string* challenge_context) {
  if (challenge_context != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  _impl_.challenge_context_.SetAllocated(challenge_context, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.challenge_context_.IsDefault()) {
    _impl_.challenge_context_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:C2S_CONNECT_Message.challenge_context)
}

// -------------------------------------------------------------------

// C2S_CONNECTION_Message

// optional string addon_name = 1;
inline bool C2S_CONNECTION_Message::_internal_has_addon_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool C2S_CONNECTION_Message::has_addon_name() const {
  return _internal_has_addon_name();
}
inline void C2S_CONNECTION_Message::clear_addon_name() {
  _impl_.addon_name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& C2S_CONNECTION_Message::addon_name() const {
  // @@protoc_insertion_point(field_get:C2S_CONNECTION_Message.addon_name)
  return _internal_addon_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void C2S_CONNECTION_Message::set_addon_name(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.addon_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:C2S_CONNECTION_Message.addon_name)
}
inline std::string* C2S_CONNECTION_Message::mutable_addon_name() {
  std::string* _s = _internal_mutable_addon_name();
  // @@protoc_insertion_point(field_mutable:C2S_CONNECTION_Message.addon_name)
  return _s;
}
inline const std::string& C2S_CONNECTION_Message::_internal_addon_name() const {
  return _impl_.addon_name_.Get();
}
inline void C2S_CONNECTION_Message::_internal_set_addon_name(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.addon_name_.Set(value, GetArenaForAllocation());
}
inline std::string* C2S_CONNECTION_Message::_internal_mutable_addon_name() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.addon_name_.Mutable(GetArenaForAllocation());
}
inline std::string* C2S_CONNECTION_Message::release_addon_name() {
  // @@protoc_insertion_point(field_release:C2S_CONNECTION_Message.addon_name)
  if (!_internal_has_addon_name()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.addon_name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.addon_name_.IsDefault()) {
    _impl_.addon_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void C2S_CONNECTION_Message::set_allocated_addon_name(std::string* addon_name) {
  if (addon_name != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.addon_name_.SetAllocated(addon_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.addon_name_.IsDefault()) {
    _impl_.addon_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:C2S_CONNECTION_Message.addon_name)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_connectionless_5fnetmessages_2eproto
