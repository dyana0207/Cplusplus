#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

using namespace std;
void SetColor(int);
bool vanpoztiv(int  , int  ,int &, int);
bool oszlop_poz(int , int , int &, int &);
int generaloelem(int , int , int &, int &);
int generaloelem_nomal(int , int , int &, int &);
void bazistransz(int , int , int & , int &);
void csere_kiir(int &, int & );
void kiir(int, int, int, int);
bool generalo_csillagos(int,int &);
void torol(int, int&,  int);
bool oszlop_poz_normal(int, int, int &, int &);
double t[10][10];
string jel[10];
string sor[10],oszlop[10];
int pozitivindex=0;

int main()
{
    string szam;
    ifstream be;
     cout<<"Add meg a feladat sorszamat: ";
    do{
        system("CLS");
        cout<<"Add meg a feladat sorszamat: ";
        cin>>szam;
        string f="feladat";
        f+=szam;
        f+=".txt";
        be.open(f.c_str());
        if(be.fail())
        {
            cout<<"Hiba! A fajl nem talalhato"<<endl;
            Sleep(2000);
        }

    }
    while(be.fail());
    int sz;
    string b;
    int db=0,db1=0;
    bool nemjo=false;
    while(!be.eof())
    {
        nemjo=false;
        be>>sz;

        if(be.fail())
        {
            be.clear();
            be>>b;
            if(b!="max"){
            jel[db]=b;
            nemjo=true;}

        }
         else{
                t[db][db1]=sz;
                db1++;
        }
        if(nemjo)
        {
            if(jel[db]!="max")
            {
                be>>sz;
                t[db][db1]=sz;
                 db++;
                 db1=0;
            }
        }

    }
    db1++;
    db++;
    cout<<endl;
      for(int i=0; i<db; i++)
    {
        for(int j=0; j<db1; j++)
        {
            cout.width(8);
             cout<<setprecision(2)<<fixed;
            cout<<t[i][j];
            if(j==db1-2)
            {
                cout.width(4);
                cout<<jel[i];
            }
        }
        cout<<endl;
    }
    cout<<endl;
    db++;
     for(int i=0; i<db; i++)
    {
        if(i!=db-2)
        {
            if(jel[i]=="<=")
            {
                sor[i]="u";
                string h="";
                h+=i+49;
                sor[i]+=h;
            }
            else{
                sor[i]="*u";
                string h="";
                h+=i+49;
                sor[i]+=h;
            }
        }
        if(i==db-2){
                sor[i]="-z";
        }
        if(i==db-1){
             sor[i]="*z";
        }
    }
    for(int j=0; j<db1; j++)
    {
        if(j!=db1-1)
        {
            oszlop[j]='x';
            string h="";
            h+=j+49;
            oszlop[j]+=h;
        }
        else{
                oszlop[j]='b';
        }
    }
    for(int i=0; i<db1; i++)
    {
        int ossz=0;
        for(int j=0; j<db; j++)
        {
           if(sor[j][0]=='*')
           {
               ossz+=t[j][i];
           }
        }
        t[db-1][i]=ossz;
    }
     /*for(int i=0; i<db; i++)
    {
        for(int j=0; j<db1; j++)
        {
            cout.width(5);
            cout<<t[i][j];
        }
        cout<<endl;
    }*/
    cout<<endl;
    cout<<"Modositott normal feladat: "<<endl;
    cout<<endl;
    cout<<"Visszavezetes normal feladat: "<<endl;
    cout<<endl;
     int oszlop_id, sor_id,k=0;
    int db2=db1;
    while(vanpoztiv(db,db1,oszlop_id,k))
    {
        if(oszlop_poz(db,db1,oszlop_id,sor_id))
        {
           sor_id=generaloelem(db,db1,oszlop_id,sor_id);
           if(generalo_csillagos(db,sor_id))
           {
               kiir(db, db1,oszlop_id,sor_id);
               csere_kiir(oszlop_id,sor_id);
               bazistransz(db,db1,oszlop_id,sor_id);
                torol(db,db1,oszlop_id);
               k=0;
           }
           else{
                k++;
           }
        }
        else break;

    }
     kiir(db, db1,-1,-1);
     cout<<endl;
     db--;
     bool cs=false;
     for(int i=0; i<db-1; i++)
     {
         if(sor[i][0]=='*')
         {
             cs=true;
         }
     }
     if(cs)
     {
         cout<<"Nincs megoldas"<<endl;
     }
     else{
        cout<<"Normal feladat megoldasa: "<<endl;
        cout<<endl;
         while(vanpoztiv(db,db1,oszlop_id,k))
        {
            if(oszlop_poz_normal(db,db1,oszlop_id,sor_id))
            {
               sor_id=generaloelem_nomal(db,db1,oszlop_id,sor_id);
               kiir(db, db1,oszlop_id,sor_id);
               csere_kiir(oszlop_id,sor_id);
               bazistransz(db,db1,oszlop_id,sor_id);

            }
            else{
                break;
            }
        }
          kiir(db, db1,-1,-1);
        cout<<endl;
         bool f=false;
    for(int i=0; i<db1; i++)
    {
        if(t[db-1][i]==0)
        {
            f=true;
            break;
        }
    }
    if(f && !vanpoztiv(db,db1, oszlop_id,0))
    {
        cout<<"Alternativ optimum: "<<endl;
        for(int i=0; i<db2; i++)
        {
            for(int j=0; j<db2; j++)
            {
                if(oszlop[j][0]=='x' && oszlop[j][1]==i+49)
                {
                    cout.width(5);
                    cout<<setprecision(2)<<fixed;
                    cout<<oszlop[j]<<" = 0"<<endl;

                }
                if(sor[j][0]=='x'&& sor[j][1]==i+49)
                  {
                      cout.width(5);
                      cout<<sor[j]<<" = "<<t[j][db1-1]<<endl;
                  }
            }
        }
        cout.width(12);
        cout<<"max(z) = "<<t[db-1][db1-1]*(-1)<<endl;
    }
    else{
        cout<<"Optimalis megoldas:"<<endl;
         for(int i=0; i<db2; i++)
            {
                for(int j=0; j<db; j++)
                {
                  if(sor[j][0]=='x' && sor[j][1]==i+49)
                  {
                      cout.width(5);
                      cout<<sor[j]<<" = "<<t[j][db1-1]<<endl;
                  }
                  if(oszlop[j][0]=='x' && oszlop[j][1]==i+49)
                    {
                        cout.width(5);
                        cout<<setprecision(2)<<fixed;
                        cout<<oszlop[j]<<" = 0"<<endl;

                    }
                }
            }
            cout.width(12);
            cout<<"max(z) = "<<t[db-1][db1-1]*(-1)<<endl;
        }
    }
    return 0;
}
bool generalo_csillagos(int db,int & sor_id)
{
    if(sor[sor_id][0]=='*') return true;
    return false;
}
bool vanpoztiv(int  db, int  db1, int & oszlop_id, int k)
    {
       bool van=false;
       oszlop_id=0;
           for(int j=k; j<db1-1; j++)
                {
                    if(t[db-1][j]>0)
                    {
                        van=true;
                        oszlop_id=j;
                        break;
                    }
                }
        return van;
    }
