/*
 * course: CS216-001
 * Project: Lab 6 (as part of Project 1)
 * Purpose: this program can be used as a math tutor for a young student.
 *          it repeatedly allow the user to practice solving Multiplication questions untill the user clicks "q" or "Q" to stop
 *          when the practice for the user stops, this program generates the report:
 *          (1) the list of questions with correct answers which the user has practiced;
 *          (2) the total number of questions the user has solved;
 *          (3) the total number of mistakes the user has made;
 *          (4) display either "Great job!"(if (2) > (3)) or "You will do better next time..." (otherwise)
 *          it then quits the program.
 * Author: Evan Wells
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

int main()
{
    string choice;     // The user's choice: either answer the question or quit
    MathReport userReport;  // The user report for using Math Tutor program

    // Seed the random number generator.
    srand(time(0));

    cout << "\tMonth-at-a-Glance (MAAG) of September" << endl;
    cout << "\tMath Is Fun! Try to solve Multiplication problems..." << endl;
    cout << "\tPress Enter to continue; Press Q(or q) to quit ";
    getline(cin, choice);

    while (choice != "Q" && choice != "q")
    {
        int num1;          // The first random number
        int num2;          // The second random number
        int studentAnswer; // The student's answer
        MathOperations question; // the question for user to solve

        // Generate two random numbers: 
        // The first one is in the range of [1, 100];
        // The second one is in the range of [1 - 9].
        num1 = 1 + rand() % 100;   
        num2 = 1 + rand() % 9;
        question.setOperands(num1, num2);
        question.Multiplication();
        // Display the problem.
        question.print();
        cout << "Your answer is: ";
        cin  >> studentAnswer;
        cin.ignore(256, '\n');

        // user input validation
        // if the user input is invalid, allow the user to try again
        while (cin.fail())
        {
            cin.clear(); // reset the status to "good"
            cin.ignore(256, '\n'); // clean the leftover in the pipe
            cout << "Invalid input! Please try again..." << endl;
            cout << "Your answer is: ";
            cin  >> studentAnswer;
            cin.ignore(256, '\n');
        }

        // when the user input is valid
        // check if it is the correct answer
        if (question.checkAnswer(studentAnswer))
            cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
        else
            cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;

        //add the current question and the user answer into the user report
        userReport.insert(question, studentAnswer);

        cout << "\tMonth-at-a-Glance (MAAG) of September" << endl;
        cout << "\tMath Is Fun! Try to solve Multiplication problems..." << endl;
        cout << "\tPress Enter to continue; Press Q(or q) to quit ";
        getline(cin, choice);
    } 

    // generate the user report for using Math Tutor
    cout << endl;
    userReport.generateReport();
    cout << "Thank you for using Math Tutor." << endl;
    return 0;
}
