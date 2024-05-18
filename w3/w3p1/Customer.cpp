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
#include "Customer.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

namespace seneca {

    Customer::Customer() {
        setEmpty();
    }

    Customer::~Customer() {
        deallocateMemory();
    }

    void Customer::setEmpty() {
        m_id = 0;
        m_name = nullptr;
        m_car = nullptr;
    }

    bool Customer::isEmpty() const {
        return (m_name == nullptr || strlen(m_name) == 0 || m_car == nullptr);
    }

    void Customer::deallocateMemory() {
        delete[] m_name;
        m_name = nullptr;
    }

    void Customer::set(int customerId, const char* name, const Car* car) {
        deallocateMemory();
        setEmpty();
        if (name != nullptr && strlen(name) > 0 && car != nullptr) {
            m_id = customerId;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_car = car;
        }
    }

    void Customer::display() const {
        if (!isEmpty()) {
            cout << left << setw(15) << "Customer ID:" << right << setw(20) << m_id << endl;
            cout << left << setw(15) << "First Name:" << right << setw(20) << m_name << endl;
            m_car->display();
        }
    }

    const Car& Customer::car() const {
        return *m_car;
    }
}
