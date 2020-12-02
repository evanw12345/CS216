/* course: CS216-001
 * Project: Lab 6 (as part of Project 1)
 * Purpose: Provide the implementation of member functions for  the class named MathReport
 * Author: Evan Wells
 */

#include <iostream>
#include <iomanip>
#include "MathReport.h"

using namespace std;

// default constructor
MathReport::MathReport() { 
    numCorrectAnswers = 0; 
    numWrongAnswers = 0;
}

// add a MathOperations object into the vector named mathQuestions
// and the response to check with the correct answer: 
//    if response is correct, increase numCorrectAnswers
//    otherwise, increase numWrongAnswers
void MathReport::insert(MathOperations newQuestion, int response) {
    mathQuestions.push_back(newQuestion);
    if (mathQuestions.back().checkAnswer(response)) numCorrectAnswers++;
    else numWrongAnswers++;
}

// return the value of numCorrectAnswers
int MathReport::getNumOfCorrectAnswers() const { return numCorrectAnswers;  }

// return the value of numWrongAnswers
int MathReport::getNumOfWrongAnswers() const { return numWrongAnswers; }

// generate a brief report:
//   the total number of math problems has been solved;
//   the list of math problems solved with correct answers
//   the total number of correctly answered questions
//   the toal number of questions with wrong answers
//   if numCorrectAnswers > numWrongAnswers, display message of "Great job!"
//   otherwise display message of "You will do better next time..."
void MathReport::generateReport() const {
    for (int i = 0; i < mathQuestions.size(); i++) {
        cout << endl;
        cout << "Question " << i + 1 << " :" << endl;
        mathQuestions[i].print();
        cout << "  " << setw(MAXDIGITS) << mathQuestions[i].getAnswer() << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "You answered " << numCorrectAnswers << " question(s) correctly." << endl;
    cout << "You made " << numWrongAnswers << " mistake(s)." << endl;
    if (numCorrectAnswers > numWrongAnswers) cout << "Great job!" << endl;
    else cout << "You will do better next time..." << endl;
}
