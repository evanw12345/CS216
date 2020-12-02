//Method implementation of class PokerHand
//Author: Evan Wells
//CS 216-001

#include "pokerhand.h"

//---------------------
//   Public Functions
//---------------------

// Default constructor.
// We allow a blank PokerHand to be created.
// However, the default constructor should make sure
// that hand_rank is (Rank::NoRank, 0).
PokerHand::PokerHand() { hand_rank = Rank(); }

// It should store the HANDS cards
// given as parameters in the cards[] array.
// if size is not HANDS, display "Invalid number of cards!"
// It should also immediately evaluate the hand, determine
// its rank: ranking kind and the card value
void PokerHand::setPokerHand(Card in_hand[], int size)
{
    if (size != HANDS)
    {
        cout << "Invalid number of cards" << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cards[i] = in_hand[i];
        }
        sort();
        isHighCard();
        isPair();
        isThreeOfAKind();
        isStraight();
        isFlush();
        isFullHouse();
        isFourOfAKind();
        isStraightFlush();
    }
}

// Compare this hand versus otherHand according
// to the rules of poker.
// Returns a negative number (< 0)
// if this hand loses to the otherHand.
// Returns a positive number (> 0)
// if this hand beats the otherHand.
// Returns zero if it's a tie.
//
// An invalid hand loses to any hand. If both hands
// are invalid, the result is undefined (could be
// negative, zero or positive).
//
int PokerHand::compareHand(const PokerHand &otherHand) const
{
    //If otherHand wins
    if (this->hand_rank.getKind() < otherHand.hand_rank.getKind())
    {
        return -1;
    }

    //If this hand wins
    else if (this->hand_rank.getKind() > otherHand.hand_rank.getKind())
    {
        return 1;
    }

    // If both are same rank
    else
    {
        if (this->hand_rank.getPoint() < otherHand.hand_rank.getPoint())
        {
            return -1;
        }
        else if (this->hand_rank.getPoint() > otherHand.hand_rank.getPoint())
        {
            return 1;
        }
        else
            return 0;
    }
}

// Prints out the five cards and its rank to standard output.
// It should look like:
// Five cards:
// one card per line
// then followed by "Its rank is: rank"
void PokerHand::print() const
{
    cout << "Five cards:" << endl;
    for (int i = 0; i < HANDS; i++)
    {
        cards[i].print(); cout << "\t";
    }
    cout << endl;
    cout << "Its rank is: ";
    hand_rank.print();
}

// Return the rank of this hand
Rank PokerHand::getRank() const
{
    return hand_rank;
}

// The following "isXXXX()" functions shoudl all:
// 1. Assume that the hand is already sorted{ }
// 2. If true, store the rank in hand_rank{ }
// 3. use the rank if hand_rank is available.

// Returns true if the hand is a StraightFlush
// and set the hand_rank (StraightFlush, highest point of the sequential five cards)
// otherwise returns false
bool PokerHand::isStraightFlush()
{
    if (isSequence() && isAllOneSuit())
    {
        Rank temp(Rank::hRanks::StraightFlush, cards[0].getPoint());
        hand_rank = temp;
        return true;
    }
    else
        return false;
}

// Returns true if the hand is a Four of a Kind
// and set the hand_rank (FourOfAKind, highest point of the same four cards)
// otherwise returns false
//
// Checks all possible combinations
bool PokerHand::isFourOfAKind()
{
    if (cards[0].getPoint() == cards[1].getPoint() && cards[0].getPoint() == cards[2].getPoint() && cards[0].getPoint() == cards[3].getPoint())
    {
        Rank temp(Rank::hRanks::FourOfAKind, cards[0].getPoint());
        hand_rank = temp;
        return true;
    }
    else if (cards[1].getPoint() == cards[2].getPoint() && cards[1].getPoint() == cards[3].getPoint() && cards[1].getPoint() == cards[4].getPoint())
    {
        Rank temp(Rank::hRanks::FourOfAKind, cards[1].getPoint());
        hand_rank = temp;
        return true;
    }
    else
        return false;
}

// Returns true if the hand is a Full House
// and set the hand_rank (FullHouse, highest point of the same three cards)
// otherwise returns false
bool PokerHand::isFullHouse()
{
    if (cards[0].getPoint() == cards[2].getPoint() && cards[3].getPoint() == cards[4].getPoint())
    {
        Rank temp(Rank::hRanks::FullHouse, cards[0].getPoint());
        return true;
    }
    else if (cards[0].getPoint() == cards[1].getPoint() && cards[2].getPoint() == cards[4].getPoint())
    {
        Rank temp(Rank::hRanks::FullHouse, cards[2].getPoint());
        return true;
    }
}

