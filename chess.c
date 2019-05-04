#include <stdio.h>
#include <stdlib.h>

/* Defined Variables */
#define EMPTY 0
#define WIDTH 8
#define HEIGHT 8
#define TABLE_SIZE 64

/* Functions used */

// Printing the chess table 
void print_table();
void move_pawn(int pos, int turn);
void move_rook(int pos, int turn);
void move_knight(int pos, int turn);
void move_bishop(int pos, int turn);
void move_queen(int pos, int turn);
void move_king(int pos, int turn);

/* Custom Structures used */

/* Globar variables */
// EMPTY  0    0
// PAWN   1   -1
// ROOK   5   -5
// KNIGHT 3   -3
// BISHOP 4   -4
// QUEEN  20  -20
// KING   100 -100

// Black player  1 
// White player -1
static int player_turn = -1;
static int chess_table[TABLE_SIZE] = { -5, -3, -4, -100, -20, -4, -3, -5,
                                       -1, -1, -1,   -1,  -1, -1, -1, -1,
                                        0,  0,  0,    0,   0,  0,  0,  0,
                                        0,  0,  0,    0,   0,  0,  0,  0, 
                                        0,  0,  0,    0,   0,  0,  0,  0, 
                                        0,  0,  0,    0,   0,  0,  0,  0, 
                                        1,  1,  1,    1,   1,  1,  1,  1,
                                        5,  3,  4,  100,  20,  4,  3,  5 };

int main() {

	print_table();
	move_pawn(9, 1);

    return 0;
}

void print_table() {

	//system("clear");

	for ( int i = 0; i < TABLE_SIZE; i++ ) {
		if ( i % WIDTH == 0 ) {
			printf("\n");
		}

		printf(" %d", chess_table[i]);
	}

	printf("\n\n");
}

void move_pawn(int pos, int turn) {
	int available[4] = { -1, -1, -1, -1 };

	if ( chess_table[pos + turn*WIDTH] == EMPTY ) {
		available[0] = pos + turn*WIDTH;

		if ( chess_table[pos + turn*2*WIDTH] == EMPTY ) {
			available[1] = pos + turn*2*WIDTH;
		}
	}

	if ( turn == 1 ) {
		// Right
		if ( chess_table[pos + WIDTH - 1] > 0 )
			available[2] = pos + WIDTH - 1;

		// Left
		if ( chess_table[pos + WIDTH + 1] > 0 )
			available[3] = pos + WIDTH + 1;

	} else {
		// Right
		if ( chess_table[pos - WIDTH + 1] < 0 )
			available[2] = pos - WIDTH + 1;
		// Left
		if ( chess_table[pos - WIDTH - 1] < 0 )
			available[3] = pos - WIDTH - 1;
	}

	printf("%s", "Slobodna mesta: ");
	for ( int i = 0; i < 4; i++ )
		printf("%d ", available[i]);
	printf("\n");
}
