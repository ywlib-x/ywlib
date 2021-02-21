#pragma once
#include "../../ywlib"

#define _decl_0(Name_, ...) extern fat4 (__cdecl& Name_##f)(__VA_ARGS__)noexcept; extern fat8 (__cdecl& Name_##d)(__VA_ARGS__)noexcept; extern ld_t (__cdecl& Name_##l)(__VA_ARGS__)noexcept;
#define _decl_1(Name_) extern fat4 (__cdecl& Name_##f)(fat4)noexcept; extern fat8 (__cdecl& Name_##d)(fat8)noexcept; extern ld_t (__cdecl& Name_##l)(ld_t)noexcept;
#define _decl_2(Name_) extern fat4 (__cdecl& Name_##f)(fat4, fat4)noexcept; extern fat8 (__cdecl& Name_##d)(fat8, fat8)noexcept; extern ld_t (__cdecl& Name_##l)(ld_t, ld_t)noexcept;
#define _decl_3(Name_) extern fat4 (__cdecl& Name_##f)(fat4, fat4, fat4)noexcept; extern fat8 (__cdecl& Name_##d)(fat8, fat8, fat8)noexcept; extern ld_t (__cdecl& Name_##l)(ld_t, ld_t, ld_t)noexcept;
#define _decl_1V(Name_, ...) extern fat4 (__cdecl& Name_##f)(fat4, __VA_ARGS__)noexcept; extern fat8 (__cdecl& Name_##d)(fat8, __VA_ARGS__)noexcept; extern ld_t (__cdecl& Name_##l)(ld_t, __VA_ARGS__)noexcept;
#define _decl_1R(Name_, Ret_) extern Ret_ (__cdecl& Name_##f)(fat4)noexcept; extern Ret_ (__cdecl& Name_##d)(fat8)noexcept; extern Ret_ (__cdecl& Name_##l)(ld_t)noexcept;
#define _decl_1P(Name_) extern fat4 (__cdecl& Name_##f)(fat4, fat4*)noexcept; extern fat8 (__cdecl& Name_##d)(fat8, fat8*)noexcept; extern ld_t (__cdecl& Name_##l)(ld_t, ld_t*)noexcept;
#define _decl_2V(Name_, ...) extern fat4 (__cdecl& Name_##f)(fat4, fat4, __VA_ARGS__)noexcept; extern fat8 (__cdecl& Name_##d)(fat8, fat8, __VA_ARGS__)noexcept; extern ld_t (__cdecl& Name_##l)(ld_t, ld_t, __VA_ARGS__)noexcept;

_ywm_ns_start___________________________________________________(yw)
_ywm_ns_start___________________________________________________(_std)

using float_t = float;
using double_t = double;

inline constexpr fat4 INFINITY  = static_cast<fat4>(1e+300 * 1e+300);
inline constexpr fat8 HUGE_VAL  = static_cast<fat8>(INFINITY);
inline constexpr fat4 HUGE_VALF = static_cast<fat4>(INFINITY);
inline constexpr ld_t HUGE_VALL = static_cast<ld_t>(INFINITY);

inline constexpr fat4 NAN = static_cast<fat4>(INFINITY * 0.0f);
inline constexpr intt FP_INFINITE = 1;
inline constexpr intt FP_NAN = 2;
inline constexpr intt FP_NORMAL = -1;
inline constexpr intt FP_SUBNORMAL = -2;
inline constexpr intt FP_ZERO = 0;
inline constexpr intt FP_ILOGB0 = -0x80000000;
inline constexpr intt FP_ILOGBNAN = 0x7FFFFFFF;
inline constexpr intt MATH_ERRNO = 1;
inline constexpr intt MATH_ERREXCEPT = 2;

inline constexpr natt math_errhandling = MATH_ERRNO | MATH_ERREXCEPT;

