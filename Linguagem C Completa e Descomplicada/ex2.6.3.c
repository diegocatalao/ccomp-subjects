// 3) Escreva um programa que leia um número inteiro e depois imprima a mensagem
// “Valor lido:”, seguido do valor inteiro. Use apenas um comando printf().
#include <stdio.h>

int main(int argc, char const *argv[]) {
	int entrada;

	scanf("%d", &entrada);
	printf("Valor lido: %d\n", entrada);
	return 0;
}
