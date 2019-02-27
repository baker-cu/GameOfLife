#include <iostream>
#include <Grid.h>
#include <Classic.h>


using namespace std;

Classic::Classic(Grid g)
{
    current_grid = g;
}

Classic::run()
{
    int generation = 0;
    //while true
        //use copy constructor to get current_grid and next_grid


        int neighbors = 0;
        int x = 0;
        int y = 0;

        //iterate through each element

        if (current_grid.check(x,y))
        {//true means alive
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



        //if next gen = current gen
            //break


}
