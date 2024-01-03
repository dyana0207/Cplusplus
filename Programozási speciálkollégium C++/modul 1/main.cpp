#include <iostream>
#include <fstream>
using namespace std;
string fugg( string);
int main()
{
    ifstream be("fajl.txt");
    string *szo=new string{""};
    while(!be.eof())
    {
        be>>*szo;
        fugg(*szo);

    }

    return 0;
}
string fugg( string szo)
{
    int db=0;
    string *seged=new string{""};
        for(int j=szo.length()-1; j>=0; j--)
        {
            seged[0][db]=j;
            db++;
        }
     if( szo==*seged)
     {
         cout<<*seged<<" ";
     }

    delete seged;
}
