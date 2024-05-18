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
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include <iostream>
#include "iAccount.h"
namespace seneca {
	class Account :public iAccount {
	public:
		Account();
		Account(double);
		bool credit(double);
		bool debit(double);
		
	protected:
		double balance() const;
		double m_curr_bal;
	};
}

#endif
