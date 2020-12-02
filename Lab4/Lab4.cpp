/*
 *Course: CS216-00x
 *Project: Lab Assignment 4
 *Purpose: to implement a Grade Curve Calculator
 *         it allows the user to curve the scores based on the expected average.
 *         each student's score is at the range [0,100]
 *         the expected average is at the range [original average, 100]
 *****PLEASE DO NOT CHANGE THIS FILE*****
 */

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <string>
#include <cmath>        // std::abs
#include "gradebook.h"

using namespace std;

int main()
{
    const int SCALE_TO = 100;
	gradebook CS216gradebook_original;
	double input_score;

	while (true)
	{
	    cout << "Please enter a score for CS216 (type 'Q' or 'q' to quit): " << endl;
		cin >> input_score;
		cin.ignore(256, '\n');

		// check if the user input is invalid
		if (cin.fail())
		{
			string check_input;
			cin.clear();
			cin >> check_input;
            cin.ignore(256, '\n');
			if (check_input == "Q" || check_input == "q")
				break;
			else {
				cout << "Invalid input, please try again..." << endl;
				continue;
			}
		}

		// check if the input score is in the correct range: [0,100]
		if (input_score < 0 || input_score > 100)
		{
			cout << "The score is not in the correct range, please try again..." << endl;
		}
		else  // valid user input, store into gradebook object
		    CS216gradebook_original.insert(input_score);
	}

	// Implement a Grade Curve Calculator:
    // Display the average score, the highest and lowest scores from the original gradebook, then
	// Ask the user to type a "Expected Average" score if the grade book is not empty
	// Apply the "scale to Expected Average" method for the Grade Curve Calculator
	// Since any score cannot be larger than MAX_SCORE, 
	// the "Actual Average" can be less than or equal to "Expected Average"
	// Quit the Grade Curve Calculator until the user enters "Q" or "q"
	while (CS216gradebook_original.getSize()!= 0)
	{
		double expected_avg;
        cout << fixed << setprecision(2);
        cout << endl << endl;
        cout << "The original average score is:\t" << CS216gradebook_original.getAverage() << endl;
        cout << "Please enter your expected average score to curve (type 'Q' or 'q' to quit): " << endl;
		cin >> expected_avg;
		cin.ignore(256, '\n');

		// check if the user input is invalid
		if (cin.fail())
		{
			string check_input;
			cin.clear();
			cin >> check_input;
            cin.ignore(256, '\n');
			if (check_input == "Q" || check_input == "q")
				break;
			else {
				cout << "Invalid input, please try again..." << endl;
				continue;
			}
		}

		// check if the input average is in the correct range: [0,100]
		double diff = expected_avg - CS216gradebook_original.getAverage();
		const double DIFF = 1.0e-2;
        if (abs(diff) < DIFF)
		    cout << "The scores are perfect, no need for the grading curve!" << endl;
        else
        {
            if (diff < 0 || expected_avg > 100)
		    {
			    cout << "The expected average is not in the correct range, please try again..." << endl;
		    }
		    else  // valid user input, adjust scores based on the expected average
		    {
				gradebook CS216gradebook_curved = CS216gradebook_original;
				CS216gradebook_curved.incrementScore(diff);
				cout << "The original gradebook for CS216: " << endl;
				CS216gradebook_original.print();
				cout << "The number of scores is:\t" << CS216gradebook_original.getSize() << endl;
                cout << "The maximum score is:\t" << CS216gradebook_original.getMax() << endl;
                cout << "The minimum score is:\t" << CS216gradebook_original.getMin() << endl;
				cout << "The original average score is:\t" << CS216gradebook_original.getAverage() << endl;
				cout << endl << endl;
				cout << "The expected average score is:\t" << expected_avg << endl;
				cout << "The curved gradebook for CS216: " << endl;
				CS216gradebook_curved.print();
				cout << "The number of scores is:\t" << CS216gradebook_curved.getSize() << endl;
                cout << "The maximum score is:\t" << CS216gradebook_curved.getMax() << endl;
                cout << "The minimum score is:\t" << CS216gradebook_curved.getMin() << endl;
				cout << "The actual average score is:\t" << CS216gradebook_curved.getAverage() << endl;
			}
		}
	}
	cout << "Thank you for using the Grade Curve Calculator." << endl;
	return 0;
}

