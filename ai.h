#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"

// This function is a placeholder. I isolated it from the main program so it could be changed in the future.
int BOTChoosesIndex(int array[GRID_SIZE], int p_number, char symbol){
	int valid=0, value=-2;
	do{
		value=rand()%GRID_SIZE;
		if(array[value]==EMPTY){
			valid=1;
		}
	}while(valid==0);
	
	printf("PLAYER %d - %c entered in: %d\n", p_number, symbol, value+1);
	
	return value;
}