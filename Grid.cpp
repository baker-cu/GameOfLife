#include <home/cpsc350/GameOfLife/Grid.h>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

Grid::Grid()
{
    myGrid = new char[10][10];
    row = 10;
    column = 10;
    size = 100;
}

Grid::Grid(const Grid &g2)//copy constructor
{
    size = g2.size;
    row = g2.row;
    column = g2.column;
    num_living = g2.num_living;

    for(int i1 = 0; i1 < column; i1++)
    {
        for(int i2 = 0; i2 < row; i2++)
        {
            myGrid[i1][i2] = g2[i1][i2];
        }
    }
}

Grid::Grid(int x, int y, double density)
{
    //make sure when you square root the size you get an interger
    myGrid = new char[x][y];
    row = x;
    column = y;
    size = x*y;
    num_living = size * density;
    string str = ""

    for(int a = 0; a < num_living; a++)//adds the density of X's to a string
    {
        str += "X";
    }

    for(int a = 0; a < size - num_living; a++)//adds the rest to the string
    {
        str += "-";
    }

    for(int i1 = 0; i1 < column; i1++)
    {
        for(int i2 = 0; i2 < row; i2++)
        {
            //generate random numbers from index 0 to length of string - 1
            int rand = (rand()%str.length()-1)+1;
            myGrid[i1][i2] = str[rand];
            str.erase(rand);
        }
    }

}

Grid::Grid(string file)
{
    //code to create a grid from a filepath
    ifstream openfile(file);

    getline(openfile, col);
    int column = col;
    getline(openfile, r);
    int row = r;

    size = row*column;

    myGrid = new char[row][column];

    x = 0;
    while(getline(openfile, init_line))
    {
        for(int y = 0; y < row; y++)
        {
            myGrid[x][y] = init_line[x];
            if(init_line == "X")
            {
                num_living += 1;
            }
        }
        x++;
    }
    openfile.close();
}

Grid::kill(int x, int y)
{
    myGrid[x][y] = '-';
    num_living--;
}

Grid::grow(int x, int y)
{
    myGrid[x][y] = 'X';
    num_living++;
}

Grid::check(int x, int y)
{
    return (myGrid[x][y] == 'X');
}

Grid::isEmpty()
{
    return (num_living == 0);
}

Grid::getSize()
{
    return(size);
}

Grid::getNumRows()
{
    return(column);
}

Grid::getNumCol()
{
    return(row);
}

Grid::print(Grid g)
{
    for(int x = 0; x < column; x++)
    {
        for(int y = 0; y < row; y++)
        {
            cout << g[x][y];
        }
    cout << endl;
    }
}
