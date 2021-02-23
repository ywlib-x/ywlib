#pragma once
#include "../../ywlib"
_ywm_ns_start___________________________________________________(yw)

#pragma region Primal
_ywm_ns_start___________________________________________________(type)

// equals to decltype(nullptr), std::nullptr_t.
using nullptr_t = decltype(nullptr);

// equals to void if all Ts_... are valid; Otherwise this get invalid.
template<typename... Ts_> using void_t = void;
_ywm_ns_close___________________________________________________(type)
#pragma endregion

#pragma region Add/Remove
_ywm_ns_start___________________________________________________(_zyx)
template<typename T_, typename Void_ = void> struct ywtype_add_ref { using type_lv = T_; using type_rv = T_; };
template<typename T_> struct ywtype_add_ref<T_, type::void_t<T_&>> { using type_lv = T_&; using type_rv = T_&&; };
template<typename T_, typename Void_ = void> struct ywtype_add_ptr { using type = T_; };
template<typename T_> struct ywtype_add_ptr<T_, type::void_t<typename ywtype_remove_ref<T_>::type*>> { using type = typename ywtype_remove_ref<T_>::type*; };
template<typename T_> struct ywtype_remove_const { using type = T_; };
template<typename T_> struct ywtype_remove_const<const T_> { using type = T_; };
template<typename T_> struct ywtype_remove_volatile { using type = T_; };
template<typename T_> struct ywtype_remove_volatile<volatile T_> { using type = T_; };
template<typename T_> struct ywtype_remove_cv { using type = T_; };
template<typename T_> struct ywtype_remove_cv<const T_> { using type = T_; };
template<typename T_> struct ywtype_remove_cv<volatile T_> { using type = T_; };
template<typename T_> struct ywtype_remove_cv<const volatile T_> { using type = T_; };
template<typename T_> struct ywtype_remove_ref { using type = T_; };
template<typename T_> struct ywtype_remove_ref<T_&> { using type = T_; };
template<typename T_> struct ywtype_remove_ref<T_&&> { using type = T_; };
template<typename T_> struct ywtype_remove_ptr { using type = T_; };
template<typename T_> struct ywtype_remove_ptr<T_*> { using type = T_; };
template<typename T_> struct ywtype_remove_ptr<T_* const> { using type = T_; };
template<typename T_> struct ywtype_remove_ptr<T_* volatile> { using type = T_; };
template<typename T_> struct ywtype_remove_ptr<T_* const volatile> { using type = T_; };
template<typename T_> struct ywtype_remove_extent { using type = T_; };
template<typename T_> struct ywtype_remove_extent<T_[]> { using type = T_; };
template<typename T_, natt N_> struct ywtype_remove_extent<T_[N_]> { using type = T_; };
template<typename T_> struct ywtype_remove_extent_all { using type = T_; };
template<typename T_> struct ywtype_remove_extent_all<T_[]> { using type = typename ywtype_remove_extent_all<T_>::type; };
template<typename T_, natt N_> struct ywtype_remove_extent_all<T_[N_]> { using type = typename ywtype_remove_extent_all<T_>::type; };
_ywm_ns_close___________________________________________________(_zyx)
_ywm_ns_start___________________________________________________(type)

// adds const qualifier to the type.
template<typename T_> using add_const = const T_;

// adds volatile qualifier to the type.
template<typename T_> using add_volatile = volatile T_;

// adds const & volatile qualifier to the type.
template<typename T_> using add_cv = const volatile T_;

// adds left-value reference to the type.
template<typename T_> using add_ref_lv = typename _zyx::ywtype_add_ref<T_>::type_lv;

// adds right-value reference to the type.
template<typename T_> using add_ref_rv = typename _zyx::ywtype_add_ref<T_>::type_rv;

// adds pointer to the type.
template<typename T_> using add_ptr = T_*;

// removes const qualifier from the type.
template<typename T_> using remove_const = typename _zyx::ywtype_remove_const<T_>::type;

