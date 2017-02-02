#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "LinkedList.h"

void reverse_list(LinkedList *palinkedList){

	Element *paux = palinkedList->node;
	Element *pprevious_node = NULL;
	Element *pnext_node = NULL;
	while(paux != NULL){
		pnext_node = paux->pnext;
		paux->pnext = pprevious_node;
		pprevious_node = paux;
		paux = pnext_node;
	}

}

void nth_to_last(LinkedList *palinkedList, int astep){

	Element *paux = palinkedList->node;
	Element *pnth = palinkedList->node;

	int step = 0x0;
	while(step <= astep - 1){
		paux = paux->pnext;
		step++;
	}
	while(paux != NULL){
		paux = paux->pnext;
		pnth = pnth->pnext;
	}
	printf("");
}

int check_cycle(LinkedList *palinkedList){

	int *address =  palinkedList->node;

	Element *paux = palinkedList->node->pnext;

	while(paux != NULL){
		if(address == paux){
			return 0x1;
		}
		paux = paux->pnext;
	}
	return 0x0;
}
int check_cycle_markers(LinkedList *palinkedList){

	Element *pmarker_1 = palinkedList->node;
	Element *pmarker_2 = palinkedList->node;

	while(pmarker_1 != NULL){

		pmarker_1 = pmarker_1->pnext;
		pmarker_2 = pmarker_2->pnext->pnext;

		if(pmarker_1 == pmarker_2){
			return 0x1;
		}
	}

	return 0x0;
}

int main(int argc, char **argv) {


	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;
	int five = 5;
	int *pone = &one;

	Stack *pstack = init_stack("int", 0xA);
	pstack->pf_push(pstack, (void *)pone);
	pstack->pf_push(pstack, &two);
	pstack->pf_push(pstack, &three);
	pstack->pf_push(pstack, &four);
	pstack->pf_push(pstack, &five);

	printf("%d\n", *(int *)pstack->pf_pop(pstack));
	printf("%d\n", *(int *)pstack->pf_pop(pstack));
	printf("%d\n", *(int *)pstack->pf_pop(pstack));
	printf("%d\n", *(int *)pstack->pf_pop(pstack));
	printf("%d\n", *(int *)pstack->pf_pop(pstack));

}

/*
int main(int argc, char **argv) {

	LinkedList *linkedList = initialize();
	printf("%p\n", &linkedList);
	printf("%p\n", &linkedList->node);
	//linkedList->pf_initialize_node(&linkedList->node, 1);

	linkedList->pf_insert_at_begining(&linkedList->node, 10);
	linkedList->pf_insert_at_begining(&linkedList->node, 9);
	linkedList->pf_insert_at_end(&linkedList->node, 11);
	linkedList->pf_insert_at_end(&linkedList->node, 12);
	linkedList->pf_insert_at_offset(&linkedList->node, 1, 15);
	nth_to_last(linkedList, 2);
	//reverse_list(linkedList);
	//cycle(&linkedList->node);
	//linkedList->pf_size(linkedList);
	//check_cycle_markers(linkedList);
	printf("Count: %d\n", linkedList->size);

	int *data = (int *) malloc(sizeof(int));
	int found = linkedList->pf_search_element(&linkedList->node, 10, data);
	linkedList->pf_reverse(&linkedList->node, linkedList->size);
	//linkedList->pf_delete(&linkedList->node, 2);

	destroy(linkedList);
	return EXIT_SUCCESS;
}
*/
