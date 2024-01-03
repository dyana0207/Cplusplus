#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
using namespace std;

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
    return 0;
}
