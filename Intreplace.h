#ifndef OOP_INTREPLACE_H
#define OOP_INTREPLACE_H
#include "Text.h"
#include <vector>
#include <utility>

using namespace std;

class intreplace: public text {
    vector<pair<char, int>> AX;
    vector<int> inttext;
public:
    void InData(ifstream &ifst);
    void Out(ofstream &ofst);
    static vector<int> transform(string otext, vector<pair<char, int>> A);
    intreplace() {}
};

#endif

