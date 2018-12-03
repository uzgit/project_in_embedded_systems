#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int main()
{
	queue * task_queue = calloc(1, sizeof(queue));
	init_queue(task_queue);

        tcb * task_1 = calloc(1, sizeof(tcb));
               task_1->priority = 1;
        tcb * task_2 = calloc(1, sizeof(tcb));
               task_2->priority = 2;
        tcb * task_3 = calloc(1, sizeof(tcb));
               task_3->priority = 250;
        tcb * task_4 = calloc(1, sizeof(tcb));
               task_4->priority = 0;
        tcb * task_5 = calloc(1, sizeof(tcb));
               task_5->priority = 1;
        tcb * task_6 = calloc(1, sizeof(tcb));
               task_6->priority = 200;
        tcb * task_7 = calloc(1, sizeof(tcb));
               task_7->priority = 7;

	enqueue(task_queue, task_1);
	print_queue(task_queue);
	enqueue(task_queue, task_2);
	print_queue(task_queue);
	enqueue(task_queue, task_3);
	print_queue(task_queue);
	enqueue(task_queue, task_4);
	print_queue(task_queue);
	enqueue(task_queue, task_5);
	print_queue(task_queue);
	enqueue(task_queue, task_6);
	print_queue(task_queue);
	enqueue(task_queue, task_7);
	print_queue(task_queue);

	dequeue(task_queue, task_1);
	print_queue(task_queue);
	dequeue(task_queue, task_2);
	print_queue(task_queue);
	dequeue(task_queue, task_3);
	print_queue(task_queue);
	dequeue(task_queue, task_4);
	print_queue(task_queue);
	dequeue(task_queue, task_5);
	print_queue(task_queue);
	dequeue(task_queue, task_6);
	print_queue(task_queue);
	dequeue(task_queue, task_7);
	print_queue(task_queue);

	printf("Hello, World!\n");
	return 0;
}
