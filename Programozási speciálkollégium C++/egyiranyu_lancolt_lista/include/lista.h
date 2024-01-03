#ifndef LISTA_H
#define LISTA_H

#include <iostream>
struct lElem{
    int adat;
    lElem *kovetkezo;
    };
class lista
{
    lElem *Elso, *Utolso, *Akt;
    public:
        lista();
        ~lista();
        lista(const lista& other);
        lista& operator=(const lista& other);

         bool Ures();
         void insertFirst(int);
       void insertLast(int);
       void insertAfter(int);
       bool removeFrist();
       bool removeLast();
       bool removeCurrent();
       bool isFirst();
       bool isLast();
};

#endif // LISTA_H
