#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;
struct lElem{
    int adat;
    int kovetkezo;
    };
class lista
{
    int maxi,Elso, Utolso, Akt, SzH;
    lElem * t;
    public:
        lista(int);
        ~lista();
        lista(const lista& other);
        lista& operator=(const lista& other);

        bool Tele();
        bool Ures();
        void insertFirst(int);
        void insertLast(int);
        void insertAfter(int);
        bool removeFirst();
        bool removeLast();
        bool removeCurrent();
        bool isFirst();
        bool isLast();
        void Kiir();
        void stepFirst();
        void stepLast();
        void stepForwand();
        void setValue(int );
        bool getValue(int &);

};
#endif // LISTA_H
