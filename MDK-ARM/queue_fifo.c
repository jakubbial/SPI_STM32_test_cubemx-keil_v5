/**
  ******************************************************************************
  * @file           : queue_fifo.c
  * @brief          : FIFO Queue implementation
  ******************************************************************************
  * @attention
	*
	* This file contains functions needed to operate with FIFO queue
	* 	• Initialize_queue function 
	*			- Allocates space in memory for queue structure
	*			- Allocates space in memory for array that contains queue items
	*			- Initializes queue pointers and variables
	*		• Destroy_queue function
	*			-	It destroys array with items and then destroys queue struct using free()
	*		• Add_element function
	*		•	Dequeue_element
	*
  ******************************************************************************
  */

#include "queue_fifo.h"
#include <stdlib.h>


// Allocates memory for Queue struct and fulfilling its elements.
// Returns pointer to created structure.
Queue_data* Initialize_queue(uint8_t Queue_size)
{
	Queue_data *Queue_p = (Queue_data*)malloc(sizeof(Queue_data));
	Queue_p->Array_size = Queue_size;
	Queue_p->First_array_element = (uint8_t*)calloc(Queue_size, sizeof(uint8_t));
	Queue_p->Current_element=Queue_p->First_array_element;
	Queue_p->Next_element = Queue_p->First_array_element;
	Queue_p->Space_left = Queue_p->Array_size;
	Queue_p->Last_element = Queue_p->First_array_element + ((Queue_p->Array_size) - 1);
	
	return Queue_p;
}

// Freeing alocated memory
void Destroy_Queue(Queue_data *Queue_name)
{
	free(Queue_name->First_array_element);
	free(Queue_name);
	Queue_name = NULL;
}


uint8_t Add_element(Queue_data *Queue_name, uint8_t Element)
{
	uint8_t Operation_status;
	
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
	return Operation_status;
}


uint8_t Dequeue_element(Queue_data *Queue_name)
{
	uint8_t Element;
	
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
