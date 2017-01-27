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

	return EXIT_SUCCESS;
}
