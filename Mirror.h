#include <iostream>
#include "Grid.cpp"

using namespace std;

class Mirror
{
    public:
        Mirror(int x);
        ~Mirror();

        void run();

        Grid current_grid;
        Grid future_grid;

}
