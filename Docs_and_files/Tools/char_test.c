#include <stdio.h>
#include <string.h>


main(){
	char moje_tego[3] = {'A', 'B', 'C'};
	printf("1: %x, 2: %x, 3: %x, Ptr: %x\n", moje_tego[0], moje_tego+1, moje_tego[2], moje_tego);
	
	
	const char* moj_text = "ASS Baloon";
	printf("1: %x, 2: %x, 3: %x, Ptr: %x\n", moj_text[0], moj_text[1], moj_text[2], moj_text);

	
	int size = strlen(moj_text);
	printf("Len: %d\n", size);
	
	if(size>=8)
	{

	}
	
	moje_tego = 0;
	//moje_tego = moje_tego+2;
	//printf("1: %x, 2: %x, 3: %x, Ptr: %x\n", moje_tego[0], moje_tego[1], moje_tego[2], moje_tego);
	
}

