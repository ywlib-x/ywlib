#pragma once
#include "./type.hpp"
_ywm_ns_start___________________________________________________(yw)
_ywm_ns_start___________________________________________________(type)



template<class _Void, class _Callable> struct _Invoke_traits_zero {
  static inline constexpr bool is_invocable = false;
  static inline constexpr bool is_nothrow_invocable = false;
  template<class _Rx> static inline constexpr bool is_invocable_r = false;
  template<class _Rx> static inline constexpr bool is_nothrow_invocable_r = false;
};

template<class _Callable> using _Decltype_invoke_zero = decltype(util::declval<_Callable>()());
template<class _Callable> struct _Invoke_traits_zero<void_t<_Decltype_invoke_zero<_Callable>>, _Callable> {
  using type = _Decltype_invoke_zero<_Callable>;
  static inline constexpr bool is_invocable = true;
  static inline constexpr bool is_nothrow_invocable = noexcept(util::declval<_Callable>()());
  template<class _Rx> static inline constexpr bool is_invocable_r = disjunction<is_void<_Rx>, 
  template<class _Rx> static inline constexpr bool is_nothrow_invocable_r = false;
  template <class _Rx> using _Is_invocable_r = bool_constant<disjunction_v<is_void<_Rx>, is_convertible<type, _Rx>>>;
  template <class _Rx>
  using _Is_nothrow_invocable_r = bool_constant<
      conjunction_v<_Is_nothrow_invocable, disjunction<is_void<_Rx>, _Is_nothrow_convertible<type, _Rx>>>>;
};

template <class _Void, class... _Types>
struct _Invoke_traits_nonzero {
  // selected when _Callable isn't callable with nonzero _Args
  using _Is_invocable         = false_type;
  using _Is_nothrow_invocable = false_type;
  template <class _Rx>
  using _Is_invocable_r = false_type;
  template <class _Rx>
  using _Is_nothrow_invocable_r = false_type;
};

template <class _Callable, class _Ty1, class... _Types2>
using _Decltype_invoke_nonzero = decltype(
  _Invoker1<_Callable, _Ty1>::_Call(_STD declval<_Callable>(), _STD declval<_Ty1>(), _STD declval<_Types2>()...));

template <class _Callable, class _Ty1, class... _Types2>
struct _Invoke_traits_nonzero<void_t<_Decltype_invoke_nonzero<_Callable, _Ty1, _Types2...>>, _Callable, _Ty1,
  _Types2...> {
  // selected when _Callable is callable with nonzero _Args
  using type                  = _Decltype_invoke_nonzero<_Callable, _Ty1, _Types2...>;
  using _Is_invocable         = true_type;
  using _Is_nothrow_invocable = bool_constant<noexcept(_Invoker1<_Callable, _Ty1>::_Call(
      _STD declval<_Callable>(), _STD declval<_Ty1>(), _STD declval<_Types2>()...))>;
  template <class _Rx>
  using _Is_invocable_r = bool_constant<disjunction_v<is_void<_Rx>, is_convertible<type, _Rx>>>;
  template <class _Rx>
  using _Is_nothrow_invocable_r = bool_constant<
      conjunction_v<_Is_nothrow_invocable, disjunction<is_void<_Rx>, _Is_nothrow_convertible<type, _Rx>>>>;
};


template <class _Callable, class... _Args>
using _Select_invoke_traits = conditional_t<sizeof...(_Args) == 0, _Invoke_traits_zero<void, _Callable>,
  _Invoke_traits_nonzero<void, _Callable, _Args...>>;

template <class _Callable, class... _Args>
inline constexpr bool is_invocable_v = _Select_invoke_traits<_Callable, _Args...>::_Is_invocable::value;

_ywm_ns_close___________________________________________________(type)
_ywm_ns_close___________________________________________________(yw)