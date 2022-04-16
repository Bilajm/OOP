#include "Shift.h"
#include <string>

string shift::transform(string otext, int shift) {

    string stext = "";
    string eng_alph = "abcdefghijklnmopqrstuvwxyz";
    int strsize = otext.length();
    int alpsize = eng_alph.length();

    for (int i = 0; i < strsize; i++) {
        bool chektoup = false;
        int pos;
        if (eng_alph.find(tolower(otext[i])) == string::npos) {
            stext.push_back(otext[i]);
            continue;
        }
        if (isupper(otext[i]) == true) {
            chektoup = true;
            otext[i] = tolower(otext[i]);
        }
        pos = (eng_alph.find(otext[i]) + shift) % alpsize;

        if (chektoup == true) {
            stext.push_back(toupper(eng_alph[pos]));

        } else {
            stext.push_back(eng_alph[pos]);
        }
    }
    return stext;
}

void shift::InData(ifstream &ifst) {

    string otext;
    getline(ifst, otext);
    ifst >> shiftshar;
    setStr(otext);
    shifttext = transform(otext, shiftshar);
}

void shift::Out(ofstream &ofst) {

    ofst << "Input text: " << getStr() << endl
        << "Shift: " << shiftshar << endl
        << "Output text: " << shifttext << endl;
}