// removes volatile qualifier from the type.
template<typename T_> using remove_volatile = typename _zyx::ywtype_remove_volatile<T_>::type;

// removes const & volatile qualifier from the type.
template<typename T_> using remove_cv = typename _zyx::ywtype_remove_cv<T_>::type;

// removes reference from the type.
template<typename T_> using remove_ref = typename _zyx::ywtype_remove_ref<T_>::type;

// removes reference and const & volatile qualifier form the type.
template<typename T_> using remove_cvref = remove_cv<remove_ref<T_>>;

// removes pointer form the type.
template<typename T_> using remove_ptr = typename _zyx::ywtype_remove_ptr<T_>::type;

// removes extent from the type.
template<typename T_> using remove_extent = typename _zyx::ywtype_remove_extent<T_>::type;

// removes all extent from the type.
template<typename T_> using remove_extent_all = typename _zyx::ywtype_remove_extent_all<T_>::type;
_ywm_ns_close___________________________________________________(type)
#pragma endregion

#pragma region Size_of_Array
_ywm_ns_start___________________________________________________(type)

// has the value equals to rank of the Type.
template<typename T_> inline constexpr natt rank = 0;
template<typename T_> inline constexpr natt rank<T_[]> = rank<T_> + 1;
template<typename T_, natt N_> inline constexpr natt rank<T_[N_]> = rank<T_> + 1;

// has the value euqals to array-size of specified rank.
template<typename T_, natt I_> inline constexpr natt extent = 0;
template<typename T_, natt N_> inline constexpr natt extent<T_[N_], 0> = N_;
template<typename T_, natt I_> inline constexpr natt extent<T_[], I_> = extent<T_, I_ - 1>;
template<typename T_, natt I_, natt N_> inline constexpr natt extent<T_[N_], I_> = extent<T_, I_ - 1>;
_ywm_ns_close___________________________________________________(type)
#pragma endregion

#pragma region Type_Check_0
_ywm_ns_start___________________________________________________(type)

// checks if all arguments are true.
template<bool... Bs_> inline constexpr bool conjunction = (Bs_ && ...);

// checks if at least an argument is true.
template<bool... Bs_> inline constexpr bool disjunction = (Bs_ || ...);

// checks if the two types are equal.
template<typename T1_ , typename T2_> inline constexpr bool is_same = false;
template<typename T_> inline constexpr bool is_same<T_, T_> = true;

// checks if the type is included in listed types.
template<typename T_, typename... Ts_> inline constexpr bool is_included = disjunction<is_same<T_, Ts_>...>;
_ywm_ns_close___________________________________________________(type)
#pragma endregion

#pragma region Type_Check_1
_ywm_ns_start___________________________________________________(type)

// checks if the type has const qualifier.
template<typename T_> inline constexpr bool is_const = false;
template<typename T_> inline constexpr bool is_const<const T_> = true;

// checks if the type has volatile qualifier.
template<typename T_> inline constexpr bool is_volatile = false;
template<typename T_> inline constexpr bool is_volatile<volatile T_> = true;

// checks if the type is left-value reference.
template<typename T_> inline constexpr bool is_ref_lv = false;
template<typename T_> inline constexpr bool is_ref_lv<T_&> = true;

// checks if the type is right-value reference.
template<typename T_> inline constexpr bool is_ref_rv = false;
template<typename T_> inline constexpr bool is_ref_rv<T_&&> = true;

// checks if the type is reference.
template<typename T_> inline constexpr bool is_ref = is_ref_lv<T_> || is_ref_rv<T_>;

// checks if the type is pointer.
template<typename T_> inline constexpr bool is_ptr = false;
template<typename T_> inline constexpr bool is_ptr<T_*> = true;
template<typename T_> inline constexpr bool is_ptr<T_* const> = true;
template<typename T_> inline constexpr bool is_ptr<T_* volatile> = true;
template<typename T_> inline constexpr bool is_ptr<T_* const volatile> = true;

