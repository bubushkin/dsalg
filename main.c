#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, char **argv) {

	LinkedList *linkedList = initialize();
	printf("%p\n", &linkedList);
	printf("%p\n", &linkedList->node);
	//linkedList->pf_initialize_node(&linkedList->node, 1);

	linkedList->pf_insert_at_begining(&linkedList->node, 10);
	linkedList->pf_insert_at_begining(&linkedList->node, 9);
	linkedList->pf_insert_at_end(&linkedList->node, 11);
	linkedList->pf_size(linkedList);

	printf("Count: %d\n", linkedList->size);

	int *data = (int *) malloc(sizeof(int));
	int found = linkedList->pf_search_element(&linkedList->node, 10, data);

	destroy(linkedList);
	return EXIT_SUCCESS;
}
