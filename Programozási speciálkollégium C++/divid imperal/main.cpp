#include <iostream>

using namespace std;
int paros(int *t, int e, int v)
{
    if(e==v) return t[e]%2==0 ? 1:0;
    else{
        int k=(e+v)/2;
        int elso=paros(t,e,k);
        int masodik=paros(t,k+1,v);
        return elso+masodik;
    }
}
int main()
{
    int t[8]={2,8,8,4,6,9,4,2};
    cout << paros(t,0,7) << endl;
    return 0;
}
