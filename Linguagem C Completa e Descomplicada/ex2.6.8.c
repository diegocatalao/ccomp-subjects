// 8) Faça um programa que leia dois números inteiros e depois os imprima na ordem
// inversa em que eles foram lidos.
#include <stdio.h>

int main(int argc, char const *argv[]) {
	int first, second;

	scanf("%d", &first);
	scanf("%d", &second);

	printf("%d, %d", second, first);
	return 0;
}
