/*
 * LinkedList.c
 *
 *  Created on: Jan 27, 2017
 *      Author: iskandar
 */
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"


void initialize_node(Element **node, int data){
	*node = (Element *) malloc(sizeof(Element));
	(*node)->data = data;
}


void insert_at_end(Element **start, int data){

	Element *paux = *start;
	while(paux->pnext != NULL){
		paux = paux->pnext;
	}
	Element *pend = (Element *) malloc(sizeof(Element*));
	if(pend != NULL){
		pend->data = data;
		pend->pnext = NULL;
		paux->pnext = pend;
	} else{
		fprintf(stderr, "Memory allocation failed:[%s]\n", __FUNCTION__);
	}
}
void insert_at_beginning(Element **start, int data){

	Element *paux = (Element *) malloc(sizeof(Element*));
	if(paux != NULL){
		paux->data = data;
		paux->pnext = *start;
		*start = paux;
	} else{
		fprintf(stderr, "Memory allocation failed:[%s]\n", __FUNCTION__);
	}
}

LinkedList *initialize(){

	LinkedList *aLinkedList = NULL;

	aLinkedList = (LinkedList *) malloc(sizeof(LinkedList));
	aLinkedList->pf_initialize_node = initialize_node;
	aLinkedList->pf_insert_at_begining = insert_at_beginning;
	aLinkedList->pf_insert_at_end = insert_at_end;
}


