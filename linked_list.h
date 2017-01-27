#include <stdlib.h>

#ifndef LINKED_LIST_H_   /* Include guard */
#define LINKED_LIST_H_


typedef struct ListElement_ {
	int data;
	struct ListElement_ *pnext;
} ListElement;

void displayElement(ListElement *);

int countElements(ListElement *);

void searchElement(ListElement *, int, int *);

ListElement *insertAtBeginning(ListElement *, int);

void insertAtEnd(ListElement *, int);

void insertAfterValue(ListElement *, int, int);
void insertBeforeValue(ListElement *, int, int);
void insertAtOffset(ListElement *, int, int);

void deleteFirstElement(ListElement *);
void deleteLastElement(ListElement *);

void reverse(ListElement *);


ListElement *initialize2(ListElement *, int);
ListElement *createList(ListElement *);

void deconstructor(ListElement *);

#endif // LINKED_LIST_H_
