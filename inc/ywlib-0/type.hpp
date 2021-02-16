#pragma once
#include "../../ywlib"

_ywm_ns_start___________________________________________________(yw)
_ywm_ns_start___________________________________________________(type)

using nullptr_t = decltype(nullptr);
template<class... Ts_> using void_t = void;

_ywm_ns_close___________________________________________________(type)
_ywm_ns_start___________________________________________________(_zyx)
template<class T_> struct ywtype_remove_const { using type = T_; };
template<class T_> struct ywtype_remove_const<const T_> { using type = T_; };
template<class T_> struct ywtype_remove_volatile { using type = T_; };
template<class T_> struct ywtype_remove_volatile<volatile T_> { using type = T_; };
template<class T_> struct ywtype_remove_cv { using type = T_; };
template<class T_> struct ywtype_remove_cv<const T_> { using type = T_; };
template<class T_> struct ywtype_remove_cv<volatile T_> { using type = T_; };
template<class T_> struct ywtype_remove_cv<const volatile T_> { using type = T_; };
template<class T_> struct ywtype_remove_ref { using type = T_; };
template<class T_> struct ywtype_remove_ref<T_&> { using type = T_; };
template<class T_> struct ywtype_remove_ref<T_&&> { using type = T_; };
template<class T_> struct ywtype_remove_ptr { using type = T_; };
template<class T_> struct ywtype_remove_ptr<T_*> { using type = T_; };
template<class T_> struct ywtype_remove_ptr<T_* const> { using type = T_; };
template<class T_> struct ywtype_remove_ptr<T_* volatile> { using type = T_; };
template<class T_> struct ywtype_remove_ptr<T_* const volatile> { using type = T_; };
template<class T_> struct ywtype_remove_extent { using type = T_; };
template<class T_> struct ywtype_remove_extent<T_[]> { using type = T_; };
template<class T_, natt N_> struct ywtype_remove_extent<T_[N_]> { using type = T_; };
template<class T_> struct ywtype_remove_extent_all { using type = T_; };
template<class T_> struct ywtype_remove_extent<T_[]> { using type = typename ywtype_remove_extent_all<T_>::type; };
template<class T_, natt N_> struct ywtype_remove_extent<T_[N_]> { using type = typename ywtype_remove_extent_all<T_>::type; };
template<class T_, class Void_ = void> struct ywtype_add_ref { using type_lv = T_; using type_rv = T_; };
template<class T_> struct ywtype_add_ref<T_, type::void_t<T_&>> { using type_lv = T_&; using type_rv = T_&&; };
template<class T_, class Void_ = void> struct ywtype_add_ptr { using type = T_; };
template<class T_> struct ywtype_add_ptr<T_, type::void_t<typename ywtype_remove_ref<T_>::type*>> { using type = typename ywtype_remove_ref<T_>::type*; };
#define _instm_0(M_, Call_, B_)\
M_(Call_, , , , B_) M_(Call_, const, , , B_) M_(Call_, volatile, , , B_) M_(Call_, const volatile, , , B_)\
M_(Call_, , &, , B_) M_(Call_, const, &, , B_) M_(Call_, volatile, &, , B_) M_(Call_, const volatile, &, , B_)\
M_(Call_, , &&, , B_) M_(Call_, const, &&, , B_) M_(Call_, volatile, &&, , B_) M_(Call_, const volatile, &&, , B_)\
M_(Call_, , , noexcept, B_) M_(Call_, const, , noexcept, B_) M_(Call_, volatile, , noexcept, B_) M_(Call_, const volatile, , noexcept, B_)\
M_(Call_, , &, noexcept, B_) M_(Call_, const, &, noexcept, B_) M_(Call_, volatile, &, noexcept, B_) M_(Call_, const volatile, &, noexcept, B_)\
M_(Call_, , &&, noexcept, B_) M_(Call_, const, &&, noexcept, B_) M_(Call_, volatile, &&, noexcept, B_) M_(Call_, const volatile, &&, noexcept, B_)
template<class T_, class Void_ = void> inline constexpr bool ywtype_is_memptr_function = false;
#define _instm_1(Call_, Cv_, Ref_, Ne_, B_)\
template<class Ret_, class Cls_, class... Args_> inline constexpr bool ywtype_is_memptr_function<Ret_ (Call_ Cls_::*)(Args_...)Cv_ Ref_ Ne_, type::breaker<B_>> = true;
#define _instm_2(Call_, Cv_, Ref_, Ne_, B_)\
template<class Ret_, class Cls_, class... Args_> inline constexpr bool ywtype_is_memptr_function<Ret_ (Cls_::*)(Args_..., ...)Cv_ Ref_ Ne_, type::breaker<B_>> = true;
_instm_0(_instm_2, , true);
_instm_0(_instm_1, __cdecl, true);
_instm_0(_instm_1, __vectorcall, true);
_instm_0(_instm_1, __stdcall, sizeof(poid) == 4);
_instm_0(_instm_1, __fastcall, sizeof(poid) == 4);
_instm_0(_instm_1, __thiscall, sizeof(poid) == 4);
#undef _instm_0;
#undef _instm_1;
#undef _instm_2;
_ywm_ns_close___________________________________________________(_zyx)
_ywm_ns_start___________________________________________________(type)

