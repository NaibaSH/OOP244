
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
#include "Icecream.h"
#include "Utils.h"
using namespace std;
namespace seneca {
	void Icecream::getOrder() {
		flavourNumber = 1, numScoops = 1;

		// Prompt for choosing a flavour
		cout << "Select flavour:" << endl;
		cout << "----------------" << endl;
		cout << "1: Chocolate\n2: Strawberry\n3: Mango\n4: Tutti fruit\n5: Almond crunch" << endl;
		cout << "----------------" << endl;
		cout << "> ";

		// Validating inputs
		do {
			if (flavourNumber < 1 || flavourNumber > 5) {
				cout << "Invlid value(1<=val<=5)\n> ";
			}
			flavourNumber = ut.getInt();
		} while (flavourNumber < 1 || flavourNumber > 5);

		// Prompt for entering the total number of scoops
		cout << "Number of Scoops (max 3)\n> ";

		// Validating inputs
		do {
			if (numScoops < 1 || numScoops > 3) {
				cout << "Invlid value(1<=val<=3)\n> ";
			}
			// Calling the getInt() utility function for an integer input validation
			numScoops = ut.getInt();
		} while (numScoops < 1 || numScoops > 3);

		// Prompt for user to enter (Y)es if they want a Vanilla Wafer else (N)o 
		cout << "Vanilla wafer cone?" << endl;
		cout << "(Y)es/(N)o > ";
		vanillaCone = ut.yes();
}

	void Icecream::printOrder() {
		const double scoopPrice = 5;
		double pScoop = 0.0, pChoc = 0.0,pVanilla = 0.0;
		pVanilla = vanillaCone? 5 : 0;

		cout.width(14);
		cout << "Order details:";
		cout.width(21);
		cout.setf(ios::right);
		cout << "Price" << endl;
		cout.unsetf(ios::right);
		cout << "-----------------------------------" << endl;
		
		cout << "Number of scoops, " << numScoops << " total:";

		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		pScoop += scoopPrice * numScoops;
		cout << pScoop << endl;

		switch (flavourNumber) {
			case 1:
				cout.width(26);
				cout.setf(ios::left);
				cout << "Chocolate flavour:";
				cout.unsetf(ios::left);
				cout.width(9);
				cout.setf(ios::fixed);
				cout.precision(2);
				pChoc = numScoops;
				cout << pChoc << endl;
				break;

			case 2:
				cout << "Strawberry flavour" << endl;
				break;

			case 3:
				cout << "Mango flavour" << endl;
				break;

			case 4:
				cout << "Tutti fruit flavour" << endl;
				break;

			case 5:
				cout << "Almond crunch flavour" << endl;
				break;
		}

		cout.width(26);
		cout.setf(ios::left);
		cout << "Vanilla Wafer:";
		cout.unsetf(ios::left);
		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		if (pVanilla) {
			cout << scoopPrice << endl;
		}
		else {
			cout << "0.00" << endl;
		}
		
		totalAmount = pScoop + pChoc + pVanilla;

		cout.width(26);
		cout.setf(ios::left);
		cout << "Price:";
		cout.unsetf(ios::left);
		cout.width(9);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << totalAmount << endl;
	}
}