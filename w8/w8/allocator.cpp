/*/////////////////////////////////////////////////////////////////////////
OOP244 Workshop # 8:
Full Name : Naiba Shabanova
Student ID# : 164598229
Email : nshabanova@myseneca.ca
Section : ZCC
Date : 2024 - 03 - 24
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: allocator.cpp
// Version 2.0
// Date:
// Author: Chris Szalwinski, Heidar Davoudi
// Description
// This file allocates an Account object in dynamic memory
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace seneca {

    // account rates and charges
    //
    const double interestRate = 0.05;
    const double transactionFee = 0.50;
    const double monthlyFee = 2.00;

    // calls the appropriate constructor
    //
    iAccount* CreateAccount(const char* str, double balance) {
        iAccount* account = nullptr;
        switch (str[0]) {
        case 'S':
            account = new SavingsAccount(balance, interestRate);
            break;
        case 'C':
            account = new ChequingAccount(balance, transactionFee, monthlyFee);
            break;
        }
        return account;
    }
}

