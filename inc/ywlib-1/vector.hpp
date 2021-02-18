#pragma once
#include "../../ywlib"
#include "../ywlib-0/concept.hpp"

ywnsstart(yw)

template<_quant T_, natt N_> class vector {
  static_assert(N_ > 0);
public:
  T_ v[N_];
  [[nodiscard]]] constexpr T_* operator()(void)noexcept { return v; }
  [[nodiscard]]] constexpr T_* operator()(natt I_)noexcept { return v + I_; }
  [[nodiscard]]] constexpr T_& operator[](natt I_)noexcept { return v[I_]; }
  [[nodiscard]]] constexpr const T_* operator()(void)const noexcept { return v; }
  [[nodiscard]]] constexpr const T_* operator()(natt I_)const noexcept { return v + I_; }
  [[nodiscard]]] constexpr const T_& operator[](natt I_)const noexcept { return v[I_]; }
  constexpr vector& operator=(const vecotr& A_)noexcept = default;
  constexpr vector& operator=(vector&& A_)noexcept = default;
  template<_quant Tx_, natt Nx_> constexpr vector& operator=(const vector<Tx_, Nx_>& A_)noexcept {
    f
};

ywnsclose(yw)
