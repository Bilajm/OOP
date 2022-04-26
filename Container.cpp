#include "Container.h"

container::container() {len = 0; }

void container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        text *t;
        if ((t = text::In(ifst)) != nullptr) {
            if (len == 0) {
                head = t;
                tail = t;
                len++;
                t->setPrev(nullptr);
            } else {
                tail->setNext(t);
                t->setPrev(tail);
                tail = t;
                len++;
            }
        }
        tail->setNext(nullptr);
    }
}

void container::Out(ofstream &ofst) {

    text *t;
    t = head;
    ofst << "Container " << len << " elements." << endl << endl;
    for(int i = 0; i < len; i++) {
        ofst << i << ": ";
        t->Out(ofst);
        t = t->getNext();
        ofst << endl;
    }
}

void container::Clear() {

    while (head) {
        tail = head;
        head = head->getNext();
        delete tail;
    }

    len = 0;
    tail = nullptr;
}



