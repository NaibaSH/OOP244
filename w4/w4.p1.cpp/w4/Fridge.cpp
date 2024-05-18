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
#define _CRT_SECURE_NO_WARNINGS  // Disables warnings about unsafe functions

#include <iostream>
#include <cstring>
#include "Fridge.h"  // Include the header file for the Fridge class

using namespace std;

#define NAME_LEN 20  // Maximum length of a food name
#define FRIDGE_CAP 3  // Maximum capacity of the fridge

namespace seneca {

    // Default constructor for Food class
    Food::Food() {}

    // Parameterized constructor for Food class
    Food::Food(const char* nm, int wei)
    {
        strncpy(m_name, nm, NAME_LEN);  // Copy the name into m_name
        m_weight = wei;  // Set the weight
    }

    // Getter for the name of the food
    const char* Food::name() const
    {
        return m_name;
    }

    // Getter for the weight of the food
    int Food::weight() const
    {
        return m_weight;
    }

    // Default constructor for Fridge class
    Fridge::Fridge() : m_numFoods(0), m_model(nullptr)
    {
        m_model = new char[strlen("Ice Age") + 1];  // Allocate memory for the model name
        strcpy(m_model, "Ice Age");  // Copy the model name into m_model
    }

    // Parameterized constructor for Fridge class
    Fridge::Fridge(Food farr[], int nf, const char* mod) : m_numFoods(0), m_model(nullptr)
    {
        if (nf > 0 && mod != nullptr && strlen(mod) > 0)  // Check if the parameters are valid
        {
            m_numFoods = (nf > FRIDGE_CAP) ? FRIDGE_CAP : nf;  // Set the number of foods
            m_model = new char[strlen(mod) + 1];  // Allocate memory for the model name
            strcpy(m_model, mod);  // Copy the model name into m_model
            for (int i = 0; i < m_numFoods; ++i)  // Copy the food objects into m_foods
            {
                m_foods[i] = farr[i];
            }
        }
    }

    // Destructor for Fridge class
    Fridge::~Fridge()
    {
        delete[] m_model;  // Deallocate the memory for the model name
    }

    // Function to add a food to the fridge
    bool Fridge::addFood(const Food& f)
    {
        if (m_numFoods < FRIDGE_CAP)  // Check if the fridge is not full
        {
            m_foods[m_numFoods++] = f;  // Add the food to the fridge
            return true;
        }
        return false;  // Return false if the fridge is full
    }

    // Function to change the model of the fridge
    void Fridge::changeModel(const char* m)
    {
        if (m != nullptr && strlen(m) > 0)  // Check if the parameter is valid
        {
            delete[] m_model;  // Deallocate the memory for the old model name
            m_model = new char[strlen(m) + 1];  // Allocate memory for the new model name
            strcpy(m_model, m);  // Copy the new model name into m_model
        }
    }

    // Function to check if the fridge is full
    bool Fridge::fullFridge() const
    {
        return m_numFoods == FRIDGE_CAP;  // Return true if the fridge is full
    }

    // Function to find a food in the fridge
    bool Fridge::findFood(const char* f) const
    {
        for (int i = 0; i < m_numFoods; ++i)  // Loop through the foods in the fridge
        {
            if (strcmp(m_foods[i].name(), f) == 0)  // Check if the food name matches the parameter
            {
                return true;  // Return true if the food is found
            }
        }
        return false;  // Return false if the food is not found
    }

    // Function to display the fridge
    void Fridge::display() const
    {
        if (m_model == nullptr) return;  // Check if the model name is not null

        if (m_numFoods == 0)
        {
            // If there are no foods in the fridge, you could add a message here
        }
        else
        {
            cout << "Fridge Model: " << m_model << endl;  // Print the model name
            cout << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << endl;  // Print the number of foods and the capacity
            cout << "List of Foods" << endl;  // Print the list of foods
            for (int i = 0; i < m_numFoods; ++i)  // Loop through the foods in the fridge
            {
                cout.width(NAME_LEN);  // Set the width for the food name
                cout << right << m_foods[i].name() << " | " << m_foods[i].weight() << endl;  // Print the food name and weight
            }
        }
    }
}
