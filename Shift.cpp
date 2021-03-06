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

void shift::InData(ifstream &ifst, int &len) {

    string otext;
    string owname;
    getline(ifst, otext);
    setStr(otext);
    ifst >> shiftshar;

    if (ifst.fail()) {
        ifst.clear();
        string error;
        getline(ifst, error);
        cout << "Attention! Error reading element " << len + 1 << endl;
        return;
    }

    shifttext = transform(otext, shiftshar);
    ifst >> owname;
    setowname(owname);
}

void shift::MultiMethod(text *other, ofstream &ofst) {
    other->MMShift(ofst);
}

void shift::MMShift(ofstream &ofst) {
    ofst << "Shift and Shift" << endl;
}

void shift::MMRepl(ofstream &ofst) {
    ofst << "Replace and Shift" << endl;
}

void shift::MMIntRep(ofstream &ofst) {
    ofst << "IntReplace and Shift" << endl;
}

void shift::Out(ofstream &ofst) {

    ofst << "Input text: " << getStr() << endl
        << "Shift: " << shiftshar << endl
        << "Output text: " << shifttext << endl
        << "Owner's name: " << getowname() << endl;
}