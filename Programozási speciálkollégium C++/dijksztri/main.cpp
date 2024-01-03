#include <iostream>
#include <fstream>
using namespace std;
int t[100][100],a;
struct dijk{
    bool bejartuk;
    int suly, honnan;
    dijk();
    };
dijk tomb[100];
dijk::dijk()
{
    bejartuk=false;
    suly=0;
    honnan=-1;
}
bool legkisebb_suly(dijk & tomb)
{
      int mini=100;
    for(int i=1; i<=a; i++)
    {
        if(tomb[i].bejartuk==false && tomb[i].suly<mini)
        {
            mini=i;
        }
    }
    return mini;
}
void bejaras(int & t, int a, int k, bool bejartuk, int suly, int honnan)
{
    for(int i=1; i<=a; i++)
    {
      tomb[i]=i;
    }
    k=legkisebb_suly(tomb);
    for(int i=0; i<a; i++)
    {
        if(t[k][i]!>0 && t[k][i]<100)
        {
            if(tomb[k].suly+t[k][i] < tomb[i].suly)
            {
                tomb[i].suly=tomb[k].suly+t[k][i];
                tomb[i].honnan=k;
            }
        }
    }
    tomb[k].bejartuk=true;
}
int main()
{
    cout << "Add meg a szamot!" << endl;
    string n;
    cin>>n;
    ifstream be;
    string f="Dijkstra";
    f+=n;
    f+=".txt";
    be.open(f.c_str());
    be>>a;
    int i=0,j=0;
    while(!be.eof())
    {
        be>>t[i][j];
        if(j==a-1)
        {
            i++;
            j=0;
        }
        else j++;
    }
    cout<<"Csomopontok szama: "<<a<<endl;
    for (i=0; i<a; i++)
    {
        for(j=0; j<a; j++)
        {
            cout.width(5);
            cout<<t[i][j];
        }
        cout<<endl;
    }
    cout<<"Add meg a kiindulasi csomopontot: "<<endl;
    int k;
    cin>>k;
    bejaras(t,9,k,false,0,-1);
    return 0;
}
