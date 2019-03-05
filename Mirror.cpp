#include "Mirror.h"

#ifndef _MIRROR_C
#define _MIRROR_C

#include <iostream>
#include <fstream>

using namespace std;

Mirror::Mirror(int x)
{
    if(x==1)
    {
        string file;
        cout<<"Enter the filepath for original grid: "<<endl;
        cin>>file;

        current_grid = Grid(file);
    }
    if(x==2)
    {
        int r,c;
        double d;
        cout<<"Enter number of rows: "<<endl;
        cin>>r;
        cout<<"Enter number of columns: "<<endl;
        cin>>c;
        cout<<"Enter the population density: "<<endl;
        cin>>d;

        current_grid = Grid(r,c,d);
    }
}

Mirror::~Mirror()
{
    current_grid.~Grid();
    future_grid.~Grid();
}

void Mirror::run()
{
    int generation = 0;
    cout << "Generation: " << generation << endl;
    //printg(current_grid.getNumRows(),current_grid.getNumCol(), current_grid);
    while(true){
        //use copy constructor to get current_grid and future_grid
        Grid current_grid = Grid(future_grid);

        int neighbors = 0;

        //iterate through each element
        for(int x = 0; x < current_grid.getNumRows(); x++)
        {
            for(int y = 0; y < current_grid.getNumCol(); y++)
            {
                if(x>0 && y>0 && x < current_grid.getNumRows()-1 && y < current_grid.getNumCol()-1)//if the idex is not on the edges of the board
                {
                    if (current_grid.check(x-1,y-1))
                    {//up and to left
                        neighbors++;
                    }
                    if (current_grid.check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y+1))
                    {//up and to right
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y-1))
                    {//below and right
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y-1))
                    {//below and left
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y))
                    {//left
                        neighbors++;
                    }
                }
                if(x==0 && y!=current_grid.getNumCol()-1 && y!=0)//if index is on the top of the board
                {
                    if (current_grid.check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y-1))
                    {//below and right
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y-1))
                    {//below and left
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y))
                    {//left
                        neighbors++;
                    }
                    //Mirror
                    if(current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if(current_grid.check (x-1,y))//left again
                    {
                        neighbors++;
                    }
                    if(current_grid.check (x+1,y))//right again
                    {
                        neighbors++;
                    }
                }
                if(x==current_grid.getNumRows()-1 && y!=0 && y!=current_grid.getNumCol()-1)//index is on bottom of the board
                {
                    if (current_grid.check(x-1,y-1))
                    {//up and to left
                        neighbors++;
                    }
                    if (current_grid.check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y+1))
                    {//up and to right
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y))
                    {//left
                        neighbors++;
                    }
                    //Mirror
                    if (current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y))//right
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y))//left
                    {
                        neighbors++;
                    }
                }
                if(y==0 && x!=0 && x!=current_grid.getNumRows()-1)//on left edge of board
                {
                    if (current_grid.check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y+1))
                    {//up and to right
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y-1))
                    {//below and right
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    //Mirror
                    if (current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if (current_grid.check(x,y-1))//above
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))//below
                    {
                        neighbors++;
                    }
                }
                if(y==current_grid.getNumCol()-1 && y!=0 && x!=current_grid.getNumRows()-1)//on right edge of board
                {
                    if (current_grid.check(x-1,y-1))
                    {//up and to left
                        neighbors++;
                    }
                    if (current_grid.check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y-1))
                    {//below and left
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y))
                    {//left
                        neighbors++;
                    }
                    //Mirror
                    if (current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if (current_grid.check(x,y-1))//above
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))//below
                    {
                        neighbors++;
                    }
                }
                if(x==0 && y==0)//top left corner
                {
                    if (current_grid.check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y-1))
                    {//below and right
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    //Matrix
                    if (current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))//below
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y))//to the right
                    {
                        neighbors++;
                    }
                }
                if(x==0 && y==current_grid.getNumCol()-1)//top right corner
                {
                    if (current_grid.check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y-1))
                    {//below and left
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y))
                    {//left
                        neighbors++;
                    }
                    //Mirror
                    if (current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x,y))//itself
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))//below
                    {
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y))//left
                    {
                        neighbors++;
                    }
                }
                if(x==current_grid.getNumRows()-1 && y==0)//bottom left corner
                {
                    if (current_grid.check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y+1))
                    {//up and to right
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    //Mirror
                    if (current_grid.check (x,y))
                    {//itself
                        neighbors++;
                    }
                    if (current_grid.check(x,y))
                    {//itself
                        neighbors++;
                    }
                    if (current_grid.check(x,y))
                    {//itself
                        neighbors++;
                    }
                    if (current_grid.check(x,y-1))
                    {//right
                        neighbors++;
                    }
                    if (current_grid.check(x+1,y))
                    {//above
                        neighbors++;
                    }
                }
                if(x==current_grid.getNumRows()-1 && y==current_grid.getNumCol()-1)//bottom right corner
                {
                    if (current_grid.check(x-1,y-1))
                    {//up and to left
                        neighbors++;
                    }
                    if (current_grid.check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y))
                    {//left
                        neighbors++;
                    }
                    //Mirror
                    if (current_grid.check (x,y))
                    {//itself
                        neighbors++;
                    }
                    if (current_grid.check (x,y))
                    {//itself
                        neighbors++;
                    }
                    if (current_grid.check (x,y))
                    {//itself
                        neighbors++;
                    }
                    if (current_grid.check (x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid.check (x-1,y))
                    {//left
                        neighbors++;
                    }
                }

                //code for if the cell grows or dies
                //rules:
                //if a cell has 1 or fewer neighbors...dies
                //if a cell has 2 neighbors...stays same
                //if a cell has 3 neighbors...grows
                //if a cell has 4 or more neighbors...dies

                if(neighbors <= 1)
                {
                    future_grid.kill(x,y);
                }
                if(neighbors == 3)
                {
                    future_grid.grow(x,y);
                }
                if(neighbors >= 4)
                {
                    future_grid.kill(x,y);
                }
            }
        }

        if (current_grid.equals(future_grid))//if the grids stablize or there are 0 living the loop will break
        {
            break;
        }

        //code for grid to output to a file
        /*if(CODE FOR IF)
        {
            //CODE FOR OUTPUT TO FILE
        }*/

        cout << "Generation: " << generation << endl;
        //printg(future_grid.getNumRows(), future_grid.getNumCol(), future_grid);

        cout << "Press Enter to Continue..." << endl;
        cin.ignore();

    }
}

#endif
