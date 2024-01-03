#include <iostream>
#include "Ido.h"
using namespace std;

int main()
{
   Ido a(10,20,20);
   Ido b(20,20,50);
   Ido c=a+b;
   b+=a;
   cout<<c.getora()<<" :"<<c.getperc()<<" :"<<c.getmasodperc()<<endl;
    cout<<b.getora()<<": "<<b.getperc()<<" :"<<b.getmasodperc()<<endl;
    return 0;
}
