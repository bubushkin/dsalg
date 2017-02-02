/*
 * Stack.c
 *
 *  Created on: Feb 1, 2017
 *      Author: iskandar
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


Stack *init_stack(char *type, unsigned int asize){


	Stack *pastack = (Stack *)calloc(0x1, sizeof(Stack));

	if(strcmp(type, "int") == 0){
		pastack->pstack = (int *)calloc(asize, sizeof(int));
		if(pastack->pstack == NULL){
			fprintf(stderr, "Memory allocation failed:[%s]\n", __FUNCTION__);
		}

	} else if(strcmp(type, "long") == 0x0){
		pastack->pstack = (long *)calloc(asize, sizeof(long));
		if(pastack->pstack == NULL){
			fprintf(stderr, "Memory allocation failed:[%s]\n", __FUNCTION__);
		}
		memcpy(pastack->pstack, 0x0, sizeof(long) * asize);

	} else if(strcmp(type, "float") == 0x0){
		pastack->pstack = (float *)calloc(asize, sizeof(float));
		if(pastack->pstack == NULL){
			fprintf(stderr, "Memory allocation failed:[%s]\n", __FUNCTION__);
		}
		memcpy(pastack->pstack, 0x0, sizeof(float) * asize);

	} else if(strcmp(type, "char") == 0x0){
		pastack->pstack = (char *)calloc(asize, sizeof(char));
		if(pastack->pstack == NULL){
			fprintf(stderr, "Memory allocation failed:[%s]\n", __FUNCTION__);
		}
		memcpy(pastack->pstack, 0x0, sizeof(char) * asize);

	} else{
		fprintf(stderr, "Given type is not supported:[%s]\n", __FUNCTION__);
	}

	pastack->ptype = (char *)calloc(0x1, strlen(type));

	if(pastack->ptype == NULL){
		fprintf(stderr, "Memory allocation failed:[%s]\n", __FUNCTION__);
	}
	memcpy(pastack->ptype, type, sizeof(type));
	pastack->pf_size = stack_size;
	pastack->pf_push = push;
	pastack->pf_pop = pop;
	pastack->limit = asize;
	pastack->counter = 0x0;

	return pastack;

}

void* pop(struct Stack_ *pastack){

	void *pret = pastack->pstack;

	pastack->counter--;

	if(strcmp(pastack->ptype, "int") == 0x0){
		pastack->pstack -= sizeof(int);
	} else if(strcmp(pastack->ptype, "long") == 0x0){
		pastack->pstack -= sizeof(long);
	} else if(strcmp(pastack->ptype, "float") == 0x0){
		pastack->pstack -= sizeof(float);
	} else if(strcmp(pastack->ptype, "char") == 0x0){
		pastack->pstack -= sizeof(char);
	}
	return pret;
}

int stack_size(Stack *pastack){
	return sizeof(pastack->pstack)/sizeof(pastack->pstack[0]);
}

void push(struct Stack_ *pastack, void *paelem){

	if(pastack->counter < pastack->limit){

		switch(pastack->counter){
		case 0x0:
			if(strcmp(pastack->ptype, "int") == 0x0){
				pastack->pstack = (int *)paelem;
			} else if(strcmp(pastack->ptype, "long") == 0x0){
				pastack->pstack = (long *)paelem;
			} else if(strcmp(pastack->ptype, "float") == 0x0){
				pastack->pstack = (long *)paelem;
			} else if(strcmp(pastack->ptype, "char") == 0x0){
				pastack->pstack = (long *)paelem;
			}
			break;
		default:
			if(strcmp(pastack->ptype, "int") == 0x0){
				pastack->pstack += sizeof(int);
				pastack->pstack = (int *)paelem;
			} else if(strcmp(pastack->ptype, "long") == 0x0){
				pastack->pstack += sizeof(long);
				pastack->pstack = (long *)paelem;
			} else if(strcmp(pastack->ptype, "float") == 0x0){
				pastack->pstack += sizeof(long);
				pastack->pstack = (long *)paelem;
			} else if(strcmp(pastack->ptype, "char") == 0x0){
				pastack->pstack += pastack->counter++ * sizeof(long);
				pastack->pstack = (long *)paelem;
			}
			break;
		}
		pastack->counter++;
	}
//	printf("%d\n", *(int *)pastack->pstack);
}
