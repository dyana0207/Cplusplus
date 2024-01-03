#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;
double t[10][10];
string sor[10],oszlop[10];
void SetColor(int);
void kiir1(int, int);
void kiir_atalakitott(int, int,int);
bool vanpoztiv(int  , int  ,int &);
bool oszlop_poz(int , int , int &, int &);
int generaloelem(int , int , int &, int &);
void bazistransz(int , int , int & , int &);
void csere_kiir(int &, int & );
void kiir(int, int, int, int, int);
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
    int db=0,db1=0,i=0,j=0;
    be>>db;
    be>>db1;
    while(!be.eof())
    {
        be>>sz;
        t[i][j]=sz;
        j++;
        if(j==db1)
        {
            i++;
            j=0;
        }

    }
    db++;
    db1++;
    cout<<endl;
    cout<<"J1 jatekos strategiaja: ";
    for(int i=1; i< db; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"J2 jatekos strategiaja: ";
    for(int j=1; j<db1; j++)
    {
        cout<<j<<" ";
    }
    cout<<endl;
    kiir1(db,db1);
    int novekmeny=0;
    bool neg=false;
     for(int i=0; i<db; i++)
    {
        for(int j=0; j<db1; j++)
        {
            if(t[i][j]<novekmeny)
            {
                novekmeny=t[i][j];
                neg=true;
            }
        }
    }
    cout<<endl;
    if(neg)
    {
        novekmeny=(-1)*novekmeny +1;
        for(int i=0; i<db; i++)
        {
            for(int j=0; j<db1; j++)
            {
                t[i][j]+=novekmeny;
            }
        }
        cout<<"Atalakított kifizetesi matrix (novekmeny : "<< novekmeny<<") :"<<endl;
        kiir_atalakitott(db,db1,0);
    }
    else{
        cout<<"Atalakított kifizetesi matrix (novekmeny : 0) :"<<endl;
        kiir1(db,db1);
    }
    cout<<endl;
    cout<<"Jelenitsuk meg a szamitas menetet (I/N)"<<endl;
    char kerdes;
    do{
        kerdes=getch();
    }
    while(tolower(kerdes)!='i' && tolower(kerdes)!='n');
     for(int i=0; i<db; i++)
    {
        for(int j=0; j<db1; j++)
        {
            if(j==db1-1 && i!=db-1)
            {
                t[i][j]=1;
            }
            if(i==db-1 && j!=db1-1)
            {
                t[i][j]=1;
            }

        }
    }
     t[db-1][db1-1]=0;
    for(int i=0; i<db; i++)
    {
        if(i!=db-1)
        {
            sor[i]='x';
            string h="";
            h+=i+49;
            sor[i]+=h;
        }
        else{
                sor[i]="-z";
        }
    }
    for(int j=0; j<db1; j++)
    {
        if(j!=db1-1)
        {
            oszlop[j]='y';
            string h="";
            h+=j+49;
            oszlop[j]+=h;
        }
        else{
                oszlop[j]='b';
        }
    }
    int oszlop_id, sor_id;
    if(kerdes=='I')
    {
         while(vanpoztiv(db,db1,oszlop_id))
        {
            if(oszlop_poz(db,db1,oszlop_id,sor_id))
            {
               sor_id=generaloelem(db,db1,oszlop_id,sor_id);
               kiir(db, db1,oszlop_id,sor_id,novekmeny);
               csere_kiir(oszlop_id,sor_id);
               bazistransz(db,db1,oszlop_id,sor_id);
            }
            else break;
        }
    kiir(db, db1,-1,-1,novekmeny);
    }
    else{
         while(vanpoztiv(db,db1,oszlop_id))
        {
            if(oszlop_poz(db,db1,oszlop_id,sor_id))
            {
               sor_id=generaloelem(db,db1,oszlop_id,sor_id);
               csere_kiir(oszlop_id,sor_id);
               bazistransz(db,db1,oszlop_id,sor_id);
            }
            else break;
        }
    }
    double a;
    cout<<endl;
cout<<"J1 jatekos strategiai valasztasa:"<<endl;
for(int j=0; j<db-1; j++)
    {
        bool van=false;
        for(int i=0; i<db-1; i++)
        {
            if(oszlop[i][0]=='x' && oszlop[i][1]==j+49)
            {
                van=true;
            }
        }
        if(van){
                cout<<setprecision(0)<<fixed;
                a=(-1)/t[db-1][db1-1];
                SetColor(2);
                cout<< j+1;
                   SetColor(15);
                cout<<" - ";
                   SetColor(4);
                cout<<((-1)*t[db-1][j])*a*100<<" % ";
                cout.width(4);
                   SetColor(15);
        }
        else{
                    SetColor(2);
                    cout<< j+1;
                    SetColor(15);
                    cout<<" - ";
                    SetColor(4);
                    cout<<"0%";
                    cout.width(4);
                    SetColor(15);
        }
}
cout<<endl;
cout<<endl;
cout<<"J2 jatekos strategiai valasztasa:"<<endl;
for(int j=0; j<db1-1; j++)
    {
        bool van=false;
        for(int i=0; i<db1-1; i++)
        {
            if(sor[i][0]=='y' && sor[i][1]==j+49)
            {
                van=true;
            }
        }
        if(van){
                cout<<setprecision(0)<<fixed;
                a=(-1)/t[db-1][db1-1];
                SetColor(2);
                cout<< j+1;
                SetColor(15);
                cout<<" - ";
                SetColor(4);
                cout<<(t[j][db1-1])*a*100<<" % ";
                cout.width(4);
                SetColor(15);
        }
        else{
                SetColor(2);
             cout<< j+1;
              SetColor(15);
            cout<<" - ";
            SetColor(4);
            cout<<"0%";
            cout.width(4);
            SetColor(15);
        }
}
cout<<endl;
cout<<endl;
cout<<"A jatek varhato erteke: ";
cout<<setprecision(2)<<fixed;
cout<<a-novekmeny<<endl;

    return 0;
}
void kiir1(int db, int db1)
{
    int oszlop=(db1/2)+1;
    SetColor(1);
    for(int i=0; i<db1+2; i++)
           {
               if(i==oszlop)
               {
                   cout.width(3+(oszlop*3));
                   cout<<"J2"<<endl;
                   break;
               }
           }
    SetColor(15);
    for(int i=0; i<db; i++)
    {
        for(int j=0; j<db1; j++)
        {
            if(i==0)
            {
                if(j==0)
                {
                    cout.width(8);
                }
                else{
                    SetColor(2);
                    cout<<j;
                    cout.width(3);

                }
                SetColor(15);
            }
            else{
                    if(j==0){
                    SetColor(2);
                    cout.width(5);
                    cout<<i;
                    SetColor(15);
                    }
                    else{
                    cout.width(3);
                    cout<<t[i-1][j-1];
                    }
                }

        }

        cout<<endl;
    }

}
void kiir_atalakitott(int db, int db1, int novekmeny)
{
    int oszlop=(db1/2)+1;
    SetColor(1);
    for(int i=0; i<db1+2; i++)
           {
               if(i==oszlop)
               {
                   cout.width(5+(oszlop*3));
                   cout<<"J2"<<endl;
                   break;
               }
           }
    SetColor(15);
    for(int i=0; i<db; i++)
    {
        for(int j=0; j<db1; j++)
        {
            if(i==0)
            {
                if(j==0)
                {
                    cout.width(8);
                }
                else{
                    SetColor(2);
                    cout<<j;
                    cout.width(3);

                }
                SetColor(15);
            }
            else{
                    if(j==0){
                    SetColor(2);
                    cout.width(5);
                    cout<<i;
                    SetColor(15);
                    }
                    else{
                    cout.width(3);
                    cout<<t[i-1][j-1]+novekmeny;
                    }
                }

        }

        cout<<endl;
    }
}
bool vanpoztiv(int  db, int  db1, int & oszlop_id)
    {
       bool van=false;
       oszlop_id=0;
           for(int j=0; j<db1-1; j++)
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
                    if(t[i][db1-1]/t[i][oszlop_id] < mini)
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
void kiir( int db, int db1,int oszlop_id,int sor_id, int novekmeny)
{
    cout.width(13);
    for(int j=0; j<db1; j++)
        {
            if(oszlop[j][0]=='y') SetColor(2);
            if(oszlop[j][0]=='x') SetColor(1);
            if(oszlop[j][0]=='b') SetColor(4);
            cout<< oszlop[j];
            SetColor(15);
            cout.width(10);
        }
        cout<<endl;
        cout.width(5);
    for(int i=0; i<db; i++)
    {
        if(sor[i][0]=='y') SetColor(2);
        if(sor[i][0]=='x') SetColor(1);
        if(sor[i][0]=='-') SetColor(4);
        cout.width(5);
        cout<<sor[i];
        SetColor(15);
        for(int j=0; j<db1; j++)
        {
            cout.width(10);
            cout<<setprecision(2)<<fixed;
            if(i==sor_id && j==oszlop_id)  SetColor(5);
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
void csere_kiir(int & oszlop_id, int & sor_id )
{

    string csere=oszlop[oszlop_id];
        oszlop[oszlop_id]=sor[sor_id];
        sor[sor_id]=csere;
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
