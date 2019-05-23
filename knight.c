void move_knight(PIECE knight){
	int k = 0;
    POINT pos;
	
	// gore 2 levo 1
	pos.y = knight.point.y - 2;
	if (knight.point.y > 1 && knight.point.x > 0) {
		pos.x = knight.point.x - 1;
		if ( eatable(pos) != -1 ) {
			playable[k].x = pos.x;
			playable[k].y = pos.y;
			k++;
		}
	}

	// gore 2 desno 1
	if (knight.point.y > 1 && knight.point.x < 7) {
		pos.x = knight.point.x + 1;
		if ( eatable(pos) != -1 ) {
			playable[k].x = pos.x;
			playable[k].y = pos.y;
			k++;
		}
	}

	// gore 1 levo 2
	pos.y = knight.point.y - 1;
	if (knight.point.y > 0 && knight.point.x > 1) {
		pos.x = knight.point.x - 2;
		if ( eatable(pos) != -1 ) {
			playable[k].x = pos.x;
			playable[k].y = pos.y;
			k++;
		}
	}

	// gore 1 desno 2
	if (knight.point.y > 0 && knight.point.x < 6) {
		pos.x = knight.point.x + 2;
		if ( eatable(pos) != -1 ) {
			playable[k].x = pos.x;
			playable[k].y = pos.y;
			k++;
		}
	}

	// dole 1 levo 2
	pos.y = knight.point.y + 1;
	if (knight.point.y < 7 && knight.point.x > 1) {
		pos.x = knight.point.x - 2;
		if ( eatable(pos) != -1 ) {
			playable[k].x = pos.x;
			playable[k].y = pos.y;
			k++;
		}
	}

	// dole 1 desno 2
	if (knight.point.y < 7 && knight.point.x < 6) {
		pos.x = knight.point.x + 2;
		if ( eatable(pos) != -1 ) {
			playable[k].x = pos.x;
			playable[k].y = pos.y;
			k++;
		}
	}

	// dole 2 levo 1
	pos.y = knight.point.y + 2;
	if (knight.point.y < 6 && knight.point.x > 0) {
		pos.x = knight.point.x - 1;
		if ( eatable(pos) != -1 ) {
			playable[k].x = pos.x;
			playable[k].y = pos.y;
			k++;
		}
	}

	// dole 2 desno 1
	if (knight.point.y < 6 && knight.point.x < 7) {
		pos.x = knight.point.x + 1;
		if ( eatable(pos) != -1 ) {
			playable[k].x = pos.x;
			playable[k].y = pos.y;
			k++;
		}
	}
}	
	
