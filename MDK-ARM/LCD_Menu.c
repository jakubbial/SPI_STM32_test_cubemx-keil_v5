/**
  ******************************************************************************
  * @file           : LCD_Menu.c
  * @brief          : Create menu
  ******************************************************************************
  *
  *		
  *
  ******************************************************************************
  */



#include "LCD_Menu.h"
#include "LCD_Tools.h"


struct Item_Params Header_Item, Regular_Item;

struct Item Item_List[LIST_LENGTH] = {{'R', "Item I", 		1},
																			{'R', "Item II", 		2},
																			{'R', "Item III", 	3},
																			{'R', "Item IV", 		4},
																			{'R', "Item V", 		5},
																			{'R', "Item VI", 		6},
																			{'R', "Item VII", 	7},
																			{'R', "Item VIII", 	8},
																			{'R', "Item IX", 		9},
																			{'R', "Item X", 		10}};

void Prepare_item_parameters(void)
{
	Set_Item_Params(&Header_Item, Font20, WHITE, BLACK);
	Set_Item_Params(&Regular_Item, Font16, GREEN, BLACK);
}

void LCD_Create_Item_Using_Struct(struct Item Param, uint8_t Item)
{
	if(Param.Item_Type == 'H')
	{
		LCD_Create_Item(Header_Item, Param.Text, Item);
	}else if(Param.Item_Type == 'R')
	{
		LCD_Create_Item(Regular_Item, Param.Text, Item);
	}
}
	

void Fulfill_list(void)
{
	Prepare_item_parameters();
	
	uint8_t i;
	for(i=0; i<LIST_LENGTH; i++)
	{
		LCD_Create_Item_Using_Struct(Item_List[i], i);
	}
}
