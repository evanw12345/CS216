 /* 
 * File:   gradebook.h
 * Course: CS216
 * Project: Lab4
 * Purpose: provide the declaration of the gradebook class
 *         
 *****PLEASE DO NOT CHANG THIS FILE***** 
 *
 */

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <vector>

using namespace std;

const double MAX_SCORE = 100;

class gradebook
{
  public:
    // default constructor
    gradebook();   
    
    // return the size of the gradebook
    int getSize() const;
    
    // insert a score into the end of the gradebook
    void insert(double score);

    // return the maximum score among all scores in the gradebook
    double getMax() const;

    // return the minimum score among all scores in the gradebook
    double getMin() const;
    
    // return the average score among all scores in the gradebook
    double getAverage() const;
    
    // each score in the gradebook will be increased by the given value 
    // If the score reaches MAX_SCORE, it does not go beyond
    void incrementScore(double value);
    
    // print the scores in the gradebook
    void print() const;

  private:
    vector<double> scores;
};

#endif /* GRADEBOOK_H */

