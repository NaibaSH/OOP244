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

#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include "LibraryItem.h"
namespace seneca {
	class Book : public LibraryItem {
		char* m_author{};

	public:
		Book(const char* title, int year, const char* author); // parameters constructions

		// rule of three(3)
		// 1. copy constructor
		Book(Book& other);
		// 2. copy assignment
		Book& operator=(Book& other);
		// 3. destructor
		virtual ~Book();

		ostream& display(ostream& ostr = cout) const;
		bool operator >(const Book& other)const;
	};
}


















#endif 
































