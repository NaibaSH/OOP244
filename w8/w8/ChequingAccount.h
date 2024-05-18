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
#ifndef  SENECA_CHEQUINGACCOUNT_H
#define  SENECA_CHEQUINGACCOUNT_H
#include <iostream>
#include "iAccount.h"
#include "Account.h"
namespace seneca {
	class ChequingAccount :public Account {
		double m_trans_fee;
		double m_month_fee;
	public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};

	
}
#endif
