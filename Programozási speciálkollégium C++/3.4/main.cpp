#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    srand(time(0));
    int **t, **t1, **t2;
   cout<<"Adj meg egy szamot"<<endl;
   int n;
   cin>>n;
   t=new int *[n];
    t1=new int *[n];
    for(int i=0; i<n; i++)
    {
        t[i]=new int [n];
        for(int j=0; j<n; j++)
        {
           t[i][j]=rand() % 50;
           cout.width(3);
           cout<<t[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
 for(int i=0; i<n; i++)
    {
        t1[i]=new int [n];
        for(int j=0; j<n; j++)
        {
             t1[i][j]=rand() % 50;
             cout.width(3);
            cout<<t1[i][j];
        }
        cout<<endl;
    }
     t2=new int *[n];
    for(int i=0; i<n; i++)
    {
         t2[i]=new int [n];
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                t2[i][j]+=t[k][j]* t1[i][k];
            }
            cout.width(3);
            cout<<t2[i][j];
        }
          cout<<endl;
    }
    for(int i=0; i<n; i++)
    {
        delete []t[i];
        delete [] t1[i];
        delete[] t2[i];
    }
    delete [] t;
    delete [] t1;
    delete [] t2;
    return 0;
}