// checks if the type is bounded array.
template<typename T_> inline constexpr bool is_array_bounded = false;
template<typename T_, natt N_> inline constexpr bool is_array_bounded<T_[N_]> = true;

// checks if the type is unbounded array.
template<typename T_> inline constexpr bool is_array_unbounded = false;
template<typename T_> inline constexpr bool is_array_unbounded<T_[]> = true;

// checks if the type is array.
template<typename T_> inline constexpr bool is_array = is_array_bounded<T_> || is_array_unbounded<T_>;
_ywm_ns_close___________________________________________________(type)
#pragma endregion

#pragma region Type_Check_2
_ywm_ns_start___________________________________________________(_zyx)
template<typename T_, typename Void_ = void> inline constexpr bool ywtype_is_memptr_function = false;
#undef _instm0
#undef _instm1
#undef _instm2
#undef _instm3
#define _instm0(M_, Call_)\
M_(Call_, ,   , ) M_(Call_, const,   , ) M_(Call_, volatile,   , ) M_(Call_, const volatile,   , )\
M_(Call_, ,  &, ) M_(Call_, const,  &, ) M_(Call_, volatile,  &, ) M_(Call_, const volatile,  &, )\
M_(Call_, , &&, ) M_(Call_, const, &&, ) M_(Call_, volatile, &&, ) M_(Call_, const volatile, &&, )\
M_(Call_, ,   , noexcept) M_(Call_, const,   , noexcept) M_(Call_, volatile,   , noexcept) M_(Call_, const volatile,   , noexcept)\
M_(Call_, ,  &, noexcept) M_(Call_, const,  &, noexcept) M_(Call_, volatile,  &, noexcept) M_(Call_, const volatile,  &, noexcept)\
M_(Call_, , &&, noexcept) M_(Call_, const, &&, noexcept) M_(Call_, volatile, &&, noexcept) M_(Call_, const volatile, &&, noexcept)
#define _instm1(Call_, Cv_, Ref_, Ne_)\
template<typename Ret_, typename Cls_, typename... Args_> inline constexpr bool ywtype_is_memptr_function<Ret_ (Cls_::*)(Args_..., ...)Cv_ Ref_ Ne_> = true;
#define _instm2(Call_, Cv_, Ref_, Ne_)\
template<typename Ret_, typename Cls_, typename... Args_> inline constexpr bool ywtype_is_memptr_function<Ret_ (Call_ Cls_::*)(Args_...)Cv_ Ref_ Ne_> = true;
#define _instm3(Call_, Cv_, Ref_, Ne_)\
template<typename Ret_, typename Cls_, typename... Args_> inline constexpr bool ywtype_is_memptr_function<Ret_ (Call_ Cls_::*)(Args_...)Cv_ Ref_ Ne_, type::breaker<sizeof(Cls_*) == 4>> = true;
_instm0(_instm1, ); _instm0(_instm2, __cdecl); _instm0(_instm2, __vectorcall); _instm0(_instm3, __stdcall);
//_instm0(_instm3, __fastcall); _instm0(_instm3, __thiscall);
#undef _instm0
#undef _instm1
#undef _instm2
#undef _instm3
_ywm_ns_close___________________________________________________(_zyx)
_ywm_ns_start___________________________________________________(type)

// checks if the type is void.
template<typename T_> inline constexpr bool is_void = is_same<remove_cv<T_>, void>;

// checks if the type is nullptr_t.
template<typename T_> inline constexpr bool is_nullptr = is_same<remove_cv<T_>, nullptr_t>;

// checks if the type is bool.
template<typename T_> inline constexpr bool is_bool = is_same<remove_cv<T_>, bool>;

// checks if the type is cat (character type).
template<typename T_> inline constexpr bool is_cat = is_included<T_, cat0, cat1, cat2, cat4>;

// checks if the type is int (integral value type).
template<typename T_> inline constexpr bool is_int = is_included<T_, int1, int2, int4, int8>;

// checks if the type is nat (natural value type).
template<typename T_> inline constexpr bool is_nat = is_included<T_, nat1, nat2, nat4, nat8>;

