#include "main.h"


#define LIST_LENGTH 10

struct Item
{
	char Item_Type;
	const char* Text;
	uint16_t Value;
};


void Fulfill_list(void);
void Change_Item_Value(uint8_t Item_Number, uint32_t New_Val);
