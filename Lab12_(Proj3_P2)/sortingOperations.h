/* File: sortingOperations.h
 * Course: CS216-00x
 * Project: Lab12 (as part of Project 3)
 * Purpose: the declaration of two functions to provide sorting operations.
 *
 *** DO NOT CHANGE THIS FILE ***
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "card.h"
#include "deck.h"
#include "term.h"
#include "SortingList.h"

using namespace std;

// sort five-card in hand in both ascending and descending orders by card points respectively
void sortCards();

// provide the prefix matching
// prefix is defined as the string from user input
// prefix matching is to find all the terms in which each query starts exactly with the prefix
// then sort the matched terms in lexicographic order by query
// then sort the matched terms in descending order by weight
void sortTerms();


