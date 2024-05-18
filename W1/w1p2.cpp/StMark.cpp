/*
*                                     OOP244 Workshop1 # p2:
* Name: Naiba Shabanova
* StudentEmail: nshabanova@myseneca.ca
* StudentID: 164598229
* Section : ZCC
* Date: Jan 21, 2024
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.

*/

#include <iostream>
#include <string>
#include <iomanip>
#include "file.h"
#include "StMark.h"
#include "graph.h"
#include "io.h"

using namespace std;

namespace seneca
{
    StMark student[MAX_NO_RECS];
    int recoredsRead = 0;
    int i, j;
    const int printGroup = 10;
    int group[printGroup] = { 0 };
    bool printReport(const char* filename)
    {
        if (openFile(filename)) {
            recoredsRead = readMarks(student);
            for (i = 0; i < MAX_NO_RECS - 1; i++) {
                for (j = 0; j < MAX_NO_RECS - i - 1; j++) {
                    if (student[j].mark < student[j + 1].mark) {
                        swap(student[j], student[j + 1]);
                    }
                }
            }
            for (i = 0; i < recoredsRead; i++)
            {
                if (student[i].mark >= 91 && student[i].mark <= 100)
                {
                    group[0]++;

                }
                else if (student[i].mark >= 81 && student[i].mark <= 90)
                {
                    group[1]++;
                }
                else if (student[i].mark >= 71 && student[i].mark <= 80)
                {
                    group[2]++;
                }
                else if (student[i].mark >= 61 && student[i].mark <= 70)
                {
                    group[3]++;
                }
                else if (student[i].mark >= 51 && student[i].mark <= 60)
                {
                    group[4]++;
                }
                else if (student[i].mark >= 41 && student[i].mark <= 50)
                {
                    group[5]++;

                }
                else if (student[i].mark >= 31 && student[i].mark <= 40)
                {
                    group[6]++;

                }
                else if (student[i].mark >= 21 && student[i].mark <= 30)
                {
                    group[7]++;

                }
                else if (student[i].mark >= 11 && student[i].mark <= 20)
                {
                    group[8]++;

                }
                else if (student[i].mark >= 0 && student[i].mark <= 10)
                {
                    group[9]++;
                }

            }

            printGraph(group, printGroup, "Students' mark distribution");
            string space1, space2;
            for (int i = 0; i < recoredsRead; i++) {
                if (i < 8) {
                    space1 = "  :";
                }
                else if (i > 8 && i < 99) {
                    space1 = " :";

                }
                else if (i >= 99) {
                    space1 = ":";
                }

                if (student[i].mark <= 9) {
                    space2 = "  ]";

                }
                else if (student[i].mark >= 10 && student[i].mark <= 99) {
                    space2 = " ]";

                }
                else if (student[i].mark == 100) {
                    space2 = "]";
                }


                cout << (i + 1) << space1 << " [" << student[i].mark << space2 << " " << student[i].name
                    << " " << student[i].surname << endl;


            }
            cout << "----------------------------------------\n";

            closeFile();
            return true;
        }
        else {
            return false;
        }


    }


}
