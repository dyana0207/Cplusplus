#include <iostream>
#include "verem.h"
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    Verem v;
    for(int i=0; i<10; i++)
    {
        double a=rand() % 90+10;
        cout<<a<<" ";
        v.Verembe(a);
    }
    cout<<endl;
    double a;
    while(v.Verembol(a)){
        cout<<a<<" ";
    }

}
