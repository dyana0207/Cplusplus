#include <iostream>
#include <time.h>
#include <cstdlib>
#include "StatIntVerem.h"
#include "StatIntVeremPointer.h"
using namespace std;

int main()
{
    srand(time(0));
    StatIntVeremPointer v;
    for(int i=0; i<v.Elemszam(); i++){
        int a=rand() % 90+10;
        cout<<a<<" ";
        v.Verembe(a);
    }
    cout<<endl;
    for(int i=0; i<v.Elemszam(); i++){
       cout<< v.Verembol()<<" ";
    }
}

