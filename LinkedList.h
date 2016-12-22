#ifndef LINKEDLIST_H_   /* Include guard */
#define LINKEDLIST_H_

typedef struct ListElement_ {
	int data;
	ListElement *pnext = NULL;
} ListElement;

void displayElement(ListElement *);

int countElements(ListElement *);

void searchElement(ListElement *, int, int *);

ListElement *insertAtBeginning(ListElement *, int);

void insertAtEnd(ListElement *, int);

ListElement *initialize(ListElement *, int);
ListElement *createList(ListElement *);

#endif // FOO_H_