bool oszlop_poz(int  db, int  db1, int & oszlop_id, int & sor_id)
{
    bool van=false;
       sor_id=0;
           for(int j=0; j<db-2; j++)
                {
                    if(t[j][oszlop_id]>0)
                    {
                        van=true;
                        sor_id=j;
                        break;
                    }
                }
        return van;
}
bool oszlop_poz_normal(int  db, int  db1, int & oszlop_id, int & sor_id)
{
    bool van=false;
       sor_id=0;
           for(int j=0; j<db-1; j++)
                {
                    if(t[j][oszlop_id]>0)
                    {
                        van=true;
                        sor_id=j;
                        break;
                    }
                }
        return van;
}
 int generaloelem(int  db, int  db1, int & oszlop_id, int & sor_id)
    {
        bool elso=true;
        bool megoldas=true;
        double mini;
        int id;
        for(int i=sor_id; i<db-2; i++)
        {
           if(t[i][oszlop_id]>0)
           {
               if(elso)
               {
                   mini=t[i][db1-1]/t[i][oszlop_id];
                   id=i;
                   elso=false;
               }
               else{
                    if(t[i][db1-1]/t[i][oszlop_id] <= mini)
                    {
                           mini=t[i][db1-1]/t[i][oszlop_id];
                           id=i;
                    }
               }
           }
        }
        return id;

    }
