#define EMPTY 0
#define X 1
#define O 2

#define SIZE 3
#define GRID_SIZE 9
#define PLAYER_AMOUNT 2

#define err2 "ERROR: Invalid player status.\n"
#define err3 "ERROR: Invalid value.\n"
#define err4 "ERROR: Value can't be overwritten.\n"

#define separator "--------------------------------\n"

#define profileurl \
    "https:/" "/github.com/ZGURemixer/tictactoe\n"

#define BOT 1
#define HUMAN 0

#define INVALID -420

typedef unsigned int nat;

typedef struct p {
    int isBot;
    char symbol;
    int number;
} PLAYER;

PLAYER createPlayer(int isBot, char symbol, int number) {
    PLAYER p;
    p.isBot = isBot;
    p.symbol = symbol;
    p.number = number;
    return p;
}