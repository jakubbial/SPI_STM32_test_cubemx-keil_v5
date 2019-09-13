/**
  ******************************************************************************
  * @file           : queue_fifo.h
  * @brief          : FIFO Queue header file
  ******************************************************************************
  * @attention
	*
  ******************************************************************************
  */
	
	#include "main.h"
	
	typedef struct Queue {
	uint8_t Array_size;
	int *First_array_element;
	int *Current_element;
	int *Next_element;
	int *Last_element;
	uint8_t Space_left;
	
} Queue_data;
	
Queue_data* Initialize_queue(uint8_t Queue_size);
void Destroy_Queue(Queue_data *Queue_name);
int Add_element(Queue_data *Queue_name, uint8_t Element);
uint8_t Dequeue_element(Queue_data *Queue_name);


