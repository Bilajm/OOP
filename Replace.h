#ifndef OOP_REPLACE_H
#define OOP_REPLACE_H
#include <vector>
#include <utility>
#include "Text.h"

class replace: public text{
    vector<pair<char, char>> AA;
    string repltext;
public:
    void InData(ifstream &ifst);
    void Out(ofstream &ofst);
    static string transform(string otext,vector<pair<char, char>> A);
    void OutRep(ofstream &ofst);
    replace() {}
};

#endif //OOP_REPLACE_H
