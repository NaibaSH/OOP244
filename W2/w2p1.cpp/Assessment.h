/*
* WORKSHOP1-PART1
Name: Naiba Shabanova
* StudentEmail: nshabanova@myseneca.ca
* StudentID: 164598229
* Section : ZCC
* Date: Jan 19, 2024
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.

*/
#ifndef ASSESSMENTS_H
#define ASSESSMENTS_H

#include <cstdio>
namespace seneca {
    struct Assessment {
        double* m_mark;
        char* m_title;
    };

    bool read(int& value, FILE* fptr);
    bool read(double& value, FILE* fptr);
    bool read(char* cstr, FILE* fptr);
    bool read(Assessment& assess, FILE* fptr);
    void freeMem(Assessment*& aptr, int size);
    int read(Assessment*& aptr, FILE* fptr);
}
#endif // ASSESSMENTS_H
