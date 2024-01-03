#include <iostream>

using namespace std;
/*bool igeretes(int k)
{
     for(int i=0; i<k; i++)
    {
        if((x[i]==x[k]) || (abs(i-k)=abs(x[i]-x[k]))) (return false);
    }
    return true;
}*/
void kiir(int *x,int p)
{
     for(int i=0; i<p; i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
bool isSzabad(int uj, int n, int*x){
    bool szabad = true;
    for(int i=0; i<=n; i++){
        if(uj == x[i]){
            szabad = false;
            break;
        }
    }
    return szabad;
}
void permutacio(int *x, int n, int p, int k)
 {
     if(k==p)
     {
         kiir(x,p);
     }
     else{
         for(int i=k+1; i<=n; i++)
         {
             if(k==0 || isSzabad(i,n,x))
             {
                 x[k]=i;

                permutacio(x,n,p,k+1);
             }
         }
     }
 }
int main()
{
    //backtr(0);
    int n;
    cin>>n;
    int *x;
    for(int i=0; i<n; i++)
    {
        x=new int [i];
    permutacio(x, n,i,0);
    }
    return 0;

}
