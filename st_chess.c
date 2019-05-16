#include <stdio.h>
#include <stdlib.h>

#define BLACK -1
#define WHITE  1
#define WIDTH  8

enum Piece { DEAD = -1, EMPTY = 0, PAWN = 10, ROOK = 50, KNIGHT = 30, BISHOP = 40, QUEEN = 200, KING = 1000 };

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
void print_board(SQUARE board[][WIDTH]);
void draw_board(SQUARE board[][WIDTH]);
void draw_square(POINT out, int color);
void draw_piece(POINT in, POINT out);

/*-----------------------------------MAIN--------------------------------------*/

int main() {

    PIECE black[WIDTH<<1] = {};
    PIECE white[WIDTH<<1] = {};
    SQUARE board[WIDTH][WIDTH] = {};

    setup_players(black, white);
    setup_board(board, black, white);
    //print_board(board);
    draw_board(board);

    return 0;
}

/*-----------------------------------MAIN--------------------------------------*/

void setup_board(SQUARE board[][WIDTH], PIECE black[], PIECE white[]) {
    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            board[y][x].point.x = x;
            board[y][x].point.y = y;
            board[y][x].piece = NULL;

            if (y == 0)
                board[y][x].piece = (PIECE*)(black + x);
            if (y == 1)
                board[y][x].piece = (PIECE*)(black + WIDTH + x);
            if (y == 6)
                board[y][x].piece = (PIECE*)(white + WIDTH + x);
            if (y == 7)
                board[y][x].piece = (PIECE*)(white + x);

            if (((x+y) % 2) == 0)
                board[y][x].color = WHITE;
            else
                board[y][x].color = BLACK;
        }
    }
}

void setup_players(PIECE black[], PIECE white[]) {

    // PAWNS Black & White

    for (int i = 0; i < WIDTH; i++) {
        black[WIDTH+i].point.x = i;
        black[WIDTH+i].point.y = 1;
        black[WIDTH+i].piece = PAWN;
        black[WIDTH+i].color = BLACK;

        white[WIDTH+i].point.x = i;
        white[WIDTH+i].point.y = 6;
        white[WIDTH+i].piece = PAWN;
        white[WIDTH+i].color = WHITE;
    }

    // ROOKS's Black & White

    black[0].point.x = 0;
    black[0].point.y = 0;
    black[0].piece = ROOK;
    black[0].color = BLACK;

    white[0].point.x = 0;
    white[0].point.y = 7;
    white[0].piece = ROOK;
    white[0].color = WHITE;

    black[7].point.x = 7;
    black[7].point.y = 0;
    black[7].piece = ROOK;
    black[7].color = BLACK;

    white[7].point.x = 7;
    white[7].point.y = 7;
    white[7].piece = ROOK;
    white[7].color = WHITE;

    // KNIGHT's Black & White

    black[1].point.x = 1;
    black[1].point.y = 0;
    black[1].piece = KNIGHT;
    black[1].color = BLACK;

    white[1].point.x = 1;
    white[1].point.y = 7;
    white[1].piece = KNIGHT;
    white[1].color = WHITE;

    black[6].point.x = 6;
    black[6].point.y = 0;
    black[6].piece = KNIGHT;
    black[6].color = BLACK;

    white[6].point.x = 6;
    white[6].point.y = 7;
    white[6].piece = KNIGHT;
    white[6].color = WHITE;

    // BISHOP's Black & White

    black[2].point.x = 2;
    black[2].point.y = 0;
    black[2].piece = BISHOP;
    black[2].color = BLACK;

    white[2].point.x = 2;
    white[2].point.y = 7;
    white[2].piece = BISHOP;
    white[2].color = WHITE;

    black[5].point.x = 5;
    black[5].point.y = 0;
    black[5].piece = BISHOP;
    black[5].color = BLACK;

    white[5].point.x = 5;
    white[5].point.y = 7;
    white[5].piece = BISHOP;
    white[5].color = WHITE;

    // QUEEN's Black & White

    black[4].point.x = 4;
    black[4].point.y = 0;
    black[4].piece = QUEEN;
    black[4].color = BLACK;

    white[4].point.x = 4;
    white[4].point.y = 7;
    white[4].piece = QUEEN;
    white[4].color = WHITE;

    // KING's Black & White

    black[3].point.x = 3;
    black[3].point.y = 0;
    black[3].piece = KING;
    black[3].color = BLACK;

    white[3].point.x = 3;
    white[3].point.y = 7;
    white[3].piece = KING;
    white[3].color = WHITE;
}

void print_board(SQUARE board[][WIDTH]) {

    for (int y = 0; y < WIDTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("[%d", board[y][x].color);
            if ( board[y][x].piece != NULL)
                printf(" %d %d", board[y][x].piece->color, board[y][x].piece->piece);
            printf("] ");

            if (x == 7)
                printf("\n");
        }
    }
}

