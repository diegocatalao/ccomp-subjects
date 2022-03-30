#include "dsmath.h"

Vector1D* Vector1D_init(void) {
	Vector1D* vector1D_ptr = malloc(sizeof(Vector1D));
	(*vector1D_ptr).first_element_ptr = NULL;
	(*vector1D_ptr).current_element_ptr = NULL;
	(*vector1D_ptr).last_element_ptr = NULL;
	
	return vector1D_ptr;
}

void Vector1D_append(Vector1D* vector1D_ptr, double value) {
	if ((*vector1D_ptr).size_l == 0) {
		(*vector1D_ptr).first_element_ptr = malloc(sizeof(Element1D));
		(*vector1D_ptr).last_element_ptr = (*vector1D_ptr).first_element_ptr;
		(*vector1D_ptr).current_element_ptr = (*vector1D_ptr).first_element_ptr;

		(*vector1D_ptr).size_l = 0;
		(*vector1D_ptr).current_element_ptr->value = value;
		(*vector1D_ptr).current_element_ptr->next_ptr = NULL;
	} else {
		(*vector1D_ptr).current_element_ptr = (*vector1D_ptr).last_element_ptr;
		(*vector1D_ptr).current_element_ptr->next_ptr = malloc(sizeof(Element1D));
		(*vector1D_ptr).current_element_ptr = (*vector1D_ptr).current_element_ptr->next_ptr;

		(*vector1D_ptr).current_element_ptr->value = value;
		(*vector1D_ptr).current_element_ptr->next_ptr = NULL;

		(*vector1D_ptr).last_element_ptr = (*vector1D_ptr).current_element_ptr;
		(*vector1D_ptr).last_element_ptr->next_ptr = (*vector1D_ptr).first_element_ptr;
	}

	(*vector1D_ptr).size_l++;
}

void Vector1D_remove(Vector1D* vector1D_ptr, int index) {

}

void Vector1D_printf(Vector1D* vector1D_ptr) {
	(*vector1D_ptr).current_element_ptr = (*vector1D_ptr).first_element_ptr;
	printf("[");
	for (int index = 0; index < (*vector1D_ptr).size_l; index++) {
		printf(" %g", (*vector1D_ptr).current_element_ptr->value);
		(*vector1D_ptr).current_element_ptr = (*vector1D_ptr).current_element_ptr->next_ptr;
	}
	printf(" ]\n");
}

void __Vector1D_goto(Vector1D* vector1D_ptr, int index) {
	assert(!(index < 0));
	assert(!(index > (*vector1D_ptr).size_l));

	(*vector1D_ptr).current_element_ptr = (*vector1D_ptr).first_element_ptr;
	for (int index_l = 0; index_l < index; index++) {
		(*vector1D_ptr).current_element_ptr = (*vector1D_ptr).current_element_ptr->next_ptr;
	}
}