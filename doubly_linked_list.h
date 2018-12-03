//#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include "rosa_def.h"

#define NULL (void*)0
#define taskHandle node

typedef struct
{
	tcb task;
	struct node * next;
	struct node * previous;
} node;

typedef struct
{
	node * head;
	node * tail;
} linked_list;

int16_t insert_at_head	( linked_list *, node *);
int16_t insert_in_order	( linked_list *, node *);
int16_t insert_after	( node *, node *);
int16_t remove_node	( node *);

void print_list(linked_list *);
