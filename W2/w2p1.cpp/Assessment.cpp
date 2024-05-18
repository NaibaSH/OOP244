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
#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"
#include <cstring>
#include <iostream>

namespace seneca {

    bool read(int& value, FILE* fptr) {
        return fscanf(fptr, "%d", &value) == 1;
    }

    bool read(double& value, FILE* fptr) {
        return fscanf(fptr, "%lf", &value) == 1;
    }

    bool read(char* cstr, FILE* fptr) {
        return fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
    }

    bool read(Assessment& assess, FILE* fptr) {
        double tempMark;
        char tempTitle[61];

        if (fscanf(fptr, "%lf,%60[^\n]\n", &tempMark, tempTitle) == 2) {
            assess.m_mark = new double;
            *assess.m_mark = tempMark;

            assess.m_title = new char[strlen(tempTitle) + 1];
            strcpy(assess.m_title, tempTitle);

            return true;
        }

        return false;
    }

    void freeMem(Assessment*& aptr, int size) {
        if (aptr == nullptr)
            return;

        for (int i = 0; i < size; ++i) {
            delete aptr[i].m_mark;
            delete[] aptr[i].m_title;
        }

        delete[] aptr;
        aptr = nullptr;
    }

    int read(Assessment*& aptr, FILE* fptr) {
        int numRecords;
        if (fscanf(fptr, "%d", &numRecords) != 1) {
            return 0; // Failed to read the number of records
        }

        aptr = new Assessment[numRecords];

        int numReads = 0;
        for (int i = 0; i < numRecords; ++i) {
            if (read(aptr[i], fptr)) {
                numReads++;
            }
            else {
                break; // Stop reading if read fails
            }
        }

        if (numReads != numRecords) {
            freeMem(aptr, numReads);
            return 0;
        }

        return numRecords;
    }
}