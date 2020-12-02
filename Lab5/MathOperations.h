/* course: CS216-00x
 * Project: Lab 5 (as part of Project 1)
 * Purpose: to declare the class named MathOperations
 * Author: (your name)
 */

#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H

#include <iostream>

using namespace std;

const int MAXDIGITS = 4;    // the maximum digits of operands or answers

class MathOperations
{
  public:
    // default constructor
    MathOperations();

    // set the private data members: operand1 and operand2
    // to op1 and op2 respectively
    void setOperands(int op1, int op2);

    // get the current value of the private data member: theoperator
    char getOperator() const;

    // return the value of the data member: answer
    int getAnswer() const;

    // set theoperator to '+'
    // apply the addition operation to operand1 and operand2
    // set the answer equal to operand1 + operand2
    void Addition();

    // set theoperator to '-'
    // apply the subtraction operation to operand1 and operand2
    // set the answer equal to operand1 - operand2
    void Subtraction();

    // set theoperator to '*'
    // apply the multiplication operation to operand1 and operand2
    // set the answer equal to operand1 * operand2
    void Multiplication();

    // if answer == response, it returns true
    // otherwise it returns false
    bool checkAnswer(int response) const;

    //display the question in the format described in the problem statement
    // for example:
    //    135
    //  +  78
    //  _____
    //
    void print() const;

  private:
    int operand1;  // the first operand for basic math operation
    int operand2;  // the second operand for basic math operation
    char theoperator; // the current operator;
    int answer;    // the correct answer
};

#endif   /* MATHOPERATIONS_H */
