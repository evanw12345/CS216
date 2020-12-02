/* File: rank.cpp
 * Course: CS216-001
 * Project: Lab 9 (as part of Project 2)
 * Purpose: the implementation of member functions for the Rank class.
 * Author: Evan Wells  
 */
#include <iostream>
#include <iomanip>
#include "rank.h"

using namespace std;

// Default constructor.
Rank::Rank()
{
    kind = hRanks::NoRank;
    point = 0;
}
 
// Alternate constructor.
// Create a Rank object with specified ranking name and points.
Rank::Rank(hRanks r, rPoints p)
{
    if (r >= hRanks::NoRank && r <= hRanks::StraightFlush)
    {
        kind = r;
    }
    else
    {
        kind = hRanks::NoRank;
    }
    if (p > 1 && p < 15)
    {
        point = p;
    }
    else
    {
        point = 0;
    }
}

// access the hand ranking kind
Rank::hRanks Rank::getKind() const
{
    return kind;
}

// access the card point value of the corresponding ranking kind
Rank::rPoints Rank::getPoint() const
{
    return point;
}

// Display a description of the hand-ranking category to standard output.
// The output should look like:
//   FourOfAKind( 4)
//   FullHouse(10)
//   Flush( A)
//   ...
void Rank::print() const
{
    string value;
    if (point == 14)
        value = "A";
    else if (point == 13)
        value = "K";
    else if (point == 12)
        value = "Q";
    else if (point == 11)
        value = "J";
    else
        value = to_string(point);

    switch (kind)
    {
    case hRanks::HighCard:
        cout << "High Card (" << setw(2) << right << value << ")" << endl;
        break;
    case hRanks::Pair:
        cout << "Pair (" << setw(2) << right << value << ")" << endl;
        break;
    case hRanks::ThreeOfAKind:
        cout << "ThreeOfAKind (" << setw(2) << right << value << ")" << endl;
        break;
    case hRanks::Straight:
        cout << "Straight (" << setw(2) << right << value << ")" << endl;
        break;
    case hRanks::Flush:
        cout << "Flush (" << setw(2) << right << value << ")" << endl;
        break;
    case hRanks::FullHouse:
        cout << "FullHouse (" << setw(2) << right << value << ")" << endl;
        break;
    case hRanks::FourOfAKind:
        cout << "FourOfAKind (" << setw(2) << right << value << ")" << endl;
        break;
    case hRanks::StraightFlush:
        cout << "StraightFlush (" << setw(2) << right << value << ")" << endl;
        break;
    }
}