_decl_1(acos);
_decl_1(asin);
_decl_1(atan);
_decl_2(atan2);
_decl_1(cos);
_decl_1(sin);
_decl_1(tan);
_decl_1(acosh);
_decl_1(asinh);
_decl_1(atanh);
_decl_1(cosh);
_decl_1(sinh);
_decl_1(tanh);

_decl_1(exp);
_decl_1(exp2);
_decl_1(expm1);
_decl_1(log);
_decl_1(log2);
_decl_1(log10);
_decl_1(log1p);

_decl_2(ldexp, int4);
_decl_1V(frexp, int4*);
_decl_1R(ilogb, int4);
_decl_1(logb);

_decl_1P(modf);
_decl_1V(scalbn, int4);
_decl_1V(scalbln, sl_t);

_decl_1(fabs);
_decl_1(sqrt);
_decl_1(cbrt);
_decl_2(hypot);
_decl_3(hypot3);
_decl_1(pow);

_decl_1(erf);
_decl_1(erfc);
_decl_1(tgamma);
_decl_1(lgamma);

_decl_1(ceil);
_decl_1(floor);
_decl_1(nearbyint);
_decl_1(rint);
_decl_1R(lrint, ld_t);
_decl_1R(llrint, int8);
_decl_1(round);
_decl_1R(lround, ld_t);
_decl_1R(llround, int8);
_decl_1(trunc);

_decl_2(fmod);
_decl_2(remainder);
_decl_2V(remquo, int4*);

_decl_2(copysign);
_decl_0(nan, const cat0*);
_decl_2(nextafter);
_decl_1V(nexttoward, ld_t);

_decl_2(fdim);
_decl_2(fmax);
_decl_2(fmin);
_decl_3(fma);



float fdim(float x, float y);
double fdim(double x, double y);
long double fdim(long double x, long double y);
float fdimf(float x, float y);
long double fdiml(long double x, long double y);

float fmax(float x, float y);
double fmax(double x, double y);
long double fmax(long double x, long double y);
float fmaxf(float x, float y);
long double fmaxl(long double x, long double y);

float fmin(float x, float y);
double fmin(double x, double y);
long double fmin(long double x, long double y);
float fminf(float x, float y);
long double fminl(long double x, long double y);

float fma(float x, float y, float z);
double fma(double x, double y, double z);
long double fma(long double x, long double y, long double z);
float fmaf(float x, float y, float z);
long double fmal(long double x, long double y, long double z);

// linear interpolation
constexpr float lerp(float a, float b, float t) noexcept;
constexpr double lerp(double a, double b, double t) noexcept;
constexpr long double lerp(long double a, long double b, long double t) noexcept;

// classification / comparison functions
int fpclassify(float x);
int fpclassify(double x);
int fpclassify(long double x);

bool isfinite(float x);
bool isfinite(double x);
bool isfinite(long double x);

bool isinf(float x);
bool isinf(double x);
bool isinf(long double x);

bool isnan(float x);
bool isnan(double x);
bool isnan(long double x);

bool isnormal(float x);
bool isnormal(double x);
bool isnormal(long double x);

bool signbit(float x);
bool signbit(double x);
bool signbit(long double x);

bool isgreater(float x, float y);
bool isgreater(double x, double y);
bool isgreater(long double x, long double y);

bool isgreaterequal(float x, float y);
bool isgreaterequal(double x, double y);
bool isgreaterequal(long double x, long double y);

bool isless(float x, float y);
bool isless(double x, double y);
bool isless(long double x, long double y);

bool islessequal(float x, float y);
bool islessequal(double x, double y);
bool islessequal(long double x, long double y);

bool islessgreater(float x, float y);
bool islessgreater(double x, double y);
bool islessgreater(long double x, long double y);

bool isunordered(float x, float y);
bool isunordered(double x, double y);
bool isunordered(long double x, long double y);

// mathematical special functions

