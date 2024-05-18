/*/////////////////////////////////////////////////////////////////////////
                             OOP244 Workshop4 # p1:
Full Name  : Naiba Shabanova
Student ID#: 164598229
Email      : nshabanova@myseneca.ca
Section    : ZCC
Date       : 2024-02-08
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Fridge.h"
#include "Fridge.h"
using namespace std;
using namespace seneca;

const int linelen = 30;

void printDivider(size_t cnt = linelen) {
    for (auto i = 0u; i < cnt; ++i)
        std::cout << "*";
    std::cout << std::endl;
}

void printHeader(const char* head) {
    std::cout << std::endl;
    printDivider(linelen);
    std::cout << head << std::endl;
    printDivider(linelen);
}

int main() {

    printHeader("Empty Fridge");
    Fridge fr;
    fr.display();
    printDivider();

    printHeader("Non Empty Fridge");
    Food fo[2]{
      Food{"Apples", 4}, Food{"Milk", 5}
    };
    Fridge frfr(fo, 2);
    frfr.display();
    printDivider();

    printHeader("Filling Empty Fridge");
    fr.changeModel("So Cold");
    bool act = fr.addFood(Food{ "Brocolli", 10 });
    if (act) fr.display();
    else cout << "Failed to add food (incorrect)" << endl;
    printDivider();

    printHeader("Full Fridge");
    frfr.addFood(Food{ "Eggs", 3 });
    frfr.addFood(Food{ "Yogurt", 3 });
    bool full = frfr.fullFridge();
    if (full) frfr.display();
    else cout << "Fridge isn't full (incorrect)" << endl;
    printDivider();

    printHeader("Find Food");
    bool found = fr.findFood("Brocolli");
    bool notfound = fr.findFood("Eggs");
    if (found) cout << "Found Brocolli (correct)" << endl;
    if (!notfound) cout << "No Eggs here (correct)" << endl;
    printDivider();
}