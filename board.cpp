#include "board.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

bool Board::validCell(int row, int col){
    return (row >= 0) && (row < height) &&
    (col >= 0) && (col < width);
}
int Board::adjCells(int row, int col){

}
void Board::envolve(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if
        }
    }
}

void Board::printOut(){
    for(int i =  0; i < height; i++){
        for(int j = 0; j < width; j++){
            std::cout << mat[i][j].getState();
        }
        std::cout << std::endl;
    }
}

Board::Board(){
    struct winsize wins;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &wins);
	
	height = wins.ws_row;
	width = wins.ws_col;

    mat = new Cell*[height];

    for(int i = 0; i < width; i++)
		mat[i] = new Cell[width];

    for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			mat[i][j] = Cell(i, j);
		}
	}

}