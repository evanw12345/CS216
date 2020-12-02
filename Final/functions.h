/* File: function.h
 * Course: CS216-00x
 * Project: Coding Questions for Final Exam
 * Purpose: the declaration(prototype) of three functions.
 *** DO NOT CHANGE THIS FILE ***
 *
 */
#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#include <vector>
#include <set>

using namespace std;

// template function
// copy all elements which does not match key
// from vA to vB
template <typename T>
void DoNotCopyKey(const vector<T>& vA, vector<T>& vB, T key);

// template function
// define the operator "^" as the intersection of set s and set t
// the intersection of two sets is formed by the eleemnts that are present in both sets
template <typename T>
set<T> operator^(const set<T>& s, const set<T>& t);

// template function
// it returns the symmetic difference of set s and set t
// the symmetric difference of two sets is formed by the elements that are present in one of the sets, but not in the other
template <typename T>
set<T> symmetric_diff(const set<T>& s, const set<T>& t);

#endif	/* FUNCTIONS_H */
#include "functions.cpp"
