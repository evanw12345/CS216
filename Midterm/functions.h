/* File: function.h
 * Course: CS216-00x
 * Project: midterm
 * Purpose: the declaration(prototype) of two functions.
 *** DO NOT CHANGE THIS FILE ***
 *
 */
#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <vector>

using namespace std;

// insert the integer item from the second parametre into the vector
// and this item becomes the first data item in the vector
// call by reference so that the change is applied to the argument
void insertAtFront(vector<int>& vecA, int item);

// A run is a sequence of adjacent repeated data items.
// return the length of the longest run in a sequence stored in the vector nums, as the parameter
int run_length(const vector<int>& nums);

#endif	/* FUNCTIONS_H */

