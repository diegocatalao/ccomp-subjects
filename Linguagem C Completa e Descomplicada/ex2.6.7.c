// 7) Elabore um programa que leia um caractere e depois o imprima como um valor
// inteiro.
#include <stdio.h>

int main(int argc, char const *argv[]) {
	char entrada;

	entrada = getchar();
	printf("%d", entrada);

	return 0;
}