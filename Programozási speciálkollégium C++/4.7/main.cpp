#include <iostream>
#include <math.h>
using namespace std;
int kitevo(int, int);
int main()
{
    cout << "Add meg a ket syamot" << endl;
    int a,b;
    cin>>a>>b;
    int c=kitevo(a,b);
    cout<<c<<endl;

}
int kitevo(int a, int b=2)

{
    return pow(a,b);
}
