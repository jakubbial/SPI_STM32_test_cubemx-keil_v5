/**
  ******************************************************************************
  * File Name          : USART.h
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
	uint8_t Queue_size;			// Size of array
};
