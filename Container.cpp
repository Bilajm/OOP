#include "Container.h"

container::container() {len = 0; }

void container::In(ifstream &ifst) {
    while(!ifst.eof()) {
        text *t;
        if ((t = text::In(ifst, len)) != nullptr) {
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

        if (head == nullptr) {
            tail = nullptr;
        } else {
            tail->setNext(nullptr);
        }
    }
}

void container::Out(ofstream &ofst) {

    text *t;
    t = head;
    ofst << "Container " << len << " elements." << endl << endl;
    for(int i = 0; i < len; i++) {
        ofst << i + 1 << ": ";
        t->Out(ofst);
        t = t->getNext();
        ofst << endl;
    }
}

void container::Lenotext(ofstream &ofst) {

    text *t;
    t = head;
    ofst << "Container " << len << " elements." << endl << endl;
    for(int i = 0; i < len; i++) {
        ofst << i + 1 << ": ";
        t->Out(ofst);
        ofst << "Message length: "
             << t->Lenotext() << endl;
        t = t->getNext();
        ofst << endl;
    }
}

void container::Sort() {
    for (int i = 0; i < len; i++) {
        text *iter = head;
        while (iter != tail) {
            if (iter->Compare(*iter->getNext())) {
                text *tmp = iter->getNext();
                if (iter->getPrev() == nullptr) {
                    tmp->getNext()->setPrev(iter);
                    tmp->setPrev(iter->getPrev());
                    iter->setNext(tmp->getNext());
                    tmp->setNext(iter);
                    iter->setPrev(tmp);
                    head = tmp;
                } else if (tmp->getNext() == nullptr) {
                    iter->getPrev()->setNext(tmp);
                    tmp->setPrev(iter->getPrev());
                    iter->setNext(tmp->getNext());
                    tmp->setNext(iter);
                    iter->setPrev(tmp);
                    tail = iter;
                } else {
                    iter->getPrev()->setNext(tmp);
                    tmp->getNext()->setPrev(iter);
                    tmp->setPrev(iter->getPrev());
                    iter->setNext(tmp->getNext());
                    tmp->setNext(iter);
                    iter->setPrev(tmp);
                }
            }
            if (iter != tail)
                iter = iter->getNext();
        }
    }
}

void container::OutRep(ofstream &ofst) {

    text *t;
    t = head;
    ofst << "Only replace." << endl << endl;
    for(int i = 0; i < len; i++) {
        ofst << i + 1 << ": ";
        t->OutRep(ofst);
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



