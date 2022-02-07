/**
 * @file exercicio_u1.3.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Conversão de binário (unsigned int) para decimal (sem sinal)
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 * Escreva um programa na linguagem C que leia uma string de tamanho qualquer contendo
 * dígitos binários e imprima na tela o valor decimal correspondente.
 * A leitura da entrada deve ser feita caracter a caracter usando a função getchar().
 */

#include <stdio.h>

int main(int argc,char* argv[]) {
	// Observações:
	// o professor não tem piedade das almas dos alunos

	char binary;													// caractere no buffer que o usuário vai digitar
	unsigned int decimal = 0;										// valor decimal do binário que o usuário deu

	printf("Entre com o número binário a ser convertido: \n");

	while ((binary != '\n') && (binary != EOF)) {					// enquanto o usuário não apertar enter, faça
		binary = getchar();											// pega a entrada que o usuário botou no buffer
		if (binary == '1') {										// se a entrada for igual ao caractere '1', faça
			decimal = (decimal << 1) + 1;							// move um bit a esquerda e adiciona 1 à 'decimal'
		} else if (binary == '0') {									// se a entrada for igual ao caractere '0' faça
			decimal = decimal << 1;									// move um bit a esquerda
		} else if ((binary != '\n') && (binary != EOF)) {			// se a entrada for uma entrada inválida
			printf("Erro: você só pode entrar com '0' ou '1'.\n");
			return -1;												// finaliza a execução do programa com -1 (erro)
		}
	}

	printf("O número binário inserido em decimal é: %d\n", decimal);
	return 0;
}