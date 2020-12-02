/*
 * Course: CS216-00x
 * Project: Lab 9 (as part of Project 2)
 * Purpose: use the Card, Deck and SortedLinkedList classes to display 
 *          the 5 cards in user's hand in descreasing order by card points
 *          Note the suit of a card has NO impact on the order
 *          A (=14) has higher point than all other cards, J = 11, Q = 12, K = 13
 *          1 point is not used in the card 
 *          then based on the highest point card in the user's hand
 *          use the Rank class to display all possible hand rankings from highest to lowest
 *** DO NOT CHANGE THIS FILE ***
*/
#include <iostream>
#include <vector>
#include "SortedLinkedList.h"
#include "rank.h"
#include "deck.h"

using namespace std ;

int main() {

    // create an object of Deck class to represent standard 52-card deck
    // create a 52-card deck first
    // then shuffle the cards
    Deck playDeck;
    playDeck.createDeck();
    playDeck.shuffleDeck();

    const int HANDS = 5;  // simulate five-card poker hands
    Card Cards[HANDS];
    cout << "The cards in your hand are: "<< endl;

    for (int i=0; i< HANDS; i++)
    {    
        Cards[i] = playDeck.deal_a_card();
        Cards[i].print();
        cout << "\t";
    }
    
    cout << endl << endl << "The cards in your hand are put in order: " << endl;
    SortedLinkedList myHand;
    for (int i=0; i < HANDS; i++)
    {
        myHand.insert(Cards[i]);
    }

    myHand.print();

    // display the highest card point in user's hand
    vector<Card> cards_in_hand = myHand.access();
    cout << "Hence the highest card point in your hand is: ";
    cards_in_hand[0].print(); 

    // based on the highest card point in user's hand
    // display the possible hand ranking from higher to lower
    const int RANKING_CATEGORIES = 8; // there are eight ranking categories
    cout << endl << endl << "Based on your highest card point, the possible hand ranking from highest to lowest: " << endl;
    for (int i = RANKING_CATEGORIES; i > 0; i--)
    {
        Rank current(Rank::hRanks(i),cards_in_hand[0].getPoint());
        current.print();
    }

    cout << endl << endl << "You need to be a little patient to wait for me to decide your hand ranking based on your FIVE cards... " << endl;
    cout << "Wait for me to finish my project 2...thank you." << endl;
    return 0;
}

