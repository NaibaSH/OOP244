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

#ifndef StMark_h
#define StMark_h

namespace seneca {
    /// <summary>
    /// Record of a mark received by a student.
    /// </summary>

    struct StMark {
        char name[21];
        char surname[31];
        int mark;
    };

    bool printReport(const char* filename);


}
#endif /* StMark_hpp */



