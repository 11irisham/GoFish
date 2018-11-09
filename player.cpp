// Iris Ham and Sam Wang

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
    myBook.push_back(removeCardFromHand(c1));
    myBook.push_back(removeCardFromHand(c2));
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    int size = myHand.size();
    for (int i = 0; i < size-1; i++) {
        for (int j = 1; j < size; j++) {
            if (myHand.at(i).getRank() == myHand.at(j).getRank()) {
                c1 = myHand.at(i);
                c2 = myHand.at(j);
                return true;
            }
        }
    }
    return false;
}

bool Player::rankInHand(Card c) const {
    int size = myHand.size();
    for (int i = 0; i < size; i++) {
        if (myHand.at(i).getRank() == c.getRank()) {
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

    return myHand.at(rand1);
}

Card Player::removeCardFromHand(Card c) {
    for (int i = 0; i < myHand.size(); i++) {
        if (c == myHand.at(i)) {
            Card returnCard = myHand.at(i);
            myHand.erase(myHand.begin()+i);
            return returnCard;
        }
    } 
}

string Player::showHand() const {
    int size = myHand.size();
    string s;

    for (int i = 0; i < size; i++) {
        s += myHand.at(i).toString();
    }

    return s;
}

string Player::showBooks() const {
    int size = myBook.size();
    string s;

    for (int i = 0; i < size; i++) {
        s += myBook.at(i).toString();
    }

    return s;
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
