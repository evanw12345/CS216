/* 
 * File:   gradebook.cpp
 * Course: CS216
 * Project: Lab4
 * Purpose: provide the implementation of the member functions of gradebook class
 *
 * Author: Evan Wells
 *
 */
#include <iostream>
#include "gradebook.h"
#include <iomanip>

// default constructor
gradebook::gradebook()
{
    // do nothing
    // vector class from STL provide default constructor
}

// return the size of the gradebook
int gradebook::getSize() const
{
    return scores.size();
}

// insert a score into the tail of the gradebook
void gradebook::insert(double score)
{
    scores.insert(scores.end(), score);
}

// return the maximum score among all scores in the gradebook
double gradebook::getMax() const
{
    double max = 0;
    for (int i = 0; i < scores.size(); i++){
        if (scores[i] > max){
            max = scores[i];
        }
    }
    return max;
}

// return the minimum score among all scores in the gradebook
double gradebook::getMin() const
{
    double min = scores[0];
    for (int i = 0; i < scores.size(); i++){
        if (min > scores[i]){
            min = scores[i];        
        }
    }
    return min;
}

// return the average score among all scores in the gradebook
double gradebook::getAverage() const
{
    double sum, averageScore;
    for (int i = 0; i < scores.size(); i++){
        sum += scores[i];
    }
    averageScore = sum/scores.size();
    return averageScore;
}

// each score in the gradebook will be increased by the given value 
// If the score reaches MAX_SCORE, it does not go beyond
void gradebook::incrementScore(double value)
{ 
    for (int i = 0; i < scores.size(); i++){
        scores[i] += value;
        if(scores[i] > MAX_SCORE){
            scores[i] = MAX_SCORE;
        }
    }
}

// print the scores in the gradebook
// in the following format: (Score No.:    value)
// For example:
// Score 1:    78.50
// Score 2:    90.00
// Score 3:    87.00
void gradebook::print() const
{
    for (int i = 0; i < scores.size(); i++){
        cout << "Score " << i + 1 << ":\t" << right << setprecision(2) << fixed << scores[i] << endl;
    }
}

