/*/////////////////////////////////////////////////////////////////////////
						 OOP244 Workshop # 8:
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024-03-24
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include <iostream>
#include "Account.h"
namespace seneca {
	class SavingsAccount : public Account {
	private:
		double m_interestRate;
	public:
		SavingsAccount(double, double);
		void  monthEnd();
		void  display(std::ostream&) const;
	};
}

#endif
