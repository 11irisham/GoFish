#include "card.h"
#include "deck.h"
#include "player.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    int size = myHand.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != j) {
                if (myHand[i].getRank() == myHand[j].getRank()) {
                    c1 = myHand[i];
                    c2 = myHand[j];
                    return true;
                }
            }
        }
    }
    return false;
}

bool Player::rankInHand(Card c) const {
    int size = myHand.size();
    for (int i = 0; i < size; i++) {
        if (myHand[i].getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    int size = myHand.size();
    int rand1;
    for (int i = 1; i < 1000; i++) {
        rand1 = rand() % size;
    }

    return myHand[rand1];
}

Card Player::removeCardFromHand(Card c) {
    for (int i = 0; i < myHand.size(); i++) {
        if (c.getRank() == myHand[i].getRank()) {
            Card returnCard = myHand[i];
            myHand.erase(myHand.begin()+i);
            return returnCard;
        }
    } 
}

string Player::showHand() const {
    int size = myHand.size();
    for (int i = 0; i < size; i++) {
        cout << myHand.at(i);
    }
}

string Player::showBooks() const {
    int size = myBook.size();
    for (int i = 0; i < size; i++)
    {
        cout << myBook.at(i);
    }
}

int Player::getHandSize() const {
    int handSize = myHand.size();
    return handSize;
}

int Player::getBookSize() const {
    int bookSize = myBook.size();
    return bookSize;
}

// bool Player::checkHandForPair(Card &c1, Card &c2) {

// }

// bool Player::sameRankInHand(Card c) const {

// }