// checks if the type is fat (floating-point value type).
template<typename T_> inline constexpr bool is_fat = is_included<T_, fat4, fat8>;

// checks if the type is for counting.
template<typename T_> inline constexpr bool is_count = is_int<T_> || is_nat<T_>;

// checks if the type is for quantifying
template<typename T_> inline constexpr bool is_quant = is_count<T_> || is_fat<T_>;

// checks if the type has integral value.
template<typename T_> inline constexpr bool is_integral = is_bool<T_> || is_cat<T_> || is_count<T_>;

// checks if the type has signed value.
template<typename T_> inline constexpr bool is_signed = is_integral<T_> ? (static_cast<remove_cv<T_>>(-1) < static_cast<remove_cv<T_>>(0)) : is_fat<T_>;

// checks if the type has unsigned value.
template<typename T_> inline constexpr bool is_unsigned = is_integral<T_> ? !is_signed<T_> : false;

// checks if the type is function.
template<typename T_> inline constexpr bool is_function = !is_const<const T_> && !is_ref<T_>;

// checks if the type is object.
template<typename T_> inline constexpr bool is_object = !is_function<T_>;

// chcecks if the type is member function pointer.
template<typename T_> inline constexpr bool is_memptr_function = _zyx::ywtype_is_memptr_function<T_>;

// checks if the type is member object pointer.
template<typename T_> inline constexpr bool is_memptr_object = false;
template<typename Ret_, typename Cls_> inline constexpr bool is_memptr_object<Ret_ Cls_::*> = !is_function<Ret_>;

// checks if the type is member pointer.
template<typename T_> inline constexpr bool is_memptr = is_memptr_function<T_> || is_memptr_object<T_>;

// checks if the type is scalar.
template<typename T_> inline constexpr bool is_scalar = is_integral<T_> || is_fat<T_> || is_enum<T_> || is_ptr<T_> || is_memptr<T_> || is_nullptr<T_>;

// checks if the type is fundamental.
template<typename T_> inline constexpr bool is_fundamental = is_integral<T_> || is_fat<T_> || is_void<T_> || is_nullptr<T_>;

// checks if the type is compound.
template<typename T_> inline constexpr bool is_compound = !is_fundamental<T_>;

// checks if the type is enum.
//template<typename T_> inline constexpr bool is_enum;

// checks if the type is union.
//template<typename T_> inline constexpr bool is_union;

// checks if the type is class.
//template<typename T_> inline constexpr bool is_class;
_ywm_ns_close___________________________________________________(type)
#pragma endregion

#pragma region declval
_ywm_ns_start___________________________________________________(_zyx)
template<typename T_> struct ywtype_declval_agent { static const bool stop = false; typename ywtype_add_ref<T_>::type_rv delegate()noexcept; };
_ywm_ns_close___________________________________________________(_zyx)
_ywm_ns_start___________________________________________________(type)

// obtains any non-evaluable value for noexcept(), decltype(), etc..
template<typename T_> type::add_ref_rv<T_> declval(void)noexcept { static_assert(_zyx::ywtype_declval_agent<T_>::stop); return _zyx::ywtype_declval_agent<T_>::delegate(); }
_ywm_ns_close___________________________________________________(type)
#pragma endregion

