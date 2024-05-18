/*/////////////////////////////////////////////////////////////////////////
						 OOP244 Workshop5 # p2:
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024-02-20
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef HERO_H
#define HERO_H

#include "Power.h"
#include "iostream"

namespace seneca {

	const int MAX_NAME_LEN = 50;

	class Hero {

		// Data members.
		char m_hero_name[MAX_NAME_LEN + 1];
		Power* m_powers;
		int m_num_powers;
		int m_power_lvl;
	public:

		// Constructors and Destructor.
		Hero();
		Hero(const char* name, Power* pow, int n_pow);
		~Hero();

		// Member functions.
		void setEmpty();
		std::ostream& display(std::ostream& os = std::cout) const;
		bool isEmpty() const;
		void updatelvl();
		int checkPowerLvl() const;

		// Member operators.
		bool operator+= (Power& pow);
		bool operator-= (int pow_lvl);

	};

	// Global operators.
	bool operator< (Hero& lhs, Hero& rhs);
	bool operator> (Hero& lhs, Hero& rhs);
	bool operator>> (Power& pow, Hero& hero);
	bool operator<< (Hero& hero, Power& pow);

}

#endif // !HERO_H

