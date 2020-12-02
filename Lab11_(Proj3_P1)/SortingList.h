/* File: SortingList.h
 * Course: CS216-00x
 * Project: Lab11 (as the first part of Proejct 3)
 * Purpose: the declaration for the SortingList class.
 *          it stores a sequence of Building objects to perform sorting operation
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef SORTINGLIST_H
#define	SORTINGLIST_H

#include <vector>
#include <string>
#include "building.h"

using namespace std;

class SortingList
{
   public:
    // inserts the newbuilding to the end of the current vector   
    void insert(Building newbuilding);

    // return how many items in the list
    int size();

    // operator overloading for "[]"
    // provide the direct access by index number
    Building& operator[](int index);

    // sort all items in ascending order 
    // the items are compared using operator "<"
    // using sort() from standard library
    void sort();

    // provide different sorting algorithms 
    // based on comparison defined by the function passing in as parameter
    
    // apply selection sorting algorithm
    void selection_sort(int (*compare)(const Building& b1, const Building& b2));

    // apply bubble sorting algorithm
    void bubble_sort(int (*compare)(const Building& b1, const Building& b2));

    // apply merge sorting algorithm
    void merge_sort(int (*compare)(const Building& b1, const Building& b2));

    // apply shuffle algorithm
    void shuffle();

    // display all the items in the sequence
    void print();
    
   private:
    vector<Building> items;

    // helper functions
    void merge(int first, int mid, int last, int (*compare)(const Building& b1, const Building& b2));
    void merge_sortHelper(int min, int max, int (*compare)(const Building& b1, const Building& b2));
};


#endif	/* SORTINGLIST_H */

