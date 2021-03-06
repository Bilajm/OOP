#ifndef OOP_TEXT_H
#define OOP_TEXT_H
#include <fstream>
#include <iostream>

using namespace std;

class text {
    string opentext;
    string ownername;
    text* next;
    text* prev;
public:
    static text* In(ifstream &ifst, int &len);
    virtual void InData(ifstream &ifst, int &len) = 0;
    virtual void Out(ofstream &ofst) = 0;
    virtual void OutRep(ofstream &ofst);
    int long long Lenotext();
    bool Compare(text &other);

    virtual void MultiMethod(text *other, ofstream &ofst) = 0;
    virtual void MMShift(ofstream &ofst) = 0;
    virtual void MMRepl(ofstream &ofst) = 0;
    virtual void MMIntRep(ofstream &ofst) = 0;

    void setStr(string otext) {opentext = otext;}
    string getStr() {return opentext;}
    void setowname(string owname) {ownername = owname;}
    string getowname() {return ownername;}
    text* getNext() {return next;}
    void setNext(text *t) {next = t;}
    text* getPrev() {return prev;}
    void setPrev(text *t) {prev = t;}
protected:
    text() {}
};

#endif //OOP_TEXT_H
