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
	void (*pf_initialize_node)(Element **, int);
	void (*pf_insert_at_begining)(Element **, int);
	void (*pf_insert_at_end)(Element **, int);

} LinkedList;

LinkedList *initialize();
void initialize_node(Element **, int);
void insert_at_beginning(Element **, int);
void insert_at_end(Element **, int);


#endif /* LINKEDLIST_H_ */
