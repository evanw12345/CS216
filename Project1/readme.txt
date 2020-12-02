Project 1 readme.txt 
Evan Wells CS216-001
---------------------
This program prompts the user to choice to choose a type of simple math problem to solve.
1. Addition problem
	-The range of numbers is from 1 - 500 for both operands
2. Subtraction problem
	-The range of numbers is from 1 - 500 for both operands
	-Operand 2 can never be larger than operand 1
3. Multiplication problem
	-Operand 1 has a range of 1 - 100
	-Operand 2 has a range of 1 - 9
4. Quits the program
	-Upon quitting the program, a report of the questions solved is generated. The correct answers are shown for each. The number of correct/wrong answers are also shown

File Descriptions
------------------
MathOperations.h - Class definition for class MathOperations
	-This class sets the operands and the operator for a question
	-Also handles print format for a question
MathOperations.cpp - Methods for class MathOperations

MathReport.h - Class definition for MathReport
	-This class initializes a vector of MathOperations 
	-It keeps track of questions solved, number of correct answers, and number of wrong answers
	-Generates a report detailing the correct answers for each question. The number of correct/wrong answers are also shown
MathReport.cpp - Methods for class MathReport

PA1.cpp - contains main()
	-Contains choice selection 
	-Selects random numbers for operands

How to compile
---------------
Use "g++ PA1.cpp MathOpertions.cpp MathReport.cpp -o Project1" in the command line while inside a directory containing all necessary files.
    (without the quotation marks, " ")
