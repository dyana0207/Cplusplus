#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>

using namespace std;
bool prim(int);
int main()
{
    srand(time(0));
    int a;
    cout << "Add meg a syamot" << endl;
    cin>>a;
   if(prim(a))
   {
      cout << "Nem prim" << endl;
   }
   else{cout << "prim" << endl;}
   int t[10];
   int *tomb=new int[10];
   for(int i=0; i<10;i++)
   {
       t[i]=rand() % 50;
        cout<<t[i]<<" ";
   }
    int db=0;
   cout<<endl;
   for(int i=0; i<10;i++)
   {
       if(!prim(t[i]))
       {
          tomb[db]=t[i];
          db++;
       }
   }
   for(int i=0; i<db; i++)
   {
       cout<<tomb[i]<<" ";
   }

    return 0;
}
bool prim(int a)
{
    int db=0;
    int i=1;
    while(i<=sqrt(a))
    {
        if(a%i==0)
        {
            db++;
        }
        i++;
    }
    if(db>=2)
    {
        return true;
    }


}
