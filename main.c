#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"


int main(int argc, char **argv) {

	ListElement *start = NULL;

	start = createList(start);
	//insertBeforeValue(start, 5, 2);
	insertAtOffset(start, 7, 3);
	insertAfterValue(start, 8, 7);
	deleteLastElement(start);
	deconstructor(start);

	return EXIT_SUCCESS;
}
