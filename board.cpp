#include "board.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

bool Board::validCell(int row, int col) {
    return (row >= 0) && (row < height) &&
    (col >= 0) && (col < width);
}
int Board::adjCells(int row, int col) {
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
void Board::envolve() {
    bool aux[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            aux[i][j] = mat[i][j].getState();
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int n = adjCells(i, j);

            if(mat[i][j].getState() == 1){
                if(n < 2){
                    aux[i][j] = 0;
                } else if(n > 3){
                    aux[i][j] = 0;
                }
            } else{
                if(n == 3 && mat[i][j].getState() == 0)
                    aux[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            mat[i][j].setState(aux[i][j]);
        }
    }
}

void Board::printOut() {
    std::cout << std::flush;
    for(int i =  0; i < height; i++){
        for(int j = 0; j < width; j++){
            //std::cout << adjCells(i, j);
            //std::cout << mat[i][j].getState();
            printf(mat[i][j].getState() ? "\033[07m  \033[m" : "  ");
		    //printf("\033[E");
        }
        std::cout << std::endl;
    }
}

Board::Board(){
    struct winsize wins;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &wins);
	
	height = wins.ws_row/2;
	width = wins.ws_col/2;

    mat = new Cell*[height];

    for(int i = 0; i < width; i++)
		mat[i] = new Cell[width];

    for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			mat[i][j] = Cell(i, j);
		}
	}

}