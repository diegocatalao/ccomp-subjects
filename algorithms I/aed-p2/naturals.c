#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;
typedef char * STRING;
typedef unsigned int UINT;
typedef unsigned long long int UINT64;

typedef struct sElement {
	UINT64 value;
	struct sElement* pNext;
    struct sElement* pPrev;
} Element;

typedef struct sLinkedList {
	UINT length;
    STRING name;
	Element* pFirstElement;
    Element* pLastElement;
	Element* pCurrentElement;
} LinkedList;

LinkedList* LinkedList_aloc(STRING name);
void LinkedList_append(LinkedList* linked_list, UINT64 value);
void LinkedList_remove(LinkedList* linked_list, UINT index);
void LinkedList_printf(LinkedList* linked_list);

int main(int argc, char* argv[]) {
    UINT64 value;
    LinkedList* pLinkedListAsc = LinkedList_aloc("lista ascendente");
	LinkedList* pLinkedListDes = LinkedList_aloc("lista descendente");

	for (value = 0; value != 5; value++)
		LinkedList_append(pLinkedListAsc, value);
	LinkedList_printf(pLinkedListAsc);

    for (value = 5; value != 0; value--)
        LinkedList_append(pLinkedListDes, value);
    LinkedList_printf(pLinkedListDes);

	return 0;
}

LinkedList* LinkedList_aloc(STRING name) {
	LinkedList* pLinkedList = malloc(sizeof(LinkedList));
	(*pLinkedList).length = 0;
    (*pLinkedList).name = name;
	(*pLinkedList).pFirstElement = NULL;
    (*pLinkedList).pLastElement = NULL;
	(*pLinkedList).pCurrentElement = NULL;
}

void LinkedList_append(LinkedList* linked_list, UINT64 value) {
	if ((*linked_list).pFirstElement == NULL && (*linked_list).pCurrentElement == NULL) {
		(*linked_list).pFirstElement = (Element *) malloc(sizeof(Element));
		(*linked_list).pCurrentElement = (*linked_list).pFirstElement;
        (*linked_list).pLastElement = (*linked_list).pFirstElement;

		(*linked_list).pCurrentElement->value = value;
		(*linked_list).pCurrentElement->pNext = NULL;
        (*linked_list).pCurrentElement->pPrev = NULL;
	} else {
        (*linked_list).pCurrentElement = (*linked_list).pLastElement;
        (*linked_list).pCurrentElement->pNext = (Element *) malloc(sizeof(Element));
        (*linked_list).pCurrentElement->pPrev = (*linked_list).pLastElement;
        (*linked_list).pCurrentElement = (*linked_list).pCurrentElement->pNext;

        (*linked_list).pCurrentElement->value = value;
        (*linked_list).pCurrentElement->pNext = NULL;

        (*linked_list).pLastElement = (*linked_list).pCurrentElement;
        (*linked_list).pLastElement->pNext = (*linked_list).pFirstElement;
	}

	(*linked_list).length++;
}

void LinkedList_printf(LinkedList* linked_list) {
    BOOL asc = linked_list->pFirstElement->value <
               linked_list->pFirstElement->pNext->value ? TRUE : FALSE;

    (*linked_list).pCurrentElement = (*linked_list).pFirstElement;
    
    printf("Lista encadeada (%s): [", linked_list->name);
    while ((*linked_list).pCurrentElement != (*linked_list).pLastElement) {
        printf(" %lld", (*linked_list).pCurrentElement->value);
        (*linked_list).pCurrentElement = (*linked_list).pCurrentElement->pNext;
    }
    printf(" ]\n");
}