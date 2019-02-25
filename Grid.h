#include <iostream>

using namespace std;

class Grid
{
    public:
        Grid();
        Grid(const Grid &g2);
        Grid(int x, int y, double density);
        Grid(string file);
        ~Grid();

        bool check(int x, int y);
        bool isEmpty();
        void kill(int x, int y);
        void grow(int x, int y);
        int getSize();
        int getNumRows();
        int getNumCol();
        string print(Grid x);

        char *myGrid;

    private:
        int size; //number of cells in grid
        int row; //row length (number of columns)
        int column; //column length (number of rows)
        int num_living; //number of X's in the grid

};
