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
#include "stack_mechanism.h"

void Initialize_stack_struct(struct Stack *Stack_name, uint8_t Size)
{
	Stack_name->Item_array = NULL;
	Stack_name->Queue_size = Size;
	Stack_name->Item_array = (uint8_t *)calloc(Size, sizeof(uint8_t));
	Stack_name->Current_item = 0;
	Stack_name->Current_item_value = 0;
	Stack_name->Current_item_p = NULL;
	Stack_name->First_item = 0;
	Stack_name->Last_item = Size;
}


uint8_t Add_stack_item(struct Stack *Stack_name, uint8_t Item)
{
	uint8_t status;
	if(Stack_name->Current_item >= ((Stack_name->Queue_size)-1))
	{
		status = 0;
	} else
	{
		*(((Stack_name->Item_array)+Stack_name->Current_item)+1) = Item;
		Stack_name->Current_item += 1;
		Stack_name->Current_item_p = Stack_name->Item_array + Stack_name->Current_item;
		Stack_name->Current_item_value = *(Stack_name->Current_item_p);
		status = 1;
	}
	return status;
}


uint8_t Take_element(struct Stack *Stack_name)
{
	uint8_t Value = *Stack_name->Current_item_p;
	
	if(Stack_name->Current_item > 0)
	{
		*Stack_name->Current_item_p = 0;
		Stack_name->Current_item -= 1;
		Stack_name->Current_item_p = Stack_name->Item_array + Stack_name->Current_item;
		Stack_name->Current_item_value = *(Stack_name->Current_item_p);
	}
	return Value;
}


void Destroy_queue(struct Stack *Stack_name)
{
	free(Stack_name);
}






