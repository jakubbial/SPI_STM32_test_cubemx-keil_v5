#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
	int Array_size;
	int *First_array_element;
	int *Current_element;
	int *Next_element;
	int Space_left;
	
} Queue_data;

// Proto of printing queue
void Print_Queue(Queue_data *Queue_name);

void Initialize_queue(Queue_data *Queue_name, int Queue_size)
{
	Queue_name->Array_size = Queue_size;
	Queue_name->First_array_element = calloc(Queue_size, sizeof(int));
	Queue_name->Current_element=Queue_name->First_array_element;
	Queue_name->Next_element = Queue_name->First_array_element;
	Queue_name->Space_left = Queue_name->Array_size;
}

int Add_element(Queue_data *Queue_name, int Element)
{
	int Operation_status;
	
	printf("Space left: %d\n", Queue_name->Space_left);
	
	if(Queue_name->Space_left != 0)
	{
		*(Queue_name->Next_element) = Element;
		
		if(Queue_name->Space_left != 1)
		{
			Queue_name->Next_element += 1;
		}
		
		Queue_name->Space_left -= 1;
		Operation_status = 1;
	}else
	{
		Operation_status = 0;
	}
}

main()
{
	Queue_data d;
	Initialize_queue(&d, 4);
	Add_element(&d, 150);
	Add_element(&d, 250);	

	Print_Queue(&d);
}





















void Print_Queue(Queue_data *Queue_name)
{
	int i;
	int Queue_size = Queue_name->Array_size;
	int *First_element = Queue_name->First_array_element;
	
	printf("Addr: ");
	for(i=-1; i < Queue_size+1; i++)
	{
		printf("%16x ", First_element+i);
	}
	
	printf("\nValu: ");
	for(i=-1; i < Queue_size+1; i++)
	{
		printf("%16d ", *(First_element+i));
	}
	
	printf("\nCurr: ");
	for(i=-1; i < Queue_size+1; i++)
	{
		if(Queue_name->Current_element == (First_element+i))
		{
			printf("%16d ", 1);
		}else
		{
			printf("%16d ", 0);
		}
	}
	
	printf("\nNext: ");
	for(i=-1; i < Queue_size+1; i++)
	{
		if(Queue_name->Next_element == (First_element+i))
		{
			printf("%16d ", 1);
		}else
		{
			printf("%16d ", 0);
		}
	}
	
	printf("\nFree space: %d elements", Queue_name->Space_left);
}
