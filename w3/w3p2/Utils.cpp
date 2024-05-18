/*/////////////////////////////////////////////////////////////////////////
                        Workshop-3 Part-2
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 06/02/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include "Utils.h"

using namespace std;
namespace seneca {
    Utils ut; // 
    int Utils::getInt() {
        int val{};
        cin >> val;
        while (cin.fail()) {
            cout << "Invalid entry, retry\n> ";
            cin.clear();
            cin.ignore(12000, '\n');
            cin >> val;
        }
        //cin.ignore( ); // only one character
        cin.ignore(12000, '\n');
        return val;
    }

    void Utils::getCstr(char* str, size_t len) {
        cin.getline(str, len + 1);
        while (cin.fail()) {
            cout << "Maximum " << len << " chars!, retry\n> ";
            cin.clear();
            cin.ignore(12000, '\n');
            cin.getline(str, len + 1);
        }
    }

    bool Utils::yes() {
        char response{};
        char newline{ };
        //      response = cin.get( );
        cin.get(response);
        cin.get(newline);
        while (newline != '\n' ||
            (response != 'Y' && response != 'y' && response != 'N' && response != 'n')) {
            cout << "Only Y or N are acceptable:\n> ";
            if (newline != '\n') cin.ignore(10000, '\n');
            cin.get(response);
            cin.get(newline);
        }
        return response == 'Y' || response == 'y';
    }
}