/* 
 * Course: CS216-00x
 * Project: Coding Questions for Final Exam
 * Purpose: Provide the testing of the solutions to coding questions for Final Exam
 *** DO NOT CHANGE THIS FILE ***
 *
 */
#include <iostream>
#include <string>
#include <set>
#include "functions.h"

using namespace std;

int main()
{
    const int NUM_OF_ELEMENTS = 10;
    const int NKEY = 5;
    const string WKEY = "CS216";

    int nums[NUM_OF_ELEMENTS] = {9, 2, 5, 2, 5, 7, 3, 3, 4, 5};
    string words[NUM_OF_ELEMENTS] = {"CS215", "Unix", "Virtual Machine", "CS216", "CS215", "Linux", "Vim", "CS216", "GDB", "Templates"};

    vector<int> intV1, intV2;
    vector<string> strV1, strV2;
    set<int> is, it;
    set<string> ss, st;

    for (int i = 0; i < NUM_OF_ELEMENTS; i++)
    {
        intV1.push_back(nums[i]);
        strV1.push_back(words[i]);
    }

    //calling DoNotCopyKey function
    DoNotCopyKey(intV1, intV2, NKEY);
    DoNotCopyKey(strV1, strV2, WKEY);

    // display elements in two integer vectors respectively
    cout << endl;
    cout << "The elements in intV1:" << endl;
    for (int i =0; i < intV1.size(); i++)
    {
        cout << intV1.at(i) << "  ";
        is.insert(intV1.at(i));
    }
    cout << endl;

    cout << "The elements in intV2:" << endl;
    for (int i =0; i < intV2.size(); i++)
    {
        cout << intV2.at(i) << "  ";
        it.insert(intV2.at(i));
    }
    cout << endl;

    // display elements in set is:
    cout << "set is contains: " << endl;
    cout << "{ ";

    for (auto itis = is.begin(); itis != is.end(); itis++)
    {   
        cout << *itis << "  ";
    }
    cout << " }" << endl;

    // display elements in set it:
    cout << "set it contains: " << endl;
    cout << "{ ";

    for (auto itit = it.begin(); itit != it.end(); itit++)
    {   
        cout << *itit << "  ";
    }
    cout << " }" << endl;

    // display elements in the intersection of is and it:
    set<int> interS = is ^ it;
    cout << "The intersection of is and it: " << endl;
    cout << "{ ";

    for (auto itin = interS.begin(); itin != interS.end(); itin++)
    {   
        cout << *itin << "  ";
    }
    cout << " }" << endl;
    
    // display elements in the symmetric difference of s and t:
    // by calling function symmetric_diff1()
    set<int> sym_diff = symmetric_diff(is, it);
    cout << "The symmetric difference of is and it: " << endl;
    cout << "{ ";

    for (auto itsy = sym_diff.begin(); itsy != sym_diff.end(); itsy++)
    {   
        cout << *itsy << "  ";
    }
    cout << " }" << endl;
    
    // display elements in two string vectors respectively
    cout << endl;
    cout << "The elements in strV1:" << endl;
    for (int i =0; i < strV1.size(); i++)
    {
        cout << strV1.at(i) << "  ";
        ss.insert(strV1.at(i));
    }
    cout << endl;

    cout << "The elements in strV2:" << endl;
    for (int i =0; i < strV2.size(); i++)
    {
        cout << strV2.at(i) << "  ";
        st.insert(strV2.at(i));
    }
    cout << endl;

    // display elements in set ss:
    cout << "set ss contains: " << endl;
    cout << "{ ";

    for (auto itss = ss.begin(); itss != ss.end(); itss++)
    {   
        cout << *itss << "  ";
    }
    cout << " }" << endl;

    // display elements in set st:
    cout << "set st contains: " << endl;
    cout << "{ ";

    for (auto itst = st.begin(); itst != st.end(); itst++)
    {   
        cout << *itst << "  ";
    }
    cout << " }" << endl;

    // display elements in the intersection of ss and st:
    set<string> interSS = ss ^ st;
    cout << "The intersection of ss and st: " << endl;
    cout << "{ ";

    for (auto itin = interSS.begin(); itin != interSS.end(); itin++)
    {   
        cout << *itin << "  ";
    }
    cout << " }" << endl;
    
    // display elements in the symmetric difference of s and t:
    // by calling function symmetric_diff1()
    set<string> sym_diffS = symmetric_diff(ss, st);
    cout << "The symmetric difference of ss and st: " << endl;
    cout << "{ ";

    for (auto itsy = sym_diffS.begin(); itsy != sym_diffS.end(); itsy++)
    {   
        cout << *itsy << "  ";
    }
    cout << " }" << endl;
    return 0;
}


