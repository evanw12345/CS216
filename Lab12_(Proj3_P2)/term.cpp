// Implementation of function term
// Author: Evan Wells
// CS216-001

#include <iostream>
#include "term.h"

// default constructor
Term::Term()
{
    query = "";
    weight = 0;
}

// initializes a term with the given query string and weight
Term::Term(string query, long weight)
{
    this->query = query;
    this->weight = weight;
}

// compares the two terms in descending order by weight
// if the order of T1 and T2 in descending order by weight, return 1;
// if T1 and T2 are of the same weight, return 0;
// otherwise return -1
int Term::compareByWeight(const Term &T1, const Term &T2)
{
    if (T1.weight > T2.weight)
    {
        return 1;
    }
    else if (T1.weight == T2.weight)
    {
        return 0;
    }
    else
        return -1;
}

// compares the two terms in lexicographic order but using only the first r characters of each query
int Term::compareByPrefix(const Term &T1, const Term &T2, int r)
{
    string first = "", second = ""; // Strings to hold the first "r" characters of the queries of "T1" and "T2"
                                    // "first" represents "T1" and "second" represents "T2"
    for (int i = 0; i < r; i++)
    {
        first += T1.query[i];
        second += T2.query[i];
    }

    if (first < second)
    {
        return 1;
    }
    else if (first == second)
    {
        return 0;
    }
    else
        return -1;
}

// operator overloading for operators "<" and "<<"
// they are defined as friend functions

// define the operator "<" for Term class
bool operator<(const Term &T1, const Term &T2)
{
    if (T1.query < T2.query)
    {
        return true;
    }
    else
        return false;
}

// define the operator "<<" for Term class
// to send the Term object to the cout, in the following format:
// the weight, followed by a tab key, followed by the query
ostream &operator<<(ostream &out, const Term &t)
{
    out << t.weight << "\t" << t.query;
    return out;
}