#ifndef OOP_SHIFT_H
#define OOP_SHIFT_H
#include "Text.h"

class shift: public text{
    int shiftshar;
    string shifttext;
public:
    void InData(ifstream &ifst, int &len);
    void Out(ofstream &ofst);
    static string transform(string otext, int shift);

    void MultiMethod(text *other, ofstream &ofst);
    void MMShift(ofstream &ofst);
    void MMRepl(ofstream &ofst);
    void MMIntRep(ofstream &ofst);
    shift() {}
};

#endif //OOP_SHIFT_H