void draw_board(SQUARE board[][WIDTH]) {

    POINT in, out;

    out.x = out.y = 0;

    for (int y = 0; y < WIDTH; y++, out.y++) {
        for (int x = 0; x < WIDTH; x++, out.x++) {
            if (board[y][x].piece != NULL)  {

                switch (board[y][x].piece->piece) {
                    case PAWN:

                        in.x = 0;

                        if      ( board[y][x].color == WHITE && board[y][x].piece->color == WHITE ) {
                            in.y = 0;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == WHITE && board[y][x].piece->color == BLACK ) {
                            in.y = 30;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == BLACK && board[y][x].piece->color == WHITE ) {
                            in.y = 60;
                            draw_piece(in, out);
                        }
                        else {
                            in.y = 90;
                            draw_piece(in, out);
                        }
                        break;
                    case ROOK:

                        in.x = 30;

                        if      ( board[y][x].color == WHITE && board[y][x].piece->color == WHITE ) {
                            in.y = 0;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == WHITE && board[y][x].piece->color == BLACK ) {
                            in.y = 30;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == BLACK && board[y][x].piece->color == BLACK ) {
                            in.y = 60;
                            draw_piece(in, out);
                        }
                        else {
                            in.y = 90;
                            draw_piece(in, out);
                        }
                        break;
                    case KNIGHT:

                        in.x = 60;

                        if      ( board[y][x].color == WHITE && board[y][x].piece->color == WHITE ) {
                            in.y = 0;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == WHITE && board[y][x].piece->color == BLACK ) {
                            in.y = 30;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == BLACK && board[y][x].piece->color == BLACK ) {
                            in.y = 60;
                            draw_piece(in, out);
                        }
                        else {
                            in.y = 90;
                            draw_piece(in, out);
                        }
                        break;
                    case BISHOP:

                        in.x = 90;

                        if ( board[y][x].color == WHITE && board[y][x].piece->color == WHITE ) {
                            in.y = 0;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == WHITE && board[y][x].piece->color == BLACK ) {
                            in.y = 30;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == BLACK && board[y][x].piece->color == BLACK ) {
                            in.y = 60;
                            draw_piece(in, out);
                        }
                        else {
                            in.y = 90;
                            draw_piece(in, out);
                        }
                        break;
                    case QUEEN:

                        in.x = 120;

                        if ( board[y][x].color == WHITE && board[y][x].piece->color == WHITE ) {
                            in.y = 0;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == WHITE && board[y][x].piece->color == BLACK ) {
                            in.y = 30;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == BLACK && board[y][x].piece->color == BLACK ) {
                            in.y = 60;
                            draw_piece(in, out);
                        }
                        else {
                            in.y = 90;
                            draw_piece(in, out);
                        }
                        break;
                    case KING:

                        in.x = 150;

                        if ( board[y][x].color == WHITE && board[y][x].piece->color == WHITE ) {
                            in.y = 0;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == WHITE && board[y][x].piece->color == BLACK ) {
                            in.y = 30;
                            draw_piece(in, out);
                        }
                        else if ( board[y][x].color == BLACK && board[y][x].piece->color == BLACK ) {
                            in.y = 60;
                            draw_piece(in, out);
                        }
                        else {
                            in.y = 90;
                            draw_piece(in, out);
                        }
                        break;
                    default:
                        break;
                }
            } else {
                if (board[y][x].color == WHITE)
                    draw_square(out, WHITE);
                else
                    draw_square(out, BLACK);
            }
        }
    }
}

void draw_piece(POINT in, POINT out) {
    int RGB, R, G, B;
    size_t size = 30;
    int iy, ix, ii, ox, oy, oi;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			ox = ( 40 + out.x * size ) + x; // konverzija mozda sam zajebao
			oy = ( out.y * 30 ) + y;
			oi = oy * 320 + ox;

			ix = in.x + x;
			iy = in.y + y;
			ii = iy * bitmap.width + ix;

            // RGB 5 6 5
			R = ( bitmap.pixel_data[ii * bitmap.bytes_per_pixel]         ) >> 13;
			G = ( bitmap.pixel_data[ii * bitmap.bytes_per_pixel] & 0x700 ) >> 8;
			B = ( bitmap.pixel_data[ii * bitmap.bytes_per_pixel] & 0x1C  ) >> 2;

			R <<= 6;
			G <<= 3;
			RGB = R | G | B;

			VGA_PERIPH_MEM_mWriteMemory(
					XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + GRAPHICS_MEM_OFF
							+ oi * 4, RGB);
        }
    }
}

void draw_square(POINT out, int color) {
    int RGB; // beton verzija "crna" ili "bela"
    size_t size = 30;

    RGB = (color == BLACK ? 0xA3 : 0x1F5);

    int ox, oy, oi;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			ox = ( 40 + out.x * size ) + x;
			oy = ( out.y * size ) + y;
			oi = oy * 320 + ox;

			VGA_PERIPH_MEM_mWriteMemory(
					XPAR_VGA_PERIPH_MEM_0_S_AXI_MEM0_BASEADDR + GRAPHICS_MEM_OFF
							+ oi * 4, RGB);
        }
    }
}
