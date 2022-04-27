#include "Replace.h"

int long long replace::Lenotext() {

    string otext = getStr();
    return otext.length();
}

string replace::transform(string otext, vector<pair<char, char>> A) {

    string rtext = "";
    int strsize = otext.length();

    for (int i = 0; i < strsize; i++) {
        bool chektoup = false;
        bool cheknovec = true;

        if (isalpha(otext[i]) == false) {
            rtext.push_back(otext[i]);
            continue;
        }
        if (isupper(otext[i]) == true) {
            chektoup = true;
            otext[i] = tolower(otext[i]);
        }
        for (auto & j : A) {
            if (otext[i] == j.first) {
                if (chektoup) {
                    rtext.push_back(toupper(j.second));
                } else {
                    rtext.push_back(j.second);
                }
                cheknovec = false;
                continue;
            }
        }
        if (chektoup && cheknovec) {
            rtext.push_back(toupper(otext[i]));
        } else if (!chektoup && cheknovec) {
            rtext.push_back(otext[i]);
        }

    }

    return rtext;
}

void replace::InData(ifstream &ifst) {

    string otext;
    string owname;
    string a1;
    string a2;
    getline(ifst, otext);
    setStr(otext);
    getline(ifst, a1);
    getline(ifst, a2);

    AA.resize((a1.length()));
    for (int j = 0; j < a1.length(); j++) {
        AA[j] = make_pair(a1[j], a2[j]);
        //AA.emplace_back(make_pair(a1[j], a2[j]));
    }
    repltext = transform(otext, AA);

    ifst >> owname;
    setowname(owname);
}

void replace::Out(ofstream &ofst) {
    ofst << "Input text: " << getStr() << endl
         << "Starting characters: ";

    for (auto & i : AA) {
        ofst << i.first << ' ';
    }
    ofst << endl << "End symbols:         ";

    for (auto & i : AA) {
        ofst << i.second << ' ';
    }

    ofst << endl << "Output text: " << repltext << endl
            << "Owner's name: " << getowname() << endl;
}

void replace::OutRep(ofstream &ofst) {
    Out(ofst);
}