#pragma region is_convertible
_ywm_ns_start___________________________________________________(_zyx)
template<typename T_, T_ V_> using ywtype_is_convertible_t = void;
template<typename To_, typename From_, typename Void_ = void> inline constexpr bool ywtype_is_convertible = false;
template<typename To_, typename From_> inline constexpr bool ywtype_is_convertible<To_, From_, ywtype_is_convertible_t<To_, type::declval<From_>()>> = true;
template<typename To_> void ywtype_is_nothrow_convertible_f(To_)noexcept;
template<typename To_, typename From_, bool B1_ = ywtype_is_convertible<To_, From_>, bool B2_ = type::is_void<To_>> inline constexpr bool ywtype_is_nothrow_convertible = noexcept(ywtype_is_nothrow_convertible_f<To_>(type::declval<From_>()));
template<typename To_, typename From_, bool B2_> inline constexpr bool ywtype_is_nothrow_convertible<To_, From_, false, B2_> = false;
template<typename To_, typename From_> inline constexpr bool ywtype_is_nothrow_convertible<To_, From_, true, true> = ture;
_ywm_ns_close___________________________________________________(_zyx)
_ywm_ns_start___________________________________________________(type)
template<typename To_, typename From_> inline constexpr bool is_convertible = _zyx::ywtype_is_convertible<To_, From_, type::declval<From_>()>;
template<typename To_, typename From_> inline constexpr bool is_nothrow_convertible = _zyx::ywtype_is_nothrow_convertible<To_, From_>;
_ywm_ns_close___________________________________________________(type)
#pragma endregion

#pragma region is_base_of

#pragma endregion

#pragma region invoke
_ywm_ns_start___________________________________________________(_zyx)
enum class ywtype_invoker_strategy { _Functor, _Pmf_object, _Pmf_refwrap, _Pmf_pointer, _Pmd_object, _Pmd_refwrap, _Pmd_pointer };
struct ywtype_invoker_functor {
  static constexpr ywtype_invoker_strategy _Strategy = ywtype_invoker_strategy::_Functor;
  template<typename Callable_, typename... Ts_> static constexpr auto _Call(Callable_&& Obj_, Ts_&&... As_)noexcept(noexcept(static_cast<Callable_&&>(Obj_)(static_cast<Ts_&&>(As_)...))) -> decltype(static_cast<Callable_&&>(Obj_)(static_cast<Ts_&&>(As_)...)) { return static_cast<Callable_&&>(Obj_)(static_cast<Ts_&&>(As_)...); }
};
struct ywtype_invoker_pmf_object {
  static constexpr ywtype_invoker_strategy _Strategy = ywtype_invoker_strategy::_Pmf_object;
  template<typename Decayed_, typename T1_, typename... Ts_> static constexpr auto _Call(Decayed_ Pmf_, T1_&& A1_, Ts_&&... As_)noexcept(noexcept((static_cast<T1_&&>(A1_).*Pmf_)(static_cast<Ts_&&>(As_)...))) -> decltype((static_cast<T1_&&>(A1_).*Pmf_)(static_cast<Ts_&&>(As_)...)) { return (static_cast<T1_&&>(A1_).*Pmf_)(static_cast<Ts_&&>(As_)...); }
};
struct ywtype_invoker_pmf_refwrap {
  static constexpr ywtype_invoker_strategy _Strategy = ywtype_invoker_strategy::_Pmf_refwrap;
  template<typename Decayed_, typename T1_, typename... Ts_> static constexpr auto _Call(Decayed_ Pmf_, T1_ A1_, Ts_&&... As_)noexcept(noexcept((A1_.get().*Pmf_)(static_cast<Ts_&&>(As_)...))) -> decltype((A1_.get().*Pmf_)(static_cast<Ts_&&>(As_)...)) { return (A1_.get().*Pmf_)(static_cast<Ts_&&>(As_)...); }
};
struct ywtype_invoker_pmf_pointer {
  static constexpr ywtype_invoker_strategy _Strategy = ywtype_invoker_strategy::_Pmf_pointer;
  template<typename Decayed_, typename T1_, typename... Ts_> static constexpr auto _Call(Decayed_ Pmf_, T1_&& A1_, Ts_&&... As_)noexcept(noexcept(((*static_cast<T1_&&>(A1_)).*Pmf_)(static_cast<Ts_&&>(As_)...))) -> decltype(((*static_cast<T1_&&>(A1_)).*Pmf_)(static_cast<Ts_&&>(As_)...)) { return ((*static_cast<T1_&&>(A1_)).*Pmf_)(static_cast<Ts_&&>(As_)...); }
};
struct ywtype_invoker_pmd_object {
  static constexpr ywtype_invoker_strategy _Strategy = ywtype_invoker_strategy::_Pmd_object;
  template<typename Decayed_, typename T1_> static constexpr auto _Call(Decayed_ Pmd_, T1_&& A1_)noexcept -> decltype(static_cast<T1_&&>(A1_).*Pmd_) { return static_cast<T1_&&>(A1_).*Pmd_; }
};
struct ywtype_invoker_pmd_refwrap {
  static constexpr ywtype_invoker_strategy _Strategy = ywtype_invoker_strategy::_Pmd_refwrap;
  template<typename Decayed_, typename _Refwrap> static constexpr auto _Call(Decayed_ Pmd, _Refwrap A1_)noexcept -> decltype(A1_.get().*Pmd) { return A1_.get().*Pmd; }
};
struct ywtype_invoker_pmd_pointer {
  static constexpr ywtype_invoker_strategy _Strategy = ywtype_invoker_strategy::_Pmd_pointer;
  template<typename Decayed_, typename T1_> static constexpr auto _Call(Decayed_ Pmd, T1_&& A1_)noexcept(noexcept((*static_cast<T1_&&>(A1_)).*Pmd)) -> decltype((*static_cast<T1_&&>(A1_)).*Pmd) { return (*static_cast<T1_&&>(A1_)).*Pmd; }
};
template<typename Callable_, typename T1_, typename Removed_cvref_ = type::remove_cvref<Callable_>, bool _Is_pmf = type::is_memptr_function<Removed_cvref_>, bool _Is_pmd = type::is_memptr_object<Removed_cvref_>> struct _Invoker1;
template<typename Callable_, typename T1_, typename Removed_cvref_> struct _Invoker1<Callable_, T1_, Removed_cvref_, true, false> : type::switch_<type::is_base_of<typename _Is_memfunptr<Removed_cvref_>::_Class_type, remove_reference_t<T1_>>, ywtype_invoker_pmf_object, type::switch_<_Is_specialization_v<_Remove_cvref_t<T1_>, reference_wrapper>, ywtype_invoker_pmf_refwrap, ywtype_invoker_pmf_pointer>> {}; template<typename Callable_, typename T1_, typename Removed_cvref_>
struct _Invoker1<Callable_, T1_, Removed_cvref_, false, true> : type::switch_<type::is_base_of<typename _Is_member_object_pointer<Removed_cvref_>::_Class_type, remove_reference_t<T1_>>, ywtype_invoker_pmd_object, type::switch_<_Is_specialization_v<_Remove_cvref_t<T1_>, reference_wrapper>, ywtype_invoker_pmd_refwrap, ywtype_invoker_pmd_pointer>> {};
template<typename Callable_, typename T1_, typename Removed_cvref_> struct _Invoker1<Callable_, T1_, Removed_cvref_, false, false> : ywtype_invoker_functor {};

