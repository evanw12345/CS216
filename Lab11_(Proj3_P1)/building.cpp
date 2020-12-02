#include <iomanip>
#include "building.h"

// default constructor
Building::Building()
{
    name = "";
    ID = 0;
    coordinate = "";
}

// alternate constructor
Building::Building(string name, int id, string position)
{
    this->name = name;
    ID = id;
    coordinate = position;
}

// return the current value of name
string Building::get_Name() const
{
    return name;
}

// return the current value of ID
int Building::get_ID() const
{
    return ID;
}

// return the current value of coordinate
string Building::get_Coordinate() const
{
    return coordinate;
}

// compares the two buildings in lexicographic order but using only the first r characters of each building name
int Building::compareByPrefix(const Building &b1, const Building &b2, int r)
{
    string first = "", second = ""; // Strings to hold the first "r" characters of the names of "b1" and "b2"
                                    // "first" represents "b1" and "second" represents "b2"
    for (int i = 0; i < r; i++)
    {
        first += b1.name[i];
        second += b2.name[i];
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

// compare the two Building objects in ascending order by ID
// if the order of B1 and B2 are in ascending order by ID, return 1
// if B1 and B2 are of the same ID, return 0
// otherwise return -1
int Building::compareByID(const Building &B1, const Building &B2)
{
    if (B1.ID < B2.ID)
    {
        return 1;
    }

    if (B1.ID == B2.ID)
    {
        return 0;
    }

    else
        return -1;
}

// compare the two Building objects in reversed lexicographic order by coordinate
// if the order of B1 and B2 are in reversed lexicographic order by coordinate, return 1
// if B1 and B2 are of the same coordinate, return 0
// otherwise return -1
int Building::compareByReverseCoordinate(const Building &B1, const Building &B2)
{
    if (B1.coordinate > B2.coordinate)
    {
        return 1;
    }
    else if (B1.coordinate == B2.coordinate)
    {
        return 0;
    }
    else
        return -1;
}

// operator overloading for operators "<" and "<<"
// one (< operator) defined as member function;
// another one (<< operator) defined as friend function

// define the operator "<" for Building class
// which is defined as in lexicographic order by building name
bool Building::operator<(const Building &other)
{
    if (name < other.name)
    {
        return true;
    }
    else
        return false;
}

// define the operator "<<" for Building class
// to send the Building object to the cout, in the following format:
// name (ID: four-digit ID) ---> coordinate
ostream &operator<<(ostream &out, const Building &b)
{
    out << b.name << "\t( ID: " << setfill('0') << setw(DIGITS) << b.ID << " ) ---> " << b.coordinate;
    return out;
}