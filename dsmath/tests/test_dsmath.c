#include <stdio.h>
#include "debug.h"
#include "dsmath.h"

int __check_if_prime(int number) {
	for (int i = 2; i <= number/2; i++) {
		if ((number) % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char* argv[]) {
	Vector1D* vector1D_20_int = Vector1D_init();
	Vector1D* vector1D_20_primes = Vector1D_init();
	
	for (int value_d = 0; value_d <= 20; value_d++) {
		Vector1D_append(vector1D_20_int, value_d);
	}

	for (int value_d = 2; value_d <= 20; value_d++) {
		if (__check_if_prime(value_d)) {
			Vector1D_append(vector1D_20_primes, value_d);
		}
	}

	Vector1D_printf(vector1D_20_int);
	Vector1D_printf(vector1D_20_primes);

	return 0;
}