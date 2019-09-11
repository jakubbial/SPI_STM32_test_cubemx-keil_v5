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

/* Array of default items that are displayed */
struct Item Item_List[LIST_LENGTH] = {{'R', "Item I", 		1},
																			{'R', "Item II", 		2},
																			{'R', "Item III", 	3},
																			{'R', "Item IV", 		4},
																			{'R', "Item V", 		5},
																			{'R', "Item VI", 		6},
																			{'R', "Item VII", 	7},
																			{'R', "Item VIII", 	8},
																			{'R', "Item IX", 		9},
																			{'R', "Item X", 		1},
																			{'R', "Item new",		1}};


struct Item_Params Header_Item, Regular_Item;

																			
void Prepare_item_parameters(void)
{
	Set_Item_Params(&Header_Item, Font20, WHITE, BLACK);
	Set_Item_Params(&Regular_Item, Font12, BLACK, GREEN);
}

void LCD_Create_Item_Using_Struct(struct Item Item, uint8_t Item_Position)
{
	if(Item.Item_Type == 'H')
	{
		LCD_Create_Item(Header_Item, Item.Text, Item.Value, Item_Position);
	}else if(Item.Item_Type == 'R')
	{
		LCD_Create_Item(Regular_Item, Item.Text, Item.Value, Item_Position);
	}
}

void Update_Item_Value_Using_Struct(struct Item Item, uint8_t Item_Position)
{
	Display_Number(Regular_Item, Item.Value, Item_Position);
}

void Fulfill_list(void)
{
	Prepare_item_parameters();
	
	uint8_t i;
	for(i=0; i<LIST_LENGTH; i++)
	{
		LCD_Create_Item_Using_Struct(Item_List[i], i+1);
	}
}

void Update_Item_Value(uint8_t Item_Number)
{
	Update_Item_Value_Using_Struct(Item_List[Item_Number], Item_Number+1);
}

void Change_Item_Value(uint8_t Item_Number, uint32_t New_Val)
{
	Item_List[Item_Number].Value = New_Val;
	Update_Item_Value(Item_Number);
}

void Change_Item_Name(uint8_t Item_Number, char* Text)
{
	Item_List[Item_Number].Text = Text;
	//Update_Item_Value(Item_Number);
	LCD_Create_Item_Using_Struct(Item_List[Item_Number], Item_Number+1);
}
