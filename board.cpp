#include "board.h"
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

void Board::printOut(){
    std::cout << "teste";
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
	
	int height = wins.ws_row;
	int width = wins.ws_col;

    Cell **mat = new Cell*[height];

    for(int i = 0; i < width; i++)
		mat[i] = new Cell[width];

    for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			mat[i][j] = Cell(i, j);
		}
	}

}