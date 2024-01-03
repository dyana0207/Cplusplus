#include <iostream>

using namespace std;
int szam(int * , int );
string szamok={"20 1 203 10 9"};
int main()
{
    int db, *t;
    cout<<szam(t,db);
    return 0;
}
int szam(int *t, int db )
{
     t=new int[1];
    db=0;
    for(int i=0; i<szamok.length(); i++)
    {
        while(isdigit(szamok[i]))
        {
            if(db==0)
            {
                t[db]=szamok[i];
                db++;
            }
            else{
                 int *seged=t;
                 t =new int[db+1];
                 for(int i=0; i<db; i++)
                 {
                     t[i]=seged[i];
                 }
                t[db]=szamok[i];
                 db++;
                 delete [] seged;
            }
        }
    }
   // return &t;
    return db;
}
