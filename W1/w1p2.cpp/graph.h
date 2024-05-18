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

#ifndef _SENECA_GRAPH_H
#define _SENECA_GRAPH_H
namespace seneca {

	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);
	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70.
	int findMax(int samples[], int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max, int count);
	// Prints a graph comparing the sample values visually
	void printGraph(int samples[], int noOfSamples, const char* label);

}
#endif