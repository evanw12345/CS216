// Project 1: Evan Wells CS216-001
// This program prompts the user to choice to choose a type of simple math problem to solve.
// 1. Addition problem
// 	-The range of numbers is from 1 - 500 for both operands
// 2. Subtraction problem
// 	-The range of numbers is from 1 - 500 for both operands
// 	-Operand 2 can never be larger than operand 1
// 3. Multiplication problem
// 	-Operand 1 has a range of 1 - 100
// 	-Operand 2 has a range of 1 - 9
// 4. Quits the program
// 	-Upon quitting the program, a report of the questions solved is generated. The correct answers are shown for each. The number of correct/wrong answers are also shown

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MathOperations.h"
#include "MathReport.h"

using namespace std;

int main()
{
    int choice;            // The user's choice: either answer the question or quit
    MathReport userReport; // The user report for using Math Tutor program

    // Seed the random number generator.
    srand(time(0));

    cout << "1. Addition problem" << endl;
    cout << "2. Subtraction problem" << endl;
    cout << "3. Multiplication problem" << endl;
    cout << "4. Quit this program" << endl;
    cin >> choice;
    cin.ignore(256, '\n');

    // user input validation
    // if the user input is invalid, allow the user to try again
    while (cin.fail())
    {
        cin.clear();           // reset the status to "good"
        cin.ignore(256, '\n'); // clean the leftover in the pipe
        cout << "Invalid input! Please try again..." << endl;
        cin >> choice;
        cin.ignore(256, '\n');
    }

    while (choice != 4)
    {
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
        {
            //Addition problem
            if (choice == 1)
            {
                int num1;                // The first random number
                int num2;                // The second random number
                int studentAnswer;       // The student's answer
                MathOperations question; // the question for user to solve

                // Generate two random numbers:
                // The first one is in the range of  [1 - 500];
                // The second one is in the range of [1 - 500].
                num1 = 1 + rand() % 500;
                num2 = 1 + rand() % 500;
                question.setOperands(num1, num2);
                question.Addition();
                // Display the problem.
                question.print();
                cout << "Your answer is: ";
                cin >> studentAnswer;
                cin.ignore(256, '\n');

                // user input validation
                // if the user input is invalid, allow the user to try again
                while (cin.fail())
                {
                    cin.clear();           // reset the status to "good"
                    cin.ignore(256, '\n'); // clean the leftover in the pipe
                    cout << "Invalid input! Please try again..." << endl;
                    cout << "Your answer is: ";
                    cin >> studentAnswer;
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
            }

            //Subtraction problem
            else if (choice == 2)
            {
                int num1;                // The first random number
                int num2;                // The second random number
                int studentAnswer;       // The student's answer
                MathOperations question; // the question for user to solve

                // Generate two random numbers:
                // The first one is in the range of [1, 100];
                // The second one is in the range of [1 - 9].
                num1 = 1 + rand() % 500;
                num2 = 1 + rand() % 500;
                while (num2 > num1)
                {
                    num2 = 1 + rand() % 500;
                }
                question.setOperands(num1, num2);
                question.Subtraction();
                // Display the problem.
                question.print();
                cout << "Your answer is: ";
                cin >> studentAnswer;
                cin.ignore(256, '\n');

                // user input validation
                // if the user input is invalid, allow the user to try again
                while (cin.fail())
                {
                    cin.clear();           // reset the status to "good"
                    cin.ignore(256, '\n'); // clean the leftover in the pipe
                    cout << "Invalid input! Please try again..." << endl;
                    cout << "Your answer is: ";
                    cin >> studentAnswer;
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
            }

            //Multiplication problem
            else if (choice == 3)
            {
                int num1;                // The first random number
                int num2;                // The second random number
                int studentAnswer;       // The student's answer
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
                cin >> studentAnswer;
                cin.ignore(256, '\n');

                // user input validation
                // if the user input is invalid, allow the user to try again
                while (cin.fail())
                {
                    cin.clear();           // reset the status to "good"
                    cin.ignore(256, '\n'); // clean the leftover in the pipe
                    cout << "Invalid input! Please try again..." << endl;
                    cout << "Your answer is: ";
                    cin >> studentAnswer;
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
            }
        }
        else cout << "Invalid input! Please try again..." << endl;

        cout << "1. Addition problem" << endl;
        cout << "2. Subtraction problem" << endl;
        cout << "3. Multiplication problem" << endl;
        cout << "4. Quit this program" << endl;
        cin >> choice;
        cin.ignore(256, '\n');

        // user input validation
        // if the user input is invalid, allow the user to try again
        while (cin.fail())
        {
            cin.clear();           // reset the status to "good"
            cin.ignore(256, '\n'); // clean the leftover in the pipe
            cout << "Invalid input! Please try again..." << endl;
            cin >> choice;
            cin.ignore(256, '\n');
        }
    }

    // generate the user report for using Math Tutor
    cout << endl;
    userReport.generateReport();
    cout << "Thank you for using Math Tutor." << endl;
    return 0;
}
