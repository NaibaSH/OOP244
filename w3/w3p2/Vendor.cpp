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

#include <iostream>
#include "Vendor.h"
#include "Icecream.h"
using namespace std;

namespace seneca {
	void Vendor::setEmpty() {
		icecream = nullptr;
	}

	void Vendor::printLogo() {
		cout << "Seneca Icecream shop" << endl;
		cout << "          @" << endl;
		cout << "        (' .)" << endl;
		cout << "       (*.`. )" << endl;
		cout << "        \\###/" << endl;
		cout << "         \\#/" << endl;
		cout << "          V" << endl;  // Adjusted the space before V
	}





	void Vendor::takeOrders() {
		printLogo();
		clearData();
		cout << "How many Icecreams?\n> ";
		cin >> numIcecreams;
		icecream = new Icecream[numIcecreams];

		for (int i = 0; i < numIcecreams; i++) {
			cout << "Order number " << i+1 << ":" << endl;
			icecream[i].getOrder();
		}
		cout << endl;
	}

	void Vendor::displayOrders() {
		cout << "********** Order Summary **********" << endl;
		for (int i = 0; i < numIcecreams; i++) {
			cout << "Order No: " << i+1 << ":" << endl;
			icecream[i].printOrder();
			totalAmt += icecream[i].totalAmount;
			if (i != numIcecreams - 1) {
				cout << endl;
			}
		}
		cout << "-----------------------------------" << endl;

		cout.width(26);
		cout.setf(ios::left);
		cout << "Price:";
		cout.unsetf(ios::left);
		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << totalAmt << endl;

		tax = totalAmt * 0.13;

		cout.width(26);
		cout.setf(ios::left);
		cout << "Tax:";
		cout.unsetf(ios::left);
		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << tax << endl;

		billAmt = tax + totalAmt;

		cout.width(26);
		cout.setf(ios::left);
		cout << "Total Price ($):";
		cout.unsetf(ios::left);
		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << billAmt << endl;
	}

	void Vendor::clearData()
	{
		delete[] icecream;
		icecream = nullptr;
	}
}