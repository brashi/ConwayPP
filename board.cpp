#include "board.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

bool Board::validCell(int row, int col){
    return (row >= 0) && (row < height) &&
    (col >= 0) && (col < width);
}
int Board::adjCells(int row, int col){
    int count = 0;
    if(validCell(row-1, col-1) && mat[row-1][col-1].getState()) count++; //Canto superior esquerdo
  	if(validCell(row-1, col) && mat[row-1][col].getState()) count++; //Encima
  	if(validCell(row-1, col+1) && mat[row-1][col+1].getState()) count++; //Canto superior direito
  	if(validCell(row, col-1) && mat[row][col-1].getState()) count++; //Esquerda
  	if(validCell(row, col+1) && mat[row][col+1].getState()) count++; //Direita
  	if(validCell(row+1, col-1) && mat[row+1][col-1].getState()) count++; //Canto inferior esquerdo
  	if(validCell(row+1, col) && mat[row+1][col].getState()) count++; //Abaixo
  	if(validCell(row+1, col+1) && mat[row+1][col+1].getState()) count++; //Canto inferior direito

    return count;
}
void Board::envolve(){
    bool aux[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            aux[i][j] = mat[i][j].getState;
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int n = adjCells(i, j);
        }
    }
}

void Board::printOut(){
    for(int i =  0; i < height; i++){
        for(int j = 0; j < width; j++){
            //std::cout << adjCells(i, j);
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