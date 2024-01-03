#include <iostream>
#include <fstream>
using namespace std;
bool vanpoztiv(int & , int & );
int generaloelem(int & , int & );
int t[10][10];
string jel[9];
int pozitivindex=0;
int main()
{
    int sz;
    string b;
    ifstream be("fajl.txt");
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
            jel[db]=b;
            nemjo=true;

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
    for(int i=0; i<db; i++)
    {
        for(int j=0; j<db1; j++)
        {
            cout.width(3);
            cout<<t[i][j];
            if(j==db1-2)
            {
                cout.width(3);
                cout<<jel[i];
            }

        }
        cout<<endl;
    }


    /*bool vanpoztiv(int & db, int & db1)
    {
        van=false;
        for(int i=0; i<db1; i++)
        {
            if(t[db][db1]>0)
            {
                van=true;
                pozitivindex=db1;
                break;
            }
        }
        return pozitivindex;
    }


    int generaloelem(int & db, int & db1)
    {
        for(int i=0; i<db; i++)
        {

        }

    }*/
    return 0;
}
