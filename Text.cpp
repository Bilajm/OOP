#include "Text.h"
#include "Replace.h"
#include "Intreplace.h"
#include "Shift.h"

using namespace std;

bool text::Compare(text &other) {
    return Lenotext() < other.Lenotext();
}

text* text::In(ifstream &ifst, int &len) {
    text *sp;
    int k;
    ifst >> k;

    if (ifst.fail()) {
        ifst.clear();
        string error;
        getline(ifst, error);
        cout << "Attention! Error reading element " << len + 1 << ". Check the correctness of input elements " << len << " and "<< len + 1 << "." << endl;
        return nullptr;
    }
    //cout << "Good!" << endl;

    switch(k) {
        case 1:
            sp = new shift;
            break;
        case 2:
            sp = new replace;
            break;
        case 3:
            sp = new intreplace;
            break;
        default:
            return nullptr;
    }

    sp->InData(ifst, len);
    return sp;
}

void text::OutRep(ofstream &ofst) {
    ofst << endl;
}

int long long text::Lenotext() {

    string otext = getStr();
    return otext.length();
}
