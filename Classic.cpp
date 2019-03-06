#include "Classic.h"

#ifndef _CLASSIC_C
#define _CLASSIC_C

#include <iostream>
#include <fstream>

using namespace std;

Classic::Classic(int x)
{
    if(x==1)
    {
        string file;
        cout<<"Enter the filepath for original grid: "<<endl;
        cin>>file;

        this->current_grid = new Grid(file);
        this->future_grid = new Grid(file);


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

        this->current_grid = new Grid(r,c,d);
        this->future_grid = new Grid(r,c,d);

    }
}

Classic::~Classic()
{
    delete this->current_grid;
    delete this->future_grid;
}

void Classic::run()
{
    string enter;
    cout<<"Would you like to have to press after every generation? (y/n)"<<endl;
    cin>>enter;

    string tofile;
    cout<<"Would you like to print each generation to a file? (y/n)"<<endl;
    cin>>tofile;

    int generation = 0;
    cout << "Generation: " << generation << endl;

    current_grid->printg();

    string filename = "";
    if (tofile == "y")
    {
        cout<<"Enter the name of the file you would like to write to: "<< endl;
        cin>>filename;
    }



    while(true){

        int neighbors = 0;

        //iterate through each element
        for(int x = 0; x < current_grid->getNumRows()-1; x++)
        {

            for(int y = 0; y < current_grid->getNumCol()-1; y++)
            {

                if(x>0 && y>0 && x < current_grid->getNumRows()-1 && y < current_grid->getNumCol()-1)//if the idex is not on the edges of the board
                {

                    if (current_grid->check(x-1,y-1))
                    {//up and to left
                        neighbors++;
                    }
                    if (current_grid->check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y+1))
                    {//up and to right
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y-1))
                    {//below and right
                        neighbors++;
                    }
                    if (current_grid->check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y-1))
                    {//below and left
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y))
                    {//left
                        neighbors++;
                    }
                }
                else if(x==0 && y!=current_grid->getNumCol()-1 && y!=0)//if index is on the top of the board
                {
                    if (current_grid->check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y-1))
                    {//below and right
                        neighbors++;
                    }
                    if (current_grid->check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y-1))
                    {//below and left
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y))
                    {//left
                        neighbors++;
                    }

                }
                else if(x==current_grid->getNumRows()-1 && y!=0 && y!=current_grid->getNumCol()-1)//index is on bottom of the board
                {
                    if (current_grid->check(x-1,y-1))
                    {//up and to left
                        neighbors++;
                    }
                    if (current_grid->check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y+1))
                    {//up and to right
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y))
                    {//left
                        neighbors++;
                    }

                }
                else if(y==0 && x!=0 && x!=current_grid->getNumRows()-1)//on left edge of board
                {
                    if (current_grid->check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y+1))
                    {//up and to right
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y-1))
                    {//below and right
                        neighbors++;
                    }
                    if (current_grid->check (x,y-1))
                    {//below
                        neighbors++;
                    }

                }
                else if(y==current_grid->getNumCol()-1 && y!=0 && x!=current_grid->getNumRows()-1)//on right edge of board
                {
                    if (current_grid->check(x-1,y-1))
                    {//up and to left
                        neighbors++;
                    }
                    if (current_grid->check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid->check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y-1))
                    {//below and left
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y))
                    {//left
                        neighbors++;
                    }

                }
                else if(x==0 && y==0)//top left corner
                {
                    if (current_grid->check (x+1,y))
                    {//to the right
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y-1))
                    {//below and right
                        neighbors++;
                    }
                    if (current_grid->check (x,y-1))
                    {//below
                        neighbors++;
                    }
                }
                else if(x==0 && y==current_grid->getNumCol()-1)//top right corner
                {
                    if (current_grid->check (x,y-1))
                    {//below
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y-1))
                    {//below and left
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y))
                    {//left
                        neighbors++;
                    }
                }
                else if(x==current_grid->getNumRows()-1 && y==0)//bottom left corner
                {
                    if (current_grid->check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y+1))
                    {//up and to right
                        neighbors++;
                    }
                    if (current_grid->check (x+1,y))
                    {//to the right
                        neighbors++;
                    }

                }
                else if(x==current_grid->getNumRows()-1 && y==current_grid->getNumCol()-1)//bottom right corner
                {
                    if (current_grid->check(x-1,y-1))
                    {//up and to left
                        neighbors++;
                    }
                    if (current_grid->check(x,y-1))
                    {//above
                        neighbors++;
                    }
                    if (current_grid->check (x-1,y))
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
                    future_grid->kill(x,y);
                }
                else if(neighbors == 3)
                {
                    future_grid->grow(x,y);
                }
                else if(neighbors >= 4)
                {
                    future_grid->kill(x,y);
                }
                neighbors = 0;

            }
        }

        generation++;



        if (current_grid->equals(future_grid))//if the grids stablize or there are 0 living the loop will break
        {
            break;
        }




        cout << "Generation: " << generation << endl;
        future_grid->printg();

        if(tofile == "y")
            current_grid->toFile(filename, generation);

        if(enter == "y")
        {
            cout << "Press Enter to Continue..." << endl;
            cin.ignore();
        }

        this->current_grid = new Grid(future_grid);

    }

}

#endif
