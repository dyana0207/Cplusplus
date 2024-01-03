#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include "verem.h"
#include "sor.h"
struct f{
    int db;
    int *p;
    };
using namespace std;
bool vanfia(int, int & , int **, int);
bool balfia(int, int & , int **, int);
void meglatogatott(double );
 bool volt_mar(int, int, int);
 void visszaallit(int&, int&,int **);
int main()
{
    ifstream be;
    string n;
    cout << "Add meg a sorszamot" << endl;
    cin>>n;
    string f="graf";
    f+=n;
    f+=".txt";
    be.open(f.c_str());
    if(be.fail())
        {
            cout<<"Hiba! A fajl nem talalhato"<<endl;
        }
    int kezdo_cs;
    be>>kezdo_cs;
    string szam="";
    string sors="";
    while(!be.eof())
    {
        szam="";
        be>>szam;
        sors+=szam;
    }
    int db_szokoz=sqrt(sors.length());
    cout<<db_szokoz<<endl;
    int **t;
    int sor=db_szokoz, oszlop=db_szokoz;
    t=new int * [sor];
    for(int i=0; i<sor; i++)
    {
        t[i]=new int [oszlop];
    }
    int db=0;
    for(int i=0; i<sor; i++)
    {
        for(int j=0; j<oszlop; j++)
        {
            t[i][j]=sors[db]-48;
            cout.width(3);
            cout<<t[i][j]<<" ";
            db++;
        }
        cout<<endl;
    }
     verem v;
    cout<<"Preorder: "<<endl;
    v.Verembe(kezdo_cs);
   cout<<kezdo_cs<<" ";
    while(!v.Ures())
    {
        double cs=v.veremfelso();
        int fia;
        if(vanfia(cs,fia,t,oszlop))
        {
            cout<<fia<<" ";
            v.Verembe(fia);
        }
        else{
            v.Verembol(cs);
        }
    }
    cout<<endl;
    visszaallit(sor,oszlop,t);
    cout<<"Postorder: "<<endl;
    v.Verembe(kezdo_cs);
    while(!v.Ures())
    {
        double cs=v.veremfelso();
        int fia;
        if(vanfia(cs,fia,t,oszlop))
        {
            v.Verembe(fia);
        }
        else{
            v.Verembol(cs);
            cout<<cs<<" ";
        }
    }
    cout<<endl;
    visszaallit(sor,oszlop,t);
  cout<<"Inorder: "<<endl;
  int m[10],dbb=0;
    v.Verembe(kezdo_cs);
    while(!v.Ures())
    {
        double cs=v.veremfelso();
        int fia;
        if(vanfia(cs,fia,t,oszlop))
        {
            //if(!volt_mar(cs,m,dbb)) m[dbb]=cs;
            v.Verembe(fia);
            if(balfia(cs,fia,t,oszlop))
            {
                 //cout<<cs<<" ";
                 v.Verembe(fia);
            }
            else{
                    v.Verembe(fia);
                v.Verembol(cs);
                  cout<<cs<<" ";
                cout<<fia<<" ";
            }
            ///cout<<fia<<" ";
        }
        else{
            v.Verembol(cs);
            cout<<cs<<" ";
        }
    }
  cout<<endl;
   visszaallit(sor,oszlop,t);
  cout<<"Szelessegi: "<<endl;
  lsor s1;
  s1.Sorba(kezdo_cs);
  while(!s1.Ures())
  {
    double m;
    s1.Sorbol(m);
    cout<<m<<" ";
    int fia;
    while(vanfia(m,fia,t,oszlop))
        {
            s1.Sorba(fia);
        }
  }
  cout<<endl;
/*struct f tomb[oszlop];
for(int i=0; i<sor; i++)
{
    int csucs=db=0;

    for(int j=0; j<oszlop; j++)
    {
        if(t[i][j]==1)
        {
            tomb[i].p=(int*)realloc(p,sizeof(int)*(csucs+1));
            tomb[i].p[csucs]=j+1;
            csucs++;
        }
    }
    tomb[i].db=csucs;
}*/

        return 0;
}
    bool vanfia(int cs, int & fia, int **t, int oszlop)
    {
        for(int i=0; i<oszlop; i++)
        {
            if(t[cs-1][i]==1)
            {
                t[cs-1][i]=-1;
                fia=i+1;
                return true;
            }
        }
        return false;
    }
    bool balfia(int cs, int & fia, int **t, int oszlop)
    {
        int db=0;
        for(int i=0; i< oszlop; i++)
        {
            if(t[cs-1][i]==1)
            {
                db++;
                t[cs-1][i]=-1;
                if(db==1)
                    {
                    fia=i+1;
                    return true;
                }
            }
        }
        return false;
    }
    void visszaallit(int &sor, int &oszlop, int **t)
    {
         for(int i=0; i<sor; i++)
        {
            for(int j=0; j<oszlop; j++)
            {
                if(t[i][j]==-1) t[i][j]=1;
            }
        }

    }
     /*void meglatogatott(double uj)
     {
         int m[15];
         int db=0;
         m[db]=uj;
         db++;
     }*/
    /*bool volt_mar(int cs, int m, int dbb)
     {
         for(int i=0; i<dbb; i++)
            {
               if(m[i]==cs) return true;
            }
            return false;
    }*/

