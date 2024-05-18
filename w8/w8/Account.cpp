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
#include <iostream>
#include "Account.h"
#include "iAccount.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace seneca {
	Account::Account() {
		m_curr_bal = 0.0;
	}
	Account::Account(double initial_bal) {
		if (initial_bal > 0) {
			m_curr_bal = initial_bal;
		}
		else {
			m_curr_bal = 0;
		}
	}
	bool Account::credit(double credit) {
		bool success;
		if (credit > 0) {
			m_curr_bal +=credit;
			success = true;
		}
		else {
			success = false;
		}
		return success;
	}
	bool Account::debit(double debit) {
		bool success;
		if (debit >= 0) {
			m_curr_bal =m_curr_bal- debit;
			success = true;
		}
		else {
			success = false;
		}
		return success;
	}
	double Account::balance() const {
		return m_curr_bal;
	}

}
