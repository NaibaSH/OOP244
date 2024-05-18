/*/////////////////////////////////////////////////////////////////////////
						 OOP244 Workshop5 # p1:
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024-02-16
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char* name, bool checking)
	{
		m_userName[0] = '\0';		// Empty string implies is account is not open 
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char* name, bool checking)
	{
		if (isOpen())
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods
	bankAccount::operator bool() const {
		if (isOpen()) {
			return true;
		}
		return false;
	}

	bankAccount::operator double() const {
		return m_funds;
	}

	bankAccount& bankAccount::operator++() {
		if (m_funds > 0 && isOpen()) {
			if (m_checking) {
				m_funds += m_funds * CHECKING_INTEREST_RATE;
			}
			else {
				m_funds += m_funds * SAVINGS_INTEREST_RATE;
			}
		}
		return *this;
	}

	bankAccount& bankAccount::operator--() {
		if (isOpen()) {
			if (m_checking) {
				m_funds -= m_monthlyTransactions * CHECKING_TRANSACTION_FEE;
			}
			else {
				m_funds -= m_monthlyTransactions * SAVINGS_TRANSACTION_FEE;
			}
		}
		return *this;
	}

	bool bankAccount::operator += (double specifiedValue) {
		if (isOpen()) {
			printf("Deposit $%.2lf for %s\n", specifiedValue, m_userName);
			m_funds += specifiedValue;
			m_monthlyTransactions++;
			return true;
		}
		return false;
	}

	bool bankAccount::operator -= (double specifiedValue) {
		if (isOpen()) {
			printf("Withdraw $%.2lf for %s\n", specifiedValue, m_userName);
			m_funds -= specifiedValue;
			m_monthlyTransactions++;
			return true;
		}
		return false;
	}

	bool bankAccount::operator == (const bankAccount& otherAccount) const {
		if (strcmp(m_userName,otherAccount.m_userName) == 0 && (m_funds - otherAccount.m_funds < 0.001) &&
			otherAccount.m_funds - m_funds < 0.001 && m_checking == otherAccount.m_checking) {
			return true;
		}
		return false;
	}

	bool bankAccount::operator > (double specifiedValue) const{
		if (isOpen()) {
			if (m_funds > specifiedValue) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}

	bool bankAccount::operator <= (double specifiedValue) const {
		if (isOpen()) {
			if (m_funds <= specifiedValue) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}

	bool bankAccount::operator << (bankAccount& sourceAccount) {
		if (isOpen() && sourceAccount.isOpen() && sourceAccount.m_funds > 0.0) {
			printf("Transfer $%.2lf from %s to %s\n", sourceAccount.m_funds, sourceAccount.m_userName, m_userName);
			*this += sourceAccount.m_funds;
			sourceAccount -= sourceAccount.m_funds;
			return true;
		}
		else {
			return false;
		}
		return false;
	}

	void bankAccount::display(void) const {
		if (isOpen()) {
			
			cout << "Display Account -> User:" << std::setfill('-') << std::setw(16) << std::right 
				<< m_userName << " | "<< std::setfill(' ') << std::setw(8) << std::right 
				<< (m_checking ? "Checking" : "Savings") << " | Balance: $  "
				<< std::setw(6) << std::right << std::fixed << std::setprecision(2) << m_funds
				<< " | Transactions:" << std::setfill('0') << std::setw(3)
				<< m_monthlyTransactions << endl;
		}
		else {
			cout << "Display Account -> User:------- NOT OPEN" << endl;
		}
	}
	// ADD: Global Helper Functions

	bool operator > (double lhs, const bankAccount& rhs) {
		
		if (rhs.operator bool()) {
			double rhsFunds = rhs.operator double();
			return lhs > rhsFunds;
		}
		return false;
	}

	bool operator <= (double lhs, const bankAccount& rhs) {
		return !(operator> (lhs, rhs));
	}
}