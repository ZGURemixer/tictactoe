#include "ai.h"

static int matrix[SIZE][SIZE] = {EMPTY};

int changePlayerStatus(int number){
	char option='Z';
	int valid=0, result=-1;
	
	do{
		option='P';
		printf("PLAYER %d (B/H): ", number);
		fflush(stdin);
		scanf("%c", &option);
		switch(option){
			case 'B':
			case 'b':
				valid=1;
				result=BOT;
				break;
			case 'h':
			case 'H':
				valid=1;
				result=HUMAN;
				break;
			default:
				printf("ERROR: Invalid option selected.\n");
				break;
		}
	}while(valid==0);
	
	return result;
}

void convertArrayToMatrix(int array[], int m[SIZE][SIZE]) {
    int i = 0, j = 0, k = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            m[j][i] = array[k];
            k++;
        }
    }
}

int checkForFreeSpaces(int array[], int i, int x){
	switch(i){
		case GRID_SIZE:
			if(x>0){
				return 1;
			} else {
				return 0;
			}
			break;
		default:
			if(array[i]==0){
				return checkForFreeSpaces(array, i+1, x+1);
			} else {
				return checkForFreeSpaces(array, i+1, x);
			}
			break;
	}
}

int createEmptyMatrix(int i, int array[]) {
    if (i >= GRID_SIZE) {
        return EMPTY;
    } else {
        array[i] = EMPTY;
        return createEmptyMatrix(i + 1, array);
    }
}

void printGameMatrix(int array[]) {
    int i = 0, j = 0, k = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            switch (array[k]) {
                case X:
                    printf("[X]");
                    break;
                case O:
                    printf("[O]");
                    break;
                default:
                    printf("[ ]");
                    break;
            }
            k++;
        }
        printf("\n");
    }
}

int humanEntersIndex(int array[], char symbol, int p_number) {
    int value = -30, valid = 0;
    do {
        value = -30;
        printf("PLAYER %d - %c entered in: ", p_number, symbol);
        fflush(stdin);
        scanf("%d", &value);
        value--;
        if (value >= 0 && value < GRID_SIZE) {
            if (array[value] == EMPTY) {
                valid = 1;
            } else {
                printf(err4);
            }
        } else {
            printf(err3);
        }
    } while (valid == 0);

    return value;
}

int checkForWins(int array[]) {
    int wins = 0, coins = 0, i = 0, j = 0, result = 0, secondDiagonal[SIZE]={0};
    convertArrayToMatrix(array, matrix);

  	// Check horizontal lines
    for (i = 0; i < SIZE; i++) {
    	coins = 0;
    	if(matrix[0][i]!=EMPTY){
	        for (j = 1; j < SIZE; j++) {
	            if (matrix[j][i] == matrix[j - 1][i]) {
	                coins++;
	            }
	        }
	        
	        if (coins >= (SIZE - 1)) {
	            wins++;
	            result = matrix[0][i];
	            i = SIZE;
	            break;
	        }    	
		}
    }

    if (wins == 0) {
        // Check vertical lines
        for (i = 0; i < SIZE; i++) {
        	coins = 0;
        	if(matrix[i][0]!=EMPTY){
	            for (j = 1; j < SIZE; j++) {
	                if (matrix[i][j] == matrix[i][j - 1]) {
	                    coins++;
	                }
	            }
	            	            
	            if (coins >= (SIZE - 1)) {
	                wins++;
	                result = matrix[i][0];
	                i = SIZE;
	                break;
	            }
					        		
			}
        }
    }

    // Check diagonal 1
    coins = 0;
    if (wins == 0 && matrix[0][0] != EMPTY) {
        for (i = 1; i < SIZE; i++) {
            if (matrix[i][i] == matrix[i - 1][i - 1]) {
                coins++;
            }
        }
                
        if (coins >= (SIZE - 1)) {
            wins++;
            result = matrix[0][0];
        }
    }

    // Check diagonal 2
    coins = 0;
	if (wins == 0 && matrix[SIZE-1][0]!=EMPTY) {
		for(i=0; i<SIZE; i++){
			secondDiagonal[i]=matrix[i][SIZE-1-i];
		}
        
        for(i=1; i<SIZE; i++){
        	if(secondDiagonal[i]==secondDiagonal[i-1]){
        		coins++;
			}
		}
        
        if (coins >= (SIZE - 1)) {
            wins++;
            result = secondDiagonal[0];
        }
    }
    
    return result;
}

void gameTurn(PLAYER p, int array[]) {
    int indexToReplace = 0;
    switch (p.isBot) {
        case HUMAN:
            // Player isn't a bot.
            indexToReplace = humanEntersIndex(array, p.symbol, p.number);
            break;
        case BOT:
            // Player is a bot.
            indexToReplace = BOTChoosesIndex(array, p.number, p.symbol);
            break;
        default:
            // Invalid player status.
            printf(err2);
            exit(-1);
            break;
    }
    array[indexToReplace] = p.number;
    printGameMatrix(array);
}

int main() {
	srand(time(NULL));
	int array[GRID_SIZE], result=0, turnID=0, status=0, i=0;
	
    PLAYER players[2];
    createEmptyMatrix(0, array);
    
    players[0] = createPlayer(BOT, 'X', X);
    players[1] = createPlayer(BOT, 'O', O);
    
    for(i=0; i<2; i++){
    	players[i].isBot = changePlayerStatus(i+1);
	}
    
    printGameMatrix(array);
	do{	
		gameTurn(players[turnID], array);	
		switch(turnID){
			case 0:
				turnID=1;
				break;
			case 1:
				turnID=0;
				break;
		}
		status=checkForWins(array);
	}while(checkForFreeSpaces(array, 0, 0) && (status==0));
    
    switch(status){
    	case 0:
    		printf("TIE\n");
    		break;
    	default:
    		printf("PLAYER %d WINS\n", status);
    		break;
	}
    return 0;
}