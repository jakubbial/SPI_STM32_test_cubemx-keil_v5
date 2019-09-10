#include <stdio.h>
#include <stdlib.h>


struct Queue{
	int *Item_array;		// Pointer to first array element
	int First_item;
	int Last_item;
	int Current_item;		// Index of current item in array
	int *Current_item_p;	// Pointer to current item in array
	int Queue_size;			// Size of array
};

void Print_array(struct Queue *Queue_name);
void Print_var(int Variable, char Num_type);
void Print_Queue(struct Queue *Queue_name);


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
		*(((Queue_name->Item_array)+Queue_name->Current_item)+1) = Item;
		Queue_name->Current_item += 1;
		Queue_name->Current_item_p = Queue_name->Item_array + Queue_name->Current_item;
	}
}

int Dequeue_element(struct Queue *Queue_name)
{
	int Value = *Queue_name->Current_item_p;
	*Queue_name->Current_item_p = 0;
	Queue_name->Current_item -= 1;
	Queue_name->Current_item_p = Queue_name->Item_array + Queue_name->Current_item;
	return Value;
}



main()
{
	struct Queue Kju;
	struct Queue *Kju_p = &Kju;
	int Dequeued_element;
	
	Initialize_queue_struct(Kju_p, 10);	
	
	Add_Queue_Item(Kju_p, 5);
	Add_Queue_Item(Kju_p, 15);
	Add_Queue_Item(Kju_p, 8);
	Add_Queue_Item(Kju_p, 55);
	Add_Queue_Item(Kju_p, 18);
	Add_Queue_Item(Kju_p, 97);
	Print_array(Kju_p);
	Print_Queue(Kju_p);

	Dequeued_element = Dequeue_element(Kju_p);
	Print_array(Kju_p);
	Print_Queue(Kju_p);
	
	printf("\n");
	Print_var(Dequeued_element, 'd');
}





void Print_array(struct Queue *Queue_name)
{
	int i;    
	for(i = 0; i < 10; i++)
	{
		printf("\nElement number %d: %d, %x", i, *(Queue_name->Item_array+i), Queue_name->Item_array+i);
	}
}

void Print_var(int Variable, char Num_type)
{
	if(Num_type == 'd')
	{
		printf("Value is: %d\n", Variable);
	}else if(Num_type == 'h')
	{
		printf("Value is: %x\n", Variable);
	}
}

void Print_Queue(struct Queue *Queue_name)
{
	printf("\n");
	Print_var(Queue_name->Current_item, 'd');
	Print_var(Queue_name->Current_item_p, 'h');
	Print_var(*Queue_name->Current_item_p, 'd');
	Print_var(Queue_name->First_item, 'd');
	Print_var(Queue_name->Item_array, 'h');
	Print_var(Queue_name->Last_item, 'd');
	Print_var(Queue_name->Queue_size, 'd');
}

