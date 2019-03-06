#include "Grid.cpp"

#ifndef _MIRROR_H
#define _MIRROR_H

#include <iostream>

using namespace std;

class Mirror
{
    public:
        Mirror(int x);
        ~Mirror();

        void run();
    private:
        Grid* current_grid;
        Grid* future_grid;

};

#endif
