#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;
string t[10][10];
int main()
{
    srand(time(0));
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            t[i][j]=rand() % 100;
            cout.width(3);
            cout<<t[i][j];
        }
        cout<<endl;
    }
    return 0;
}
 cout.width(10);
    for(int i=0; i<db1; i++)
    {
        if(i==db1-1)
        {
            cout.width(5);
            cout<<"b";
        }
        else{
                 if(i==0)
                {
                    cout.width(11);
                    cout<<"x"<<i+1;
                }
                else{
                    cout.width(6);
                    cout<<"x"<<i+1;
                }
        }
    }
    cout<<endl;
      for(int i=0; i<db; i++)
    {
        cout.width(5);
        if(i==db-1)
        {
            cout<<"-z";
        }
        else{
                cout<<"u"<<i+1;}

        for(int j=0; j<db1; j++)
        {
            cout.width(6);
            cout<<t[i][j];

        }
        cout<<endl;
    }
    cout<<endl;
