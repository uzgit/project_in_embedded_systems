#include "doubly_linked_list.h"

int16_t insert_at_head( linked_list * list, tcb * new_head )
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
			list->head->prevtcb = new_head;
			new_head->nexttcb = list->head;
			list->head = new_head;
		}
		result = 0;
	}

	return result;
}

int16_t insert_at_tail( linked_list * list, tcb * new_tail )
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

int16_t insert_after( tcb * position_tcb, tcb * new_tcb )
{
	int16_t result = -1;

//	printf("position tcb: %d\n", position_tcb);

	if(position_tcb != NULL && new_tcb != NULL)
	{
		new_tcb->nexttcb = position_tcb->nexttcb;
		new_tcb->prevtcb = position_tcb;
		position_tcb->nexttcb = new_tcb;

		result = 0;
	}

	return result;
}

int16_t insert_in_order( linked_list * list, tcb * new_tcb )
{
//	printf("working on tcb %d\n", new_tcb->priority);
	int16_t result = -1;
	tcb * iterator;
	
	if( new_tcb != NULL )
	{
		if( list->head == NULL )
		{
//			printf("inserting tcb %d at head\n", new_tcb->priority);
			insert_at_head( list, new_tcb );
		}
		else
		{
			iterator = list->head;
			while( iterator != NULL && iterator->priority <= new_tcb->priority )
			{
				iterator = iterator->nexttcb;
			}
			
			if(iterator == NULL)
			{
//				printf("inserting tcb %d at tail\n", new_tcb->priority);
				insert_at_tail( list, new_tcb );
			}
			else if(iterator == list->head && new_tcb->priority < list->head->priority)
			{
//				printf("inserting tcb %d at head\n", new_tcb->priority);
				insert_at_head( list, new_tcb);
			}
			else
			{
				tcb * temp_tcb_just_for_printing = iterator->prevtcb;
//				printf("inserting tcb %d after tcb %d\n", new_tcb->priority, temp_tcb_just_for_printing->priority);
				insert_after( iterator->prevtcb, new_tcb );
			}

		}

		result = 0;
	}

	return result;
}

int16_t remove_tcb( tcb * removed_tcb )
{
	int16_t result = -1;
	tcb * nexttcb_tcb;
	tcb * prevtcb_tcb;

	if(removed_tcb != NULL)
	{
		nexttcb_tcb = removed_tcb->nexttcb;
		prevtcb_tcb = removed_tcb->prevtcb;
		
		prevtcb_tcb->nexttcb = removed_tcb->nexttcb;
		nexttcb_tcb->prevtcb = removed_tcb->prevtcb;

		removed_tcb->nexttcb = NULL;
		removed_tcb->prevtcb = NULL;

		result = 0;
	}

	return result;
}

void print_list( linked_list * list)
{	
	printf("tcbs:");

	tcb * iterator = list->head;
	while(iterator != NULL)
	{
		printf(" %d", iterator->priority, iterator->prevtcb, iterator->nexttcb);
		iterator = iterator->nexttcb;
	}
	printf("\n");
}
