/**
 * @file exercicio_u1.3.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Palíndromo
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 * Crie um programa que receba através do canal de entrada default uma string e teste se esta é um palíndromo.
 * Caso a string lida seja um palíndromo escreva na tela a palavra SIM (coloque um '\n' no final "SIM\n"),
 * caso contrário, escreva NAO. (coloque um '\n' no final "NAO\n")
 * Obs.: Para ler uma palavra pelo teclado use a função fgets ( char * str, int num, FILE * stream)
 * (onde o parâmetro stream deve receber o identificador stdin) e para saber o comprimento da string use a
 * função strlen(char* str)
 * Não desperdice memória, portanto não faça cópia da string ou mesmo de parte dela.
 */

#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]) {
	// Observações:
	// stdin: dispositivo de entrada padrão (geralmente o teclado)
	// palindromo: uma palavra que escrita ao contrario seja ela mesma

	char palavra[256]; 												// palavra e seu tamanho máximo de entrada
	
	printf("Esta palavra é um palindromo?: ");
	fgets(palavra, sizeof(palavra), stdin);							// pega a palavra não ignorando o espaço

	for (int counter = 0; counter != strlen(palavra) - 1; counter++) {	// pega todos os elementos da palavra
		if (palavra[counter] != palavra[strlen(palavra) - counter - 2]) {
			printf("NÃO\n");
			return 0;
		}
	}

	printf("SIM\n");
	return 0;
}