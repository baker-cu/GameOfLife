#include "Grid.cpp"

#ifndef _DOUGHNUT_H
#define _DOUGHNUT_H

#include <iostream>


using namespace std;

class Doughnut
{
    public:
        Doughnut(int x);
        ~Doughnut();

        void run();
    private:
        Grid* current_grid;
        Grid* future_grid;

};

#endif
