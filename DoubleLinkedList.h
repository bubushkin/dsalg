/*
 * DoubleLinkedList.h
 *
 *  Created on: Jan 29, 2017
 *      Author: iskandar
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

typedef struct Element_{

	int data;
	struct Element_ *pprev;
	struct Element_ *pnext;

} Element;

typedef struct LinkedList_{

	Element *node;
	unsigned int size;
	void (*pf_initialize_node)(Element **, int);
	void (*pf_insert_at_begining)(Element **, int);
	void (*pf_insert_at_end)(Element **, int);
	void (*pf_size)(struct LinkedList_ *);
	int (*pf_search_element)(Element **, int, int *);
	void (*pf_insert_at_offset)(Element **, unsigned int, int);

} LinkedList;

LinkedList *initialize();
void size(LinkedList *);
void destroy(LinkedList *);
void initialize_node(Element **, int);
void insert_at_beginning(Element **, int);
void insert_at_end(Element **, int);
int search_element(Element **, int data, int *offset);
void insert_at_offset(Element **, unsigned int offset, int data);

#endif /* DOUBLELINKEDLIST_H_ */
