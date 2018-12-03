#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main()
{
	linked_list * tasks = calloc(1, sizeof(linked_list));

	tcb * tcb_1 = calloc(1, sizeof(tcb));
	       tcb_1->back_online_time = 1;
	       tcb_1->priority = 20;
	tcb * tcb_2 = calloc(1, sizeof(tcb));
	       tcb_2->back_online_time = 2;
	       tcb_2->priority = 42;
	tcb * tcb_3 = calloc(1, sizeof(tcb));
	       tcb_3->back_online_time = 250;
	       tcb_3->priority = 17;
	tcb * tcb_4 = calloc(1, sizeof(tcb));
	       tcb_4->back_online_time = 0;
	       tcb_4->priority = 2;
	tcb * tcb_5 = calloc(1, sizeof(tcb));
	       tcb_5->back_online_time = 1;
	       tcb_5->priority = 4;
	tcb * tcb_6 = calloc(1, sizeof(tcb));
	       tcb_6->back_online_time = 200;
	       tcb_6->priority = 1;
	tcb * tcb_7 = calloc(1, sizeof(tcb));
	       tcb_7->back_online_time = 7;
	       tcb_7->priority = 8;
/*	
	insert_by_back_online_time(tasks, tcb_1);
	insert_by_back_online_time(tasks, tcb_2);
	insert_by_back_online_time(tasks, tcb_3);
	insert_by_back_online_time(tasks, tcb_4);
	insert_by_back_online_time(tasks, tcb_5);
	insert_by_back_online_time(tasks, tcb_6);
	insert_by_back_online_time(tasks, tcb_7);
*/	
	insert_by_priority(tasks, tcb_1);
	insert_by_priority(tasks, tcb_2);
	insert_by_priority(tasks, tcb_3);
	insert_by_priority(tasks, tcb_4);
	insert_by_priority(tasks, tcb_5);
	insert_by_priority(tasks, tcb_6);
	insert_by_priority(tasks, tcb_7);

	print_list(tasks);
	remove_tcb(tcb_5);
	print_list(tasks);
	insert_by_priority(tasks, tcb_5);
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
