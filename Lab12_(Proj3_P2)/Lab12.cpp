/*
 * Course: CS216-00x
 * Project: Lab 12 (as part of Project 3)
 * Purpose: it demonstrates sorting operations on different data items in different sorting criteria by using template class
 *          the program repeatedly asks the user to choose an option from the main menu
 *          1. Sort five-card in hand in ascending and descending order by card points (as in poker game)
 *          2. Sort prefix-matched terms in lexicographic order by query and in descending order by weight (as in autocomplete feature)
 */

#include <iostream>
#include <string>
#include "sortingOperations.h"

using namespace std;

int main()
{
    int option;
    while (true)
    {
        cout << "This application demonstrates sorting operations on different data items in different sorting criteria! Please choose your option (Enter Q or q to quit):" << endl;
        cout << "1. Sort five-card in hand in ascending and descending order by points" << endl;
        cout << "2. Sort prefix-matched terms in lexicographic order by query and in descending order by weight" << endl;
        cin >> option;
        cin.ignore(256, '\n');

        if (cin.fail())
        {
            string input_to_check;
            cin.clear();
            cin >> input_to_check;
            if (input_to_check == "Q" || input_to_check == "q")
                break;
            else
            {
                cout << "Invalid option!" << endl;
                continue;
            }
        }

        switch (option)
        {
            case 1: sortCards();
                    break;
            case 2: sortTerms();
                    break;
            default:
                    cout << "Invalid option!" << endl;
        }
    }
    cout << "Thank you for using my program, bye..." << endl;
    return 0;
}

