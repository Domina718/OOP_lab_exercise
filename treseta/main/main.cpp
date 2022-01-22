// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "game.h"
#include "deck.h"
#include "game.h"
#include <random>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    game treseta("Luka");
    treseta.play();
    return 0;
}
