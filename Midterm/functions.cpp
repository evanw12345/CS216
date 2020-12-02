/* File: function.cpp
 * Course: CS216-001
 * Project: Midterm Exam
 * Purpose: the implementation of two functions.
 * Author: Evan Wells 
 *
 */
#include "functions.h"

// insert the integer item from the second parametre into the vector
// and this item becomes the first data item in the vector
// call by reference so that the change is applied to the argument
void insertAtFront(vector<int> &vecA, int item) { vecA.insert(vecA.begin(), item); }

// A run is a sequence of adjacent repeated data items.
// return the length of the longest run in a sequence stored in the vector nums, as the parameter
int run_length(const vector<int> &nums) {
    int runLength = 0;     // Stores the length of the run
    int currentLength = 1; // Stores the current length of the run
                           // Note:
                           // This value is equal to one because in
                           // testing, the runLength was off by one.
                           // Making the currentLength equal to one fixed this
                           // and yielded the correct output
    if (nums.size() == 0) runLength = 0; // When there are no inputs from the user
    else if (nums.size() == 1) runLength = 1; // When there is only one input from the use
    else { // When there are n > 1 inputs from the user
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                currentLength++;
            }
            else currentLength = 1; // Same note as line 20
            if (currentLength > runLength) {
                runLength = currentLength;
            }
        }
    }
    return runLength;
}
