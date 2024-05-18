/*/////////////////////////////////////////////////////////////////////////
                        Workshop-3 Part-1
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 03/02/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include "Utils.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace seneca {

    // Implement the utility functions here

    // A safe string input function
    void readString(char* str, int maxLen) {
        if (str != nullptr && maxLen > 0) {
            cin.getline(str, maxLen);
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
    }

    // You can add more utility functions as needed

}

