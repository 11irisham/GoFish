// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand (Deck &d, Player &p, int numCards);
Card askCard (Player &p, ofstream &fptr);
bool sayCard (Player &p, ofstream &fptr, Card checkCard);
void drawCard (Deck &d, Player &p, ofstream &fptr);
void bookCard (Player &p, Card book, ofstream &fptr);




int main () {
    srand (time(NULL));
    ofstream fptr;
    fptr.open("gofish_results.txt");
    int numCards = 7;
    int pTurn = 1;

    
    Player p1("Hammy");
    Player p2("Samantha");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    Card book1;
    Card book2;
    
    //show dealt hands of both players
    cout << p1.getName() << " has : " << p1.showHand() << endl;
    cout << p2.getName() << " has : " << p2.showHand() << endl;
    //check if dealt hand has a pair and book it if it does

    while (p1.checkHandForBook(book1,book2)) {
        p1.bookCards(book1, book2);
        fptr << p1.getName() << " has a pair in its dealt hand" << endl;
        cout << p1.getName() << " has a pair in its dealt hand" << endl;
        bookCard(p1, book1, fptr);
    }

    while (p2.checkHandForBook(book1, book2)) {
        p2.bookCards(book1, book2);
        fptr << p2.getName() << " has a pair in dealt hand" << endl;
        cout << p2.getName() << " has a pair in dealt hand" << endl;
        bookCard(p2, book1, fptr);
    }

    cout << p1.getName() << " has : " << p1.showHand() << endl;
    cout << p2.getName() << " has : " << p2.showHand() << endl;
    cout << p1.getName() << " book has : " << p1.showBooks() << endl;
    cout << p2.getName() << " book has : " << p2.showBooks() << endl;

    while (d.size() != 0) {
       
        while (pTurn == 1 /*&& d.size() != 0*/) {
             if(p1.getHandSize()==0){
                 fptr << p1.getName() << " has no cards in hand" << endl;
                 drawCard(d,p1,fptr);
                 pTurn = 2;
             }
             Card checkCard = askCard(p1, fptr);
             cout << "checkCard = " << checkCard.getRank() << endl;
             if(sayCard(p2, fptr, checkCard)) {
                 book1 = p2.removeCardFromHand(checkCard);
                 p1.addCard(book1);
                 p1.bookCards(checkCard,book1);
                 bookCard(p1, book1, fptr);
                 fptr << endl;
                 cout << endl;
             }
             else {
                 drawCard(d, p1, fptr);
                 while (p1.checkHandForBook(book1,book2)){
                     p1.bookCards(book1, book2);
                     fptr << p1.getName() << " has found a pair with the drawn card" << endl;
                     cout << p1.getName() << " has found a pair with the drawn card" << endl;
                     bookCard(p1, book1, fptr);
                 }
                 fptr << endl;
                 cout << endl;
                 pTurn = 2;
             }
        }

        while (pTurn == 2 /*&& d.size() != 0*/) {
            Card checkCard = askCard(p2, fptr);
            if (p2.getHandSize() == 0) {
                fptr << p2.getName() << " has no cards in hand" << endl;
                drawCard(d, p2, fptr);
            }
            else if (sayCard(p1, fptr, checkCard)) {
                book1 = p1.removeCardFromHand(checkCard);
                p2.addCard(book1);
                p2.bookCards(checkCard, book1);
                bookCard(p2, book1, fptr);
                fptr << endl;
                cout << endl;
            }
            else {
                drawCard(d, p2, fptr);
                while (p2.checkHandForBook(book1, book2)) {
                    p2.bookCards(book1, book2);
                    fptr << p2.getName() << " has found a pair with the drawn card" << endl;
                    cout << p2.getName() << " has found a pair with the drawn card" << endl;
                    bookCard(p2, book1, fptr);
                }
                fptr << endl;
                cout << endl;
                pTurn = 1;
            }
        }
    }

    if (p1.getBookSize() > p2.getBookSize()) {
        fptr << p1.getName() << " wins the game with " << (p1.getBookSize())/2 << "pairs!" << endl;
        cout << p1.getName() << " wins the game with " << (p1.getBookSize())/2 << "pairs!" << endl;
        fptr << p1.getName() << " book: "<< p1.showBooks() << endl;
        cout << p1.getName() << " book: " << p1.showBooks() << endl;
        fptr << p2.getName() << " book: " << p2.showBooks() << endl;
        cout << p2.getName() << " book: " << p2.showBooks() << endl;
        fptr.close();
        return EXIT_SUCCESS;
    }
    else if (p1.getBookSize() < p2.getBookSize())
    {
        fptr << p2.getName() << " wins the game with " << (p2.getBookSize())/2 << "pairs!" << endl;
        cout << p2.getName() << " wins the game with " << (p2.getBookSize())/2 << "pairs!" << endl;
        fptr << p2.getName() << " book: " << p2.showBooks() << endl;
        cout << p2.getName() << " book: " << p2.showBooks() << endl;
        fptr << p1.getName() << " book: " << p1.showBooks() << endl;
        cout << p1.getName() << " book: " << p1.showBooks() << endl;
        fptr.close();
        return EXIT_SUCCESS;
    }
    else {
        fptr << "Tie Game!!" << endl;
        fptr << p2.getName() << " book: " << p2.showBooks() << endl;
        cout << p2.getName() << " book: " << p2.showBooks() << endl;
        fptr << p1.getName() << " book: " << p1.showBooks() << endl;
        cout << p1.getName() << " book: " << p1.showBooks() << endl;
        fptr.close();
        return EXIT_SUCCESS;
    }
}



void dealHand (Deck &d, Player &p, int numCards) {
   for (int i=0; i < numCards; i++) {
      p.addCard(d.dealCard());
   }
}

Card askCard (Player &p, ofstream& fptr) {
    Card cardChosen = p.chooseCardFromHand();
    fptr << p.getName() << " asks - Do you have a " << cardChosen.rankString(cardChosen.getRank()) << "?" << endl;
    cout << p.getName() << " asks - Do you have a " << cardChosen.rankString(cardChosen.getRank()) << "?" << endl;
    return cardChosen;
}

bool sayCard(Player &p, ofstream &fptr, Card checkCard) {
    if(p.rankInHand(checkCard)) {
        fptr << p.getName() << " says - Yes. I have a " << checkCard.rankString(checkCard.getRank()) << "." << endl;
        cout << p.getName() << " says - Yes. I have a " << checkCard.rankString(checkCard.getRank()) << "." << endl;
        return true;
    }
    else {
        fptr << p.getName() << " says - Go Fish." << endl;
        cout << p.getName() << " says - Go Fish." << endl;
        return false;
    }
}

void drawCard (Deck &d, Player &p, ofstream &fptr) {
    Card drawnCard = d.dealCard();
    p.addCard(drawnCard);
    fptr << p.getName() << " draws " << drawnCard.rankString(drawnCard.getRank()) << "." << endl;
    cout << p.getName() << " draws " << drawnCard.rankString(drawnCard.getRank()) << "." << endl;
    cout << p.getName() << " Hand: " << p.showHand() << endl;
}

void bookCard (Player &p, Card book, ofstream&fptr) {
    fptr << p.getName() << " books the " << book.rankString(book.getRank()) << "." << endl;
    cout << p.getName() << " books the " << book.rankString(book.getRank()) << "." << endl;
    cout << p.getName() << " Book: " << p.showBooks() << endl;
}

