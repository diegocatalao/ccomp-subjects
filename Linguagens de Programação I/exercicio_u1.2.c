/**
 * @file exercicio_u1.2.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Exercício U1.2 - Primeiro programa C
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 * Exercício U1.2 - Primeiro programa C
 * Escreva um programa que leia dois números inteiros pelo teclado e imprima
 * na tela do terminal quociente e o remaindero da divisão.
 * Caso o valor do divisor seja zero o programa deve evitar erro de divisão
 * por zero, imprimindo a mensagem: "Erro: divisor igual a zero."
 */

#include <stdio.h>

int main(int argc,char* argv[]) {
	int dividend, divisor;
	int quocient, remainder;

	printf("Entre com o primeiro número: ");
	scanf("%d", &dividend);
	printf("Entre com o segundo número: ");
	scanf("%d", &divisor);

	quocient = dividend / divisor;
	remainder = dividend % divisor;

	printf("Quociente: %d\n", quocient);
	printf("Resto: %d\n", remainder);

	return 0;
}