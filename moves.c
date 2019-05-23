/* Template za izradu funkcija */

/*
    int eatable(POINT pos);
    -1 - naisao je na figuru svoje boje (ne sme da jede)
     1 - naisao je na figuru druge boje (sme da jede)
     0 - prazno polje
*/

void swap(POINT from, POINT to) {

    // ako je neko bio na toj poziciji vise nije
    if (board[to.y][to.x].piece != NULL) {
        board[to.y][to.x].piece->piece = DEAD; // got killed brah

        // TO DO: if kralj game over
    }

    // pokazivac sa novog polja pokazuje na figuru
    board[to.y][to.x].piece = board[from.y][from.x].piece;
    // update X i Y za figuru na vrednosti novog polja
    board[to.y][to.x].piece->point.x = to.x;
    board[to.y][to.x].piece->point.y = to.y;

    // brisemo pokazivac sa starog polja
    board[from.y][from.x].piece = NULL;
}

void for_whom_the_bell_tolls(PIECE piece) {
    // reset_playable(); ???

    switch (piece.piece) {
        case PAWN:
            move_pawn(piece);
            break;
        case ROOK:
            move_rook(piece);
            break;
        case KNIGHT:
            move_knight(piece);
            break;
        case BISHOP:
            move_bishop(bishop);
            break;
        case QUEEN:
            move_queen(piece);
            break;
        case KING:
            move_king(piece);
            break;
    }

    // mark_playable(); ???
}


void move_king(PIECE king) {
    int k = 0;
    POINT pos;

    reset_playable();

    // GORE DOLE
    pos.x = king.point.x;

    if (king.point.y != 0) {
        pos.y = king.point.y + 1;

        if ( eatable(pos) != -1 ) {
            playable[k].x = pos.x;
            playable[k].y = pos.y;
            k++;
        }
    }

    if (king.point.y != WIDTH-1) {
        pos.y = king.point.y - 1;

        if ( eatable(pos) != -1 ) {
            playable[k].x = pos.x;
            playable[k].y = pos.y;
            k++;
        }
    }

    // LEVO DESNO
    pos.y = king.point.y;

    if (king.point.x != 0) {
        pos.x = king.point.x - 1;

        if ( eatable(pos) != -1 ) {
            playable[k].x = pos.x;
            playable[k].y = pos.y;
            k++;
        }
    }

    if (king.point.x != WIDTH-1) {
        pos.x = king.point.x + 1;

        if ( eatable(pos) != -1 ) {
            playable[k].x = pos.x;
            playable[k].y = pos.y;
            k++;
        }
    }

    // GORE LEVO
    if (king.point.y != 0 && king.point.x != 0) {
        pos.x = king.point.x - 1;
        pos.y = king.point.y - 1;

        if ( eatable(pos) != 1 ) {
            playable[k].x = pos.x;
            playable[k].y = pos.y;
            k++;
        }
    }

    // GORE DESNO
    if (king.point.y != 0 && king.point.x != WIDTH-1) {
        pos.x = king.point.x + 1;
        pos.y = king.point.y - 1;

        if ( eatable(pos) != 1 ) {
            playable[k].x = pos.x;
            playable[k].y = pos.y;
            k++;
        }
    }

    // DOLE LEVO
    if (king.point.y != WIDTH-1 && king.point.x != 0) {
        pos.x = king.point.x - 1;
        pos.y = king.point.y + 1;

        if ( eatable(pos) != 1 ) {
            playable[k].x = pos.x;
            playable[k].y = pos.y;
            k++;
        }
    }

    // DOLE DESNO
    if (king.point.y != WIDTH-1 && king.point.x != WIDTH-1) {
        pos.x = king.point.x + 1;
        pos.y = king.point.y + 1;

        if ( eatable(pos) != 1 ) {
            playable[k].x = pos.x;
            playable[k].y = pos.y;
            k++;
        }
    }

    mark_playable();
}


