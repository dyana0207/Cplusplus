#include <cstdlib>
#include <time.h>
#include "verem.h"
using namespace std;

int main()
{
    srand(time(0));
    verem v;
    for(int i=0; i<10; i++)
    {
        double a=rand() % 90+10;
        cout<<a<<" ";
        v.Verembe(a);
    }
         cout<<endl;

    double a;
    /*while(v.Verembol(a)){
        cout<<a<<" ";
    }*/
    //v1=v;
     /*while(v1.Verembol(a)){
        cout<<a<<" ";
     }
     cout<<endl;
     while(v.Verembol(a)){
        cout<<a<<" ";
     }*/
    //v1.Kiir();
    cout<<endl;
    v.Kiir();
    verem v1=v;
    cout<<endl;
    v1.Kiir();
     cout<<endl;
    v[1];
}
