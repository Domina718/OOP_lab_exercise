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
    string name;
    cout << "Enter your name: ";
    cin >> name;
    game treseta(name);
    treseta.play();
    return 0;
}
