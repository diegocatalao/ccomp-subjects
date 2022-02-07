/**
 * @file exercicio_u1.1.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Exercício U1.1 -Tabela de temperatura Célsius -> Fahrenheit usando o laço for
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 * Exercício U1.1 -Tabela de temperatura Célsius -> Fahrenheit usando o laço for
 * Faça uma tabela com as temperaturas em graus Célsius e Fahrenheit.
 * Os valores em Célsius são -10, 0, 10, 20, 30, 40, 50. A cada linha na tela seu
 * programa deve imprimir a temperatura em graus Célsius, caracter de tabulação e
 * a temperatura em Fahrenheit. As temperaturas deve ser armazenadas usando o tipo
 * float e devem ser apresentadas com duas casas decimais, para isso é necessário
 * usar a formatação "%.2f".
 * Nas estruturas de repetição, somente é permitido utilizar o comando for.
 */
#include <stdio.h>

int main(int argc,char* argv[]) {
	float fahrenheit;

	printf("Célsius\t\tFahrenheit\n");

	for (float celsius = -10; celsius <= 50; celsius += 10) {
		fahrenheit = 1.8*celsius + 32;
		printf("%.2f\t\t%.2f\n", celsius, fahrenheit);
	}

	return 0;
}