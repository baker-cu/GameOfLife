#include <iostream>

using namespace std;

class Classic
{
    public:
        Classic();

        void run();

        Grid current_grid;
};

/* [0][0] [0][1] [1][2]
   [1][0] [1][1] [1][2]
   [2][0] [2][1] [2][2]
   [3][0] [3][1] [3][2] */
