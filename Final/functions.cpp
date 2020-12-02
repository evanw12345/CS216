/* File: function.cpp
 * Course: CS216-001
 * Project: Coding Questions for Final Exam
 * Purpose: Provide the implementation of three functions.
 * Author: (Evan Wells)
 *
 */
#ifndef FUNCTIONS_CPP
#define FUNCTIONS_CPP

#include "functions.h"

//your implementation should start here...
// template function
// copy all elements which does not match key
// from vA to vB
template <typename T>
void DoNotCopyKey(const vector<T> &vA, vector<T> &vB, T key)
{
    for (int i = 0; i < vA.size(); i++)
    {
        if (vA[i] != key)
        {
            vB.push_back(vA[i]);
        }
    }
}

// template function
// define the operator "^" as the intersection of set s and set t
// the intersection of two sets is formed by the eleemnts that are present in both sets
template <typename T>
set<T> operator^(const set<T> &s, const set<T> &t)
{
    set<T> intersection;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        if (t.count(*i) != 0)
        {
            intersection.insert(*i);
        }
    }
    return intersection;
}

// template function
// it returns the symmetic difference of set s and set t
// the symmetric difference of two sets is formed by the elements that are present in one of the sets, but not in the other
template <typename T>
set<T> symmetric_diff(const set<T> &s, const set<T> &t)
{
    set<T> symmDiff;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        if (t.count(*i) == 0)
        {
            symmDiff.insert(*i);
        }
    }
    for (auto i = t.begin(); i != t.end(); i++)
    {
        if (s.count(*i) == 0)
        {
            symmDiff.insert(*i);
        }
    }
    return symmDiff;
}

#endif /* FUNCTIONS_CPP */
