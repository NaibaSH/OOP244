/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include "bankaccount.h"
#include <cstring>

namespace seneca {

    // Constructors
    bankAccount::bankAccount(const char* name, bool checking) {
        setup(name, checking);
    }

    // Setup and isOpen methods
    bool bankAccount::setup(const char* name, bool checking) {
        if (!isOpen()) {
            strncpy(username, name, 16);
            username[16] = '\0';
            isCheckingAccount = checking;
            funds = 0;
            monthlyTransactions = 0;
            return true;
        }
        return false;
    }

    bool bankAccount::isOpen() const {
        return username[0] != '\0';
    }

    // Cast Operators
    bankAccount::operator bool() const {
        return isOpen();
    }

    bankAccount::operator double() const {
        return funds;
    }

    // Unary Operators
    bankAccount& bankAccount::operator++() {
        // Implementation needed
        return *this;
    }

    bankAccount& bankAccount::operator--() {
        // Implementation needed
        return *this;
    }

    // Binary Operators
    bool bankAccount::operator+=(double amount) {
        // Implementation needed
        return false;
    }

    bool bankAccount::operator-=(double amount) {
        // Implementation needed
        return false;
    }

    bool bankAccount::operator==(const bankAccount& rhs) const {
        // Implementation needed
        return false;
    }

    bool bankAccount::operator>(double amount) const {
        // Implementation needed
        return false;
    }

    bool bankAccount::operator<=(double amount) const {
        // Implementation needed
        return false;
    }

    // Additional Methods
    bool bankAccount::transferFunds(bankAccount& source) {
        // Implementation needed
        return false;
    }

    void bankAccount::display() const {
        // Implementation needed
    }

    // Global Helper Functions
    bool operator>(double lhs, const bankAccount& rhs) {
        // Implementation needed
        return false;
    }

    bool operator<=(double lhs, const bankAccount& rhs) {
        // Implementation needed
        return false;
    }

} // namespace seneca
