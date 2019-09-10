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
	
#include "main.h"
	
struct Queue{
	uint8_t *Item_array;		// Pointer to first array element
	uint8_t First_item;
	uint8_t Last_item;
	uint8_t Current_item;		// Index of current item in array
	uint8_t *Current_item_p;	// Pointer to current item in array
	uint8_t Current_item_value;
	uint8_t Queue_size;			// Size of array
};

void Initialize_queue_struct(struct Queue *Queue_name, uint8_t Size);
uint8_t Add_Queue_Item(struct Queue *Queue_name, uint8_t Item);
uint8_t Dequeue_element(struct Queue *Queue_name);
void Destroy_queue(struct Queue *Queue_name);
