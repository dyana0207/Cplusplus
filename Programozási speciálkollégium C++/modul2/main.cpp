#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
int atmasol (int *, int , int *, int );
bool nincsbenne(int *, int , int );
int belerak(int *, int , int);
int main()
{
    srand(time(0));
    int t1[7]={1,2,6,45,12,3,47};
    int t2[7]={2,5,1,6,59,89,2};
    int t3[14];
    int db;
    atmasol(t1,7,t3,7);
    for(int j=0; j<7; j++)
    {
        if(nincsbenne(t1,7,t2[j]))
        {
            belerak(t3,*db,t2[j]);
        }
    }
    for(int j=0; j<db; j++)
    {
        cout<<t3[j]<<" ";
    }
    return 0;

}
int atmasol (int *t1, int n, int *t3, int db)
{
     db=0;
     for(int i=0; i<n; i++)
    {
        t3[db]=t1[i];
        db++;
    }
}
bool nincsbenne(int *t2, int m, int a)
{
    bool nincs=true;
    for(int j=0; j<m; j++)
      {
            if(t2[j]==a)
               {
                   nincs=false;
               }
      }

        return nincs;
}
int belerak(int *t3, int db, int a)
{
        t3[db++]=a;

}
