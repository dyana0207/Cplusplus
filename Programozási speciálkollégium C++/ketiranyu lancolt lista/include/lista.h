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
       bool removeFrist();
       bool removeLast();
       bool removeCurrent();
        bool isLast();
        bool isFirst();
        bool Ures();
        /*stepFirst();
        stepLast();
        stepForwand();
        stepBackward();
        setValue(int);
        getValue();*/

};

#endif // LISTA_H
