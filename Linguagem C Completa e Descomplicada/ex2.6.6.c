// 6) Faça um programa que leia um valor do tipo double e depois o imprima na forma
// de notação científica.
#include <stdio.h>

int main(int argc, char const *argv[]) {
	double notacao;

	scanf("%lf", &notacao);
	printf("%E", notacao);

	return 0;
}
