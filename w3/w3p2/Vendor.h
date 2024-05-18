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

#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H
#include "Icecream.h"

namespace seneca {
	class Vendor {
		Icecream* icecream{};
		int numIcecreams{};
		double totalAmt{};
		double tax{};
		double billAmt{};
		void printLogo();

	public:

		void setEmpty();
		void takeOrders();
		void displayOrders();
		void clearData();
	};
}
#endif // !SENECA_VENDOR_H