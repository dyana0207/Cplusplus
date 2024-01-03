#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Adj meg egy mondatot" << endl;
    getline(cin,s);
    int * a=new int;
    int * i=new int;
    int * j=new int;
    string * b= new string(s);
     for(*i=0; *i<(*b).length(); (*i)++)
     {
         *a=1;
        for(*j=*(i+1); *j<(*b).length(); (*j)++)
        {
            if(b[0][*j]!=b[0][*i])
            {
                (*a)++;
                *j=0;
            }
        }
        if(b[0][*i]!=0 && b[0][*i]!=' ' )
        {
        cout<<b[0][*i]<<" betubol "<< *a <<" darab van"<<endl;
        }
     }
    return 0;
}
