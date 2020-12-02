/*
 * Course: CS216-00x
 * Project: Lab 8 Part 1 (As part of Project 2)
 * Purpose: use the Card and SortedLinkedList classes to display 
 *          the 5 cards in user's hand in descreasing order by card points
 *          Note the suit of a card has NO impact on the order
 *          A (=14) has higher point than all other cards, J = 11, Q = 12, K = 13
 *          1 point is not used in the card 
 *** DO NOT CHANGE THIS FILE ***
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "SortedLinkedList.h"
#include "card.h"

using namespace std ;

int main() 
{
    // Avoid magic numbers
    // define constants for a standard 52-card deck
    const int CARD_START = 2;  // the card point value starting at 2
    const int SUITS = 4;    // standard 52-card deck includes four suits
    const int POINTS = 13;   // standard 52-card deck includes 13 points values
    const int HANDS = 5;    // play 5-card in hand

    // create a standard 52-card deck
    // avoid invalid card such as 5 cards of the same value
    vector<Card> deck;
    deck.clear();
    for (int s= (int)Card::cSuits::Spade; s < (int)Card::cSuits::Spade+SUITS; s++)
    {    
        for (Card::cPoints val = CARD_START; val < CARD_START+POINTS; val++)
        {
            Card::cSuits suit = static_cast<Card::cSuits>(s);
            Card newcard(suit, val);
            deck.push_back(newcard);
        }
    }

    // shuffle the cards in 52-card deck
    srand(time(0));
    Card temp;  // for swapping
    for (int i = deck.size()-1; i>= 1; i--)
    {
        int j = rand() % (i+1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }

    // declare an array of fixed size of 5 to store the cards in your hand
    Card fiveCards[HANDS];
    cout << "The cards in your hand are: "<< endl;

    for (int i=0; i< HANDS; i++)
    {    
        fiveCards[i] = deck.back();
        deck.pop_back();
        fiveCards[i].print();
        cout << "\t";
    }

    cout << endl << endl << "The cards in your hand are put in order: " << endl;
    SortedLinkedList myHand;
    for (int i=0; i < HANDS; i++)
    {
        myHand.insert(fiveCards[i]);
    }

    myHand.print();
    return 0;
}

