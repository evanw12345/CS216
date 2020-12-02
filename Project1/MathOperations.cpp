/* course: CS216-001
 * Project: Lab 5 (as part of Project 1)
 * Purpose: provide the complete implementation of the class named MathOperations
 * Author: Evan Wells
 */
#include <iostream>
#include <iomanip>
#include "MathOperations.h"

// default constructor    
MathOperations::MathOperations()
{
    operand1 = 0;
    operand2 = 0;
    theoperator = '\0';
    answer = -1;
}

// set the private data members: operand1 and operand2
// to op1 and op2 respectively
void MathOperations::setOperands(int op1, int op2)
{
    operand1 = op1;
    operand2 = op2;
    theoperator = '\0';
    answer = -1;
}

// read the current value of the private data member: current operator
char MathOperations::getOperator() const
{
    return theoperator;
}

// return the value of the data member: answer
int MathOperations::getAnswer() const
{
    return answer;
}

// apply the addition operation to operand1 and operand2
// set the answer equal to operand1 + operand2
void MathOperations::Addition()
{
    theoperator = '+';
    answer = operand1 + operand2;
}

// apply the subtraction operation to operand1 and operand2
// set the answer equal to operand1 - operand2
void MathOperations::Subtraction()
{
    theoperator = '-';
    answer = operand1 - operand2;
}

// apply the multiplication operation to operand1 and operand2
// set the answer equal to operand1 * operand2
void MathOperations::Multiplication()
{
    theoperator = '*';
    answer = operand1 * operand2;
}

// if answer == response, it returns true
// otherwise it returns false
bool MathOperations::checkAnswer(int response) const
{
    if (response == answer)
        return true;
    else
        return false;
}

//display the question in the format described in the problem statement
// for example:
//    135
//  +  78
//  _____
//
void MathOperations::print() const
{
    cout << "  " << setw(MAXDIGITS) << operand1 << endl;
    cout << " " << theoperator << setw(MAXDIGITS) << operand2 << endl;
    cout << " " << "-----"  << endl;
}
