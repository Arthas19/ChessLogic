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

    setup_board(board, black, white);
    //TO DO: print_board(board, black, white);

    return 0;
}

void setup_players(PIECE black[], PIECE white[]) {
        black[0].point.x = 0;
        black[0].point.y = 0;
}

void setup_board(SQUARE board[][WIDTH], PIECE black[], PIECE white[]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j].point.x = i;
            board[i][j].point.y = j;
            board[i][j].piece = NULL;

            if (i = 0)
                board[i][j].piece = (PIECE*)(black + j);
            if (i = 1)
                board[i][j].piece = (PIECE*)(black + WIDTH+j);
            if (i = 6)
                board[i][j].piece = (PIECE*)(white+WIDTH+j);
            if (i = 7)
                board[i][j].piece = (PIECE*)(white + j);

            if ((i+j) % 2)
                board[i][j].color = BLACK;
            else
                board[i][j].color = WHITE;
        }
    }
}