_ywm_ns_close___________________________________________________(_zyx)
_ywm_ns_start___________________________________________________(util)
template<typename Callable_> constexpr auto invoke(Callable_&& Obj_)noexcept(noexcept(static_cast<Callable_&&>(Obj_)())) -> decltype(static_cast<Callable_&&>(Obj_)()) { return static_cast<Callable_&&>(Obj_)(); }
template <class Callable_, class T1_, class... Ts_> constexpr auto invoke(Callable_&& _Obj, T1_&& _Arg1, Ts_&&... _Args2)
  noexcept(noexcept(_Invoker1<Callable_, T1_>::_Call(static_cast<Callable_&&>(_Obj), static_cast<T1_&&>(_Arg1), static_cast<Ts_&&>(_Args2)...)))
  -> decltype(_Invoker1<Callable_, T1_>::_Call(static_cast<Callable_&&>(_Obj), static_cast<T1_&&>(_Arg1), static_cast<Ts_&&>(_Args2)...)) {
  if      constexpr (_Invoker1<Callable_, T1_>::_Strategy == _Invoker_strategy::_Functor) { return static_cast<Callable_&&>(_Obj)(static_cast<T1_&&>(_Arg1), static_cast<Ts_&&>(_Args2)...); }
  else if constexpr (_Invoker1<Callable_, T1_>::_Strategy == _Invoker_strategy::_Pmf_object) { return (static_cast<T1_&&>(_Arg1).*_Obj)(static_cast<Ts_&&>(_Args2)...); }
  else if constexpr (_Invoker1<Callable_, T1_>::_Strategy == _Invoker_strategy::_Pmf_refwrap) { return (_Arg1.get().*_Obj)(static_cast<Ts_&&>(_Args2)...); }
  else if constexpr (_Invoker1<Callable_, T1_>::_Strategy == _Invoker_strategy::_Pmf_pointer) { return ((*static_cast<T1_&&>(_Arg1)).*_Obj)(static_cast<Ts_&&>(_Args2)...); }
  else if constexpr (_Invoker1<Callable_, T1_>::_Strategy == _Invoker_strategy::_Pmd_object) { return static_cast<T1_&&>(_Arg1).*_Obj; }
  else if constexpr (_Invoker1<Callable_, T1_>::_Strategy == _Invoker_strategy::_Pmd_refwrap) { return _Arg1.get().*_Obj; }
  else { static_assert(_Invoker1<Callable_, T1_>::_Strategy == _Invoker_strategy::_Pmd_pointer, "bug in invoke"); return (*static_cast<T1_&&>(_Arg1)).*_Obj; }
}
_ywm_ns_close___________________________________________________(util)
#pragma endregion

