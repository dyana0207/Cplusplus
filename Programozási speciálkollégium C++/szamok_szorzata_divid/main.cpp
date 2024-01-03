#include <iostream>

using namespace std;
int t[6]={2,8,7,4,6,9};
void szorzat(int t, int n, char k, char v)
{
    if(n==1)
    {
        osszeg+=t[i];
    }
    else{
        szorzat(t,(k+v)/2,k,v,osszeg);
    }
}
int main()
{
    szorzat(t,6,'k','v');
    return 0;
}
