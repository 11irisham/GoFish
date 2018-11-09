// Iris Ham and Sam Wang

#include "card.h"
#include "deck.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    return rankString(myRank)+suitString(mySuit)+" ";
}


bool Card::sameSuitAs(const Card& c) const {
    if (mySuit == c.mySuit) {
        return true;
    }
    else {
        return false;
    }
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Suit s) const {
    switch (s) {
        case 0: return "s"; break;
        case 1: return "h"; break;
        case 2: return "d"; break;
        case 3: return "c"; break;
    }
}

string Card::rankString(int r) const {
    string s;
    switch (r) {
        case 1: return "A"; break;
        case 10: return "10"; break;
        case 11: return "J"; break;
        case 12: return "Q"; break;
        case 13: return "K"; break;
    }
    //return to_string(r);
    s.push_back(static_cast<char>(r+48));
    return s;
}

bool Card::operator == (const Card& rhs) const {
    if (mySuit == rhs.mySuit && myRank == rhs.myRank) {
        return true;
    }
    else {
        return false;
    }
}

bool Card::operator != (const Card& rhs) const {
    if (mySuit != rhs.mySuit || myRank != rhs.myRank) {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<(ostream &out, const Card &c) {
    out << c.toString();
    return out;
}
