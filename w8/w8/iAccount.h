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
#ifndef SENECA_IACCOUNT_H
#define SENECA_IACCOUNT_H
#include <iostream>
namespace seneca {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void  monthEnd() = 0;
		virtual void  display(std::ostream&) const = 0;
        virtual ~iAccount(){}

	};
	iAccount* CreateAccount(const char*, double);
}

#endif
