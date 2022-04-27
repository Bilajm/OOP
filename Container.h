#ifndef OOP_CONTAINER_H
#define OOP_CONTAINER_H
#include "Text.h"

using namespace std;

class container {
    text *head; // первый элемент
    text *tail; // послдний элемент
    int len; // текущая длина
public:
    void In(ifstream &ifst); // ввод фигур
    void Out(ofstream &ofst); // вывод фигур
    void Lenotext(ofstream &ofst);
    void Clear(); // очистка контейнера от фигур
    void Sort();
    //void push_back(text* t);
    container(); // инициализация контейнера
    ~container() {Clear();} // утилизация контейнера
};

#endif //OOP_CONTAINER_H
