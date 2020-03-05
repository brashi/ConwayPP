#include <iostream>
#include "board.h"
#include <sys/ioctl.h>
#include <unistd.h>

/*void printOut(Cell **board, int t_height, int t_width){
	for(int i = 0; i < t_height; i++){
		for(int j = 0; j < t_width; j++){
			std::cout << board[i][j].getState();
		}
		std::cout << std::endl;
	}
}*/

int main(){
	/*struct winsize wins;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &wins);
	
	int t_height = wins.ws_row;
	int t_width = wins.ws_col;

	Cell **board = new Cell*[t_height];

	for(int i = 0; i < t_width; i++)
		board[i] = new Cell[t_width];

	for(int i = 0; i < t_height; i++){
		for(int j = 0; j < t_width; j++){
			board[i][j] = Cell(i, j);
		}
	}
	printOut(board, t_height, t_width);*/

	Board board;
	board = Board();
	board.printOut();
	return 0;
}
