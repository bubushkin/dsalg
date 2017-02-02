/*
 * Stack.h
 *
 *  Created on: Feb 1, 2017
 *      Author: iskandar
 */

#ifndef STACK_H_
#define STACK_H_



typedef struct Stack_{

	int counter;
	int limit;
	char *ptype;
	void *pstack;
	int (*pf_size)(struct Stack_*);
	void (*pf_push)(struct Stack_*, void *);
	void* (*pf_pop)(struct Stack_*);


} Stack;


Stack *init_stack(char *, unsigned int);
int stack_size(struct Stack_ *);

void* pop(struct Stack_ *);
void push(struct Stack_ *, void *);

#endif /* STACK_H_ */
