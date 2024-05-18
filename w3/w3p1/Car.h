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
#ifndef SENECA_CAR_H
#define SENECA_CAR_H

namespace seneca {

    class Car {
        char m_licencePlate[9]; // License plate number (max 8 chars + null terminator)
        char* m_makeModel;      // Dynamically allocated C string for make and model
        char* m_serviceDesc;    // Dynamically allocated C string for service description
        double m_cost;          // Cost of the service

    public:
        Car(); // Default constructor
        ~Car(); // Destructor to manage dynamic memory

        // Check if the car object is in a safe recognizable empty state
        bool isEmpty() const;

        // Set the car object to a safe recognizable empty state
        void setEmpty();

        // Deallocate dynamically allocated memory
        void deallocateMemory();

        // Set car information and service details
        void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);

        // Display the car information
        void display() const;
    };

}

#endif // SENECA_CAR_H