template<class T_> using remove_const = typename _zyx::ywtype_remove_const<T_>::type;
template<class T_> using remove_volatile = typename _zyx::ywtype_remove_volatile<T_>::type;
template<class T_> using remove_cv = typename _zyx::ywtype_remove_cv<T_>::type;
template<class T_> using remove_ref = typename _zyx::ywtype_remove_ref<T_>::type;
template<class T_> using remove_cvref = remove_cv<remove_ref<T_>>;
template<class T_> using remove_ptr = typename _zyx::ywtype_remove_ptr<T_>::type;
template<class T_> using remove_extent = typename _zyx::ywtype_remove_extent<T_>::type;
template<class T_> using remove_extent_all = typename _zyx::ywtype_remove_extent_all<T_>::type;

template<class T_> using add_const = const T_;
template<class T_> using add_volatile = volatile T_;
template<class T_> using add_cv = const volatile T_;
template<class T_> using add_ref_lv = typename _zyx::ywtype_add_ref::type_lv;
template<class T_> using add_ref_rv = typename _zyx::ywtype_add_ref::type_rv;
template<class T_> using add_ptr = T_*;

template<class T_> struct _declval_protector { static const bool stop = false; static add_ref_rv<T_> delegate()noexcept; };
template<class T_> add_ref_rv<T_> declval(void)noexcept { static_assert(_declval_protector<T_>::stop); return declval_protector<T_>::delegate(); }
inline constexpr bool now_constevaluating(void)noexcept { return __builtin_is_constant_evaluated(); }

template<class T_> inline constexpr natt rank = 0;
template<class T_> inline constexpr natt rank<T_[]> = rank<T_> + 1;
template<class T_, natt N_> inline constexpr natt rank<T_[N_]> = rank<T_> + 1;
template<class T_, natt I_> inline constexpr natt extent = 0;
template<class T_, natt N_> inline constexpr natt extent<T_[N_], 0> = N_;
template<class T_, natt I_> inline constexpr natt extent<T_[], I_> = extent<T_, I_ - 1>;
template<class T_, natt I_, natt N_> inline constexpr natt extent<T_[N_], I_> = extent<T_, I_ - 1>;

