#include "Intreplace.h"

int long long intreplace::Lenotext() {

    string otext = getStr();
    return otext.length();
}

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

void intreplace::InData(ifstream &ifst) {

    string otext;
    string owname;
    string a1;
    vector<int> a2;
    getline(ifst, otext);
    setStr(otext);
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