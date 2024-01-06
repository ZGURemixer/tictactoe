#include "game.h"

static int matrix[SIZE][SIZE] = {EMPTY};
static const int minOption=1, maxOption=3;

int mainMenu(){
	int result=INVALID, valid=0;
	do{
		result=INVALID;
		printf("Welcome to Roger's Tic-Tac-Toe!\n");
		printf("1. Start match.\n");
		printf("2. About.\n");
		printf("3. Exit.\n");
		printf("Selected option: ");
		scanf("%d", &result);
		if((result>=minOption && result<=maxOption))
			valid=1;
		else
			printf(err3);
	}while(valid==0);
	
	return result;
}

int main() {
	srand(time(NULL));
	int exit=0, option=INVALID, i=0;
	
    PLAYER players[PLAYER_AMOUNT];

    players[0] = createPlayer(BOT, 'X', X);
    players[1] = createPlayer(BOT, 'O', O);
    
    do{
    	option=mainMenu();
    	switch(option){
    		case 1: // Start match
				match(players, matrix);
    			break;
    		case 2: // About
    			printf("This is a small project I made in C during the summer of 2024 to practice my coding skills.\n");
    			printf("To play the game, each player takes turns to fill a %dx%d grid with their symbol.\n", SIZE, SIZE);
    			printf("The first player to get %d in a row wins the game.\n", SIZE);
    			printf(profileurl);
    			break;
    		case 3: // Exit
    			exit=1;
    			break;
		}
	}while(exit==0);
    return 0;
}