#include <iostream>
#include <fstream>
using namespace std;

int main()
{ ifstream be("szamok.txt");
    int db=0;
    int *p[5];
    while(!be.eof())
    {
        for(int i=0; i<5; i++)
        {
        p[i]=new int [1];
        while(db!=0)
        {
             be>>p[i][db];
            db++;
        }
        else{
                int **p1=p;
                p[i]=new int [db+1];
                    for(int j=0; j<db; j++)
                    {
                        p[i][j]=p1[i][j];
                    }
                be>>p[i][db];
                db++;
                delete [] p1;
            }
    }
    }
    for(int i=0; i<db-1; i++)
    {
        for(int j=0; j<db-1; j++)
        {
            cout.width(3);
        cout<<p[i][j]<<" ";
    }
    cout<<endl;
    }
    for(int i=0; i<5; i++)
    {
       delete [] p[i];
    }
    delete [] p;
    return 0;
}
