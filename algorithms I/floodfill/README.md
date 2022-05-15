Implemente um programa em múltiplos arquivos que demonstre o resultado do 
algoritmo flood fill recursivo (instanciado chamadas recursivas para os 
vizinhos norte-sul-leste-oeste 
[veja o pseudocódigo](https://en.wikipedia.org/wiki/Flood_fill#Stack-based_recursive_implementation_.28four-way.29)).
Seu programa deve receber como entrada pelo teclado o nome do arquivo de entrada 
e fornecer na tela do terminal o resultado final do algoritmo. Caso o arquivo de 
entrada não exista, seu programa deve imprimir a mensagem 
"Erro arquivo inexistente\n".

O programa deve necessariamente estar subdividido em três arquivos:

- main.c - programa principal
- floodfill.h - protótipos das funções usadas no programa principal
- floodfill.c - implementações das funções criadas para este trabalho

Arquivo texto de entrada:
20 linhas, cada uma com 20 caracteres contendo os pixels da matriz Imagem.
na linha 21 o arquivo deve conter a coordenada x (xis) seguida da coordenada y 
(ipslon) a partir da qual o floodfil deve começar a ser aplicado.

Os elementos da matriz imagem são do tipo caracter. O caracter 'X' indica que o 
pixel está aceso, enquanto ' ' (caracter espaço) indica que o pixel está 
apagado.

Referências:
[Algoritmo flood fill na wikipedia](https://en.wikipedia.org/wiki/Flood_fill)