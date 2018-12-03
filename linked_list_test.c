#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main()
{
	linked_list * tasks = calloc(1, sizeof(linked_list));

	tcb * tcb_1 = calloc(1, sizeof(tcb));
	       tcb_1->priority = 1;
	tcb * tcb_2 = calloc(1, sizeof(tcb));
	       tcb_2->priority = 2;
	tcb * tcb_3 = calloc(1, sizeof(tcb));
	       tcb_3->priority = 250;
	tcb * tcb_4 = calloc(1, sizeof(tcb));
	       tcb_4->priority = 0;
	tcb * tcb_5 = calloc(1, sizeof(tcb));
	       tcb_5->priority = 1;
	tcb * tcb_6 = calloc(1, sizeof(tcb));
	       tcb_6->priority = 200;
	tcb * tcb_7 = calloc(1, sizeof(tcb));
	       tcb_7->priority = 7;
	
	insert_in_order(tasks, tcb_1);
	insert_in_order(tasks, tcb_2);
	insert_in_order(tasks, tcb_3);
	insert_in_order(tasks, tcb_4);
	insert_in_order(tasks, tcb_5);
	insert_in_order(tasks, tcb_6);
	insert_in_order(tasks, tcb_7);
	
	print_list(tasks);
	remove_tcb(tcb_5);
	print_list(tasks);
	insert_in_order(tasks, tcb_5);
	print_list(tasks);

	free(tcb_1);	
	free(tcb_2);	
	free(tcb_3);	
	free(tcb_4);	
	free(tcb_5);	
	free(tcb_6);	
	free(tcb_7);	

	printf("Hello, World!\n");
	return 0;
}