#pragma region is_invocable
_ywm_ns_start___________________________________________________(_zyx)
template<typename Callable_> using ywtype_decltype_invoke_zero = decltype(ywtype_declval<Callable_>()());
template<typename Callable_, typename T_, typename... Ts_> using ywtype_decltype_invoke_nonzero = decltype();
template<typename Callable_, typename Void_> struct ywtype_invoke_traits_zero {
  static inline constexpr bool is_invocable = false;
  static inline constexpr bool is_nothrow_invocable = false;
  template<typename Ret_> static inline constexpr bool is_invocable_r = false;
  template<typename Ret_> static inline constexpr bool is_nothrow_invocable_r = false;
};
template<typename Callable_> struct ywtype_invoke_traits_zero<Callable_, type::void_t<ywtype_decltype_invoke_zero<Callable_>>> {
  using type = ywtype_decltype_invoke_zero<Callable_>;
  static inline constexpr bool is_invocable = true;
  static inline constexpr bool is_nothrow_invocable = noexcept(ywtype_declval<Callable_>()());
  template<typename Ret_> static inline constexpr bool is_invocable_r = type::disjunction<type::is_void<Ret_>, ywtype_is_convertible<type, Ret_>>;
  template<typename Ret_> static inline constexpr bool is_nothrow_invocable_r = type::conjunction<is_nothrow_invocable, type::disjunction<is_void<Ret_>, type::is_nothrow_convertible<type, Ret_>>>;
};
template<typename Void_, typename... Ts_> struct ywtype_invoke_traits_nonzero {
  static inline constexpr bool is_invocable = false;
  static inline constexpr bool is_nothrow_invocable = false;
  template<typename Ret_> static inline constexpr bool is_invocable_r = false;
  template<typename Ret_> static inline constexpr bool is_nothrow_invocable_r = false;
};
_ywm_ns_close___________________________________________________(_zyx)

#pragma endregion

#pragma region Advanced

_ywm_ns_start___________________________________________________(type)



// checks if From_ is convertible to To_ implicitly.
template<typename To_, typename From_> inline constexpr bool is_convertible = _zyx::ywtype_is_convertible<To_, From_>;

// checks if the type is trivial.
//template<class T_> inline constexpr bool is_trivial;

// checks if the type is empty class.
//template<class T_> inline constexpr bool is_empty;

// checks if the type is polymorphic class.
//template<class T_> inline constexpr bool is_polymorphic;

