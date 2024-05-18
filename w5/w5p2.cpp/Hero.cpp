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

#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include "iostream"
#include "iomanip"
#include "string.h"

using namespace std;
using namespace seneca;

// Default constructor for stetting data members to empty safe state.
Hero::Hero() {

	setEmpty();

}

// 3 parameter constructor for setting data members to the values passed through the parameters.
Hero::Hero(const char* name, Power* pow, int n_pow) {

	setEmpty(); // setting the data members to empty safe state.

	if (name[0] != '\0' && pow != nullptr && n_pow > 0){

		strncpy(m_hero_name, name, MAX_NAME_LEN);

		int i;

		m_powers = new Power[n_pow];
		for (i = 0; i < n_pow; i++) {
			m_powers[i] = pow[i];
		}

		m_num_powers = n_pow;

		updatelvl(); // call to update the power level.
	}
}

// Function to set the data members to empty safe state.
void Hero::setEmpty() {

	m_hero_name[0] = '\0';
	m_powers = nullptr;
	m_num_powers = 0;
	m_power_lvl = 0;
}

// Function to display the hero and its powers.
std::ostream& Hero::display(std::ostream& os) const {

	int indentSize = 2;
	int i;

	os << "Name: " << left << m_hero_name << endl
		<< "List of available powers: " << endl;

	for (i = 0; i < m_num_powers; i++) {
		os << std::setw(indentSize) << "" << "Name: " << m_powers[i].checkName() << ", " << "Rarity: " << m_powers[i].checkRarity() << endl; 
			
	}
	os << "Power Level: " << m_power_lvl;

	return os;
}

// Function to check if the hero is empty.
bool Hero::isEmpty() const {

	return(m_hero_name[0] == '0' || m_powers == nullptr || m_num_powers == 0 || m_power_lvl == 0);
}

// Function to update the power level of the hero.
void Hero::updatelvl() {

	int i, t_rarity = 0;

	for (i = 0; i < m_num_powers; i++) {
		t_rarity += this->m_powers[i].checkRarity();
	}

	m_power_lvl = t_rarity * m_num_powers;
}

// Function to get the power level of the hero.
int Hero::checkPowerLvl() const {

	return m_power_lvl;
}

// Member operator to add a power to the hero.
bool Hero::operator+= (Power& pow) {

	if (!pow.isEmpty()) { // Check if the power is not empty.

		int i;

		// Create a temporary array to store the powers.
		Power* tempArr = new Power[m_num_powers];

		// Copy the powers to the temporary array.
		for (i = 0; i < m_num_powers; i++) {
			tempArr[i] = m_powers[i];
		}

		m_num_powers++;

		// Delete the old array and create a new array with the new size.
		delete[] m_powers;
		m_powers = new Power[m_num_powers];

		// Copy the powers from the temporary array to the new array.
		for (i = 0; i < m_num_powers - 1; i++) 
		{
			m_powers[i] = tempArr[i];
		}
		// Add the new power to the new array.
		m_powers[m_num_powers - 1] = pow;

		// Delete the temporary array and set it to a safe state.
		delete[] tempArr; 
		tempArr = nullptr;

		updatelvl(); // Update the power level.

		return true;
	}
	else
	{
		return false;
	}
}

// Member operator to decrease the power of a hero.
bool Hero::operator-= (int pow_lvl) {

	if (pow_lvl > 0) {
		m_power_lvl -= pow_lvl;
		return true;
	}
	else
	{
		return false;
	}
}

// 2 global operator to compare the power level of two heroes.
//#1
bool seneca::operator< (Hero& lhs, Hero& rhs) {
	return (lhs.checkPowerLvl() < rhs.checkPowerLvl());
}
//#2
bool seneca::operator> (Hero& lhs, Hero& rhs) {
	return (lhs.checkPowerLvl() > rhs.checkPowerLvl());
}

// 2 global operator to add a power to a hero.
//#1
bool seneca::operator>> (Power& pow, Hero& hero) {
	if (!pow.isEmpty() && !hero.isEmpty()) {
		hero += pow;
		return true;
	}
	else
	{
		return false;
	}
}
//#2
bool seneca::operator<< (Hero& hero, Power& pow) {
	return pow >> hero;
}

// Destructor to deallocate the memory and set it to a safe empty state.
Hero::~Hero() {
	delete[] m_powers;
	m_powers = nullptr;
}
