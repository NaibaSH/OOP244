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
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_FRIDGE_H
#define SENECA_FRIDGE_H

#include <iostream>
#include <cstring>

#define NAME_LEN 20
#define FRIDGE_CAP 3

namespace seneca {


    class Food {
        char m_name[NAME_LEN]{};
        int m_weight{};
    public:
        const char* name()const;
        int weight()const;
        Food();
        Food(const char* nm, int wei);
    };

    class Fridge {
    private:
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
        void display() const;
    };

}

#endif