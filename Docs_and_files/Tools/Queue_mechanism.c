#include <stdio.h>
#include <stdlib.h>


struct Queue{
	int* Item_array;
	int* First_item;
	int* Last_item;
	int* Current_item;
	int Queue_size;
};

void Initialize_queue_struct(struct Queue Queue_name, int Size)
{
	Queue_name.Item_array = NULL;
	Queue_name.Queue_size = Size;
	Queue_name.Item_array = malloc(Queue_name.Queue_size);	
}

void Add_Queue_Item(struct Queue Queue_name)
{
	Queue_name.Item_array = 1;
	
}



main()
{
	struct Queue Kju1;
	Initialize_queue_struct(Kju1, 10);
}

