#include <iostream>
#include <Grid.h>
#include "Grid.cpp"
#include <Classic.h>


using namespace std;

Classic::Classic(Grid g)
{
    current_grid = g;
}

Classic::run()
{
    int generation = 0;
    cout << "Generation: " << generation << endl;
    current_grid.printg();
    //while true
        //use copy constructor to get current_grid and next_grid


        int neighbors = 0;

        //iterate through each element
        for(int x = 0; x < current_grid.getNumRows(); x++)
        {
            for(int y = 0; y < current_grid.getNumCol(); y++)
            {
                if(x>0 && y>0 && r < current_grid.getNumRows()-1 && x < current_grid.getNumCol()-1)//if the idex is not on the edges of the board
                {
                    if (current_grid.check(x-1,y-1))
                    {//up and to left
                        neighbors++;
                    }
                    if (current_grid.check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (check (x+1,y+1))
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
                    if (check (x+1,y+1))
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
                }
                if(y==0 && x!=0 && x!=current_grid.getNumRows()-1)//on left edge of board
                {
                    if (current_grid.check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (check (x+1,y+1))
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
                }
                if(x==current_grid.getNumRows()-1 && y==0)//bottom left corner
                {
                    if (current_grid.check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (check (x+1,y+1))
                    {//up and to right
                        neighbors++;
                    }
                    if (current_grid.check (x+1,y))
                    {//to the right
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
                }

            }
        }
        //code for if the cell grows or dies



        //if next gen = current gen
            //break


}
