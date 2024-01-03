#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

int main()
{
    srand(time(0));
    int t[50];
    for(int i=0; i<50; i++)
    {
        t[i]=rand() % 15;
        cout<<t[i]<<" ";
    }
    cout<<endl;
    int db=0, db1=0;
    int *pt;
    pt=t;
    for(int i=0; i<50; i++)
    {db1=0;
        for(int j=i+1; j<50; j++)
        {
            if(t[j]==t[i] && t[j]!=0)
            {
                db1++;
                if(db1==1)
                {
                    *(pt+db)=t[i];
                     db++;
                     t[j]=0;
                }
                t[j]=0;
            }
        }
    }
    delete [] pt;
    for(int i=0; i<db; i++)
    {
        cout<<*(pt+i)<<" ";
    }
    return 0;
}
