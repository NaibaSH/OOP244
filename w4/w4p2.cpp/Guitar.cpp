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
#include "Guitar.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca {

    GuitarStr::GuitarStr() {}// It is default constructor

    GuitarStr::GuitarStr(const char* ma, double ga)// So it's constructor with parameters
    {
        strncpy(m_material, ma, MAT_LEN - 1);
        m_material[MAT_LEN - 1] = '\0'; // I must ensure null-termination
        m_gauge = ga;
    }

    const char* GuitarStr::material() const//For this code I  get the material of the guitar string
    {
        return m_material;
    }

    double GuitarStr::gauge() const//To get the gauage of the guitar string
    {
        return m_gauge;
    }

    Guitar::Guitar(const char* mod) : m_numStrings(0)//Default constructor
    {
        m_strings = nullptr;
        strncpy(m_model, mod, 15);
    }

    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod)//constructor for Guitar class with parameters
    {
        if (ns <= 0 || ns > 100 || strlen(mod) > 15)
        {
            m_strings = nullptr;
            m_numStrings = 0;
            return;
        }

        m_strings = new GuitarStr[ns];
        for (int i = 0; i < ns; ++i) 
        {
            m_strings[i] = strs[i];
        }
        m_numStrings = ns;
        strncpy(m_model, mod, 15);
    }

    Guitar::~Guitar()//Destructor of Guitar class 
    {
        delete[] m_strings;
    }

    bool Guitar::changeString(const GuitarStr& gs, int sn)//To change a guitar string
    {
        if (sn >= 0 && sn < m_numStrings) //To check if the given string is valid and assign the given string to a particular index in m_string array.
        {
            m_strings[sn] = gs;
            return true;
        }
        return false;
    }

    void Guitar::reString(GuitarStr strs[], int ns)//To restring guitar
    {
        delete[] m_strings;//deallocate existing memory for m_strings array
        m_strings = new GuitarStr[ns];//To allocate memory for new m_strings array
        for (int i = 0; i < ns; ++i)//To copy the provided strings to m_strings array and update the number of strings.
        {
            m_strings[i] = strs[i];
        }
        m_numStrings = ns;
    }

    void Guitar::deString() //To destring the guitar
    {
        delete[] m_strings;//deallocate memory for m_strings array
        m_strings = nullptr;
        m_numStrings = 0;
    }

    bool Guitar::strung() const //To check if the guitar is strung by checking if the number of strings is greater than 0.
    {
        return m_numStrings > 0;
    }

    bool Guitar::matchGauge(double ga) const //To check if the guitar string matches any particular gauge and return true or false
    {
        for (int i = 0; i < m_numStrings; ++i)//To loop through m_strings array
        {
            if (m_strings[i].gauge() == ga) 
            {
                return true;
            }
        }
        return false;
    }

    std::ostream& Guitar::display(std::ostream& os) const {
        if (!strung()) //To check if guitar is not strung and output a messege indicating empty guitar 
        {
            os << "***Empty Guitar***\n"; 
        }
        else//output the details of guitar
        {
            os << "Guitar Model: " << m_model << "\n";
            os << "Strings: " << m_numStrings << "\n";
            for (int i = 0; i < m_numStrings; ++i) {
                os << "#" << i + 1 << "" << std::setw(MAT_LEN) << m_strings[i].material()
                    << " | " << std::fixed << std::setprecision(1) << m_strings[i].gauge() << "\n";
            }
        }
        return os;//To return the output
    }

} // namespace seneca