// checks if the type is abstract class.
//template<class T_> inline constexpr bool is_abstract;

// checks if the type is final class.
//template<class T_> inline constexpr bool is_final;

// checks if the type is aggregate.
//template<class T_> inline constexpr bool is_aggregate;

// checks if the type is trivially copyable.
//template<class T_> inline constexpr bool is_trivially_copyable;

// checks if the type has standard layout.
//template<class T_> inline constexpr bool is_standard_layout;

//template<class T_> inline constexpr bool has_unique_object_representations;
//template<class Base_, class Derived_> inline constexpr bool is_base_of;

//template<class T_, class... Args_> inline constexpr bool is_constructible;
//template<class T_, class... Args_> inline constexpr bool is_nothrow_constructible;
//template<class T_, class... Args_> inline constexpr bool is_trivially_constructible;
//template<class T_> inline constexpr bool is_constructible_default = __is_constructible(T_);
//template<class T_> inline constexpr bool is_nothrow_constructible_default;
//template<class T_> inline constexpr bool is_trivially_constructible_default;
//template<class T_> inline constexpr bool is_constructible_copy;
//template<class T_> inline constexpr bool is_nothrow_constructible_copy;
//template<class T_> inline constexpr bool is_trivially_constructible_copy;
//template<class T_> inline constexpr bool is_constructible_move;
//template<class T_> inline constexpr bool is_nothrow_constructible_move;
//template<class T_> inline constexpr bool is_trivially_constructible_move;
//template<class To_, class From_> inline constexpr bool is_assignable;
//template<class To_, class From_> inline constexpr bool is_nothrow_assignable;
//template<class To_, class From_> inline constexpr bool is_trivially_assignable;;
//template<class T_> inline constexpr bool is_assignable_copy;
//template<class T_> inline constexpr bool is_nothrow_assignable_copy;
//template<class T_> inline constexpr bool is_trivially_assignable_copy;
//template<class T_> inline constexpr bool is_assignable_move;
//template<class T_> inline constexpr bool is_nothrow_assignable_move;
//template<class T_> inline constexpr bool is_trivially_assignable_move;
//template<class T_> inline constexpr bool is_destructible;
//template<class T_> inline constexpr bool is_nothrow_destructible;
//template<class T_> inline constexpr bool is_trivially_destructible;
//template<class T_> inline constexpr bool has_virtual_destructor;
_ywm_ns_close___________________________________________________(type)
#pragma endregion

#pragma region Make_Type
_ywm_ns_start___________________________________________________(_zyx)
template<natt N_> struct ywtype_make {};
template<> struct ywtype_make<1> { using type_c = cat1; using type_i = int1; using type_n = nat1; };
template<> struct ywtype_make<2> { using type_c = cat2; using type_i = int2; using type_n = nat2; };
template<> struct ywtype_make<4> { using type_c = cat4; using type_i = int4; using type_n = nat4; using type_f = fat4; };
template<> struct ywtype_make<8> { using type_i = int8; using type_n = nat8; using type_f = fat8; };
_ywm_ns_close___________________________________________________(_zyx)
_ywm_ns_start___________________________________________________(type)

// makes cat-type has sepcified size.
template<natt N_> using make_cat = typename _zyx::ywtype_make<N_>::type_c;

// makes int-type has sepcified size.
template<natt N_> using make_int = typename _zyx::ywtype_make<N_>::type_i;

// makes nat-type has sepcified size.
template<natt N_> using make_nat = typename _zyx::ywtype_make<N_>::type_n;

// makes fat-type has sepcified size.
template<natt N_> using make_fat = typename _zyx::ywtype_make<N_>::type_f;
_ywm_ns_close___________________________________________________(type)
#pragma endregion


_ywm_ns_start___________________________________________________(util)

// checks if it is constant-evaluating now.
inline constexpr bool constevaluating(void)noexcept { return __builtin_is_constant_evaluated(); }
_ywm_ns_close___________________________________________________(util)

_ywm_ns_close___________________________________________________(yw)
