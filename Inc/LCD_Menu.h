#include "main.h"


#define LIST_LENGTH 11

struct Item
{
	char Item_Type;		// H for header, R for regular item
	char* Text;				// Text that is displayed to speciffic item
	uint16_t Value;		// Value of item
};


void Fulfill_list(void);
void Change_Item_Value(uint8_t Item_Number, uint32_t New_Val);
void Change_Item_Name(uint8_t Item_Number, char* Text);
