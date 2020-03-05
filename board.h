#include "cell.h"

class Board {
    private:
        int height;
        int width;
        Cell **mat;

    public:
        Board();
        bool validCell(int row, int col);
        int adjCells(int row, int col);
        void envolve();
        void printOut();

};