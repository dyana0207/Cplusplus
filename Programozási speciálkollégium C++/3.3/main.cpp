#include <iostream>
#include <fstream>
using namespace std;

int main()
{ ifstream be("szamok.txt");
    int *db=new int(0);
    int *p=new int [1];
    while(!be.eof())
    {
        if(*db==0)
        {
             be>>p[*db];
            (*db)++;
        }
        else{
                int *p1=p;
                p=new int [*db+1];
                int *j=new int (0);
                    for( *j=0; *j<*db;(*j)++)
                    {
                        p[*j]=p1[*j];
                    }
                delete j;
                be>>p[*db];
                (*db)++;
                delete [] p1;
            }
    }
    int *i=new int (0);
    for(*i=0; *i<*db-1; (*i)++)
    {
        cout<<p[*i]<<" ";
    }
    delete db;
    delete i;
    delete [] p;
    return 0;
}
