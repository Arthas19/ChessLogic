#include <stdio.h>
#include <stdlib.h>

/* Defined variables */
#define EMPTY       0
#define BLACK       1
#define WHITE      -1
#define WIDTH       8
#define TABLE_SIZE 64

/* Functions used */

// Printing chess table
void print_table();
// Printing fields available to play
void print_available(int arr[], int size);
// Moving logic for all the figures
void move_pawn(int pos, int turn);
void move_rook(int pos, int turn);
void move_knight(int pos, int turn);
void move_bishop(int pos, int turn);
void move_queen(int pos, int turn);
void move_king(int pos, int turn);

// Checking if target is eatable
int eatable(int x, int turn);

/* Custom structures used */

/* Globar variables */
// EMPTY  0    0
// PAWN   1   -1
// ROOK   5   -5
// KNIGHT 3   -3
// BISHOP 4   -4
// QUEEN  20  -20
// KING   100 -100

static int player_turn = WHITE;
static int chess_table[TABLE_SIZE] = { -5, -3, -4, -100, -20, -4, -3, -5,
                                       -1, -1, -1,   -1,  -1, -1, -1, -1,
                                        0,  0,  0,    0,   0,  0,  0,  0,
                                        0,  0,  0,    0,   0,  0,  0,  0,
                                        0,  0,  0,    0,   0,  0,  0,  0,
                                        -1,  1,  5,    0,   0,  0,  -1,  0,
                                        1,  1,  -1,    1,   1,  1,  1,  1,
                                        5,  3,  -4,  100,  20,  4,  3,  5 };

int main() {

	print_table();
	//move_pawn(48, -1);
    move_rook(42, -1);

    return 0;
}

void move_rook(int pos, int turn) {
    int available[14] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

    int x;
    int j = 0;

    for ( int i = 1; i <= pos / WIDTH; i++ ) {
        x = pos - i * WIDTH;
        if ( chess_table[x] != EMPTY) {
            if ( eatable(x, turn) )
                available[j++] = x;
            break;
        } else {
            available[j++] = x;
        }
    }

    // Down
    for ( int i = 1; i < ( WIDTH - ( pos / WIDTH ) ); i++ ) {
        x = pos + i * WIDTH;
        if ( chess_table[x] != EMPTY ) {
            if ( eatable(x, turn) )
                available[j++] = x;
            break;
        } else {
            available[j++] = x;
        }
    }

    // Right
    for ( int i = 1; i < ( WIDTH - ( pos % WIDTH ) ); i++ )
    {
        x = pos + i;
        if ( chess_table[x] != EMPTY ) {
            if ( eatable(x, turn) )
                available[j++] = x;
            break;
        } else {
            available[j++] = x;
        }
    }
    // Left
    for ( int i = 1; i <= pos % WIDTH; i++ ) {
        x = pos - i;
        if ( chess_table[x] != EMPTY ) {
            if (  eatable(x, turn) )
                available[j++] = x;
            break;
        } else {
            available[j++] = x;
        }
    }

    print_available(available, 14);
}

void move_pawn(int pos, int turn) {
    int available[4] = { -1, -1, -1, -1 };

	// Black
	if ( turn == BLACK ) {

		// Move forward by 1
		if ( pos < 56) {
			if ( chess_table[pos + WIDTH] == EMPTY ) {
				available[0] = pos + WIDTH;

				// Move forward by 2
				if ( pos < 16)
					if ( chess_table[pos + 2*WIDTH] == EMPTY )
						available[1] = pos + 2*WIDTH;
			}
		}

		// Eat Right
		if (pos % WIDTH != 0)
			if ( chess_table[pos + WIDTH - 1] > 0 )
				available[2] = pos + WIDTH - 1;

		// Eat Left
		if (pos % WIDTH != 7)
			if ( chess_table[pos + WIDTH + 1] > 0 )
				available[3] = pos + WIDTH + 1;
	// White
	} else {

		// Move forward by 1
		if ( pos > 7) {
			if ( chess_table[pos - WIDTH] == EMPTY ) {
				available[0] = pos - WIDTH;

				// Move forward by 2
				if ( pos > 47)
					if ( chess_table[pos - 2*WIDTH] == EMPTY )
						available[1] = pos - 2*WIDTH;
			}
		}
		// Eat Right
		if (pos % WIDTH != 7)
			if ( chess_table[pos - WIDTH + 1] < 0 )
				available[2] = pos - WIDTH + 1;

		// Eat Left
		if (pos % WIDTH != 0)
			if ( chess_table[pos - WIDTH - 1] < 0 )
				available[3] = pos - WIDTH - 1;
	}

    print_available(available, 4);
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

void print_available(int arr[], int size) {
    printf("Slobodna mesta: ");

    for ( int i = 0; i < size; i++ )
        printf("%d ", arr[i]);

    printf("\n");
}

int eatable(int x, int turn) {
    if ( ( chess_table[x] < 0  && turn == WHITE ) || ( chess_table[x] > 0 && turn == BLACK ) )
        return 1;
    return 0;
}
