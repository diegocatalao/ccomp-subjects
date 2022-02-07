/**
 * @file exercicio_u1.3.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Tamanho dos tipos primitivos da linguagem C
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 * Faça um programa que imprima os tamanhos dos tipos primitivos da linguagem C,
 * para isso use a função sizeof().
 * Exemplo: printf("O tamanho de um (char) é de %ld byte(s)\n", sizeof(char));
 * Os tamanhos devem ser impresso na seguinte ordem:
 * 1. char,
 * 2. short,
 * 3. int,
 * 4. long,
 * 5. long long,
 * 6. float,
 * 7. double,
 * 8. long double.
 */

#include <stdio.h>

int main(int argc,char* argv[]) {
	printf("O tamanho de um 'char' é de %ld byte(s).\n", sizeof(char));
	printf("O tamanho de um 'short' é de %ld byte(s).\n", sizeof(short));
	printf("O tamanho de um 'int' é de %ld byte(s).\n", sizeof(int));
	printf("O tamanho de um 'long' é de %ld byte(s).\n", sizeof(long));
	printf("O tamanho de um 'long' é de %ld byte(s).\n", sizeof(long long));
	printf("O tamanho de um 'float' é de %ld byte(s).\n", sizeof(float));
	printf("O tamanho de um 'double' é de %ld byte(s).\n", sizeof(double));
	printf("O tamanho de um 'long' é de %ld byte(s).\n", sizeof(long double));
	return 0;
}