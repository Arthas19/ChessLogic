#include <stdio.h>
#include <stdlib.h>

#define BLACK -1
#define WHITE  1
#define WIDTH  8

enum Piece { EMPTY = 0, PAWN = 10, ROOK = 50, KNIGHT = 30, BISHOP = 40, QUEEN = 200, KING = 1000 };

/* Custom structures used in game */

typedef struct point_st {
    int x, y;
} POINT;

typedef struct chess_piece_st {
    POINT point;
    int piece;
    int color;
} PIECE;

typedef struct square_st {
    POINT point;
    int color;
    PIECE* piece;
} SQUARE;


/* Global variables used in game */

static int player_turn = WHITE;


/* Functions used in game */

void setup_board(SQUARE board[][WIDTH], PIECE black[], PIECE white[]);
void setup_players(PIECE black[], PIECE white[]);
void print_board(SQUARE board[][WIDTH], PIECE black[], PIECE white[]);

int main() {

    PIECE black[WIDTH<<1] = {};
    PIECE white[WIDTH<<1] = {};
    SQUARE board[WIDTH][WIDTH] = {};

    //TO DO: setup_players(black, white);
    setup_board(board, black, white);
    //TO DO: print_board(board, black, white);

    return 0;
}

void setup_board(SQUARE board[][WIDTH], PIECE black[], PIECE white[]) {
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x].point.x = x;
            board[y][x].point.y = y;
            board[y][x].piece = NULL;

            if (y = 0)
                board[y][x].piece = (PIECE*)(black + x);
            if (y = 1)
                board[y][x].piece = (PIECE*)(black + WIDTH + x);
            if (y = 6)
                board[y][x].piece = (PIECE*)(white + WIDTH + x);
            if (y = 7)
                board[y][x].piece = (PIECE*)(white + x);

            if ((x+y) % 2)
                board[y][x].color = BLACK;
            else
                board[y][x].color = WHITE;
        }
    }
}

void setup_players(PIECE black[], PIECE white[]) {
    
}