template<class T_> inline constexpr bool is_const = false;
template<class T_> inline constexpr bool is_const<const T_> = true;
template<class T_> inline constexpr bool is_volatile = false;
template<class T_> inline constexpr bool is_volatile<volatile T_> = true;
template<bool... Bs_> inline constexpr bool conjunction = (Bs_ && ...);
template<bool... Bs_> inline constexpr bool disjunction = (Bs_ || ...);
template<class T1_ , class T2_> inline constexpr bool is_same = false;
template<class T_> inline constexpr bool is_same<T_, T_> = true;
template<class T_, class... Ts_> inline constexpr bool is_included = disjunction<is_same<T_, Ts_>...>;
template<class T_> inline constexpr bool is_void = is_same<remove_cv<T_>, void>;
template<class T_> inline constexpr bool is_bool = is_same<remove_cv<T_>, bool>;
template<class T_> inline constexpr bool is_cat = is_included<T_, cat0, cat1, cat2, cat4>;
template<class T_> inline constexpr bool is_int = is_included<T_, int1, int2, int4, int8>;
template<class T_> inline constexpr bool is_nat = is_included<T_, nat1, nat2, nat4, nat8>;
template<class T_> inline constexpr bool is_fat = is_included<T_, fat4, fat8>;
template<class T_> inline constexpr bool is_count = is_int<T_> || is_nat<T_>;
template<class T_> inline constexpr bool is_quant = is_count<T_> || is_fat<T_>;
template<class T_> inline constexpr bool is_integral = is_bool<T_> || is_cat<T_> || is_count<T_>;
template<class T_> inline constexpr bool is_signed = is_integral<T_> ? (static_cast<remove_cv<T_>>(-1) < static_cast<remove_cv<T_>>(0)) : is_fat<T_>;
template<class T_> inline constexpr bool is_unsigned = is_integral<T_> ? !is_signed<T_> : false;
template<class T_> inline constexpr bool is_ref_lv = false;
template<class T_> inline constexpr bool is_ref_lv<T_&> = true;
template<class T_> inline constexpr bool is_ref_rv = false;
template<class T_> inline constexpr bool is_ref_rv<T_&&> = true;
template<class T_> inline constexpr bool is_ref = is_ref_lv<T_> || is_ref_rv<T_>;
template<class T_> inline constexpr bool is_nullptr = is_same<remove_cv<T_>, nullptr_t>;
template<class T_> inline constexpr bool is_ptr = false;
template<class T_> inline constexpr bool is_ptr<T_*> = true;
template<class T_> inline constexpr bool is_ptr<T_* const> = true;
template<class T_> inline constexpr bool is_ptr<T_* volatile> = true;
template<class T_> inline constexpr bool is_ptr<T_* const volatile> = true;
template<class T_> inline constexpr bool is_array_bounded = false;
template<class T_, natt N_> inline constexpr bool is_array_bounded<T_[N_]> = true;
template<class T_> inline constexpr bool is_array_unbounded = false;
template<class T_> inline constexpr bool is_array_unbounded<T_[]> = true;
template<class T_> inline constexpr bool is_array = is_array_bounded<T_> || is_array_unbounded<T_>;
template<class T_> inline constexpr bool is_enum = __is_enum(T_);
template<class T_> inline constexpr bool is_union = __is_union(T_);
template<class T_> inline constexpr bool is_class = __is_class(T_);
template<class T_> inline constexpr bool is_function = !is_const<const T_> && !is_ref<T_>;
template<class T_> inline constexpr bool is_object = !is_function<T_>;
template<class T_> inline constexpr bool is_memptr_function = _zyx::ywtype_is_memptr_function<T_>;
template<class T_> inline constexpr bool is_memptr_object = false;
template<class Ret_, class Cls_> inline constexpr bool is_memptr_object<Ret_ Cls_::*> = !is_function<Ret_>;
template<class T_> inline constexpr bool is_memptr = is_memptr_function<T_> || is_memptr_object<T_>;
template<class T_> inline constexpr bool is_fundamental = is_integral<T_> || is_fat<T_> || is_void<T_> || is_nullptr<T_>;
template<class T_> inline constexpr bool is_compound = !is_fundamental<T_>;
template<class T_> inline constexpr bool is_scalar = is_integral<T_> || is_fat<T_> || is_enum<T_> || is_ptr<T_> || is_memptr<T_> || is_nullptr<T_>;

