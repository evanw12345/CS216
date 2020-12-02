//Main function implementation for project 2
//Author: Evan Wells
//CS 216-001

#include "pokerhand.h"
#include "deck.h"
#include <vector>
#include <string>

using namespace std;

const int NUM_CARDS = 2;       // Number of cards in a player's hand
const int NUM_TABLE_CARDS = 5; // Number of cards on the table to share
const int HAND = 5;
const int TOTAL_CARDS = NUM_CARDS + NUM_TABLE_CARDS;

// decide the best five cards out of seven cards
// best means the highest ranking of five-card poker hand defined in the poker game
// pass in a vector of seven cards
// (const call by reference: safe for the arugment and no copy is made for efficiency)
// return the best PokerHand object which represents the best five-card poker hand
PokerHand best_FIVE_out_of_SEVEN(const vector<Card> &cards);

int main()
{

    while (true)
    {
        string choice = "";
        Card playerCards[NUM_CARDS];
        Card computerCards[NUM_CARDS];
        Card tableCards[NUM_TABLE_CARDS];
        PokerHand bestComputer, bestPlayer;
        vector<Card> playerAll, computerAll;

        //Creates and shuffles deck for the game
        Deck pokerDeck;
        pokerDeck.createDeck();
        pokerDeck.shuffleDeck();

        //Deals the player's cards
        for (int i = 0; i < NUM_CARDS; i++)
        {
            playerCards[i] = pokerDeck.deal_a_card();
        }

        cout << "The cards in your hand are:" << endl;
        for (int i = 0; i < NUM_CARDS; i++)
        {
            cout << "\t";
            playerCards[i].print();
            cout << endl;
        }

        //Deals the table's cards
        for (int i = 0; i < NUM_TABLE_CARDS; i++)
        {
            tableCards[i] = pokerDeck.deal_a_card();
        }

        cout << "The FIVE cards on the deck to share are:" << endl;
        cout << "*************************" << endl;
        for (int i = 0; i < NUM_TABLE_CARDS; i++)
        {
            cout << "*\t";
            tableCards[i].print();
            cout << "\t\t*" << endl;
        }
        cout << "*************************" << endl;

        //Deals the computer's cards
        for (int i = 0; i < NUM_CARDS; i++)
        {
            computerCards[i] = pokerDeck.deal_a_card();
        }

        cout << "The computer's cards are:" << endl;
        for (int i = 0; i < NUM_CARDS; i++)
        {
            cout << "\t";
            computerCards[i].print();
            cout << endl;
        }

        //Selects best five card hand out of all seven cards
        for (int i = 0; i < NUM_CARDS; i++)
        {
            playerAll.push_back(playerCards[i]);
            computerAll.push_back(computerCards[i]);
        }
        for (int i = 0; i < NUM_TABLE_CARDS; i++)
        {
            playerAll.push_back(tableCards[i]);
            computerAll.push_back(tableCards[i]);
        }

        cout << "Player 1: You" << endl;
        bestPlayer = best_FIVE_out_of_SEVEN(playerAll);

        cout << "Player 2: Computer" << endl;
        bestComputer = best_FIVE_out_of_SEVEN(computerAll);

        int result = bestPlayer.compareHand(bestComputer);
        if (result > 0)
        {
            cout << "Congratulations, you win the game!" << endl;
        }
        else if (result < 0)
        {
            cout << "Sorry, the computer wins this game!" << endl;
        }
        else if (result == 0)
        {
            cout << "It is a tie game!" << endl;
        }

        cout << "Do you want to play poker game again (Press \"q\" or \"Q\" to quit the program)" << endl;
        getline(cin, choice);
        if (choice == "q" || choice == "Q")
        {
            break;
        }
    }
    cout << "Thank you for using this program" << endl;
    return 0;
}

PokerHand best_FIVE_out_of_SEVEN(const vector<Card> &cards)
{

    PokerHand bestH;
    PokerHand cardsH;

    // check if the parameter is valid
    if (cards.size() != TOTAL_CARDS)
    {
        cout << "Invalid Cards, we need SEVEN cards!" << endl;
        return cardsH; // return a PokerHand object by default constructor
    }

    // Consider all possible ways of dropping two cards
    // from all seven cards
    // i is the index of the first card dropped
    // and j is the index of the second card dropped.
    // There are 21 different ways to pick 5 cards out of 7
    for (int i = 0; i < TOTAL_CARDS; i++)
    {
        for (int j = i + 1; j < TOTAL_CARDS; j++)
        {
            Card pick[HAND];
            int index = 0;

            // Iterate over all seven cards and assign them to the pick[] array
            // exclude cards with index numbers of #i and #j.
            for (int k = 0; k < TOTAL_CARDS; k++)
            {
                if (k == i || k == j)
                    continue;
                pick[index] = cards[k];
                index++;
            }

            // create a PokerHand with pick[]
            cardsH.setPokerHand(pick, HAND);

            // Check to see if current pick is better than
            // the best you have seen so far
            if (bestH.compareHand(cardsH) < 0)
            {
                bestH = cardsH;
            }
        }
    }

    // Now bestH holds the best poker hand among all 21 poker hands
    cout << "*** Best five-card hand ***" << endl;
    bestH.print();
    cout << endl
         << endl;
    return bestH;
}