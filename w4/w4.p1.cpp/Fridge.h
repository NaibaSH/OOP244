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
// Fridge.h
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <cstring>
#include <iostream>

namespace seneca {

    const int NAME_LEN = 20;
    const int FRIDGE_CAP = 3;

    class Food {
        char m_name[NAME_LEN]{};
        int m_weight{};
    public:
        Food();
        Food(const char* nm, int wei);
        const char* name() const;
        int weight() const;
    };

    class Fridge {
        Food m_foods[FRIDGE_CAP];
        int m_numFoods;
        char* m_model;
    public:
        Fridge();
        Fridge(Food farr[], int nf, const char* mod = "Ice Age");
        ~Fridge();
        bool addFood(const Food& f);
        void changeModel(const char* m);
        bool fullFridge() const;
        bool findFood(const char* f) const;
        std::ostream& display(std::ostream& os = std::cout) const;
    };
}

#endif // SENECA_FRIDGE_H