template<class T_> inline constexpr bool is_trivial = __is_trivially_constructible(T_) && __is_trivially_copyable(T_);
template<class T_> inline constexpr bool is_empty = __is_empty(T_);
template<class T_> inline constexpr bool is_polymorphic = __is_polymorphic(T_);
template<class T_> inline constexpr bool is_abstract = __is_abstract(T_);
template<class T_> inline constexpr bool is_final = __is_final(T_);
template<class T_> inline constexpr bool is_aggregate = __is_aggregate(T_);
template<class T_> inline constexpr bool is_trivially_copyable = __is_trivially_copyable(T_);
template<class T_> inline constexpr bool is_standard_layout = __is_standard_layout(T_);
template<class T_> inline constexpr bool has_unique_object_representations = __has_unique_object_representations(T_);
template<class Base_, class Derived_> inline constexpr bool is_base_of = __is_base_of(Base_, Derived_);
template<class To_, class From_> inline constexpr bool is_convertible = __is_convertible(From_, To_);

template<class T_, class... Args_> inline constexpr bool is_constructible = __is_constructible(T_, Args_...);
template<class T_, class... Args_> inline constexpr bool is_nothrow_constructible = __is_nothrow_constructible(T_, Args_...);
template<class T_, class... Args_> inline constexpr bool is_trivially_constructible = __is_trivially_constructible(T_, Args_...);
template<class T_> inline constexpr bool is_constructible_default = __is_constructible(T_);
template<class T_> inline constexpr bool is_nothrow_constructible_default = __is_nothrow_constructible(T_);
template<class T_> inline constexpr bool is_trivially_constructible_default = __is_trivially_constructible(T_);
template<class T_> inline constexpr bool is_constructible_copy = __is_constructible(T_, add_ref_lv<const T_>);
template<class T_> inline constexpr bool is_nothrow_constructible_copy = __is_nothrow_constructible(T_, add_ref_lv<const T_>);
template<class T_> inline constexpr bool is_trivially_constructible_copy = __is_trivially_constructible(T_, add_ref_lv<const T_>);
template<class T_> inline constexpr bool is_constructible_move = __is_constructible(T_, T_);
template<class T_> inline constexpr bool is_nothrow_constructible_move = __is_nothrow_constructible(T_, T_);
template<class T_> inline constexpr bool is_trivially_constructible_move = __is_trivially_constructible(T_, T_);
template<class To_, class From_> inline constexpr bool is_assignable = __is_assignable(To_, From_);
template<class To_, class From_> inline constexpr bool is_nothrow_assignable = __is_nothrow_assignable(To_, From_);
template<class To_, class From_> inline constexpr bool is_trivially_assignable = __is_trivially_assignable(To_, From_);
template<class T_> inline constexpr bool is_assignable_copy = __is_assignable(T_, add_ref_lv<const T_>);
template<class T_> inline constexpr bool is_nothrow_assignable_copy = __is_nothrow_assignable(T_, add_ref_lv<const T_>);
template<class T_> inline constexpr bool is_trivially_assignable_copy = __is_trivially_assignable(T_, add_ref_lv<const T_>);
template<class T_> inline constexpr bool is_assignable_move = __is_assignable(T_, T_);
template<class T_> inline constexpr bool is_nothrow_assignable_move = __is_nothrow_assignable(T_, T_);
template<class T_> inline constexpr bool is_trivially_assignable_move = __is_trivially_assignable(T_, T_);
template<class T_> inline constexpr bool is_destructible = __is_destructible(T_);
template<class T_> inline constexpr bool is_nothrow_destructible = __is_nothrow_destructible(T_);
template<class T_> inline constexpr bool is_trivially_destructible = __is_trivially_destructible(T_);
template<class T_> inline constexpr bool has_virtual_destructor = __has_virtual_destructor(T_);

_ywm_ns_close___________________________________________________(type)
_ywm_ns_close___________________________________________________(yw)