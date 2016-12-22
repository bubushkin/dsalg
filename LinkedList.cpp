#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

void displayElement(ListElement *start) {

	ListElement *elem;
	if (start == NULL) {

		printf("List is empty!\n");
		return;
	}

	printf("The list is: ");
	elem = start;
	while (elem != NULL) {
		printf("%d ", elem->data);
		elem = elem->pnext;
	}
}

void insertAtEnd(ListElement *start, int data) {

	ListElement *pelem = (ListElement *)malloc(sizeof(ListElement));
	pelem->data = data;

	ListElement *pix = start;

	while (pix->pnext != NULL) {
		pix = pix->pnext;
	}

	pix->pnext = pelem;
	pelem->pnext = NULL;
}

ListElement *insertAtBeginning(ListElement *start, int data) {

	ListElement *aux = (ListElement*)malloc(sizeof ListElement);
	aux->data = data;
	aux->pnext = start;
	start = aux;

	return start;
}

int countElements(ListElement *start) {

	int n = 0x0;
	ListElement *elem = start;
	while (elem != NULL) {
		n++;
		elem = elem->pnext;
	}
	return n;
}

void searchElement(ListElement *start, int data, int *poffset) {

	ListElement *elem = start;
	int offset = 0x0;
	while (elem != NULL) {

		if (elem->data == data) {
			memcpy(poffset, &offset, 0x01);
			return;
		}
		offset++;
	}
	memcpy(poffset, NULL, 0x01);
}