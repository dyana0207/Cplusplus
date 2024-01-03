#include <iostream>
#include <fstream>
using namespace std;
int t[100][100],a;
void ut(int **, int , int);
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
    for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
            {
                  cout.width(5);
                cout<<t[i][j];

            }
            cout<<endl;
        }
    int **kozbulso=new int *[a];
 for(int i=0; i<a; i++)
    {
        kozbulso[i]=new int[a];
        for(int j=0; j<a; j++)
        {
           kozbulso[i][j]=-1;
        }
    }
    for(int k=0; k<a; k++)
    {
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
            {
                if(t[i][j]>t[i][k]+t[k][j])
                {
                    t[i][j]=t[i][k]+t[k][j];
                    kozbulso[i][j]=k+1;
                }
            }
        }
    }
    cout<<"Megoldas"<<endl;
    for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
            {
                 cout.width(5);
                cout<<t[i][j];

            }
            cout<<endl;
        }
    cout<<endl;
     for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
            {
                 cout.width(5);
                cout<<kozbulso[i][j];

            }
            cout<<endl;
        }
    cout<<"Legrovidebb utak "<<endl;
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<a; j++)
        {
            cout<<i+1<<"-->"<<j+1;
            if(t[i][j]==0 || t[i][j]==100) cout<<" Nincs ut";
            else if(kozbulso[i][j]== -1){
                cout<<" Ut sulya: "<<t[i][j]<<" Ut: "<<i+1<<"->"<<j+1;}
            else{
                cout<<" Ut sulya: "<<t[i][j]<<" Ut: ";
                //cout<<i+1;
                ut(kozbulso,i,j);
                cout<<j+1;
            }
             cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
void ut(int ** kozbulso, int i, int j)
{
    if(kozbulso[i][j]== -1){
              cout << i+1<<"->";
            }
    else{
        int k=kozbulso[i][j];
         ut(kozbulso, i,k-1);
        ut(kozbulso, k-1,j);
    }

}
