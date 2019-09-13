#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
	int Array_size;
	int *First_array_element;
	int *Current_element;
	int *Next_element;
	int *Last_element;
	int Space_left;
	
} Queue_data;

// Proto of printing queue
void Print_Queue(Queue_data *Queue_name);
int Initialize_queue_test();


// Allocates memory for Queue struct and fulfilling its elements.
// Returns pointer to created structure.
Queue_data* Initialize_queue(int Queue_size)
{
	// Allocate memory for struct
	Queue_data *Queue_p = (Queue_data*)malloc(sizeof(Queue_data));
	// Assign size
	Queue_p->Array_size = Queue_size;
	// Allocate memory for array that is speciffied size
	Queue_p->First_array_element = (int*)calloc(Queue_size, sizeof(int));
	// Current item is first element
	Queue_p->Current_element=Queue_p->First_array_element;
	// Next element is also current item
	Queue_p->Next_element = Queue_p->First_array_element;
	// All queue is free
	Queue_p->Space_left = Queue_p->Array_size;
	//
	Queue_p->Last_element = Queue_p->First_array_element + ((Queue_p->Array_size) - 1);
	
	return Queue_p;
}

// Freeing alocated memory
void Destroy_Queue(Queue_data *Queue_name)
{
	free(Queue_name->First_array_element);
	free(Queue_name);
	Queue_name == NULL;
}


int Add_element(Queue_data *Queue_name, int Element)
{
	int Operation_status;
	
	if(Queue_name->Space_left != 0)
	{
		*(Queue_name->Next_element) = Element;
		
		if (Queue_name->Next_element == Queue_name->Last_element)
		{
			Queue_name->Next_element = Queue_name->First_array_element;
		}else
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


int Dequeue_element(Queue_data *Queue_name)
{
	int Element;
	
	if(Queue_name->Space_left == Queue_name->Array_size)
	{
		Element = 0;
	} else
	{
		Element = *Queue_name->Current_element;
		*Queue_name->Current_element = 0;
		Queue_name->Space_left += 1;
		if(Queue_name->Current_element == Queue_name->Last_element)
		{
			Queue_name->Current_element = Queue_name->First_array_element;
		}else
		{
			Queue_name->Current_element += 1;
		}
	}
	return Element;
}


main()
{
	Queue_data *Koleja = Initialize_queue(5);
	char Decision = 0;
	int Deququed;
	
	
	while(1)
	{
		
		Decision = getchar();
		
		switch(Decision)
		{
			case 'A':
				{
					Add_element(Koleja, 150);
					system("cls");
					Print_Queue(Koleja);
					break;
				}
			case 'D':
				{
					Deququed = Dequeue_element(Koleja);
					system("cls");
					Print_Queue(Koleja);
					printf("\nDequeued element: %d\n", Deququed);
					
					break;
				}
			default:
				{
					break;
				}
		}
		
		if(Decision == 'E')
		{
			break;
		}
	}
	
	
	Destroy_Queue(Koleja);
}





















void Print_Queue(Queue_data *Queue_name)
{
	int i;
	int Queue_size = Queue_name->Array_size;
	int *First_element = Queue_name->First_array_element;
	int Elements_to_print = Queue_size+1;
	
	
	printf("Addr: ");
	for(i=-1; i < Elements_to_print; i++)
	{
		printf("%9x ", First_element+i);
	}
	
	printf("\nValu: ");
	for(i=-1; i < Elements_to_print; i++)
	{
		printf("%9d ", *(First_element+i));
	}
	
	printf("\nCurr: ");
	for(i=-1; i < Elements_to_print; i++)
	{
		if(Queue_name->Current_element == (First_element+i))
		{
			printf("%9d ", 1);
		}else
		{
			printf("%9d ", 0);
		}
	}
	
	printf("\nNext: ");
	for(i=-1; i < Elements_to_print; i++)
	{
		if(Queue_name->Next_element == (First_element+i))
		{
			printf("%9d ", 1);
		}else
		{
			printf("%9d ", 0);
		}
	}
	
	printf("\nFree space: %d elements\n\n", Queue_name->Space_left);
}


int Initialize_queue_test()
{
	int Elements = 9;
	int i;
	int Arr[10] = {0, 2, 3, 4, 5, 6, 7, 8, 9};
	Queue_data *Koleja = NULL;
	
	for(i=0; i<(sizeof(Arr)/sizeof(int)); i++ )
	{
		Koleja = Initialize_queue(Elements);
		
		if(Koleja->Array_size == Elements)
		{
			printf("\nJest ok");
		} else
		{
			printf("\n %d Elementow - Fail", Elements);
		}
		
		Destroy_Queue(Koleja);
	}
}

