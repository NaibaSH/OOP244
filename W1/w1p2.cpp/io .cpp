/*
*                                     OOP244 Workshop1 # p2:
* Name: Naiba Shabanova
* StudentEmail: nshabanova@myseneca.ca
* StudentID: 164598229
* Section : ZCC
* Date: Jan 21, 2024
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.

*/

#include <iostream>
#include "io.h" 
#include <iomanip>
using namespace std;

namespace seneca {

    void printInt(int value, int fieldWidth) {
        cout << value;
        for (int i = 0; i < fieldWidth - intDigits(value); i++) {
            cout << " ";
        }
    }

    int intDigits(int value) {
        int count = (value == 0);
        while (value != 0) {
            value /= 10;
            ++count;
        }
        return count;
    }

    // Performs a fool-proof integer entry
    int getInt(int min, int max) {
        int val = min - 1;
        bool done = false;
        while (!done) {
            cin >> val;
            if (val < min || val > max) {
                cout << "Invalid value!" << endl << "The value must be between " << min << " and " << max << ": ";
            }
            else {
                done = true;
            }
        }
        return val;
    }

    // moves the cursor backwards
    void goBack(int n) {
        for (int i = 0; i < n; cout << "\b", i++);
    }

    // displays the user interface menu
    int menu(int noOfSamples) {
        line(28);
        cout << "| No Of Samples: ";
        printInt(noOfSamples, 5);
        cout << "     |" << endl;
        line(28);
        cout << "| 1- Set Number of Samples |" << endl;
        cout << "| 2- Enter Samples         |" << endl;
        cout << "| 3- Graphs                |" << endl;
        cout << "| 0- Exit                  |" << endl;
        cout << "\\ >                        /";
        goBack(24);

        return getInt(0, 3);
    }

    // draw line
    void labelLine(int n, const char* label) {
        cout << "+";
        for (int i = 0; i < n + 2; cout << "-", i++);
        cout << "+";
        if (label) {
            goBack(n);
            cout << label;
        }
        cout << endl;
    }

    void line(int n) {
        cout << "+";
        for (int i = 0; i < n + 2; cout << "-", i++);
        cout << "+";
        cout << endl;
    }

}