/**
 * @file sort_linked_list.c
 * @author Diego Catalão (catalao.diego@graduacao.uerj.br)
 * @brief Este programa é capaz de criar uma lista encadeada e ordenar de diversas formas
 * @version 0.1
 * @date 2022-03-23
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct sElement {
	int value;
	struct sElement* next_ptr;
} Element;

typedef struct sLinkedList {
	int size_l;
	Element* first_element_ptr;
	Element* current_element_ptr;
} LinkedList;

LinkedList* LinkedList_init(void);
void LinkedList_append(LinkedList* linked_list, int value);
void LinkedList_remove(LinkedList* linked_list, int index);
void LinkedList_printf(LinkedList* linked_list);
int LinkedList_goto(LinkedList* linked_list, int index);

void LinkedList_insertion_sort(LinkedList* linked_list);
void LinkedList_selection_sort(LinkedList* linked_list);

int main(int argc, char* argv[]) {
	LinkedList* linked_list_ptr = LinkedList_init();

	printf("Lista encadeada:\t\t");
	for (int value = 20; value >= 1; value--) {
		LinkedList_append(linked_list_ptr, value);
	}
	LinkedList_append(linked_list_ptr, 233);
	LinkedList_printf(linked_list_ptr);

	printf("LinkedList_insertion_sort:\t");
	LinkedList_insertion_sort(linked_list_ptr);
	LinkedList_printf(linked_list_ptr);

	printf("LinkedList_selection_sort:\t");
	LinkedList_selection_sort(linked_list_ptr);
	LinkedList_printf(linked_list_ptr);

	return 0;
}

LinkedList* LinkedList_init(void) {
	LinkedList* linked_list_ptr = malloc(sizeof(LinkedList));
	(*linked_list_ptr).size_l = 0;
	(*linked_list_ptr).first_element_ptr = NULL;
	(*linked_list_ptr).current_element_ptr = NULL;
}

void LinkedList_append(LinkedList* linked_list, int value) {
	if ((*linked_list).first_element_ptr == NULL && (*linked_list).current_element_ptr == NULL) {
		(*linked_list).first_element_ptr = malloc(sizeof(Element));
		(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;
		(*linked_list).current_element_ptr->value = value;
		(*linked_list).current_element_ptr->next_ptr = NULL;
	} else {
		(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;
		while ((*linked_list).current_element_ptr->next_ptr != NULL) {
			(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_ptr;
		}
		(*linked_list).current_element_ptr->next_ptr = malloc(sizeof(Element));
		(*linked_list).current_element_ptr->next_ptr->value = value;
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_ptr;
		(*linked_list).current_element_ptr->next_ptr = NULL;
	}

	(*linked_list).size_l++;
}

void LinkedList_remove(LinkedList* linked_list, int index) {
	Element* removedElement;

	if (index < 0 || index > (*linked_list).size_l - 1) {
		printf("Index out of bounds.\n");
		exit(-1);
	}

	(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;
	for (int index_l = 0; index_l < index - 1; index_l++) {
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_ptr;
	}

	if (index == 0) {
		removedElement = (*linked_list).first_element_ptr;
		(*linked_list).first_element_ptr = removedElement->next_ptr;
		removedElement->next_ptr = NULL;
	} else {
		removedElement = (*linked_list).current_element_ptr->next_ptr;
		(*linked_list).current_element_ptr->next_ptr = removedElement->next_ptr;
		removedElement->next_ptr = NULL;
	}
	free(removedElement);
	(*linked_list).size_l--;
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

int LinkedList_goto(LinkedList* linked_list, int index) {
	(*linked_list).current_element_ptr = (*linked_list).first_element_ptr;
	for (int index_l = 0; index_l < index - 1; index_l++) {
		(*linked_list).current_element_ptr = (*linked_list).current_element_ptr->next_ptr;
	}
	return (*linked_list).current_element_ptr->value;
}

void LinkedList_insertion_sort(LinkedList* linked_list) {
	int value, j;
	for (int i = 1; i < (*linked_list).size_l; i++) {
		LinkedList_goto(linked_list, i);
		value = (*linked_list).current_element_ptr->value;
		j = i - 1;
		LinkedList_goto(linked_list, j);
		while (j >= 0 && value < (*linked_list).current_element_ptr->value) {
			(*linked_list).current_element_ptr->next_ptr->value = (*linked_list).current_element_ptr->value;
			j--;
			LinkedList_goto(linked_list, j);
		}
		(*linked_list).current_element_ptr->value = value;
	}
}

void LinkedList_selection_sort(LinkedList* linked_list) {
	int min, aux;
	for (int i = 0; i < (*linked_list).size_l - 1; i++) {
		min = i;
		for (int j = (i + 1); j < (*linked_list).size_l; j++) {
			if (LinkedList_goto(linked_list, j) < LinkedList_goto(linked_list, min)) {
				min = j;
			}
		}
		if (i != min) {
			aux = LinkedList_goto(linked_list, i);
			(*linked_list).current_element_ptr->value = LinkedList_goto(linked_list, min);
			linked_list->current_element_ptr->value = aux;
		}
	}
}
