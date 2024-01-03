#include <iostream>

using namespace std;
void szam(string, int);
int main()
{
    cout << "Add meg a ket syamot" << endl;
    string a;
    int b;
    getline(cin,a);
    cin>>b;
    szam(a,b);

}
void szam(string a, int b)

{
    for(int i=0; i<=a.length(); i++)
    {
        if(i==b)
        {
            cout<< a[i-1];

        }
    }
}
