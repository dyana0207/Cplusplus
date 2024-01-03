#include <iostream>
#include <math.h>
using namespace std;
int szam(string);
bool arms(string);
 void szam(string, int);
int main()
{
    string a;
    cout << "add meg a szamot!" << endl;
    cin>>a;
    szam(a);
    arms(a);
    if (arms(a))
    {
        cout<<"Armstrong"<<endl;
    }
    else
    {
        cout<<"Nem armstrong"<<endl;
    }
    return 0;
}
int szam(string a)
{
    int k=a.length();
    cout<<k;
}
bool arms( string a)
{
    int k=a.length();
    int m=0;
    for(int i=1; i<=k; i++)
            {
                m+=pow(a[i],k);
            }
    if(m==a)
    {
        return true;
    }
}
