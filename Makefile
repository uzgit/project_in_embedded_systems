CC=gcc
CFLAGS=-I

all: linked_list queue

linked_list: linked_list_test.c doubly_linked_list.c
	$(CC) -o linked_list linked_list_test.c doubly_linked_list.c

queue: queue_test.c queue.c
	$(CC) -o queue queue_test.c queue.c
