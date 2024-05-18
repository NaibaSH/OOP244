/*/////////////////////////////////////////////////////////////////////////
                             OOP244 Workshop4 # p1:
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024-02-08
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
// Fridge.cpp
#include "Fridge.h"
#include <cstring>
#include <iostream>

namespace seneca {

    // Food class implementations
    Food::Food() {}

    Food::Food(const char* nm, int wei) {
        strncpy(m_name, nm, NAME_LEN);
        m_name[NAME_LEN - 1] = '\0'; // Ensuring null-termination
        m_weight = wei;
    }

    const char* Food::name() const {
        return m_name;
    }

    int Food::weight() const {
        return m_weight;
    }

    // Fridge class implementations
    Fridge::Fridge() : m_numFoods(0), m_model(nullptr) {}

    Fridge::Fridge(Food farr[], int nf, const char* mod) : Fridge() {
        // Implementation as per workshop instructions
        // ...
    }

    Fridge::~Fridge() {
        delete[] m_model;
    }

    // Other member functions
    // ...
}

