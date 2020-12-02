/*
 * Course: CS216-00x
 * Project: Lab 11 (as first part of Project 3)
 * Purpose: repeatedly ask the user to type prefix to match
 *          then display the matched buildings in three orders:
 *          in lexicographic order by building names;
 *          in ascending order by building IDs (four-digit numbers);
 *          in reversed lexicographic order by building coordinates.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "building.h"
#include "SortingList.h"

using namespace std;

int main(int argc, char** argv) 
{
    const int ARGUMENTS = 2;
    
    // check the command line argument, an input file name is needed
    if (argc != ARGUMENTS)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }    
    
    // check if the input file can be opened successfully
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.good())
    {
        cout << "Cannot open the file named " << argv[1] << endl;
        return 2;
    }  
    
    // Read data from the file and store into the SortingList object
    // Assume "good data" from the file
    SortingList UKY_buildingList;
    string line;  // to store each complete text line from the file
    while (!infile.eof())
    {
        getline(infile, line);
        string name, position;
        int ID;
        istringstream iss(line);
        getline(iss, name, '\t');

        // separate the rest part into ID and coordinate in the map, and also extra white space
        iss >> ws >> ID >> ws >> position;

        if (name != "")  // avoid extra line from input file
        {    
            Building newbuilding(name, ID, position);
            UKY_buildingList.insert(newbuilding);
        }    
    }    
    // close the file after finishing reading data from
    infile.close(); 

    string prefix;
    cout << "Please input the building name to search(type \"exit\" to quit): " << endl;
    getline(cin, prefix);
    
    while (prefix != "exit")
    {
        // create a Building object from given prefix, ID is 0, coordinate is empty string
        Building toMatch(prefix, 0, "");

        // create a SortingList object named matchedBuildings to store the prefix-match buildings
        SortingList matchedBuildings;
        // use sequential search (linear search) to find the matched buildings
        for (int i = 0; i < UKY_buildingList.size(); i++)
        {
            if (Building::compareByPrefix(UKY_buildingList[i], toMatch, prefix.length()) == 0)
                matchedBuildings.insert(UKY_buildingList[i]);
        }
        
        if (matchedBuildings.size() == 0)
            cout << "No matched building name!" << endl;
        else //found matched buildings
        {
            // sort the matched buildings in lexicographic order by building name
            cout << endl << "The matched buildings are in lexicographic order by building name: " << endl;
            matchedBuildings.sort();
            matchedBuildings.print();

            // sort the matched buildings in ascending order by building ID
            cout << endl << "The matched buildings are in ascending order by building ID: " << endl;
            // pass in the function name directly
            matchedBuildings.merge_sort(&Building::compareByID);
            /* //another way: to declare a function pointer
            int (*compare)(const Building& b1, const Building& b2);
            compare = &Building::compareByID;
            matchedBuildings.merge_sort((*compare));
            */
            matchedBuildings.print();
            
            // sort the matched buildings in reversed lexicographic order by building coordinate
            cout << endl << "The matched buildings are in reversed lexicographic order by building coordinate: " << endl;
            // pass in the function name directly
            matchedBuildings.merge_sort(&Building::compareByReverseCoordinate);
            /* //another way: to declare a function pointer
            int (*compare)(const Building& b1, const Building& b2);
            compare = &Building::compareByReverseCoordinate;
            matchedBuildings.merge_sort((*compare));
            */
            matchedBuildings.print();
        }

        cout << "Please input the building name to search(type \"exit\" to quit): " << endl;
        getline(cin, prefix);
    }    

    return 0;
}

