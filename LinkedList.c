/*
 * LinkedList.c
 *
 *  Created on: Jan 27, 2017
 *      Author: iskandar
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void size(struct LinkedList_ *palist){

	Element *paux = palist->node;

	while(paux != NULL){
		palist->size++;
		paux = paux->pnext;
	}
}

void cycle(Element **pastart){

	Element *aux = *pastart;

	while(aux->pnext != NULL){
		aux = aux->pnext;
	}
	aux->pnext = *pastart;

}

int search_element(Element **pastart, int adata, int *paddr){

	Element *aux = *pastart;

	while(aux != NULL){
		if(aux->data == adata){
			memcpy(paddr, &aux->data, 0x1);
			return 0x1;
		}
		aux = aux->pnext;
	}
	return 0x0;
}

void destroy(LinkedList *palist){

	LinkedList *aux;

	while(palist->node != NULL){
		aux = palist->node;
		palist->node = palist->node->pnext;
		free(aux);
	}

	palist->size = NULL;
	palist->pf_initialize_node = NULL;
	palist->pf_insert_at_begining = NULL;
	palist->pf_insert_at_end = NULL;
	palist->pf_size = NULL;
	free(palist);
}

void insert_at_offset(Element **pastart, unsigned int aoffset, int adata){

	Element *aux = *pastart;
	unsigned int offset = 0x0;
	while(aux->pnext != NULL){

		if(offset == (aoffset - 0x1)){
			Element *pelem = (Element *) malloc(sizeof(Element));
			if(pelem != NULL){
				pelem->data = adata;
				pelem->pnext = aux->pnext;
				aux->pnext = pelem;
				break;
			} else{
				fprintf(stderr, "Memory allocation failed:[%s]\n", __FUNCTION__);
			}
		}
		offset++;
		aux = aux->pnext;
	}
}

void delete(Element **pastart, unsigned int aoffset){

	int offset = 0x0;
	Element *aux = *pastart;
	while(aux != NULL){
		if(offset == (aoffset - 0x1)){
			Element *ptemp = aux->pnext;
			aux->pnext = ptemp->pnext;
			free(ptemp);
			ptemp->pnext = NULL;
			break;
		}
		offset++;
		aux = aux->pnext;
	}
}

void reverse(Element **pastart, unsigned int asize){

	if(asize == 0x0){
		return;
	}
	Element *_arr = malloc(sizeof(Element) * asize);
	Element *aux = *pastart;
	Element *prvs = NULL;

	int i = 0x0;

//	while(aux != NULL){
//		memcpy(*(_arr)[i++], aux, 0x1);
//		aux = aux->pnext;
//	}
//	int k = asize - 0x2;
//	prvs = _arr[asize - 0x1];
//
//	while(k > 0x0){
//		prvs->pnext =_arr[k--];
//	}
	*pastart = prvs;
}

LinkedList *initialize(){

	LinkedList *aLinkedList = NULL;

	aLinkedList = (LinkedList *) malloc(sizeof(LinkedList));
	aLinkedList->size = 0x0;
	aLinkedList->pf_initialize_node = initialize_node;
	aLinkedList->pf_insert_at_begining = insert_at_beginning;
	aLinkedList->pf_insert_at_end = insert_at_end;
	aLinkedList->pf_size = size;
	aLinkedList->pf_search_element = search_element;
	aLinkedList->pf_insert_at_offset = insert_at_offset;
	aLinkedList->pf_delete = delete;
	aLinkedList->pf_reverse = reverse;
	return aLinkedList;
}
