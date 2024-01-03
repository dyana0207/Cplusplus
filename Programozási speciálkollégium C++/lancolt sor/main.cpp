#include <iostream>
#include "sor.h"
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    sor s;
    for(int i=0; i<5; i++)
    {
        double a=rand() % 100;
         s.Sorba(a);
    }
    cout<<s;
    cout<<endl;
    sor s1;
    s1=s;
    cout<<s1;
    return 0;
}
