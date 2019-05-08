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
                                        0,  0,  0,    0,   0,  0,  0,  0,
                                        1,  1,  1,    1,   1,  1,  1,  1,
                                        5,  3,  4,  100,  20,  4,  3,  5 };

int main() {

	print_table();
	//move_pawn(48, -1);
    //move_rook(42, -1);
    move_knight(46, -1);

    return 0;
}

void move_knight(int pos, int turn) {
    int available[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };

    int x, j = 0;

    switch (pos) {
        case 0:
            // upper left
            if ( eatable(10, turn) || chess_table[10] == EMPTY )
                available[j++] = 10;
            if ( eatable(17, turn) || chess_table[17] == EMPTY )
                available[j++] = 17;
            break;
        case 7:
            // upper right
            if ( eatable(13, turn) || chess_table[13] == EMPTY )
                available[j++] = 13;
            if ( eatable(22, turn) || chess_table[22] == EMPTY )
                available[j++] = 22;
            break;
        case 56:
            // bottom left
            if ( eatable(41, turn) || chess_table[41] == EMPTY )
                available[j++] = 41;
            if ( eatable(50, turn) || chess_table[50] == EMPTY )
                available[j++] = 50;
            break;
        case 63:
            // bottom right
            if ( eatable(46, turn) || chess_table[46] == EMPTY )
                available[j++] = 46;
            if ( eatable(53, turn) || chess_table[53] == EMPTY )
                available[j++] = 53;
            break;
        case 9:
            // upper left + 8 + 1
            if ( eatable(3, turn) || chess_table[3] == EMPTY )
                available[j++] = 3;
            if ( eatable(19, turn) || chess_table[19] == EMPTY )
                available[j++] = 19;
            if ( eatable(24, turn) || chess_table[24] == EMPTY )
                available[j++] = 24;
            if ( eatable(26, turn) || chess_table[26] == EMPTY )
                available[j++] = 26;
            break;
        case 49:
            // bottom left - 8 + 1
            if ( eatable(32, turn) || chess_table[32] == EMPTY )
                available[j++] = 32;
            if ( eatable(34, turn) || chess_table[34] == EMPTY )
                available[j++] = 34;
            if ( eatable(43, turn) || chess_table[43] == EMPTY )
                available[j++] = 43;
            if ( eatable(59, turn) || chess_table[59] == EMPTY )
                available[j++] = 59;
            break;
        case 14:
            // upper right + 8 - 1
            if ( eatable(4, turn) || chess_table[4] == EMPTY )
                available[j++] = 4;
            if ( eatable(20, turn) || chess_table[20] == EMPTY )
                available[j++] = 20;
            if ( eatable(29, turn) || chess_table[29] == EMPTY )
                available[j++] = 29;
            if ( eatable(31, turn) || chess_table[31] == EMPTY )
                available[j++] = 31;
            break;
        case 54:
            // bottom right - 8 - 1
            if ( eatable(37, turn) || chess_table[37] == EMPTY )
                available[j++] = 37;
            if ( eatable(39, turn) || chess_table[39] == EMPTY )
                available[j++] = 39;
            if ( eatable(44, turn) || chess_table[44] == EMPTY )
                available[j++] = 44;
            if ( eatable(60, turn) || chess_table[60] == EMPTY )
                available[j++] = 60;
            break;
        case 1:
            // upper left + 1
            if ( eatable(11, turn) || chess_table[11] == EMPTY )
                available[j++] = 11;
            if ( eatable(16, turn) || chess_table[16] == EMPTY )
                available[j++] = 16;
            if ( eatable(18, turn) || chess_table[18] == EMPTY )
                available[j++] = 18;
            break;
        case 8:
            // upper left + 8
            if ( eatable(2, turn) || chess_table[2] == EMPTY )
                available[j++] = 37;
            if ( eatable(18, turn) || chess_table[18] == EMPTY )
                available[j++] = 18;
            if ( eatable(25, turn) || chess_table[25] == EMPTY )
                available[j++] = 25;
            break;
        case 6:
            // upper right - 1
            if ( eatable(12, turn) || chess_table[12] == EMPTY )
                available[j++] = 12;
            if ( eatable(21, turn) || chess_table[21] == EMPTY )
                available[j++] = 21;
            if ( eatable(23, turn) || chess_table[23] == EMPTY )
                available[j++] = 23;
            break;
        case 15:
            // upper right + 8
            if ( eatable(5, turn) || chess_table[5] == EMPTY )
                available[j++] = 5;
            if ( eatable(21, turn) || chess_table[21] == EMPTY )
                available[j++] = 21;
            if ( eatable(30, turn) || chess_table[30] == EMPTY )
                available[j++] = 30;
            break;
        case 48:
            // bottom left - 8
            if ( eatable(33, turn) || chess_table[33] == EMPTY )
                available[j++] = 33;
            if ( eatable(42, turn) || chess_table[42] == EMPTY )
                available[j++] = 42;
            if ( eatable(58, turn) || chess_table[58] == EMPTY )
                available[j++] = 58;
            break;
        case 57:
            // bottom left + 1
            if ( eatable(40, turn) || chess_table[40] == EMPTY )
                available[j++] = 40;
            if ( eatable(42, turn) || chess_table[42] == EMPTY )
                available[j++] = 42;
            if ( eatable(51, turn) || chess_table[51] == EMPTY )
                available[j++] = 51;
            break;
        case 55:
            // bottom right - 8
            if ( eatable(38, turn) || chess_table[38] == EMPTY )
                available[j++] = 38;
            if ( eatable(45, turn) || chess_table[45] == EMPTY )
                available[j++] = 45;
            if ( eatable(61, turn) || chess_table[61] == EMPTY )
                available[j++] = 61;
            break;
        case 62:
            // bottom right - 1
            if ( eatable(45, turn) || chess_table[45] == EMPTY )
                available[j++] = 45;
            if ( eatable(47, turn) || chess_table[47] == EMPTY )
                available[j++] = 47;
            if ( eatable(52, turn) || chess_table[52] == EMPTY )
                available[j++] = 52;
            break;
        // >|
        case 16:
        case 24:
        case 32:
        case 40:
            if ( eatable(pos - 2*WIDTH + 1, turn) || chess_table[pos - 2*WIDTH + 1] == EMPTY )
                available[j++] = pos - 2*WIDTH + 1;
            if ( eatable(pos + 2*WIDTH + 1, turn) || chess_table[pos + 2*WIDTH + 1] == EMPTY )
                available[j++] = pos + 2*WIDTH + 1;
            if ( eatable(pos - WIDTH + 2, turn) || chess_table[pos - WIDTH + 2] == EMPTY )
                available[j++] = pos - WIDTH + 2;
            if ( eatable(pos + WIDTH + 2, turn) || chess_table[pos + WIDTH + 2] == EMPTY )
                available[j++] = pos + WIDTH + 2;
            break;
        // >||
        case 17:
        case 25:
        case 33:
        case 41:
            if ( eatable(pos - 2*WIDTH + 1, turn) || chess_table[pos - 2*WIDTH + 1] == EMPTY )
                available[j++] = pos - 2*WIDTH + 1;
            if ( eatable(pos + 2*WIDTH + 1, turn) || chess_table[pos + 2*WIDTH + 1] == EMPTY )
                available[j++] = pos + 2*WIDTH + 1;
            if ( eatable(pos - 2*WIDTH - 1, turn) || chess_table[pos - 2*WIDTH - 1] == EMPTY )
                available[j++] = pos - 2*WIDTH - 1;
            if ( eatable(pos + 2*WIDTH - 1, turn) || chess_table[pos + 2*WIDTH - 1] == EMPTY )
                available[j++] = pos + 2*WIDTH - 1;
            if ( eatable(pos - WIDTH + 2, turn) || chess_table[pos - WIDTH + 2] == EMPTY )
                available[j++] = pos - WIDTH + 2;
            if ( eatable(pos + WIDTH + 2, turn) || chess_table[pos + WIDTH + 2] == EMPTY )
                available[j++] = pos + WIDTH + 2;
            break;
        // |<
        case 22:
        case 30:
        case 38:
        case 46:
            if ( eatable(pos - 2*WIDTH - 1, turn) || chess_table[pos - 2*WIDTH - 1] == EMPTY )
                available[j++] = pos - 2*WIDTH - 1;
            if ( eatable(pos + 2*WIDTH - 1, turn) || chess_table[pos + 2*WIDTH - 1] == EMPTY )
                available[j++] = pos + 2*WIDTH - 1;
            if ( eatable(pos - 2*WIDTH + 1, turn) || chess_table[pos - 2*WIDTH + 1] == EMPTY )
                available[j++] = pos - 2*WIDTH + 1;
            if ( eatable(pos + 2*WIDTH + 1, turn) || chess_table[pos + 2*WIDTH + 1] == EMPTY )
                available[j++] = pos + 2*WIDTH + 1;
            if ( eatable(pos - WIDTH + 2, turn) || chess_table[pos - WIDTH + 2] == EMPTY )
                available[j++] = pos - WIDTH + 2;
            if ( eatable(pos + WIDTH + 2, turn) || chess_table[pos + WIDTH + 2] == EMPTY )
                available[j++] = pos + WIDTH + 2;
            break;
        // ||<
        case 23:
        case 31:
        case 39:
        case 47:
            if ( eatable(pos - 2*WIDTH - 1, turn) || chess_table[pos - 2*WIDTH - 1] == EMPTY )
                available[j++] = pos - 2*WIDTH - 1;
            if ( eatable(pos + 2*WIDTH - 1, turn) || chess_table[pos + 2*WIDTH - 1] == EMPTY )
                available[j++] = pos + 2*WIDTH - 1;
            if ( eatable(pos - WIDTH + 2, turn) || chess_table[pos - WIDTH + 2] == EMPTY )
                available[j++] = pos - WIDTH + 2;
            if ( eatable(pos + WIDTH + 2, turn) || chess_table[pos + WIDTH + 2] == EMPTY )
                available[j++] = pos + WIDTH + 2;
            break;

        // Upper -
        case 2:
        case 3:
        case 4:
        case 5:
            break;

        // Upper =
        case 10:
        case 11:
        case 12:
        case 13:
            break;

        // lower =
        case 50:
        case 51:
        case 52:
        case 53:
            break;

        // lower -
        case 58:
        case 59:
        case 60:
        case 61:
            break;

        // middle square, 4x4
        default:
            break;
    //pos -+ 2*WIDTH -+ 1
    //pos -+   WIDTH -+ 2
    }

    print_available(available, 8);
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