int generaloelem_nomal(int  db, int  db1, int & oszlop_id, int & sor_id)
{
    bool elso=true;
    bool megoldas=true;
    double mini;
    int id;
    for(int i=sor_id; i<db-1; i++)
    {
       if(t[i][oszlop_id]>0)
       {
           if(elso)
           {
               mini=t[i][db1-1]/t[i][oszlop_id];
               id=i;
               elso=false;
           }
           else{
                if(t[i][db1-1]/t[i][oszlop_id] <= mini)
                {
                       mini=t[i][db1-1]/t[i][oszlop_id];
                       id=i;
                }
           }
       }
    }
    return id;

}
void bazistransz(int  db, int db1, int & oszlop_id, int & sor_id)
    {
        for(int i=0; i<db; i++)
        {
            for(int j=0; j<db1; j++)
            {
                if(i!=sor_id && j!=oszlop_id)
                {
                    t[i][j]-=(t[sor_id][j]*t[i][oszlop_id])/t[sor_id][oszlop_id];
                }
            }
        }
        t[sor_id][oszlop_id]=1/t[sor_id][oszlop_id];
        for(int i=0; i<db1; i++)
        {
            if(i!=oszlop_id)
            {
                t[sor_id][i]*=t[sor_id][oszlop_id];
            }
        }
         for(int i=0; i<db; i++)
        {
            if(i!=sor_id)
            {
                t[i][oszlop_id]*=-t[sor_id][oszlop_id];
            }
        }
    }
void csere_kiir(int & oszlop_id, int & sor_id )
{

    string csere=oszlop[oszlop_id];
        oszlop[oszlop_id]=sor[sor_id];
        sor[sor_id]=csere;
}
void torol(int  db, int& db1, int  oszlop_id)
{
    for(int j=oszlop_id; j<db1; j++)
    {
         for(int i=0; i<db; i++)
        {
            t[i][j]=t[i][j+1];
        }
        oszlop[j]=oszlop[j+1];
    }
    db1--;
}

void kiir( int db, int db1,int oszlop_id,int sor_id)
{
    cout.width(13);
    for(int j=0; j<db1; j++)
        {
            if(oszlop[j][0]=='x') SetColor(1);
            if(oszlop[j][0]=='u') SetColor(14);
            cout<< oszlop[j];
            SetColor(15);
            cout.width(10);
        }
        cout<<endl;
        cout.width(5);
    for(int i=0; i<db; i++)
    {

        if(sor[i][0]=='u' || sor[i][0]=='*' && sor[i][1]=='u') SetColor(14);
        if(sor[i][0]=='x') SetColor(1);
        cout.width(5);
        cout<<sor[i];
        SetColor(15);
        for(int j=0; j<db1; j++)
        {
            cout.width(10);
            cout<<setprecision(2)<<fixed;
            if(i==sor_id && j==oszlop_id)  SetColor(2);
                if(i==db-1 || j==db1-1)
                {
                    cout<<t[i][j];
                }
                else{
                    cout<<t[i][j];
                }
            SetColor(15);
        }
        cout<<endl;
    }
    cout<<endl;
}
void SetColor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
