/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
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
#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

namespace seneca {

    class bankAccount {
    private:
        char username[17]; // maximum of 16 characters + null terminator
        double funds;
        bool isCheckingAccount;
        int monthlyTransactions;
        const double TRANSACTION_FEE_CHECKING = 1.25;
        const double TRANSACTION_FEE_SAVINGS = 3.50;
        const double INTEREST_RATE_CHECKING = 0.005; // 0.5%
        const double INTEREST_RATE_SAVINGS = 0.025; // 2.5%

        // Additional private members if necessary

    public:
        // Constructors
        bankAccount(const char* name = "", bool checking = false);

        // Setup and isOpen methods
        bool setup(const char* name, bool checking);
        bool isOpen() const;

        // Cast Operators
        operator bool() const;
        operator double() const;

        // Unary Operators
        bankAccount& operator++();
        bankAccount& operator--();

        // Binary Operators
        bool operator+=(double amount);
        bool operator-=(double amount);
        bool operator==(const bankAccount& rhs) const;
        bool operator>(double amount) const;
        bool operator<=(double amount) const;

        // Additional Methods
        bool transferFunds(bankAccount& source);
        void display() const;

        // Global helper functions will be declared outside the class
    };

    // Global Helper Functions
    bool operator>(double lhs, const bankAccount& rhs);
    bool operator<=(double lhs, const bankAccount& rhs);

} // namespace seneca

#endif // SENECA_BANKACCOUNT_H
