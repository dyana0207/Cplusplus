#include <iostream>
#include "lista.h"
using namespace std;

int main()
{
    lista t(5);
    t.insertFirst(20);
    t.insertFirst(4);
    t.insertLast(16);
    t.insertFirst(-6);
    t.insertFirst(99);
    t.Kiir();
    t.setValue(3);
    //lista t1=t;
    //t1.Kiir();
    return 0;
}
