/*/////////////////////////////////////////////////////////////////////////
                        Workshop-3 Part-1
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 03/02/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#include "Car.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

namespace seneca {

    Car::Car() {
        setEmpty();
    }

    Car::~Car() {
        deallocateMemory();
    }

    void Car::setEmpty() {
        m_licencePlate[0] = '\0';
        m_makeModel = nullptr;
        m_serviceDesc = nullptr;
        m_cost = 0.0;
    }

    bool Car::isEmpty() const {
        return (m_licencePlate[0] == '\0' || m_makeModel == nullptr || m_serviceDesc == nullptr);
    }

    void Car::deallocateMemory() {
        delete[] m_makeModel;
        m_makeModel = nullptr;
        delete[] m_serviceDesc;
        m_serviceDesc = nullptr;
    }

    void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost) {
        deallocateMemory();
        setEmpty();
        if (plateNo != nullptr && strlen(plateNo) > 0 && carMakeModel != nullptr && strlen(carMakeModel) > 0
            && serviceDesc != nullptr && strlen(serviceDesc) > 0) {
            strncpy(m_licencePlate, plateNo, sizeof(m_licencePlate) - 1);
            m_licencePlate[sizeof(m_licencePlate) - 1] = '\0';

            m_makeModel = new char[strlen(carMakeModel) + 1];
            strcpy(m_makeModel, carMakeModel);

            m_serviceDesc = new char[strlen(serviceDesc) + 1];
            strcpy(m_serviceDesc, serviceDesc);

            m_cost = serviceCost;
        }
    }

    void Car::display() const {
        if (!isEmpty()) {
            cout << left << setw(15) << "License Plate:" << right << setw(20) << m_licencePlate << endl;
            cout << left << setw(15) << "Model:" << right << setw(20) << m_makeModel << endl;
            cout << left << setw(15) << "Service Name:" << right << setw(20) << m_serviceDesc << endl;
            cout << left << setw(15) << "Service Cost:" << right << setw(20) << fixed << setprecision(2) << m_cost << endl;
        }
    }
}

