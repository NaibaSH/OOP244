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
#include "Utils.h"
#include <cctype> // for std::isdigit

namespace seneca {

    bool isNumber(const std::string& str) {
        for (char const& c : str) {
            if (!std::isdigit(c)) return false;
        }
        return true;
    }

    

} 




