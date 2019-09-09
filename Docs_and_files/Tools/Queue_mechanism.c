#include <stdio.h>
#include <stdlib.h>


struct Queue{
	int *Item_array;
	int First_item;
	int Last_item;
	int Current_item;
	int *Current_item_p;
	int Queue_size;
};

void Initialize_queue_struct(struct Queue *Queue_name, int Size)
{
	Queue_name->Item_array = NULL;
	Queue_name->Queue_size = Size;
	Queue_name->Item_array = (int *)calloc(Size, sizeof(int));
	Queue_name->Current_item = 0;
	Queue_name->Current_item_p = NULL;
	Queue_name->First_item = 0;
	Queue_name->Last_item = Size;
}

void Add_Queue_Item(struct Queue *Queue_name, int Item)
{
	if(Queue_name->Current_item >= Queue_name->Queue_size)
	{
		printf("Queue full");
	} else
	{
		*((Queue_name->Item_array)+Queue_name->Current_item) = Item;
		Queue_name->Current_item += 1;
		Queue_name->Current_item_p = Queue_name->Item_array + Queue_name->Current_item;
	}
}



main()
{
	struct Queue Kju1;
	Initialize_queue_struct(&Kju1, 10);	
	Add_Queue_Item(&Kju1, 5);
	Add_Queue_Item(&Kju1, 8);
	Add_Queue_Item(&Kju1, 55);
	printf("First item: %d\nLast item: %d\nCurrent item: %d\nCurrent item pointer: %x\nFirst element pointer: %x\nCurrent item value: %d\n",
		    Kju1.First_item, Kju1.Last_item, Kju1.Current_item, Kju1.Current_item_p, Kju1.Item_array, *(Kju1.Current_item_p-1));
	int i;    
	for(i = 0; i < 10; i++)
	{
		printf("Element number %d: %d, %x\n", i, *(Kju1.Item_array+i), Kju1.Item_array+i);
	}
}






