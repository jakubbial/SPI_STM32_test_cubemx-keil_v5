/**
  ******************************************************************************
  * File Name          : 
  * Description        : 
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */
	
#include <stdlib.h>
#include "Queue.h"

void Initialize_queue_struct(struct Queue *Queue_name, uint8_t Size)
{
	Queue_name->Item_array = NULL;
	Queue_name->Queue_size = Size;
	Queue_name->Item_array = (uint8_t *)calloc(Size, sizeof(uint8_t));
	Queue_name->Current_item = 0;
	Queue_name->Current_item_value = 0;
	Queue_name->Current_item_p = NULL;
	Queue_name->First_item = 0;
	Queue_name->Last_item = Size;
}


uint8_t Add_Queue_Item(struct Queue *Queue_name, uint8_t Item)
{
	uint8_t status;
	if(Queue_name->Current_item >= ((Queue_name->Queue_size)-1))
	{
		status = 0;
	} else
	{
		*(((Queue_name->Item_array)+Queue_name->Current_item)+1) = Item;
		Queue_name->Current_item += 1;
		Queue_name->Current_item_p = Queue_name->Item_array + Queue_name->Current_item;
		Queue_name->Current_item_value = *(Queue_name->Current_item_p);
		status = 1;
	}
	return status;
}


uint8_t Dequeue_element(struct Queue *Queue_name)
{
	uint8_t Value = *Queue_name->Current_item_p;
	
	if(Queue_name->Current_item > 0)
	{
		*Queue_name->Current_item_p = 0;
		Queue_name->Current_item -= 1;
		Queue_name->Current_item_p = Queue_name->Item_array + Queue_name->Current_item;
		Queue_name->Current_item_value = *(Queue_name->Current_item_p);
	}
	return Value;
}


void Destroy_queue(struct Queue *Queue_name)
{
	free(Queue_name);
}






