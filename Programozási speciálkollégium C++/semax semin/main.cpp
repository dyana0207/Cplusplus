#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
using namespace std;
void SetColor(int);
int main()
{
    cout<<"Syamok"<<endl;
    srand(time(0));
    int m,n,i,j;
    cin>>n>>m;
    int t[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            t[i][j]=rand() % 100-50;
            cout.width(3);
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int maxi=t[0][0], mini=t[0][0];
    j=0;
    int tomb[n][m];
    for(int i=0; i<m; i++)
    {
        maxi=t[0][i];
        mini=t[0][i];
        for(int j=0; j<n; j++)
        {
            tomb[j][i]=t[j][i];
            if(t[j][i]>maxi)
            {
                maxi=t[j][i];
            }

            if(t[j][i]<mini)
            {
                mini=t[j][i];
            }

        }
        /*cout<<maxi<<" "<<mini<<endl;*/
       for(int k=0; k<n;k++)
        {
             if(tomb[k][i]== mini || tomb[k][i]== maxi )
            {
                SetColor(2);
            cout.width(3);
            cout<<tomb[k][i]<<" ";
             SetColor(0);
            }
            else{
            cout.width(3);
            cout<<tomb[k][i]<<" ";
            }
        }
        cout<<endl;
    }
    int db=0;
    int f[m];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(SetColor(2))
            {
                break;
            }
            else
            {
                db++;
                f[db]=i;
            }
        }
    }
    cout<<db<<" darab varos"<<endl;
    for(int i=0; i<db;i++)
    {
        cout<<f[i]<<" ";
    }

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
