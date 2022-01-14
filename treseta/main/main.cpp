// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "game.h"
#include "deck.h"
#include "card.h"

using namespace std;

int main()
{
    deck deck;
    deck.print_deck();
    cout << "\n\n\n\nSHUFFLE\n\n";
    deck.shuffle();
    deck.print_deck();
    humanplayer h;

    vector<card> hand = deck.deal();

    cout << "\n\nruka\n\n";
    for (auto c : hand)
        cout << c.get_number() << " of " << c.get_suit() << endl;

    cout << "\n\n\n rest od deck\n" << endl;
    deck.print_deck();

    return 0;
}
