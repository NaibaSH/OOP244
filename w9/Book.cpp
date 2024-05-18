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
#include <iostream>
#include <cstring>

#include "Book.h"

//  this book is derived from libraryitem class, so as its implementations
using namespace std;
namespace seneca {
	Book::Book(const char* title, int year, const char* author):LibraryItem(title, year) { // parameters constructions
		if (author && *author) // 
		{
			delete[] m_author;
			m_author = new char[strlen(author) + 1];
			strcpy(m_author, author);
			
		}
	}


	Book::Book(Book& other):LibraryItem(other) { // copy constructor
		m_author = new char[strlen(other.m_author) + 1];
		strcpy(m_author, other.m_author);
	}


	Book& Book::operator=(Book& other) { // copy assignment
		if (&other != this) {
			LibraryItem::operator=(other);
			delete[] m_author;
			m_author = new char[strlen(other.m_author) + 1];
			strcpy(m_author, other.m_author);
		}
		return *this;
	}

	Book :: ~Book() { // destructor
		delete[] m_author;
		m_author = nullptr;
	}

	ostream& Book::display(ostream& ostr) const {
		LibraryItem::display(ostr);
		ostr << endl;
		ostr << "Author: " << m_author;
		return ostr;
	} // formatted output

	bool Book::operator>(const Book& other) const {
		bool returnValue = true;
		if (other.m_author && other.m_author[0] && m_author && m_author[0]) {
			return m_author[0] > other.m_author[0];
		}
		else {
			returnValue = false;
		}
		return returnValue;
	}  // boolean operator ...

}