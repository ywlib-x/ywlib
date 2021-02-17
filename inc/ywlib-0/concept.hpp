#pragma once
#include "../../ywlib"
#include "./type.hpp"

_ywm_ns_start___________________________________________________(yw)

template<class T_> concept _cat = type::is_cat<T_>;
template<class T_> concept _int = type::is_int<T_>;
template<class T_> concept _nat = type::is_nat<T_>;
template<class T_> concept _fat = type::is_fat<T_>;

template<class T_> concept _count = type::is_count<T_>;
template<class T_> concept _quant = type::is_quant<T_>;

_ywm_ns_close___________________________________________________(yw)
