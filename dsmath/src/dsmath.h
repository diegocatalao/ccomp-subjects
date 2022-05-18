#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef DSMATH_H_
#define DSMATH_H_

#define dsmath_PI = M_PI
#define dsmath_E = M_E
#define dsmath_TAU = 2*M_PI
#define dsmath_INF = 'inf'
#define dsmath_NAN = 'nan'

typedef struct sElement1D {
	double value;
	struct sElement1D* next_ptr;
} Element1D;

typedef struct sVector1D {
	int size_l;
	Element1D* first_element_ptr;
	Element1D* last_element_ptr;
	Element1D* current_element_ptr;
} Vector1D;

/** Operações de inserção, remoção e ordenação da lista ligada */
Vector1D* Vector1D_init(void);
void Vector1D_append(Vector1D* linked_list, double value);
void Vector1D_remove(Vector1D* linked_list, int index);
void Vector1D_printf(Vector1D* linked_list);
/** Funções privadas ao módulo */
void __Vector1D_goto(Vector1D* vector1D_ptr, int index);

/** Operações matemáticas para a lista ligada */
void Vector1D_sin(Vector1D* linked_list);
void Vector1D_sin(Vector1D* linked_list);
void Vector1D_cos(Vector1D* linked_list);
void Vector1D_tan(Vector1D* linked_list);
void Vector1D_arcsin(Vector1D* linked_list);
void Vector1D_arccos(Vector1D* linked_list);
void Vector1D_arctan(Vector1D* linked_list);
void Vector1D_hypot(Vector1D* linked_list);
void Vector1D_arctan2(Vector1D* linked_list);
void Vector1D_degrees(Vector1D* linked_list);
void Vector1D_radians(Vector1D* linked_list);
void Vector1D_unwrap(Vector1D* linked_list);
void Vector1D_deg2rad(Vector1D* linked_list);
void Vector1D_rad2deg(Vector1D* linked_list);
void Vector1D_sinh(Vector1D* linked_list);
void Vector1D_cosh(Vector1D* linked_list);
void Vector1D_tanh(Vector1D* linked_list);
void Vector1D_arcsinh(Vector1D* linked_list);
void Vector1D_arccosh(Vector1D* linked_list);
void Vector1D_arctanh(Vector1D* linked_list);
void Vector1D_around(Vector1D* linked_list);
void Vector1D_round_(Vector1D* linked_list);
void Vector1D_rint(Vector1D* linked_list);
void Vector1D_fix(Vector1D* linked_list);
void Vector1D_floor(Vector1D* linked_list);
void Vector1D_ceil(Vector1D* linked_list);
void Vector1D_trunc(Vector1D* linked_list);
void Vector1D_prod(Vector1D* linked_list);
void Vector1D_sum(Vector1D* linked_list);
void Vector1D_nanprod(Vector1D* linked_list);
void Vector1D_nansum(Vector1D* linked_list);
void Vector1D_cumprod(Vector1D* linked_list);
void Vector1D_cumsum(Vector1D* linked_list);
void Vector1D_nancumprod(Vector1D* linked_list);
void Vector1D_nancumsum(Vector1D* linked_list);
void Vector1D_diff(Vector1D* linked_list);
void Vector1D_ediff1d(Vector1D* linked_list);
void Vector1D_gradient(Vector1D* linked_list);
void Vector1D_cross(Vector1D* linked_list);
void Vector1D_trapz(Vector1D* linked_list);
void Vector1D_exp(Vector1D* linked_list);
void Vector1D_expm1(Vector1D* linked_list);
void Vector1D_exp2(Vector1D* linked_list);
void Vector1D_log(Vector1D* linked_list);
void Vector1D_log10(Vector1D* linked_list);
void Vector1D_log2(Vector1D* linked_list);
void Vector1D_log1p(Vector1D* linked_list);
void Vector1D_logaddexp(Vector1D* linked_list);
void Vector1D_logaddexp2(Vector1D* linked_list);
void Vector1D_i0(Vector1D* linked_list);
void Vector1D_sinc(Vector1D* linked_list);
void Vector1D_signbit(Vector1D* linked_list);
void Vector1D_copysign(Vector1D* linked_list);
void Vector1D_frexp(Vector1D* linked_list);
void Vector1D_ldexp(Vector1D* linked_list);
void Vector1D_nextafter(Vector1D* linked_list);
void Vector1D_spacing(Vector1D* linked_list);
void Vector1D_lcm(Vector1D* linked_list);
void Vector1D_gcd(Vector1D* linked_list);
void Vector1D_add(Vector1D* linked_list);
void Vector1D_reciprocal(Vector1D* linked_list);
void Vector1D_positive(Vector1D* linked_list);
void Vector1D_negative(Vector1D* linked_list);
void Vector1D_multiply(Vector1D* linked_list);
void Vector1D_divide(Vector1D* linked_list);
void Vector1D_power(Vector1D* linked_list);
void Vector1D_subtract(Vector1D* linked_list);
void Vector1D_true_divide(Vector1D* linked_list);
void Vector1D_floor_divide(Vector1D* linked_list);
void Vector1D_float_power(Vector1D* linked_list);
void Vector1D_fmod(Vector1D* linked_list);
void Vector1D_mod(Vector1D* linked_list);
void Vector1D_modf(Vector1D* linked_list);
void Vector1D_remainder(Vector1D* linked_list);
void Vector1D_divmod(Vector1D* linked_list);
void Vector1D_angle(Vector1D* linked_list);
void Vector1D_real(Vector1D* linked_list);
void Vector1D_imag(Vector1D* linked_list);
void Vector1D_conj(Vector1D* linked_list);
void Vector1D_conjugate(Vector1D* linked_list);
void Vector1D_maximum(Vector1D* linked_list);
void Vector1D_fmax(Vector1D* linked_list);
void Vector1D_amax(Vector1D* linked_list);
void Vector1D_nanmax(Vector1D* linked_list);
void Vector1D_minimum(Vector1D* linked_list);
void Vector1D_fmin(Vector1D* linked_list);
void Vector1D_amin(Vector1D* linked_list);
void Vector1D_nanmin(Vector1D* linked_list);
void Vector1D_convolve(Vector1D* linked_list);
void Vector1D_clip(Vector1D* linked_list);
void Vector1D_sqrt(Vector1D* linked_list);
void Vector1D_cbrt(Vector1D* linked_list);
void Vector1D_square(Vector1D* linked_list);
void Vector1D_absolute(Vector1D* linked_list);
void Vector1D_fabs(Vector1D* linked_list);
void Vector1D_sign(Vector1D* linked_list);
void Vector1D_heaviside(Vector1D* linked_list);
void Vector1D_nan_to_num(Vector1D* linked_list);
void Vector1D_real_if_close(Vector1D* linked_list);
void Vector1D_interp(Vector1D* linked_list);

#endif