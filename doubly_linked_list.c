#include "doubly_linked_list.h"

int16_t insert_at_head( linked_list * list, node * new_head )
{
	int16_t result = -1;
	
	if(new_head != NULL)
	{
		if( list->head == NULL)
		{
			list->head = new_head;
			list->tail = new_head;
		}
		else
		{
			list->head->previous = new_head;
			new_head->next = list->head;
			list->head = new_head;
		}
		result = 0;
	}

	return result;
}

int16_t insert_at_tail( linked_list * list, node * new_tail )
{
	int16_t result = -1;

	if(new_tail != NULL)
	{
		if(list->tail == NULL)
		{
			list->head = new_tail;
			list->tail = new_tail;
		}
		else
		{
			insert_after( list->tail, new_tail );
			list->tail = new_tail;
		}
	
		result = 0;
	}

	return result;
}

int16_t insert_after( node * position_node, node * new_node )
{
	int16_t result = -1;

	printf("position node: %d\n", position_node);

	if(position_node != NULL && new_node != NULL)
	{
		new_node->next = position_node->next;
		new_node->previous = position_node;
		position_node->next = new_node;

		result = 0;
	}

	return result;
}

int16_t insert_in_order( linked_list * list, node * new_node )
{
	printf("working on node %d\n", new_node->task.priority);
	int16_t result = -1;
	node * iterator;
	
	if( new_node != NULL )
	{
		if( list->head == NULL )
		{
			printf("inserting node %d at head\n", new_node->task.priority);
			insert_at_head( list, new_node );
		}
		else
		{
			iterator = list->head;
			while( iterator != NULL && iterator->task.priority <= new_node->task.priority )
			{
				iterator = iterator->next;
			}
			
			if(iterator == NULL)
			{
				printf("inserting node %d at tail\n", new_node->task.priority);
				insert_at_tail( list, new_node );
			}
			else if(iterator == list->head && new_node->task.priority < list->head->task.priority)
			{
				printf("inserting node %d at head\n", new_node->task.priority);
				insert_at_head( list, new_node);
			}
			else
			{
				node * temp_node_just_for_printing = iterator->previous;
				printf("inserting node %d after node %d\n", new_node->task.priority, temp_node_just_for_printing->task.priority);
				insert_after( iterator->previous, new_node );
			}

		}

		result = 0;
	}

	return result;
}

int16_t remove_node( node * removed_node )
{
	int16_t result = -1;
	node * next_node;
	node * previous_node;

	if(removed_node != NULL)
	{
		next_node     = removed_node->next;
		previous_node = removed_node->previous;
		
		previous_node->next = removed_node->next;
		next_node->previous = removed_node->previous;

		removed_node->next = NULL;
		removed_node->previous = NULL;

		result = 0;
	}

	return result;
}

void print_list( linked_list * list)
{	
	printf("nodes:");

	node * iterator = list->head;
	while(iterator != NULL)
	{
		printf(" %d", iterator->task.priority, iterator->previous, iterator->next);
		iterator = iterator->next;
	}
	printf("\n");
}
