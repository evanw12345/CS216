/* File: card.cpp
 * Course: CS216-001
 * Project: Lab 8 (as part of Project 2)
 * Purpose: the implementation of member functions for the Card class.
 * Author: Evan Wells 
 */
#include "card.h"
#include <iomanip>

// Default constructor marks card as invalid
Card::Card()
{
    suit = cSuits::Invalid;
    point = 0;
}

// Alternate constructor
Card::Card(cSuits s, cPoints p)
{
    suit = s;
    point = p;
}

// access the card point value
Card::cPoints Card::getPoint() const
{
    return point;
}

// access the card suit value
Card::cSuits Card::getSuit() const
{
    return suit;
}

// compare with another Card object passed in as parameter: other
// if the object your are working on has higher point than other, return 1;
// if the object your are working on has lower point than other, return -1;
// otherwise, return 0
int Card::compareTo(Card other) const
{
    if (this->point < other.point)
        return -1;
    if (this->point > other.point)
        return 1;
    if (this->point == other.point)
        return 0;
}

// Display a description of the Card object to standard output
// The output should look like:
//   the sign of suit, followed by the point, then followed by the sign of suit again
void Card::print() const
{
    string Royal;
    if (point == 14)
        Royal = "A";
    else if (point == 13)
        Royal = "K";
    else if (point == 12)
        Royal = "Q";
    else if (point == 11)
        Royal = "J";
    
    switch (suit)
    {
    case cSuits::Spade:
        if (point < 11)
            cout << SPADE << setw(2) << right << point << SPADE << "  ";
        else
            cout << SPADE << setw(2) << right << Royal << SPADE << "  ";
        break;
    case cSuits::Club:
        if (point < 11)
            cout << CLUB << setw(2) << right << point << CLUB << "  ";
        else
            cout << CLUB << setw(2) << right << Royal << CLUB << "  ";
        break;
    case cSuits::Heart:
        if (point < 11)
            cout << HEART << setw(2) << right << point << HEART << "  ";
        else
            cout << HEART << setw(2) << right << Royal << HEART << "  ";
        break;
    case cSuits::Diamond:
        if (point < 11)
            cout << DIAMOND << setw(2) << right << point << DIAMOND << "  ";
        else
            cout << DIAMOND << setw(2) << right << Royal << DIAMOND << "  ";
        break;
    default:
        break;
    }
}
