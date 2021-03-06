#include "Intreplace.h"

vector<int> intreplace::transform(string otext, vector<pair<char, int>> A) {

    vector<int> itext;

    for (char i : otext) {
        bool cheknovec = true;
        for (auto & j : A) {
            if (tolower(i) == j.first) {
                itext.push_back(j.second);
                cheknovec = false;
                continue;
            }
        }
        if (cheknovec) {
            itext.push_back(i);
        }
    }
    return itext;
}

void intreplace::InData(ifstream &ifst, int &len) {

    string otext;
    string owname;
    string a1;
    vector<int> a2;
    getline(ifst, otext);
    setStr(otext);
    //getline(ifst, a1);
    getline(ifst, a1);

    int x = a1.length() - (a1.length() - 1)/ 2;
    for (int j = 0; j < x; j++) {
        int t;
        ifst >> t;
        AX.emplace_back(make_pair(a1[j * 2], t));
    }
    inttext = transform(otext, AX);

    ifst >> owname;
    setowname(owname);
}

void intreplace::MultiMethod(text *other, ofstream &ofst) {
    other->MMIntRep(ofst);
}

void intreplace::MMShift(ofstream &ofst) {
    ofst << "Shift and IntReplace" << endl;
}

void intreplace::MMRepl(ofstream &ofst) {
    ofst << "Replace and IntReplace" << endl;
}

void intreplace::MMIntRep(ofstream &ofst) {
    ofst << "IntReplace and IntReplace" << endl;
}

void intreplace::Out(ofstream &ofst) {
    ofst << "Input text: " << getStr() << endl
         << "Starting characters: ";

    for (auto & i : AX) {
        ofst << i.first << ' ';
    }

    ofst << endl << "End symbols:         ";

    for (auto & i : AX) {
        ofst << i.second << ' ';
    }

    ofst << endl << "Output text: ";
    for (auto i : inttext) {
        ofst << i << " ";
    }
    ofst << endl << "Owner's name: " << getowname() << endl;
}