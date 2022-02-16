// 9) Faça um programa que leia dois valores do tipo float. Use um único comando de
// leitura para isso. Em seguida, imprima os valores lidos na ordem inversa em que eles
// foram lidos.
#include <stdio.h>

int main(int argc, char const *argv[]) {
	float entrada1, entrada2;

	scanf("%f%f", &entrada1, &entrada2);
	printf("%f, %f", entrada2, entrada1);
	
	return 0;
}
