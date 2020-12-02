/* 
 * File: smartReverse.h
 * Purpose: provide the declaration of the smartReverse class
 *
 * Author: Pike
 ******PLEASE DO NOT CHANGE THIS FILE!******
 *
 */

#ifndef SMARTREVERSE_H
#define	SMARTREVERSE_H

#include <string>

using namespace std;

class smartReverse
{
    public:
        // default constructor
        smartReverse();

        // constructor: initialize str with ini_str passing as a parameter
        smartReverse(string ini_str);

        // return the current value of the private data member: str
        string getString() const;

        // set the value of str to be the passed in parameter input_str
        void setString(string input_str);

        // return a reverse string
        // using a loop to implement
        // Note that str has not been changed
        string rev_loop() const;

        // return a reverse string
        // using recursion to implement
        // Note that str has not been changed
        string rev_recursive() const;

        // return a reverse string
        // using a stack to implement
        // Note that str has not been changed
        string rev_stack() const;

    private:
        string str;
};

#endif	/* SMARTREVERSE_H */

