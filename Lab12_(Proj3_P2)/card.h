/* File: card.h
 * Course: CS216-00x
 * Project: Lab 12 (as part of Project 3)
 * Purpose: the declaration for the Card class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

// define the unicode for four suits for display purpose
const char SPADE[] = "\u2660";
const char CLUB[] = "\u2663";
const char HEART[] = "\x1B[31m\u2665\033[0m";
const char DIAMOND[] = "\x1B[31m\u2666\033[0m";

class Card 
{
    public:
        // Type definition for the suits of a playing card.
        // Invalid means the Card object has not been initialized.
        // Note: outside Card member functions, refer this type using Card::cSuits, 
        // Card::Spades, Card::Hearts, ...
        //
        typedef enum class cSuits {Invalid, Spade, Club, Heart, Diamond} cSuits;

        // Type definition for the point value of a playing card.
        // A point value of 0 means the Card object has not been initialized.
        // J = 11, Q = 12, K = 13, A = 14.
        // A point value of 1 is not used.
        // Note: outside Card member functions, refer this type using Card::cPoints
        //
        typedef unsigned int cPoints;

        // Default constructor.
        // We allow uninitialized Cards to be created.
        // This allows arrays of Cards.
        // Uninitialized cards should have Invalid for its suit
        // and 0 for its points.
        Card(); 

        // Alternate constructor
        // Create a Card with specified suit and points.
        Card(cSuits s, cPoints p);
        
        // compare the two cards in descending order by points
        // if the order of C1 and C2 in descending order by points, return 1;
        // if C1 and C2 are of the same points, return 0;
        // otherwise, return -1
        static int compareByPoint(const Card& C1, const Card& C2);

        // access the card point value
        cPoints getPoint() const;

        // access the card suit value
        cSuits getSuit() const;

        // operator overloading for operators "<" and "<<"
        // they are defined as friend functions

        // define the operator "<" for Card class
        friend bool operator<(Card C1, Card C2);

        // define the operator "<<" for Card class
        // to send the Card object to the cout
        // The output should look like:
        // suit-character point-character suit-character  
        friend ostream& operator<<(ostream &out, const Card& C);

    private:
        cSuits suit;        // suit of the card
        cPoints point;    // point value of the card
};
#endif  /* CARD_H */
