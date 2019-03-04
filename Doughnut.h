#include <iostream>
#include "Grid.cpp"

using namespace std;

class Doughnut
{
    public:
        Doughnut(int x);
        ~Doughnut();

        void run();

        Grid current_grid;
        Grid future_grid;

};
