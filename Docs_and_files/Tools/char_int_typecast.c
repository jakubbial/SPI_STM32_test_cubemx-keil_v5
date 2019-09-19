#include <stdio.h>
#include <stdlib.h>


//int* Convert_char_array();


main()
{
	//int *Int_Arr;
	//Int_Arr = Convert_char_array();
	/*
	char usb_response[31] = "You have just pressed my button";
	int Int_arr;
	*/
	int usb_response = (int*)"You have just pressed my button";
	printf(usb_response);
	
	/*
	sscanf(usb_response, "%x", Int_arr);
	printf("Char: %d, Int: %x\n", usb_response, Int_arr);
	printf("Char: %d, Int: %x\n", usb_response+1, Int_arr+1);
	*/
}

/*
int* Convert_char_array()
{
	char usb_response[31] = "You have just pressed my button";
	int Int_arr;
	sscanf(usb_response, "%x", Int_arr);
	

	int size = sizeof(usb_response);
	int Int_arr[31];
	int i=0;
	
	for(i=0; i<size; i++)
	{
		Int_arr[i] = (int)usb_response[i];
	}
}
*/
