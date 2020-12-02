/* File: sortingOperations.cpp
 * Course: CS216-00x
 * Project: Lab12 (as part of Project 3)
 * Purpose: the implementation of two functions to provide sorting operations.
 *
 *** DO NOT CHANGE THIS FILE ***
 */
#include "sortingOperations.h"

// sort five-card in hand in both ascending and descending orders by card points
void sortCards()
{
    const int CARDS_IN_HAND = 5;
    // create an object of Deck class to represent standard 52-card deck
    // create a 52-card deck first
    // then shuffle the cards
    Deck playDeck;
    playDeck.createDeck();
    playDeck.shuffleDeck();

    Card fiveCards[CARDS_IN_HAND];
    cout << "The cards in your hand are: "<< endl;

    // deal 5 cards from the current deck
    for (int i=0; i< CARDS_IN_HAND; i++)
    {    
        fiveCards[i] = playDeck.deal_a_card();
        cout << fiveCards[i] << "\t";
    }
    cout << endl;
    
    // using SortingList class to sort cards in your hand
    // 1. in ascending order by card points
    // 2. in descending order by card points
    SortingList<Card>  myHand;
    for (int i=0; i < CARDS_IN_HAND; i++)
    {
        myHand.insert(fiveCards[i]);
    }

    cout << endl << "The cards in your hand are put in ascending order by card points: " << endl;
    myHand.sort();
    myHand.print();
    
    cout << endl << "The cards in your hand are put in descending order by card points: " << endl;
    myHand.selection_sort(Card::compareByPoint);
    myHand.print();
}

// provide the prefix matching
// prefix is defined as the string from user input
// prefix matching is to find all the terms in which each query starts exactly with the prefix
// then sort the matched terms in lexicographic order by query
// then sort the matched terms in descending order by weight
void sortTerms()
{
    // ask the user to input the filename to read data from
    string filename;
    cout << "Please input the filename to read terms data from: "<< endl;
    getline(cin, filename);
    
    // check if the input file can be opened successfully
    ifstream infile;
    infile.open(filename);
    if (!infile.good())
    {
        cout << "Cannot open the file named " << filename << endl;
        return;
    }  
    
    // read in the terms from the input file
    // line by line and store into SortingList object
    SortingList<Term> dataList;
    long weight;
    string query;
    
    while (infile >> weight)
    {
        infile >> ws;
        getline(infile, query);
        if (query != "")
        {    
            Term newterm(query, weight);
            dataList.insert(newterm);
        }    
    } 

    // close the file stream
    infile.close();

    string prefix;
    cout << "Please input the search query(type \"exit\" to quit): " << endl;
    getline(cin, prefix);
    
    while (prefix != "exit")
    {
        // create a Term object from given prefix, weight is 0
        Term toMatch(prefix, 0);

        // create a SortingList object named matchedTerms to store the prefix-match terms
        SortingList<Term> matchedTerms;
        // use sequential search (linear search) to find the matched terms
        for (int i = 0; i < dataList.size(); i++)
        {
            if (Term::compareByPrefix(dataList[i], toMatch, prefix.length()) == 0)
                matchedTerms.insert(dataList[i]);
        }
        
        if (matchedTerms.size() == 0)
            cout << "No matched query!" << endl;
        else //found matched terms
        {
            // sort the matched terms in lexicographic order by query
            cout << endl << "The matched terms are in lexicographic order by query: " << endl;
            matchedTerms.sort();
            matchedTerms.print();

            // sort the matched terms in descending order by weight
            cout << endl << "The matched terms are in descending order by weight: " << endl;
            // pass in the function name directly
            matchedTerms.merge_sort(Term::compareByWeight);
            matchedTerms.print();
        }
        cout << "Please input the search query(type \"exit\" to quit): " << endl;
        getline(cin, prefix);
    }    
}

