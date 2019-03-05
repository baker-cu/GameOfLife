#include "Classic.cpp"
#include "Doughnut.cpp"
#include "Mirror.cpp"
#include "Grid.cpp"

#ifndef _MAIN_C
#define _MAIN_C

#include <iostream>


using namespace std;

int main()
{
    Grid x = Grid();
    x.printg(x.getNumRows(), x.getNumCol());
    while(true)
    {
        while(true)
        {
            int mode,type;
            cout<< "Would you like to run the simulation in " <<endl;
            cout<< "Classic mode (1), Doughnut mode (2), " <<endl;
            cout<< "or Mirror mode (3)? Enter 1, 2, or 3: " <<endl;
            cin>>mode;

            cout<< "Would you like to provide a file path (1) or generate a random grid (2)? "<<endl;
            cout<< "Enter 1 or 2: "<<endl;
            cin>>type;

            if(mode == 1)
            {
                //code for classic
                Classic game = Classic(type);
                cout<<"game made"<<endl;
                game.run();

                break;
            }

            if(mode == 2)
            {
                //code for doughnut
                Doughnut game = Doughnut(type);
                game.run();

                break;
            }

            if(mode == 3)
            {
                //code for mirror
                Mirror game = Mirror(type);
                game.run();

                break;
            }

            else
            {
                cout<<"You did not enter a valid option."<<endl;
            }
        }

        string choice;
        cout<<"Would you like to run the simulation again? (y/n)"<<endl;
        cin>>choice;
        if(choice == "y")
        {
            continue;
        }
        else
        {
            break;
        }
    }

    return 0;
}

#endif
