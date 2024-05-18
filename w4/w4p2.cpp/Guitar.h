
//
/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P2)
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS 
#ifndef GUITAR_H
#define GUITAR_H

#include <iostream>

namespace seneca {

    // Constants
    const int MAT_LEN = 10;

    // Guitar String class
    class GuitarStr {
        char m_material[MAT_LEN];
        double m_gauge;
    public:
        GuitarStr();
        GuitarStr(const char* ma, double ga);
        const char* material() const;
        double gauge() const;
    };

    // Guitar class
    class Guitar {
        GuitarStr* m_strings;
        int m_numStrings;
        char m_model[16];
    public:
        Guitar(const char* mod = "Stratocaster");
        Guitar(GuitarStr strs[], int ns, const char* mod);
        ~Guitar();

        bool changeString(const GuitarStr& gs, int sn);
        void reString(GuitarStr strs[], int ns);
        void deString();

        bool strung() const;
        bool matchGauge(double ga) const;
        std::ostream& display(std::ostream& os = std::cout) const;
    };

} // namespace seneca

#endif // GUITAR_H

