#include <iostream>

using namespace std;
int maximum(int *t, int e, int v)
{
    if(e==v) return t[e];
    else{
        int k=(e+v)/2;
        int elso=maximum(t,e,k);
        int masodik=maximum(t,k+1,v);
        return elso>masodik ? elso : masodik;
    }
}
int main()
{
    int t[8]={2,1,8,4,6,9,44,3};
    cout << maximum(t,0,7) << endl;
    return 0;
}
