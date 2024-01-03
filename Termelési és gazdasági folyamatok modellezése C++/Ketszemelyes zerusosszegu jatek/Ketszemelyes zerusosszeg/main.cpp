#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
using namespace std;
void SetColor(int);
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
            SetColor(4);
            cout<<"Hiba! A fajl nem talalhato"<<endl;
            Sleep(2000);
            SetColor(15);
        }

    }
    while(be.fail());
    int n,m;
    be>>n>>m;
    int tomb[n][m];
    while(!be.eof())
    {
        for(int i=0; i<n; i++)
        {
           for(int j=0; j<m; j++)
           {
               be>>tomb[i][j];
           }
        }
    }
    cout<<endl;
    cout<<"A J1 jatekos strategiai: ";
    SetColor(2);
    for(int i=1; i<=n; i++)
    {
        cout<<i<<" ";
    }
    SetColor(15);
    cout<<endl;
    cout<<"A J2 jatekos strategiai: ";
    SetColor(2);
    for(int i=1; i<=m; i++)
    {
        cout<<i<<" ";
    }
    SetColor(15);
    cout<<endl;
    cout<<endl;
    cout<<"Kifizetesi matrix: "<<endl;
    int oszlop=(m/2)+1;
    int sor=(n/2)+1;
    int tomb1[n+2][m+2];
    SetColor(1);
    for(int i=0; i<m+2; i++)
           {
               if(i==oszlop)
               {
                   cout.width(5+(oszlop*3));
                   cout<<"J2"<<endl;
                   break;
               }
           }
    SetColor(15);
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
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
                if(j==0)
                {
                    if(i!=sor)
                    {
                        SetColor(2);
                        cout.width(5);
                        cout<<i;
                        cout.width(3);
                    }
                    else{
                            SetColor(1);
                            cout<<"J1";
                            cout.width(2);
                            SetColor(2);
                            cout<<i;
                             cout.width(3);
                        }
                }
                else{
                        SetColor(15);
                    cout<<tomb[i-1][j-1];
                     cout.width(3);
                }
            }
        }

        cout<<endl;
    }
    cout<<endl;
    int sor_mini=tomb[0][0], oszlop_maxi=tomb[0][0], mini[n], maxi[m];
    for(int i=0; i<n; i++)
    {
        sor_mini=tomb[i][0];
        for(int j=0; j<m; j++)
        {
            if(tomb[i][j]<sor_mini)
            {
                sor_mini=tomb[i][j];
            }
        }
        mini[i]=sor_mini;
    }
    for(int i=0; i<m; i++)
    {
        oszlop_maxi=tomb[0][i];
        for(int j=1; j<n; j++)
        {
            if(tomb[j][i]>oszlop_maxi)
            {
                oszlop_maxi=tomb[j][i];
            }
        }
        maxi[i]=oszlop_maxi;
    }
    cout<<endl;
    SetColor(1);
    for(int i=0; i<m+2; i++)
           {
               if(i==oszlop)
               {
                   cout.width(5+(oszlop*3));
                   cout<<"J2"<<endl;
                   break;
               }
           }
    SetColor(15);
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
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
            }
            else{
                if(j==0)
                {
                    if(i!=sor)
                    {
                        SetColor(2);
                        cout.width(5);
                        cout<<i;
                        cout.width(3);
                    }
                    else{
                            SetColor(1);
                            cout<<"J1";
                            cout.width(3);
                            SetColor(2);
                            cout<<i;
                             cout.width(3);
                        }
                }
                else{
                    SetColor(15);
                    cout<<tomb[i-1][j-1];
                     cout.width(3);
                }
            if( j==m )
            {
                SetColor(14);
                cout.width(3);
                cout<<mini[i-1];
            }
           }
        }
        cout<<endl;
    }
    cout.width(8);
    SetColor(14);
for(int i=0; i<m; i++)
{
    cout<<maxi[i];
    cout.width(3);
}
SetColor(15);
cout<<endl;
cout<<"Legjobb strategiak, jatek erteke: "<<endl;
SetColor(1);
cout.width(5);
cout<<"J1";
cout.width(5);
cout<<"J2";
SetColor(15);
cout<<endl;
int maxx=mini[0],maxindex=0;
int db=0;
for(int i=1; i<n; i++)
{
    if(mini[i]>maxx)
    {
        maxx=mini[i];
    }
}
int db1=0;
int minn=maxi[0],minindex=0;
for(int i=1; i<m; i++)
{
    if(maxi[i]<minn)
    {
        minn=maxi[i];
    }
}
for(int i=0; i<n; i++)
{
    for(int j=0; j<m; j++)
    {
        if(mini[i]==maxx && maxi[j]==minn)
        {

            if(mini[i]==maxi[j])
            {
                SetColor(2);
                cout.width(5);
                cout<<i+1;
                cout.width(5);
                cout<<j+1;
                cout.width(5);
                SetColor(15);
                cout<<tomb[i][j];
                cout.width(5);
                SetColor(4);
                cout<<"  -egyensulyi pont"<<endl;
            }
            else{
                SetColor(2);
                cout.width(5);
                cout<<i+1;
                cout.width(5);
                cout<<j+1;
                cout.width(5);
                SetColor(15);
                cout<<tomb[i][j]<<endl;
            }
        }
    }
}
SetColor(15);
    return 0;
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
