/*/////////////////////////////////////////////////////////////////////////
                        Workshop-3 Part-2
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 06/02/2024

Authenticity Declaration:
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H

namespace seneca {
	class Icecream {
		int flavourNumber{};
		int numScoops{};
		char vanillaCone{};

	public:
		double totalAmount{};
		void getOrder();
		void printOrder();
	};
}
#endif // !SENECA_ICECREAM_H
