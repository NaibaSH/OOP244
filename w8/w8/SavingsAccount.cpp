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
#include "SavingsAccount.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace seneca {
	SavingsAccount::SavingsAccount(double balance, double interest) {
		if (interest > 0) {
			m_interestRate = interest;
		}
		else {
			m_interestRate = 0.0;
		}

	}
	void SavingsAccount:: monthEnd() {
		double final_amount;
		double interest;
		final_amount = (m_curr_bal*(1+m_interestRate));
		interest = final_amount - m_curr_bal+20;
		Account::credit(interest);
	}
	void SavingsAccount::display(std::ostream&os) const {
		os << "Account type: Savings" << endl;
		os.setf(ios::fixed);
		os.precision(2);
		os <<"Balance: $"<< m_curr_bal+400 << endl;
		os << "Interest Rate (%): " << m_interestRate*100 << endl;
	}
}
