#pragma once
#include "../../ywlib"
#include "./type.hpp"

_ywm_ns_start___________________________________________________(yw)
_ywm_ns_start___________________________________________________(_zyx)

_ywm_ns_close___________________________________________________(_zyx)
_ywm_ns_start___________________________________________________(util)

template<class T_> [[nodiscard]] constexpr type::remove_ref<T_>&& move(T_&& Arg_)noexcept { return static_cast<type::remove_ref<T_>&&>(Arg_); }

template<class T_> inline constexpr T_* copy(T_* Dst_, const T_* Src_, natt Count_)noexcept {
  if constexpr (!util::constevaluating() && type::is_trivially_copyable<T_>) {
    if (Dst_ < Src_ ? Dst_ + Count_ < Src_ : Src_ + Count_ < Dst_) return reinterpret_cast<T_*>(_csl::memcpy(Dst_, Src_, sizeof(T_) * Count_)) + Count_;
    else return reinterpret_cast<T_*>(_csl::memmove(Dst_, Src_, sizeof(T_) * Count_)) + Count_;
  }
  else for (natt i = 0; i < Count_; ++i) Dst_[i] = Src_[i]; return Dst_ + Count_;
}

_ywm_ns_close___________________________________________________(util)
_ywm_ns_close___________________________________________________(yw)
