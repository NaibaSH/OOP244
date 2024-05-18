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
#ifndef SENECA_GUEST_H
#define SENECA_GUEST_H

namespace seneca {
    struct Guest {
        char* m_firstName{};
        char* m_lastName{};
        bool m_adult;
    };

    // sets the Guest variables and sets the m_adult flag to true if 
    // the age is greater than or equal to 18
    void set(Guest& guest, const char* first, const char* last, int age);
    void print(const Guest& guest);
    void book(Guest& guest);
    void vacate(Guest& guest);
}
#endif // !SENECA_GUEST_H