#include "cell.h"

class Board {
    private:
        int height;
        int width;
        Cell **mat;

    public:
        Board();
        void printOut();

};