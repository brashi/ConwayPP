#include "cell.h"
#include <stdlib.h>

void Cell::setState(bool st) {
	state = st;
}

bool Cell::getState() {
	return state;
}

Cell::Cell(){
	state = 0;
	xCoord = 0;
	yCoord = 0;
}
Cell::Cell(int x, int y){
	state = rand() < RAND_MAX / 10 ? 1 : 0;
	xCoord = x;
	yCoord = y;
}
