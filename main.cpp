//
//  main.cpp
//  MySimpleRacegame
//
//  Created by Pedro Beltran on 2/25/18.
//  Copyright © 2018 Pedro Beltran. All rights reserved.
//

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <random>
#include "player.h"
using namespace std;

int main()
{
    const int M = 37;
    const int N = 5;
    Player player[N];
    player[0].setName("Ged"); player[0].setPoints(0);
    player[1].setName("Ted"); player[1].setPoints(0);
    player[2].setName("Jed");  player[2].setPoints(0);
    player[3].setName("Edd");  player[3].setPoints(0);
    player[4].setName("Zed");  player[4].setPoints(0);
    
    default_random_engine dre(static_cast<size_t>(2));
    uniform_int_distribution<int> player_uid(0, N - 1);
    uniform_int_distribution<int> dice_uid(1, 6);
    int index = player_uid(dre);
    
    do
    {
        if (player[index].getPoints() > M)
        {
            cout << "Player " << player[index].getName() << " loses half their points and their next turn." << endl;
            
            //player losses half points
            player[index].setPoints(player[index].getPoints()/2);
            //skip player
            player[index].setSkip(true);
        }
        
        index = (index + 1) % N;//implements circular array
        
        if (player[index].getSkip() == false)
        {
            int die1 = dice_uid(dre);
            int die2 = dice_uid(dre);
            int points = player[index].getPoints();
            player[index].setPoints(points + die1 + die2);
            cout << player[index].getName() << '/' << setw(2) << die1 + die2 << '/' << setw(2) << player[index].getPoints() << endl;
        }
        else
        {
            cout << "lost turn" << endl;
            player[index].setSkip(false);
        }
        
        
    } while (player[index].getPoints() != M);
    cout << player[index].getName() << " wins" << endl;
    
    system( "read -n 1 -s -p \"Press enter to continue...\"" );
    //For Visual Studios
    //system("pause");
    return 0;
}

