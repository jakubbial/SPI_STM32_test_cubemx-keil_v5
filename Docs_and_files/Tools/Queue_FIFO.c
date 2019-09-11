#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
	int Array_size;
	int *First_array_element;
	
} Queue_data;

void Print_Queue(Queue_data *Queue_name);


void Initialize_queue(Queue_data *Queue_name, int Queue_size)
{
	Queue_name->Array_size = Queue_size;
	Queue_name->First_array_element = calloc(Queue_size, sizeof(int));
}

main()
{
	Queue_data d;
	d.Array_size = 5;
	Print_Queue(&d);
}

void Print_Queue(Queue_data *Queue_name)
{
	int i;
	int Queue_size = Queue_name->Array_size;
	int *First_element = Queue_name->First_array_element;
	
	printf("Addresses:\n");
	for(i=0; i < Queue_size; i++)
	{
		printf("%08x ", First_element+i);
	}
	printf("\n Values:");
	for(i=0; i < Queue_size; i++)
	{
		printf("%08d ", *(First_element+i));
	}
}
