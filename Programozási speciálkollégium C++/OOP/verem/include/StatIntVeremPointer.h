#ifndef STATINTVEREMPOINTER_H
#define STATINTVEREMPOINTER_H

#include <iostream>
class StatIntVeremPointer
{
     const int max_elem;
    int verem[10];
    int *felso;
    public:
        StatIntVeremPointer();

        bool Verembe(int);
        int Verembol ();
        bool Ures() const;
        bool Televan() const;
        int Elemszam() const;

};

#endif // STATINTVEREMPOINTER_H
