#include <stdio.h>
#include <stdlib.h>


struct Koleja{
	int *tablica_wskaznik;
};

void Initialize(struct Koleja *Kolej)
{
	Kolej->tablica_wskaznik = (int *)calloc(10, sizeof(int));
}

void Add_element(struct Koleja *Kolej, int item)
{
	*Kolej->tablica_wskaznik = item;
}



main()
{
	struct Koleja Kol;
	Initialize(&Kol);	
	Add_element(&Kol, 12);
	
	//*Kol.tablica_wskaznik = 10;
	//*(Kol.tablica_wskaznik+1) = 10;
	
	printf("Wskaznik: %x, Wartosc: %d\n", Kol.tablica_wskaznik, *(Kol.tablica_wskaznik));
	
	
	/*
	int *ass = (int *)calloc(10, sizeof(int));
	
	*ass = 1;
	*(ass+1) = 2;
	
	int i, val;
	
	for(i=0; i<11; i++)
	{
		val = *(ass++);
		printf("Value of %d is: %d\n", i, val);
	}
	*/
}

