#ifndef _GRID_H
#define _GRID_H

#include <iostream>

using namespace std;

class Grid
{
    public:
        Grid();
        Grid(Grid* g2);
        Grid(int x, int y, double density);
        Grid(string file);
        ~Grid();

        bool check(int x, int y); //check  if a cell is inhabited or not
        bool isEmpty();//check if a grid is living
        bool equals(Grid* g2);//checks if two grids are equal
        void kill(int x, int y);//kill a cell
        void grow(int x, int y);//grow a cell
        int getSize();
        int getNumRows();
        int getNumCol();
        int getNumLiving();
        void printg();
        char get(int x, int y) const;
        void toFile(string fname, int gen);

    private:
        int size; //number of cells in grid
        int row; //row length (number of columns)
        int column; //column length (number of rows)
        int num_living; //number of X's in the grid

        char** myGrid;

};

#endif