// associated Laguerre polynomials
double       assoc_laguerre(unsigned n, unsigned m, double x);
float        assoc_laguerref(unsigned n, unsigned m, float x);
long double  assoc_laguerrel(unsigned n, unsigned m, long double x);

// associated Legendre functions
double       assoc_legendre(unsigned l, unsigned m, double x);
float        assoc_legendref(unsigned l, unsigned m, float x);
long double  assoc_legendrel(unsigned l, unsigned m, long double x);

// beta function
double       beta(double x, double y);
float        betaf(float x, float y);
long double  betal(long double x, long double y);

// complete elliptic integral of the first kind
double       comp_ellint_1(double k);
float        comp_ellint_1f(float k);
long double  comp_ellint_1l(long double k);

// complete elliptic integral of the second kind
double       comp_ellint_2(double k);
float        comp_ellint_2f(float k);
long double  comp_ellint_2l(long double k);

// complete elliptic integral of the third kind
double       comp_ellint_3(double k, double nu);
float        comp_ellint_3f(float k, float nu);
long double  comp_ellint_3l(long double k, long double nu);

// regular modified cylindrical Bessel functions
double       cyl_bessel_i(double nu, double x);
float        cyl_bessel_if(float nu, float x);
long double  cyl_bessel_il(long double nu, long double x);

// cylindrical Bessel functions of the first kind
double       cyl_bessel_j(double nu, double x);
float        cyl_bessel_jf(float nu, float x);
long double  cyl_bessel_jl(long double nu, long double x);

// irregular modified cylindrical Bessel functions
double       cyl_bessel_k(double nu, double x);
float        cyl_bessel_kf(float nu, float x);
long double  cyl_bessel_kl(long double nu, long double x);

// cylindrical Neumann functions;
// cylindrical Bessel functions of the second kind
double       cyl_neumann(double nu, double x);
float        cyl_neumannf(float nu, float x);
long double  cyl_neumannl(long double nu, long double x);

// incomplete elliptic integral of the first kind
double       ellint_1(double k, double phi);
float        ellint_1f(float k, float phi);
long double  ellint_1l(long double k, long double phi);

// incomplete elliptic integral of the second kind
double       ellint_2(double k, double phi);
float        ellint_2f(float k, float phi);
long double  ellint_2l(long double k, long double phi);

// incomplete elliptic integral of the third kind
double       ellint_3(double k, double nu, double phi);
float        ellint_3f(float k, float nu, float phi);
long double  ellint_3l(long double k, long double nu, long double phi);

// exponential integral
double       expint(double x);
float        expintf(float x);
long double  expintl(long double x);

// Hermite polynomials
double       hermite(unsigned n, double x);
float        hermitef(unsigned n, float x);
long double  hermitel(unsigned n, long double x);

// Laguerre polynomials
double       laguerre(unsigned n, double x);
float        laguerref(unsigned n, float x);
long double  laguerrel(unsigned n, long double x);

// Legendre polynomials
double       legendre(unsigned l, double x);
float        legendref(unsigned l, float x);
long double  legendrel(unsigned l, long double x);

// Riemann zeta function
double       riemann_zeta(double x);
float        riemann_zetaf(float x);
long double  riemann_zetal(long double x);

// spherical Bessel functions of the first kind
double       sph_bessel(unsigned n, double x);
float        sph_besself(unsigned n, float x);
long double  sph_bessell(unsigned n, long double x);

// spherical associated Legendre functions
double       sph_legendre(unsigned l, unsigned m, double theta);
float        sph_legendref(unsigned l, unsigned m, float theta);
long double  sph_legendrel(unsigned l, unsigned m, long double theta);

// spherical Neumann functions;
// spherical Bessel functions of the second kind
double       sph_neumann(unsigned n, double x);
float        sph_neumannf(unsigned n, float x);
long double  sph_neumannl(unsigned n, long double x);
}

_ywm_ns_close___________________________________________________(_std)
_ywm_ns_close___________________________________________________(yw)
