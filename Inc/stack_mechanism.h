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
	
struct Stack{
	uint8_t *Item_array;		// Pointer to first array element
	uint8_t First_item;
	uint8_t Last_item;
	uint8_t Current_item;		// Index of current item in array
	uint8_t *Current_item_p;	// Pointer to current item in array
	uint8_t Current_item_value;
	uint8_t Queue_size;			// Size of array
};

void Initialize_stack_struct(struct Stack *Stack_name, uint8_t Size);
uint8_t Add_stack_item(struct Stack *Stack_name, uint8_t Item);
uint8_t Take_element(struct Stack *Stack_name);
void Destroy_queue(struct Stack *Stack_name);
