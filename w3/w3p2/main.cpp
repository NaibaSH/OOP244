*/////////////////////////////////////////////////////////////////////////
OOP244 Workshop4 # p1:
Full Name : Naiba Shabanova
Student ID# : 164598229
Email : nshabanova@myseneca.ca
Section : ZCC
Date : 2024 - 02 - 08
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
// main.cpp
#include "Fridge.h"
#include <iostream>

using namespace seneca;
using namespace std;

int main() {
    // Example: Creating Food items
    Food apple("Apple", 150);
    Food banana("Banana", 100);
    Food orange("Orange", 120);

    // Creating a Fridge instance
    Fridge myFridge;

    cout << "Adding Food items to the Fridge:" << endl;
    if (!myFridge.addFood(apple)) {
        cout << "Failed to add Apple" << endl;
    }
    if (!myFridge.addFood(banana)) {
        cout << "Failed to add Banana" << endl;
    }
    if (!myFridge.addFood(orange)) {
        cout << "Failed to add Orange" << endl;
    }

    // Displaying Fridge contents
    cout << "\nFridge Contents:" << endl;
    myFridge.display(cout);

    // Checking if the Fridge is full
    cout << "\nIs the Fridge full? " << (myFridge.fullFridge() ? "Yes" : "No") << endl;

    // Searching for a specific Food item
    const char* searchItem = "Banana";
    cout << "\nIs " << searchItem << " in the Fridge? "
        << (myFridge.findFood(searchItem) ? "Yes" : "No") << endl;

    // Change Fridge model and display again
    myFridge.changeModel("SuperCool 3000");
    cout << "\nFridge Contents after model change:" << endl;
    myFridge.display(cout);

    return 0;
}
