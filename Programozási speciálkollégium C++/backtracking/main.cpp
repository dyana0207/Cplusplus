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
/*void backtr(int k)
{
     if(k==4) kiir();
    else{
        for(int i=1; i<=4; i++)
        {
            x[k]=i;
            backtr(k+1);
        }
    }
}*/
/*void szere(int *x,int n, int p,int k)
{
     if(k==p) kiir(x,p);
    else{
        for(int i=1; i<=n; i++)
        {
            x[k]=i;
            szere(x,n,p,k+1);
        }
    }
}*/
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
    int n,p;
    cin>>n>>p;
    int x[p];
    //szere(x,n,p,0);
    permutacio(x, n,  p,0);
    return 0;

}
