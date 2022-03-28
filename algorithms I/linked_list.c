/**
 * @file linked_list.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Este programa cria uma lista encadeada em C com as funções de inicializar, adicionar e remover
 * @version 0.1
 * @date 2022-03-22
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef int linked_list_value; 																		// tipo para o valor contido na lista
typedef int linked_list_size; 																		// tipo para o tamanho da lista
typedef int linked_list_max_val; 																	// tipo para o valor máximo da lista
typedef int linked_list_min_val; 																	// tipo para o valor mínimo da lista

typedef struct sElement {
	linked_list_value value;																		// valor da lista encadeada
	struct sElement* next_element_ptr;																// próxima estrutura da lista
} Element;
typedef struct sLinkedLists {			
	Element* first_element_ptr;																		// primeiro elemento da lista
	Element* current_element_ptr;																	// elemento atual da lista
} LinkedList;

linked_list_max_val LinkedList_max_value(LinkedList* linked_list);									// função que recupera o valor máximo da lista
linked_list_min_val LinkedList_min_value(LinkedList* linked_list);  								// função que recupera o valor mínimo da lista

void LinkedList_init(LinkedList* linked_list);														// função que inicializa a lista
void LinkedList_add_element(LinkedList* linked_list, int value);									// função que adiciona um elemento à lista
void LinkedList_remove_element(LinkedList* linked_list, int value); 								// função que remove um elemento da lista
linked_list_size LinkedList_size(LinkedList* linked_list);											// função que retorna o tamanho da lista
void LinkedList_printf(LinkedList* linked_list);													// função que mostra todos os elementos da lista

int main(int argc, char* argv[]) {
	LinkedList* linked_list = malloc(sizeof(LinkedList));											// aloca um espaço para a lista na memória

	LinkedList_init(linked_list);																	// inicializa a lista com um próximo nulo
	for (int i = 10; i > 0; i--) {
		LinkedList_add_element(linked_list, i);														// insere 10 elementos na lista
	}

	LinkedList_printf(linked_list);																	// mostra a lista no tamanho atual
	printf("Tamanho da lista encadeada: %d\n", LinkedList_size(linked_list));						// mostra o tamanho da lista
	printf("Valor máximo da lista: %d\n", LinkedList_max_value(linked_list));						// mostra o valor máximo da lista
	printf("Valor mínimo da lista: %d\n", LinkedList_min_value(linked_list));						// mostra o valor mínimo da lista
	return 0;
}

void LinkedList_init(LinkedList* linked_list) {
	(*linked_list).first_element_ptr = malloc(sizeof(LinkedList));									// aloca o primeiro elemento na memória
	(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;							// aponta o elemento atual como o primeiro elemento alocado
	(*linked_list).first_element_ptr->next_element_ptr = NULL;										// aponta o próximo elemento do primeiro elemento como nulo
}

void LinkedList_add_element(LinkedList* linked_list, int value) {
	while ((*linked_list).current_element_ptr->next_element_ptr != NULL) {							// enquanto o próximo elemento do elemento atual não for nulo (último)
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_element_ptr;	// aponta o elemento atual para o próximo elemento do elemento atual
	}

	(*linked_list).current_element_ptr->next_element_ptr = malloc(sizeof(Element));					// aloca o próximo elemento do elemento atual (último)
	(*linked_list).current_element_ptr->value = value;												// adiciona o valor do parâmetro no elemento atual
	(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_element_ptr;		// aponta o elemento atual para o próximo elemento (último elemento adicionado)
}

void LinkedList_remove_element(LinkedList* linked_list, int index) {
	Element *removedElement;																		// elemento que será removido da lista
	linked_list_size _linked_list_size = LinkedList_size(linked_list);								// tamanho da lista que será buscado

	if ((index < 0) || (index >= LinkedList_size(linked_list))) {									// se o usuário acessar um elemento que não está na lista
		raise(SIGSEGV);																				// segmentation fault
	}

	if (index == 0) {																				// se a remoção foi no início da lista
		removedElement = (*linked_list).first_element_ptr;											// seleciona para remover o primeiro elemento
		(*linked_list).current_element_ptr = removedElement->next_element_ptr;						// aponta o elemento atual para o próximo elemento do elemento a ser removido
		(*linked_list).first_element_ptr = removedElement->next_element_ptr;						// aponta o primeiro elemento ao próximo elemento do elemento a ser removido
		free(removedElement);																		// desaloca o elemento removido
		return;
	} else {																						// se não
		(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;						// aponta o elemento atual para o primeiro elemento
		for (int index_c = 0; index_c < index - 1; index_c++) {										// conta de 0 até o índice - 1 elemento que será removido da lista
			(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_element_ptr;// aponta o elemento atual para o próximo elemento do elemento atual
		}
		removedElement = (*linked_list).current_element_ptr->next_element_ptr;						// aponta o elemento a ser removido para o próximo elemento do elemento atual
		(*linked_list).current_element_ptr->next_element_ptr = removedElement->next_element_ptr;	// aponta o próximo elemento do elemento atual para o próximo do elemento removido
		free(removedElement);																		// desaloca o elemento removido
	}
}

linked_list_size LinkedList_size(LinkedList* linked_list) {
	linked_list_size _linked_list_counter = 0;														// tamanho da lista que será incrementado

	(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;							// aponta o elemento atual para o primeiro elemento
	while ((*linked_list).current_element_ptr->next_element_ptr != NULL) {							// enquanto o próximo elemento do elemento atual não for nulo
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_element_ptr;	// aponta o elemento atual para o próximo elemento da lista
		_linked_list_counter++;																		// incrementa 1 ao valor do tamanho da lista
	}

	return _linked_list_counter;
}

void LinkedList_printf(LinkedList* linked_list) {
	(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;							// aponta o elemento atual para o primeiro elemento da lista
	printf("Lista: [");
	while ((*linked_list).current_element_ptr->next_element_ptr != NULL) {							// enquanto o próximo elemento do elemento atual não for nulo
		printf(" %d", ((*linked_list).current_element_ptr->value));									// mostra o valor contido no elemento atual
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_element_ptr;	// aponta o elemento atual para o próximo elemento do elemento atual
	}
	printf(" ]\n");
}

linked_list_max_val LinkedList_max_value(LinkedList* linked_list) {
	linked_list_max_val _linked_list_max_val = (*linked_list).first_element_ptr->value;				// copia o valor do elemento atual para o valor a ser testado como max

	(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;							// aponta o elemento atual para o primeiro elemento da lista
	while ((*linked_list).current_element_ptr->next_element_ptr != NULL) {							// enquanto o próximo elemento do elemento atual não for nulo
		if ((*linked_list).current_element_ptr->value > _linked_list_max_val) {						// se o valor do elemento atual for maior do que o valor selecionado
			_linked_list_max_val = (*linked_list).current_element_ptr->value;						// atribui ao valor máximo o valor do elemento atual
		}
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_element_ptr;	// aponta o elemento atual para o próximo elemento do elemento atual
	}

	return _linked_list_max_val;
}

linked_list_min_val LinkedList_min_value(LinkedList* linked_list) {
	linked_list_min_val _linked_list_min_val = (*linked_list).first_element_ptr->value;				// copia o valor do elemento atual para o valor a ser testado como min

	(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;							// aponta o elemento atual para o primeiro elemento da lista
	while ((*linked_list).current_element_ptr->next_element_ptr != NULL) {							// enquanto o próximo elemento do elemento atual não for nulo
		if ((*linked_list).current_element_ptr->value < _linked_list_min_val) {						// se o valor do elemento atual for maior do que o valor selecionado
			_linked_list_min_val = (*linked_list).current_element_ptr->value;						// atribui ao valor mínimo o valor do elemento atual
		}
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_element_ptr;	// aponta o elemento atual para o próximo elemento do elemento atual
	}

	return _linked_list_min_val;	
}