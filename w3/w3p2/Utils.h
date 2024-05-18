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
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

#include <cstddef> // for size_t

namespace seneca {

    struct Utils {
        // Retrieves an integer from the user.
        int getInt();

        // Retrieves a C-style string from the user, ensuring it fits within the provided length.
        void getCstr(char* str, std::size_t len);

        // Asks the user a yes/no question and returns true for 'yes' and false for 'no'.
        bool yes();
    };

    // Declaration of a global Utils object for common utilities.
    extern Utils ut;

} // namespace seneca

#endif // !SENECA_UTILS_H

