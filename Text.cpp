#include "Text.h"
#include "Replace.h"
#include "Shift.h"

using namespace std;

bool text::Compare(text &other) {
    return Lenotext() < other.Lenotext();
}

text* text::In(ifstream &ifst) {
    text *sp;
    int k;
    ifst >> k;

    switch(k) {
        case 1:
            sp = new shift;
            break;
        case 2:
            sp = new replace;
            break;
        default:
            return nullptr;
    }

    sp->InData(ifst);
    return sp;
}