void move_queen(PIECE queen) {

    // obavezan deo inicirati sa promenljivima koje ce se koristiti
    int x, i, j, k = 0;
    POINT pos;

    // obavezan deo resetovati playable niz
    reset_playable();

    // provera za gore
    pos.x = queen.point.x; // X se ne menja za UP & DOWN
    for (i = (queen.point.y - 1); i >= 0; i--) {
        pos.y = i;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za dole
    for (i = (queen.point.y + 1); i < WIDTH; i++) {
        pos.y = i;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za levo
    pos.y = queen.point.y; // Y se ne menja za LEFT & RIGHT
    for (i = (queen.point.x - 1); i >= 0; i--) {
        pos.x = i;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za desno
    for (i = (queen.point.x + 1); i < WIDTH; i++) {
        pos.x = i;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za gore levo
    for (i = (queen.point.x - 1), j = (queen.point.y - 1); i >= 0 && j >= 0; i--, j--) {
        pos.x = i;
        pos.y = j;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za gore desno
    for (i = (queen.point.x + 1), j = (queen.point.y - 1); i < WIDTH && j >= 0; i++, j--) {
        pos.x = i;
        pos.y = j;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za dole levo
    for (i = (queen.point.x - 1), j = (queen.point.y + 1); i >= 0 && j < WIDTH; i--, j++) {
        pos.x = i;
        pos.y = j;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za dole desno
    for (i = (queen.point.x + 1), j = (queen.point.y + 1); i < WIDTH && j < WIDTH; i++, j++) {
        pos.x = i;
        pos.y = j;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // obavezan deo na kraju ispisati playable
    mark_playable();
}

void move_bishop(PIECE bishop) {
    int x, i, j, k = 0;
    POINT pos;

    reset_playable();

    // provera za gore levo
    for (i = (bishop.point.x - 1), j = (bishop.point.y - 1); i >= 0 && j >= 0; i--, j--) {
        pos.x = i;
        pos.y = j;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za gore desno
    for (i = (bishop.point.x + 1), j = (bishop.point.y - 1); i < WIDTH && j >= 0; i++, j--) {
        pos.x = i;
        pos.y = j;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za dole levo
    for (i = (bishop.point.x - 1), j = (bishop.point.y + 1); i >= 0 && j < WIDTH; i--, j++) {
        pos.x = i;
        pos.y = j;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za dole desno
    for (i = (bishop.point.x + 1), j = (bishop.point.y + 1); i < WIDTH && j < WIDTH; i++, j++) {
        pos.x = i;
        pos.y = j;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // obavezan deo na kraju ispisati playable
    mark_playable();
}


void move_rook(PIECE rook) {
    int x, i, k = 0;
    POINT pos;

    reset_playable();

    // provera za gore
    pos.x = rook.point.x; // X se ne menja za UP & DOWN
    for (i = (rook.point.y - 1); i >= 0; i--) {
        pos.y = i;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za dole
    for (i = (rook.point.y + 1); i < WIDTH; i++) {
        pos.y = i;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za levo
    pos.y = rook.point.y; // Y se ne menja za LEFT & RIGHT
    for (i = (rook.point.x - 1); i >= 0; i--) {
        pos.x = i;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // provera za desno
    for (i = (rook.point.x + 1); i < WIDTH; i++) {
        pos.x = i;

        x = eatable(pos);

        if ( x == -1 ) // naisla je na figuru svoje boje pa ne sme da jede
            break;

        // dodavanje u playable i povecavanje brojaca
        playable[k].x = pos.x;
        playable[k].y = pos.y;
        k++;

        if ( x == 1 ) // sme da jede ali ne sme dalje
            break;
    }

    // obavezan deo na kraju ispisati playable
    mark_playable();
}


void move_pawn(PIECE pawn) {
    int k = 0;
    POINT pos;

    reset_playable();

    if (player_turn == WHITE) {

        // vrth table ?
        if (pawn.point.y != 0) {
            pos.y = pawn.point.y - 1;

            // ako nisi u levom cosku smes da jedes.
            if ( pawn.point.x != 0 ) {
                pos.x = pawn.point.x - 1;
                if ( eatable(pos) == 1 ) {
                    playable[k].x = pos.x;
                    playable[k].y = pos.y;
                    k++;
                }
            }

            // ako nisi u desnom cosku smes da jedes.
            if ( pawn.point.x != 7 ) {
                pos.x = pawn.point.x + 1;
                if ( eatable(pos) == 1) {
                    playable[k].x = pos.x;
                    playable[k].y = pos.y;
                    k++;
                }
            }

            // prazno polje iznad
            pos.x = pawn.point.x;
            if ( eatable(pos) == 0 ) {
                playable[k].x = pos.x;
                playable[k].y = pos.y;
                k++;

                pos.y--;
                // 2 prazno polje ?
                if (pawn.point.y == 6) {
                    if ( eatable(pos) == 0 ) {
                        playable[k].x = pos.x
                        playable[k].y = pos.y;
                        k++;
                    }
                }
            }
        }
    } else {
        // dno table ?
        if (pawn.point.y != 7) {
            pos.y = pawn.point.y + 1;

            // ako nisi u levom cosku smes da jedes.
            if ( pawn.point.x != 0 ) {
                pos.x = pawn.point.x - 1;
                if ( eatable(pos) == 1 ) {
                    playable[k].x = pos.x;
                    playable[k].y = pos.y;
                    k++;
                }
            }

            // ako nisi u desnom cosku smes da jedes.
            if ( pawn.point.x != 7 ) {
                pos.x = pawn.point.x + 1;
                if ( eatable(pos) == 1) {
                    playable[k].x = pos.x;
                    playable[k].y = pos.y;
                    k++;
                }
            }

            // prazno polje ispod
            pos.x = pawn.point.x;
            if ( eatable(pos) == 0 ) {
                playable[k].x = pos.x;
                playable[k].y = pos.y;
                k++;

                pos.y++;
                // 2 prazno polje ?
                if (pawn.point.y == 6) {
                    if ( eatable(pos) == 0 ) {
                        playable[k].x = pos.x
                        playable[k].y = pos.y;
                        k++;
                    }
                }
            }
        }
    }

    mark_playable();
}
void move_knight(PIECE knight){
	int k = 0;
    POINT pos;
	
	//POLJA PO COSKOVIMA
	if (knight.point.y == 0 && knight.point.x == 0){
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x + 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 2;
			pos.x = knight.point.x + 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.y == 0 && knight.point.x == 7){
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x - 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 2;
			pos.x = knight.point.x - 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}

	if (knight.point.y == 7 && knight.point.x == 0){
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x + 1;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x + 2;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.y == 7 && knight.point.x == 7){
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x - 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x - 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	
	
	
	//POLJA DO COSKOVA
	if (knight.point.y == 0 && knight.point.x == 1){
			pos.y = knight.point.y + 2;
			pos.x = knight.point.x - 1;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 2;
			pos.x = knight.point.x + 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x + 2;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.y == 1 && knight.point.x == 0){
			pos.y = knight.point.y + 2;
			pos.x = knight.point.x + 1;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x + 2;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x + 2;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.y == 0 && knight.point.x == 6){
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x - 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 2;
			pos.x = knight.point.x + 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x - 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.y == 1 && knight.point.x == 7){
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x - 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x - 2;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 2;
			pos.x = knight.point.x - 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.y == 6 && knight.point.x == 0){
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x + 1;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x + 2;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x + 2;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.y == 7 && knight.point.x == 1){
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x + 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x + 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x - 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.y == 7 && knight.point.x == 6){
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x - 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x + 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x - 1;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.y == 6 && knight.point.x == 7){
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x - 1;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x - 2;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
			
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x - 2;
			if(eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
			}
	}
	
	if (knight.point.x == 0 && knight.point.y > 1 && knight.point.y < 6){
		
			
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x + 1;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
				}
				
			pos.y = knight.point.y + 2;
			pos.x = knight.point.x + 1;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
				}
				
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x + 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
				}
				
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x + 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
				}
	
	}
	
	
	if (knight.point.x == 7 && knight.point.y > 1 && knight.point.y < 6){
		
			
			pos.y = knight.point.y - 2;
			pos.x = knight.point.x - 1;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
				}
				
			pos.y = knight.point.y + 2;
			pos.x = knight.point.x - 1;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
				}
				
			pos.y = knight.point.y - 1;
			pos.x = knight.point.x - 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
				}
				
			pos.y = knight.point.y + 1;
			pos.x = knight.point.x - 2;
			if (eatable(pos) != -1) {
				playable[k].x = pos.x;
				playable[k].y = pos.y;
				k++;
				}
	
	}

}	
	
