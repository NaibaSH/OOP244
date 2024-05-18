/*
* Name: Naiba Shabanova
* StudentEmail: nshabanova@myseneca.ca
* StudentID: 164598229
* Section : ZCC
* Date: Jan 19, 2024
* I have done all the coding by myself and only copied the code
* that my professor provided to complete my workshops and assignments.

*/

#include <iostream>
//#include <iomanip>
#include "graph.h"
#include "io.h"

using namespace std;


namespace seneca {

    void getSamples(int samples[], int noOfSamples) {
        int i;
        for (i = 0; i < noOfSamples; i++) {
            line(28);
            cout << "\\ " << (i + 1) << "/";
            printInt(noOfSamples, 2);
            cout << ":                    /";
            goBack(20);
            samples[i] = getInt(1, 1000000);
        }
    }

    int findMax(int samples[], int noOfSamples) {
        int max = samples[0];
        int i;
        for (i = 1; i < noOfSamples; i++) {
            if (max < samples[i]) max = samples[i];
        }
        return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
    }

    void printBar(int val, int max) {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        cout << "| ";
        for (i = 0; i < barlength; i++) {
            cout << "*";
        }
        cout << " ";
        printInt(val, (GRAPH_WIDTH + 6 - barlength));
        cout << "|" << endl;
    }

    void printGraph(int samples[], int noOfSamples, const char* label) {
        int max = findMax(samples, noOfSamples);
        labelLine(GRAPH_WIDTH + 10, label);
        for (int i = 0; i < noOfSamples; i++) {
            printBar(samples[i], max);
        }
        line(GRAPH_WIDTH + 10);
    }


}


