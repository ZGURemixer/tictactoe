#define EMPTY 0
#define X 1
#define O 2

#define SIZE 3
#define GRID_SIZE 9

#define err0 "ERROR: Non-ternary matrix was used.\n"
#define err1 "ERROR: Invalid player ID.\n"
#define err2 "ERROR: Invalid player status.\n"
#define err3 "ERROR: Invalid value.\n"
#define err4 "ERROR: Value can't be overwritten.\n"

#define BOT 1
#define HUMAN 0

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