#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int a,db=0;
    int *pa;

    while(a!=0)
    {
        cout<<"Adj meg egy szamot"<<endl;
        cin>>a;
        if(db==0)
        {
        pa=new int [db];
        pa[db]=a;
        db++;
        }
        else{
            int *paa=pa;
        pa=new int [db+1];
        for(int j=0; j<db;j++)
                {
                    pa[j]=paa[j];
                }
        pa[db]=a;
        db++;
        delete [] paa;
        }
    }
    db--;
    if(a==0)
    {
        system("cls");
        for(int i=db-1; i>0; i--)
        {
            for(int j=0; j<i; j++)
            {
                if(pa[j]>pa[j+1])
                {
                    int csere=pa[j];
                    pa[j]=pa[j+1];
                    pa[j+1]=csere;
                }
            }
        }
    }
    for(int i=0; i<db;i++)
    {
        cout<<pa[i]<<" ";
    }
    return 0;
}
