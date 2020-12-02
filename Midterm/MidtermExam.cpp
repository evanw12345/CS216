/*Course: CS216-00x
 *Project: Midterm Exam
 *Purpose: To define the following two functions:(described in the Lab7functions.h file)
 *         Function1: insertAtFront()
 *         Function2: run_length()
 *         Repeatedly ask the user to input integers in the range [0, 9] until the user types "Q" to stop typing numbers.
 *         then store all the valid integers into a vector by calling insertAtFront()
 *         Then calculate the length of the longest run in the sequence
 *         sort the numbers in non-decresing order
 *         Then calculate the length of the longest run in the sorted sequence.
 *** DO NOT CHANGE THIS FILE ***
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"

using namespace std;

int main()
{
    const int MAX = 9;   // define the upper range of [0,9]
    const int MIN = 0;   // define the lower range of [0,9]
    int item;            // store the data item from the user
    vector<int> nums;    // store the sequence of data items

    while (true)
    {
        cout << "Please input an integer in the range of [0,9] (type 'Q' or 'q' to quit): " << endl;
        cin >> item;
        cin.ignore(256, '\n');   // get rid of either 256 characters or till reach the end of line, which comes first

        // check if the user input is not valid
        if (cin.fail())
        {
            string check_input;
            cin.clear();
            cin >> check_input;
            if (check_input == "Q" || check_input == "q")
                break;
            else {
                cout << "Invalid input, please try again..." << endl;
                continue;
            }    
        }
        
        // the user input is an integer, but it is not in the range of [0,9]
        if ( item < MIN || item > MAX )
        {
            cout << "The valid integer in the sequence should be in the range of [ " << MIN << " , " << MAX << " ], please try again..." << endl;
            continue;
        } 

        // valid user input item, store into the vector
        cout << "Inserting..." << item << endl;
        insertAtFront(nums, item); 
        cout << "The sequence: " << endl;
        for (int i = 0; i < nums.size(); i++)
            cout << nums.at(i) << " " ;
        cout << endl;
    }      
    
    // calculate the length of the longest run in the vector created above
    int length = run_length(nums);
    cout << "The run length of the sequence is: " << length << endl;        
    
    // sort the numbers in the vector in non-decreasing order
    sort(nums.begin(), nums.end());
    // display the sequence after sorting...
    cout << endl << "Display the sequence after sorting..." << endl;
    for (int i = 0; i < nums.size(); i++)
        cout << nums.at(i) << " ";
    cout << endl;
    // calculate the length of the longest run in the sorted sequence
    length = run_length(nums);
    cout << "The run length of the sorted sequence is: " << length << endl;        

    cout << "Thank you. Bye..." << endl;
    return 0;
}

