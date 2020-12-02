/* File: term.h
 * Course: CS216-00x
 * Project: Lab12 (as part of Project 3)
 * Purpose: the declaration for the Term class.
 *** DO NOT CHANGE THIS FILE ***
 *
 */
#ifndef TERM_H
#define	TERM_H

#include <string>

using namespace std;

class Term
{
    public:
        // default constructor
        Term();

        // initializes a term with the given query string and weight
        Term(string query, long weight);

        // compares the two terms in descending order by weight
        // if the order of T1 and T2 in descending order by weight, return 1;
        // if T1 and T2 are of the same weight, return 0;
        // otherwise return -1
        static int compareByWeight(const Term& T1, const Term& T2);

        // compares the two terms in lexicographic order but using only the first r characters of each query
        static int compareByPrefix(const Term& T1, const Term& T2, int r);

        // operator overloading for operators "<" and "<<"
        // they are defined as friend functions

        // define the operator "<" for Term class
        friend bool operator<(const Term& T1, const Term& T2);

        // define the operator "<<" for Term class
        // to send the Term object to the cout, in the following format:
        // the weight, followed by a tab key, followed by the query
        friend ostream& operator<<(ostream &out, const Term& t);

    private:
        string query;
        long weight;
};

#endif	/* TERM_H */

