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

#ifndef SENECA_ROOM_H
#define SENECA_ROOM_H
#include "Guest.h"

namespace seneca {
    struct Room {
        char m_roomNumber[6];
        int m_noOfGuests;
        Guest* m_guests;
    };

    // sets the Room by allocating a dynamic array of guests and setting the room number 
    // (no validation is done for room number)
    void set(Room& room, int numberOfGuests, const char* roomNumber);
    // Prints the room number and names of the guests in the following lines with four 
    // spaces of indentaion     
    void print(const Room& room);
    void book(Room& room);
    // vacates the room by dallocating all the memory used.
    void vacate(Room& room);
}

#endif // !SENECA_GUEST_H