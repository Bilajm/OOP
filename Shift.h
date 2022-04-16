#ifndef OOP_SHIFT_H
#define OOP_SHIFT_H
#include "Text.h"

class shift: public text{
    int shiftshar;
    string shifttext;
public:
    void InData(ifstream &ifst);
    void Out(ofstream &ofst);
    static string transform(string otext, int shift);
    shift() {}
};
#endif //OOP_SHIFT_H
