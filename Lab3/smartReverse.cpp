/* 
 * File: smartReverse.cpp
 * Purpose: provide the implementation of the smartReverse class
 *
 * Author: Evan Wells
 *
 */

#include <stack>
#include "smartReverse.h"

// default constructor
smartReverse::smartReverse()
{ str = ""; }

// constructor: initialize str with ini_str passing as a parameter
smartReverse::smartReverse(string ini_str)
{ str = ini_str; }

// return the current value of the private data member: str
string smartReverse::getString() const
{ return str; }

// set the value of str to be the passed in parameter input_str
void smartReverse::setString(string input_str)
{ str = input_str; }

// return a reverse string from str
// using a loop to implement
// Note that str has not been changed
string smartReverse::rev_loop() const
{
    string output;
    for ( int i = str.size()-1; i >= 0; i--){
        output += str[i];
    }
    return output;
}

// return a reverse string from str
// using recursion to implement
// Note that str has not been changed
string smartReverse::rev_recursive() const
{
    if (str.size() <= 1){
        return str;
    }
    else {
        string shortStr = str.substr(0, str.size() -1);
        smartReverse sr(shortStr);
        return (str[str.size()-1]+sr.rev_recursive());
    }
}

// return a reverse string from str
// using a stack to implement
// Note that str has not been changed
string smartReverse::rev_stack() const
{ 
    string output;
    stack<char> revStr;
    for(int i = 0; i < str.size(); i++){
        revStr.push(str[i]);
    }

    while (!revStr.empty()){
        output += revStr.top();
        revStr.pop();    
    }

    return output;
}

