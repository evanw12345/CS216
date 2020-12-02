/* File: building.h
 * Course: CS216-00x
 * Project: Lab 11 (as the first part of Project 3)
 * Purpose: provide the declaration of the class named Building
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#ifndef BUILDING_H
#define	BUILDING_H

#include <iostream>
#include <string>

using namespace std;

const int DIGITS = 4;  // building ID contains 4 digits (may have extra leading 0)

class Building
{
    public:
        // default constructor
        Building();

        // alternate constructor
        Building(string name, int id, string position);

        // return the current value of name
        string get_Name() const;

        // return the current value of ID
        int get_ID() const;

        // return the current value of coordinate
        string get_Coordinate() const;

        // compares the two buildings in lexicographic order but using only the first r characters of each building name
        static int compareByPrefix(const Building& b1, const Building& b2, int r);

        // compare the two Building objects in ascending order by ID
        // if the order of B1 and B2 are in ascending order by ID, return 1
        // if B1 and B2 are of the same ID, return 0
        // otherwise return -1
        static int compareByID(const Building& B1, const Building& B2);

        // compare the two Building objects in reversed lexicographic order by coordinate
        // if the order of B1 and B2 are in reversed lexicographic order by coordinate, return 1
        // if B1 and B2 are of the same coordinate, return 0
        // otherwise return -1
        static int compareByReverseCoordinate(const Building& B1, const Building& B2);

        // operator overloading for operators "<" and "<<"
        // one (< operator) defined as member function;
        // another one (<< operator) defined as friend function

        // define the operator "<" for Building class
        // which is defined as in lexicographic order by building name
        bool operator<(const Building& other);

        // define the operator "<<" for Building class
        // to send the Building object to the cout, in the following format:
        // name (ID: four-digit ID) ---> coordinate
        friend ostream& operator<<(ostream &out, const Building& b);

    private:
        string name;        // building name
        int ID;             // building ID, which is four-digit number (with possible extra leading 0)
        string coordinate;  // building coordinate in the map  
};

#endif	/* BUILDING_H */