// Returns true if the hand is a Flush
// and set the hand_rank (Flush, highest point of the five cards)
// otherwise returns false
bool PokerHand::isFlush()
{
    if (isAllOneSuit())
    {
        Rank temp(Rank::hRanks::Flush, cards[0].getPoint());
        hand_rank = temp;
        return true;
    }
    else
        return false;
}

// Returns true if the hand is a Straight
// and set the hand_rank (Straight, highest point of the sequential five cards)
// otherwise returns false
bool PokerHand::isStraight()
{
    if (isSequence())
    {
        Rank temp(Rank::hRanks::Straight, cards[0].getPoint());
        hand_rank = temp;
        return true;
    }
    else
        return false;
}

// Returns true if the hand is a Three of a Kind
// and set the hand_rank (ThreeOfAKind, highest point of the same three cards)
// otherwise returns false
bool PokerHand::isThreeOfAKind()
{
    if (cards[0].getPoint() == cards[1].getPoint() && cards[0].getPoint() == cards[2].getPoint())
    {
        Rank temp(Rank::hRanks::ThreeOfAKind, cards[0].getPoint());
        hand_rank = temp;
        return true;
    }
    else if (cards[1].getPoint() == cards[2].getPoint() && cards[1].getPoint() == cards[3].getPoint())
    {
        Rank temp(Rank::hRanks::ThreeOfAKind, cards[1].getPoint());
        hand_rank = temp;
        return true;
    }
    else if (cards[2].getPoint() == cards[3].getPoint() && cards[2].getPoint() == cards[4].getPoint())
    {
        Rank temp(Rank::hRanks::ThreeOfAKind, cards[2].getPoint());
        hand_rank = temp;
        return true;
    }
    else
        return false;
}

// Returns true if the hand is a Pair (we consider either one pair or two pairs is a Pair)
// and set the hand_rank (Pair, highest point of any pair)
// otherwise returns false
bool PokerHand::isPair()
{
    if (cards[0].getPoint() == cards[1].getPoint())
    {
        Rank temp(Rank::hRanks::Pair, cards[0].getPoint());
        hand_rank = temp;
        return true;
    }
    else if (cards[1].getPoint() == cards[2].getPoint())
    {
        Rank temp(Rank::hRanks::Pair, cards[1].getPoint());
        hand_rank = temp;
        return true;
    }
    else if (cards[2].getPoint() == cards[3].getPoint())
    {
        Rank temp(Rank::hRanks::Pair, cards[2].getPoint());
        hand_rank = temp;
        return true;
    }
    else if (cards[3].getPoint() == cards[4].getPoint())
    {
        Rank temp(Rank::hRanks::Pair, cards[3].getPoint());
        hand_rank = temp;
        return true;
    }
    else
        return false;
}

// Returns true if the hand is a High Card
// and set the hand_rank (High Card, highest point of the five cards)
// otherwise returns false
bool PokerHand::isHighCard()
{
    Rank temp(Rank::hRanks::HighCard, cards[0].getPoint());
    hand_rank = temp;
    return true;
}

//---------------------
//   Private Functions
//---------------------

// to help sort the HANDS=5 cards in decreasing order by card points
void PokerHand::sort()
{
    for (int i = 0; i < HANDS; i++)
    {
        for (int j = i + 1; j < HANDS; j++)
        {
            if (cards[i].getPoint() < cards[j].getPoint())
            {
                Card temp = cards[i];
                cards[i] = cards[j];
                cards[j] = temp;
            }
        }
    }
}

// to help decide if HANDS=5 cards are all of one suit
// return true if they are
// otherwise return false
bool PokerHand::isAllOneSuit() const
{
    Card temp(cards[0].getSuit(), cards[0].getPoint());
    for (int i = 1; i < HANDS; i++)
    {
        if (cards[i].getSuit() != temp.getSuit())
        {
            return false;
        }
    }
    return true;
}

// to help decide if HANDS=5 cards are in a continuous sequence
// return true if they are
// otherwise return false
bool PokerHand::isSequence() const
{
    Card::cPoints test = cards[0].getPoint();
    for (int i = 1; i < HANDS; i++)
    {
        if (test == cards[i].getPoint() - 1)
        {
            test = cards[i].getPoint();
        }
        else
            return false;
    }
    return true;
}