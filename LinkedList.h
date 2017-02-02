/*
 * LinkedList.h
 *
 *  Created on: Jan 26, 2017
 *      Author: iskandar
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct Element_{

	int data;
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
	void (*pf_delete)(Element **, unsigned int);
	void (*pf_reverse)(Element **, unsigned size);

} LinkedList;

LinkedList *initialize();
void size(LinkedList *);
void destroy(LinkedList *);
void initialize_node(Element **, int);
void insert_at_beginning(Element **, int);
void insert_at_end(Element **, int);
int search_element(Element **, int data, int *offset);
void insert_at_offset(Element **, unsigned int offset, int data);
void delete(Element **, unsigned int offset);
void reverse(Element **, unsigned size);
void cycle(Element **);
#endif /* LINKEDLIST_H_ */
