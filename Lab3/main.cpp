/*
 *Course: CS216-00x
 *Project: Lab Assignment 3
 *Purpose: To reverse each text line
 *         either from the specified file passing as the command line argument
 *         or from the user input
 ******PLEASE DO NOT CHANGE THIS FILE!******
 */

#include <iostream>
#include <string>
#include <fstream>
#include "smartReverse.h"

using namespace std;

int main(int argc, char** argv)
{
    // check if the number of command line arguments is correct
    if (argc < 1 || argc > 2)
    {
        cout << "Usage: " << argv[0] << "  or " << argv[0] << " <filename>" << endl;
        return 1;
    }
    // if there is no command line argument, read the standard input from the keyboard
    if (argc == 1)
    {
        string original;
        cout << "Please input a string to reverse:" << endl;
        getline(cin, original);

        //create a smartReverse object
        smartReverse to_rev(original);

        // Stop the loop when the user click Ctrl-d
        while (!cin.eof())
        {	
            cout << "The original string you type is: " << original << endl;
            cout << "Reverse of the string (using a loop): " << to_rev.rev_loop() << endl;
            cout << "Reverse of the string (using recursion): " << to_rev.rev_recursive() << endl;
            cout << "Reverse of the string (using a stack): " << to_rev.rev_stack() << endl << endl << endl;

            // ask the user to input another string to be reversed
            cout << "Please input a string to reverse:" << endl;
            getline(cin, original);
            to_rev.setString(original);
        }
        return 0;
    }
    // if there is one command line argument, read each line from the input file 
    else 
    {
        string original;
        ifstream inFile;
        inFile.open(argv[1]);
        if (!inFile.good())
        {
            cout <<"File open failure!" << endl;
            return 1;
        }
        smartReverse to_rev;
        while (getline(inFile, original))
        {
            to_rev.setString(original);
            cout << "Original (from file) --> "<< original << endl;
            cout << "Reverse using a loop --> " << to_rev.rev_loop() << endl;
            cout << "Reverse by recursion --> " << to_rev.rev_recursive() << endl;
            cout << "Reverse using a stack --> " << to_rev.rev_stack() << endl << endl << endl;
        }
        inFile.close();
        return 0;
    }
}


