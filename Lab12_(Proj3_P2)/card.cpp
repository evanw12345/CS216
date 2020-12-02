/* File: card.cpp
 * Course: CS216-00x
 * Project: Lab12 (as part of Project 3)
 * Purpose: the implementation of member functions for the Card class.
 * Author: (your name)
 */
#include <sstream>
#include <iomanip>
#include "card.h"

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

// compare the two cards in descending order by points
// if the order of C1 and C2 in descending order by points, return 1;
// if C1 and C2 are of the same points, return 0;
// otherwise, return -1
int Card::compareByPoint(const Card &C1, const Card &C2)
{
    if (C1.point > C2.point)
    {
        return 1;
    }
    else if (C1.point == C2.point)
    {
        return 0;
    }
    else
        return -1;
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

// operator overloading for operators "<" and "<<"
// they are defined as friend functions

// define the operator "<" for Card class

bool operator<(Card C1, Card C2)
{
    if (C1.point < C2.point)
    {
        return true;
    }
    else
        return false;
}

// define the operator "<<" for Card class
// to send the Card object to the cout
// Display a description of the Card object to standard output
// The output should look like:
// suit-character point-character suit-character
ostream &operator<<(ostream &out, const Card &C)
{
    const int POINTMIN = 2;
    const int POINTMAX = 14;
    const int POINTLETTER = 10;
    if (C.point < POINTMIN || C.point > POINTMAX)
    {
        out << "Invalid card value!" << endl;
        return out;
    }

    // map the point to card face
    // 11 -->J, 12 -->Q, 13 -->K, 14 --> A
    string face;
    if (C.point > POINTLETTER)
    {
        switch (C.point)
        {
        case 11:
            face = "J";
            break;
        case 12:
            face = "Q";
            break;
        case 13:
            face = "K";
            break;
        case 14:
            face = "A";
            break;
        default:
            face = "Invalid";
            break;
        }
    }
    else
    {
        // using stringstream to convert integer into string
        stringstream ss;
        ss << C.point;
        ss >> face;
    }

    // prints suit symbol with card value
    switch (C.suit)
    {
    case Card::cSuits::Spade:
        out << SPADE << setw(2) << face << SPADE;
        break;
    case Card::cSuits::Club:
        out << CLUB << setw(2) << face << CLUB;
        break;
    case Card::cSuits::Heart:
        out << HEART << setw(2) << face << HEART;
        break;
    case Card::cSuits::Diamond:
        out << DIAMOND << setw(2) << face << DIAMOND;
        break;
    default:
        out << "Invalid suit!" << endl;
        break;
    }
    return out;
}
