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
#include "Room.h"
#include "Guest.h"
using namespace std;

namespace seneca {
   
   void init(Guest& G) {
      G.m_lastName = G.m_firstName = nullptr;
      G.m_adult = false;
   }

    // sets the Room by allocating a dynamic array of guests and setting the room number 
    void set(Room& room, int numberOfGuests, const char* roomNumber) {
        room.m_guests = new Guest[numberOfGuests];

        // Initialize each guest in the room
        for (int i = 0; i < numberOfGuests; ++i) {
           init(room.m_guests[i]);
        }

        strcpy(room.m_roomNumber, roomNumber);
        room.m_noOfGuests = numberOfGuests;
    }

    // Prints the room number and names of the guests in the following lines with four 
    // spaces of indentaion 
    void print(const Room& room) {
        if (room.m_guests != nullptr && room.m_guests[0].m_firstName == nullptr) {
            cout << "Room Number: " << room.m_roomNumber << endl;
            for (int i = 0; i < room.m_noOfGuests; i++)
            {
                cout << "    Vacated!" << endl;
            }
        }
        else if (room.m_guests == nullptr) {
            cout << "Empty Room!" << endl;
        }
        else {
            cout << "Room Number: " << room.m_roomNumber << endl;
            for (int i = 0; i < room.m_noOfGuests; i++) {
                cout << "    ";
                print(room.m_guests[i]);
            }
        }
    }

    // Books a room by receiving the room number, number of guests and the guest information.
    void book(Room& room) {
        char roomNumber[6];
        int numGuests = 0;
        char f_name[40];
        char l_name[40];

        cout << "Room number: ";
        cin >> roomNumber;
        cout << "Number of guests: ";
        cin >> numGuests;
        set(room, numGuests, roomNumber);

        int age = 0;
        for (int i = 0; i < numGuests; i++) {
            cout << i + 1 << ":" << endl;
            cout << "Name: ";
            cin >> f_name;
            cout << "Lastname: ";
            cin >> l_name;
            cout << "Age: ";
            cin >> age;
            set(room.m_guests[i], f_name, l_name, age);
        }
    }

    // vacates the room by dallocating all the memory used.
    void vacate(Room& room) {
        for (int i = 0; i < room.m_noOfGuests; i++) {
           vacate(room.m_guests[i]);
        }
        delete[] room.m_guests;
        room.m_guests = nullptr;
    }
}