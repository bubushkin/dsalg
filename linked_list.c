#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	ListElement *aux = (ListElement *)malloc(sizeof(ListElement));
	aux->data = data;
	aux->pnext = start;
	start = aux;

	return start;
}

ListElement *initialize2(ListElement *start, int data) {

	start = insertAtBeginning(start, data);
	return start;
}

void reverse(ListElement *apstart){
	ListElement *prev, *curr, *next;
	prev = NULL;
	curr = apstart;

	while(curr != NULL){
		next = curr->pnext;
		curr->pnext = prev;
		prev = curr;
		curr = next;
	}
	apstart = prev;
}

void deconstructor(ListElement *apstart){

	ListElement *temp = NULL;
	temp = apstart;
	while(apstart != NULL){
		temp = apstart;
		apstart = apstart->pnext;
		free(temp);
	}
}


void deleteLastElement(ListElement *apstart){

	ListElement *aux = apstart;
	ListElement *itx = apstart;

	while(itx->pnext->pnext != NULL)
		itx = itx->pnext;

	aux = itx->pnext;
	itx->pnext = NULL;
	free(aux);

}
void deleteFirstElement(ListElement *apstart){

	ListElement *aux = apstart;
	apstart = aux->pnext;
	free(aux);
}

void insertBeforeValue(ListElement *apstart, int to_insert, int offset_value){

	ListElement *aux = (ListElement *)malloc(sizeof(ListElement));
	ListElement *itx = apstart;
	aux->data = to_insert;

	while(itx->pnext != NULL){
		if(itx->pnext->data == offset_value){
			aux->pnext = itx->pnext;
			itx->pnext = aux;
			break;
		}
		itx = itx->pnext;
	}

}

void insertAtOffset(ListElement *apstart, int pto_insert, int poffset){

	ListElement *aux = (ListElement *)malloc(sizeof(ListElement));
	ListElement *itx = apstart;
	aux->data = pto_insert;

	int offset = 0x0;

	while(itx->pnext != NULL){

		if(offset == (poffset - 0x2)){
			aux->pnext = itx->pnext;
			itx->pnext = aux;
			break;
		}
		itx = itx->pnext;
		offset++;

	}
}
void insertAfterValue(ListElement *apstart, int to_insert, int offset_value){

	ListElement *aux = (ListElement *)malloc(sizeof(ListElement));
	ListElement *itx = apstart;
	aux->data = to_insert;

	while(itx != NULL){
		if(itx->data == offset_value){
			aux->pnext = itx->pnext;
			itx->pnext = aux;
			break;
		}
		itx = itx->pnext;
	}
}

ListElement *createList(ListElement *start) {

	int n, data;

	printf("Enter number of nodes: ");
	scanf("%d", &n);

	if (n == 0x0) {
		return start;
	}

	printf("Enter the first element of the list: ");
	scanf("%d", &data);
	start = insertAtBeginning(start, data);

	for (int i = 2; i <= n; i++) {
		printf("Enter the next element of the list: ");
		scanf("%d", &data);
		insertAtEnd(start, data);
	}

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
	memcpy(poffset, 0x0, 0x01);
}
