// Iris Ham and Sam Wang

#include "card.h"
#include "deck.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <time.h>

using namespace std;

Deck::Deck() {
    for (Card::Suit i = Card::spades; i < 4; i = Card::Suit(i + 1)) {
        for (int j = 0; j < 13; j++) {
            Card newCard(j+1,i); 
            myCards[i*13+j]=newCard;
        } 
    }
    myIndex = 51;
}

void Deck::shuffle() {
    srand (time(NULL));

    for (int i = 1; i < 1000; i++) {
        int rand1 = rand() % size();
        int rand2 = rand() % size();
        Card tempCard = myCards[rand1];
        myCards[rand1] = myCards[rand2];
        myCards[rand2] = tempCard;
    }
}

Card Deck::dealCard() {
    Card dealtCard = myCards[myIndex];
    myIndex = myIndex - 1;
    return dealtCard;
}

int Deck::size() const {
    return myIndex + 1;
}
