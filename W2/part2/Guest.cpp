/*/////////////////////////////////////////////////////////////////////////
                        Workshop-2 Part-2
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 29/01/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Guest.h"
using namespace std;

namespace seneca {
    void set(Guest& guest, const char* first, const char* last, int age) {
        
       vacate(guest);

        if (first != nullptr && last != nullptr) {
            guest.m_firstName = new char[strlen(first) + 1];
            strcpy(guest.m_firstName, first);

            guest.m_lastName = new char[strlen(last) + 1];
            strcpy(guest.m_lastName, last);

            guest.m_adult = (age >= 18);
        }
    }

    /// <summary>
    /// Prints the guest name :
    /// "Name Surname(child)"
    /// The child flag is printed if the guest is not an adult
    /// and if the names are not set, "Vacated!" is printed.    
    /// </summary>
    /// <param name="guest">: to print</param>
    void print(const Guest& guest) {
        if (guest.m_firstName != nullptr && guest.m_lastName != nullptr && guest.m_firstName[0] && guest.m_lastName[0] ) {
            cout << guest.m_firstName << " " << guest.m_lastName;
            if (!guest.m_adult) {
                cout << "(Child)";
            }
            cout << endl;
        }
        else {
            cout << "Vacated!" << endl;
        }
    }

    /// <summary>
    /// Books the guest information from the console
    /// </summary>
    /// <param name="guest">: To book</param>
    void book(Guest& guest) {
        char f_name[40]{};
        char l_name[40]{};
        int age = 0;
        cout << "Name: ";
        cin >> f_name;
        cout << "Lastname: ";
        cin >> l_name;
        cout << "Age: ";
        cin >> age;
        cin.ignore();
        set(guest, f_name, l_name, age);
    }

    // Vacates the guest by dallocating its memory.
    void vacate(Guest& guest) {
        delete[] guest.m_firstName;
        delete[] guest.m_lastName;
        guest.m_firstName = guest.m_lastName = nullptr;
    }
}