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
#include "graph.h"
#include "io.h"
using namespace std;
const int GRAPH_WIDTH = 65;
const int MAX_NO_OF_SAMPLES = 20;
namespace seneca {

    // Fills the samples array with the statistic samples
    void getSamples(int samples[], int noOfSamples) {
        int i;
        for (i = 0; i < noOfSamples; i++) {
            line(38);
            cout << "\\ " << (i + 1) << "/";
            printInt(noOfSamples, 2);
            cout << ":                    /";
            goBack(20);
            samples[i] = getInt(1, 1000000);
        }
    }

    // finds the largest sample in the samples array, if it is larger than GRAPH_WIDTH,
    // otherwise it will return GRAPH_WIDTH.
    int findMax(int samples[], int noOfSamples) {
        int max = samples[0];
        int i;
        for (i = 1; i < noOfSamples; i++) {
            if (max < samples[i]) max = samples[i];
        }
        return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
    }

    // prints a scaled bar relevant to the maximum value in samples array
    void printBar(int val, int max, int count) {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        if (count == 100) {
            cout << count << " | ";
        }
        else {
            cout << count << "  | ";
        }
        for (i = 0; i < barlength; i++) {
            cout << "*";
        }
        cout << " ";
        printInt(val, (GRAPH_WIDTH + 6 - barlength));
        cout << "|" << endl;
    }

    // prints a graph comparing the sample values visually
    void printGraph(int samples[], int noOfSamples, const char* label) {
        int max = findMax(samples, noOfSamples);
        labelLine(GRAPH_WIDTH + 10, label);
        int count = 100;
        for (int i = 0; i < noOfSamples; i++) {
            printBar(samples[i], max, count);
            count = count - 10;

        }
        line(GRAPH_WIDTH + 10);
    }

}
