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

int main() {
    // Test y=my Fridge and Food functionality here
    // Example:
    Food apple("Apple", 150);
    Fridge myFridge;
    myFridge.addFood(apple);

    myFridge.display(std::cout);

    return 0;
}

