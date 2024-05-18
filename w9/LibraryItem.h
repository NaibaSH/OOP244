/*/////////////////////////////////////////////////////////////////////////
OOP244 Workshop # 9:
Full Name : Naiba Shabanova
Student ID# : 164598229
Email : nshabanova@myseneca.ca
Section : ZCC
Date : 2024 - 03 - 29
Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H
#include <iostream> // using the standard library
#include "LibraryItem.h"

using namespace std;
namespace seneca {
	class LibraryItem { // data members
		char* m_title{};
		int m_year{};

	public: // member functions
		LibraryItem();
		LibraryItem(const char* title, int year);// parameterzed constructor(that would accept a two parameters character title and year.)
		// now making the rule of three

		// 1. copy constructor
		LibraryItem(LibraryItem& library);
		// 2. copy assignment
		LibraryItem& operator=(LibraryItem& library);
		// 3. destructor
		virtual ~LibraryItem();

		// output stream
		virtual ostream& display(ostream& ostr = cout) const;
	};
}



#endif 