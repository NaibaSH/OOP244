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
#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H

#include "Car.h"

namespace seneca {

    class Customer {
        int m_id;          // Customer ID
        char* m_name;      // Dynamically allocated C string for customer name
        const Car* m_car;  // Pointer to an unmodifiable Car object

    public:
        Customer();  // Default constructor
        ~Customer(); // Destructor to manage dynamic memory

        // Check if the object is in a safe empty state
        bool isEmpty() const;

        // Set the customer to a safe empty state
        void setEmpty();

        // Deallocate dynamic memory for m_name
        void deallocateMemory();

        // Set customer details
        void set(int customerId, const char* name, const Car* car);

        // Display the customer and their car details
        void display() const;

        // Get a reference to the Car object
        const Car& car() const;
    };

}

#endif // SENECA_CUSTOMER_H
