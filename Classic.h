#include "Grid.cpp"

#ifndef _CLASSIC_H
#define _CLASSIC_H

#include <iostream>


using namespace std;

class Classic
{
    public:
        Classic(int x);//constructor
        ~Classic();//destructor

        void run();
    private:
        Grid* current_grid;
        Grid* future_grid;
};

#endif

/* [0][0] [0][1] [1][2]
   [1][0] [1][1] [1][2]
   [2][0] [2][1] [2][2]
   [3][0] [3][1] [3][2] */
