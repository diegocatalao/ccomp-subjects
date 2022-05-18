/**
 * @file sort_linked_list.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Este programa cria uma lista lincada circular com o último elemento apontando para o primeiro
 * @version 0.1
 * @date 2022-03-23
 **/
#include <stdio.h>
#include <stdlib.h>

typedef struct sElement {
	int value;
	struct sElement* next_ptr;
} Element;

typedef struct sLinkedList {
	int size_l;
	Element* first_element_ptr;
	Element* last_element_ptr;
	Element* current_element_ptr;
} LinkedList;

LinkedList* LinkedList_init(void);
void LinkedList_insert(LinkedList* linked_list, int value);
void LinkedList_remove(LinkedList* linked_list, int index);
void LinkedList_printf(LinkedList* linked_list);

int main(int argc, char* argv[]) {
	LinkedList* linked_list = LinkedList_init();

	for (int index = 1; index <= 20; index++)
		LinkedList_insert(linked_list, index);

	LinkedList_printf(linked_list);

	return 0;
}

LinkedList* LinkedList_init() {
	LinkedList* linked_list = malloc(sizeof(LinkedList));
	(*linked_list).size_l = 0;
	(*linked_list).first_element_ptr = NULL;
	(*linked_list).last_element_ptr = NULL;
	(*linked_list).current_element_ptr = NULL;
	return linked_list;
}

void LinkedList_insert(LinkedList* linked_list, int value) {
	if ((*linked_list).first_element_ptr == NULL && (*linked_list).last_element_ptr == NULL) {
		(*linked_list).first_element_ptr = malloc(sizeof(Element));
		(*linked_list).last_element_ptr = (*linked_list).first_element_ptr;
		(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;
		
		(*linked_list).current_element_ptr->value = value;
		(*linked_list).current_element_ptr->next_ptr = NULL;
	} else {
		(*linked_list).current_element_ptr = (*linked_list).last_element_ptr;
		(*linked_list).current_element_ptr->next_ptr = malloc(sizeof(Element));
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_ptr;
		(*linked_list).current_element_ptr->next_ptr = NULL;
		(*linked_list).current_element_ptr->value = value;
		(*linked_list).last_element_ptr = (*linked_list).current_element_ptr;
		(*linked_list).last_element_ptr->next_ptr = (*linked_list).first_element_ptr;

	}

	(*linked_list).size_l++;
}

void LinkedList_remove(LinkedList* linked_list, int index) {

}

void LinkedList_printf(LinkedList* linked_list) {
	printf("[");
	(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;
	for (int index_l = 0; index_l < (*linked_list).size_l; index_l++) {
		printf(" %d", (*linked_list).current_element_ptr->value);
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_ptr;
	}
	printf(" ]\n");
}