/*
 * course: CS216-00x
 * Project: Lab 5
 * Purpose: this program repeatedly allows the user
 *         to practice THREE basic math operations: + - and *
 *         until the user chooses to quit the program
 *         it generates a two-digit integer as the first operand: at the range of [10,99]
 *         it then generates a single digit integer num2 as the second operand: at the range of [1,9]
 *         it then asks the user to enter the answer to three questions:
 *         (1)num1 + num2; 
 *         (2)num1 - num2; (it guarantees that the correct answer is not negative, why?)
 *         (3)num1 * num2
 *         Please note that this version of the program makes a simple assumption that the user input is always "good data"
 *         However you will work on this Lab assignment and create your version of the program: it should allow the user to try again and agian, until the user input is a valid integer
 *         if the answer is correct, a message of congratulations should be printed;
 *         if the answer is not correct, a message should be printed showing the correct answer.
 *Author: Evan Wells
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>   // for the transform() function
#include <string>
#include "MathOperations.h"

using namespace std;

// declare global variable (constant only, avoid using global variable!)
const int LEN = 2;  // represents the length of a array: to store one character and one terminator

string toUpper(const string &original);
string toUpper_recursive(const string &original);
void collectAnswer(const MathOperations& question);

int main()
{
    // define constants for the ranges of two operands
    const int OP1MIN = 10;   // Minimum value of the first operand
    const int OP1MAX = 99;   // Maximum value of the first operand
    const int OP2MIN = 1;    // Minimum value of the second operand
    const int OP2MAX = 9;    // Maximum value of the second operand

    int num1;          // The first operand for the operations
    int num2;          // The second operand for the operations
    string choice;     // The user's choice: either answer the question or quit

    // Seed the random number generator.
    srand(time(0));

    cout << "Do you want to practice three basic math operations?" << endl;
    cout << "Press Enter to continue or press  N(o) to quit...";
    getline(cin, choice);
    // covert the string stored in choice into all uppercase
    // by calling toUpper() function 
    choice = toUpper(choice);

    while (choice != "N" && choice!= "NO")
    {  
        MathOperations question;
        // Generate a two-digit number at the range of [10,99] as the first operand
        num1 = OP1MIN + rand() % (OP1MAX - OP1MIN + 1);
        // Generate a single digit number at the range of [1,9] as the second operand
        num2 = OP2MIN + rand() % (OP2MAX - OP2MIN + 1);

        question.setOperands(num1, num2);

        // With the same operands: num1 and num2
        // (1)Produce an addition question
        // (2)Produce a substraction question
        // (3)Produce a multiplication question
        question.Addition();
        question.print();
        collectAnswer(question);

        question.Subtraction();
        question.print();
        collectAnswer(question);

        question.Multiplication();
        question.print();
        collectAnswer(question);

        cout << "Do you want to practice three basic math operations?" << endl;
        cout << "Press Enter to continue or press  N(o) to quit...";
        getline(cin, choice);
        // covert the string stored in choice into all uppercase
        // by calling toUpper_recursive() function 
        choice = toUpper_recursive(choice);
    }

    cout << "Thank you for practicing Basic Math Operations." << endl;
    return 0;
}


/*
 * Returns the string which transforms each character of the parameter into upper case
 * @param original: the original string
 *  const call by reference (no copy is made for efficiency, safe to the argument)
 * @return a new string which transforms each character of the parameter into upper case
 *  (algorithm header file is needed for the definition of transform function)
 */
string toUpper(const string &original)
{
    string result = original;
    transform(original.begin(), original.end(), result.begin(), ::toupper);
    return result;
}

/*
 * It is a recursive function.
 * Returns the string which transforms each character of the parameter into upper case
 * @param original: the original string
 *  const call by reference (no copy is made for efficiency, safe to the argument)
 * @return a new string which transforms each character of the parameter into upper case
 */
string toUpper_recursive(const string &original)
{
    static int fcount = 0; // use a static variable to count how many times the function is called
    fcount++;   // increase count by one while calling the function
    cout << "Calling the recursive function " << fcount  << " times." << endl;
    // Base case:
    if (original.length() == 0)
        return original;
    // Recursive case:
    string first = original.substr(0,1);
    const char* front = first.c_str();
    char upperFront[LEN];
    string result;
    upperFront[0] = toupper(front[0]);
    upperFront[1] = '\0';
    result = upperFront;
    return result + toUpper_recursive(original.substr(1, original.length()-1));
}

/* pass an object using const call by reference
 * (no copy is made for efficiency and no side-effect, safe to the argument)
 */
void collectAnswer(const MathOperations& question)
{
    int studentAnswer; // The student's answer
    cout << "Please type your answer: " << endl;
    //TA DA, USER VALIDATION BELOW
    while (!(cin >> studentAnswer)) {
        cout << "Invalid input! Please try again..." << endl;
        cout << "Please type your answer: " << endl; 
        cin.clear();
        cin.ignore(256, '\n');
    }
    question.checkAnswer(studentAnswer); 
    cin.ignore(256, '\n');
    
    // Assume that the user input is always valid
    // No user-input validation!!!
    // get the valid integer input, then check if it is correct


    if (question.checkAnswer(studentAnswer))
        cout << "Congratulations! " << studentAnswer << " is the right answer." << endl;
    else
        cout << "Sorry, the correct answer is " << question.getAnswer() << "." << endl;
}
