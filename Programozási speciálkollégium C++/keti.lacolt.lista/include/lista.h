#ifndef LISTA_H
#define LISTA_H

#include <iostream>
struct lElem{
    int adat;
    lElem * elozo, *kovetkezo;
    };
class lista
{
    lElem *Elso, *Utolso, *Akt;
    public:
        lista();
        ~lista();
        lista(const lista& other);
        lista& operator=(const lista& other);

       void insertFirst(int);
       void insertLast(int);
       void insertBefore(int);
       void insertAfter(int);
       bool removeFrist(int &);
       bool removeLast(int &);
       bool removeCurrent(int &);
        bool isLast();
        bool isFirst();
        bool Ures();
        void stepFirst();
        void stepLast();
        bool stepForwand();
        bool stepBackward();
        void setValue(int);
        int getValue();
        void Torol();

};

#endif // LISTA_H
