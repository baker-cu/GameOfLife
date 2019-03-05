#include "Grid.h"

#ifndef _GRID_C
#define _GRID_C

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

//compile with g++ -I /home/cpsc350/GameOfLife Grid.cpp

using namespace std;

Grid::Grid() //do i need a default constructor????
{
    char myGrid[10][10] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};
    row = 10;
    column = 10;
    size = 100;
}

Grid::Grid(const Grid& g2)//copy constructor/////////////help
{
    size = g2.size;
    row = g2.row;
    column = g2.column;
    num_living = g2.num_living;

    char** myGrid = new char*[row];
    for(int i = 0; i < row; i++)
        myGrid[i] = new char[column];

    for(int i1 = 0; i1 < row; i1++)
    {
        for(int i2 = 0; i2 < column; i2++)
        {
            //copy(&g2[i1][i2], &g2[i1][i2]+row*column,&myGrid[i1][i2]);
            myGrid[i1][i2] = g2.get(i1,i2);
        }
    }
}

Grid::Grid(int x, int y, double density)
{

    char** myGrid = new char*[x];
    for(int i = 0; i < x; i++)
        myGrid[i] = new char[y];

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
    int randnum;
    //randomly generates indicies in the string str and puts them into the array
    for(int i1 = 0; i1 < column; i1++)
    {
        for(int i2 = 0; i2 < row; i2++)
        {
            //generate random numbers from index 0 to length of string - 1
            if(str.length()>1)
            {
                randnum = (rand()%(str.length()-1))+1;
            }
            else
            {
                randnum = 0;
            }
            myGrid[i1][i2] = str[randnum];
            str.erase(randnum);
        }
    }
}

Grid::Grid(string file)
{
    num_living = 0;
    //code to create a 2d array from a filepath
    ifstream openfile(file);

    //error handling
    if(! openfile)
    {
        cout << "Error, file could not be opened" << endl;
        exit(0);
    }

    openfile >> column;//gets number of rows
    openfile >> row;//gets number of columns
    size = row*column;

    char** myGrid = new char*[row];
    for(int i = 0; i < row; i++)
        myGrid[i] = new char[column];

    for(int x = 0; x<column; x++)
    {
        for(int y = 0; y<row; y++)
        {
            openfile >> myGrid[x][y];

            if(! openfile)//error handling
            {
                cout << "Error reading file at " << row << "," << column << endl;
            }

            if(myGrid[x][y] == 'X')
            {
                num_living++;
            }
        }
    }

    openfile.close();
}

Grid::~Grid()
{
    if(myGrid)
    {
        for(int i = 0; i < row; i++)
        {
            delete []myGrid[i];
        }
        delete []myGrid;
    }
}

void Grid::kill(int x, int y)
{
    if(myGrid[x][y] == 'X')
    {
        num_living--;
    }
    myGrid[x][y] = '-';
}

void Grid::grow(int x, int y)
{
    if(myGrid[x][y] == '-')
    {
        num_living++;
    }
    myGrid[x][y] = 'X';
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

bool Grid::equals(const Grid& g2)
{
    if(size != g2.size) //checks if sizes are equal
    {
        return false;
    }
    if(row != g2.row)//checks if numRows are equal
    {
        return false;
    }
    if(column != g2.column)//checks if numCol are equal
    {
        return false;
    }
    if(num_living != g2.num_living)//checks if numliving are equal
    {
        return false;
    }
    for(int x = 0; x < row; x++)//checks each element
    {
        for(int y = 0; y < column; y++)
        {
            if(myGrid[x][y] != g2.get(x,y))
            {
                return false;
            }
        }
    }
    return true;
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

int Grid::getNumLiving()
{
    return(num_living);
}

void Grid::printg(int r, int c)
{
    for(int x = 0; x < r; x++)
    {
        for(int y = 0; y < c; y++)
        {
            cout << myGrid[x][y];
        }
    cout << endl;
    }
}

char Grid::get(int x, int y) const
{
    return myGrid[x][y];
}

#endif
