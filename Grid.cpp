#include <iostream>
#include <Grid.h>
#include <cmath>
#include <fstream>
#include <cstdlib>

//compile with g++ -I /home/cpsc350/GameOfLife Grid.cpp

using namespace std;

Grid::Grid()
{
    char(*myGrid)[10];
    myGrid = new char[10][10];
    row = 10;
    column = 10;
    size = 100;
}

/*Grid::Grid(const Grid &g2)//copy constructor
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
}*/

Grid::Grid(int x, int y, double density)
{
    char* myGrid = new char[x*y];
    row = x;
    column = y;
    size = x*y;
    num_living = size * density;
    string str = "";

    for(int a = 0; a < num_living; a++)//adds the density of X's to a string
    {
        str += 'X';
    }

    for(int a = 0; a < size - num_living; a++)//adds the rest to the string
    {
        str += '-';
    }

    //randomly generates indicies in the string str and puts them into the array
    for(int i1 = 0; i1 < column; i1++)
    {
        for(int i2 = 0; i2 < row; i2++)
        {
            //generate random numbers from index 0 to length of string - 1
            int randnum = (rand()%(str.length()-1))+1;
            myGrid[i1][i2] = str[randnum];
            str.erase(randnum);
        }
    }

}

Grid::Grid(string file)
{
    string line = "";
    string col, r;
    //code to create a grid from a filepath
    ifstream openfile(file);

    getline(openfile, col);
    int column = stoi(col);
    getline(openfile, r);
    int row = stoi(r);

    size = row*column;

    char* myGrid = new char[row*column];

    int x = 0;
    while(getline(openfile, line))
    {
        for(int y = 0; y < row; y++)
        {
            myGrid[x][y] = line[x];
            if(line == "X")
            {
                num_living += 1;
            }
        }
        x++;
    }
    openfile.close();
}

void Grid::kill(int x, int y)
{
    myGrid[x][y] = '-';
    num_living--;
}

void Grid::grow(int x, int y)
{
    myGrid[x][y] = 'X';
    num_living++;
}

bool Grid::check(int x, int y)
{
    if(y<0 || x<0)
    {
        return(false);
    }
    return (myGrid[x][y] == 'X');
}

bool Grid::isEmpty()
{
    return (num_living == 0);
}

int Grid::getSize()
{
    return(size);
}

int Grid::getNumRows()
{
    return(column);
}

int Grid::getNumCol()
{
    return(row);
}

void Grid::printg(Grid x)
{
    for(int x = 0; x < column; x++)
    {
        for(int y = 0; y < row; y++)
        {
            cout << myGrid[x][y];
        }
    cout << endl;
    }
}
