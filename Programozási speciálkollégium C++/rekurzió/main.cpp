#include <iostream>

using namespace std;
/*int ossz(unsigned int n)
{
    if(n==1)
        return 1;
    else{
        return n * ossz(n-1);
    }

    cout<<n;
}*/
/*int hatvany(unsigned int n,unsigned int k)
{
    if(k==1)
        return n;
    else{
        return  n* hatvany(n,k-1);
    }
}*/
/*int euklidesz(unsigned int a,unsigned int b)
{
    if(b==0)
    {
        return a;
    }
    else{
        return euklidesz(b,a%b);
    }
}
int fibo(unsigned int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    else{
        return fibo(n-1)+fibo(n-2);
    }
}*/
/*void szo(int n,int i=1)
{
    string s;
    cout<<"Adj meg egy szot"<<endl;
    if(i<=n)
    {
      cin>>s;
      szo(n,i+1);
    }
    cout<<s<<" ";
}*/
void longos(long int a)
{
    if(a>0)
    {
        int sz=a%10;
        longos(a/10);
        cout<<sz<<" ";
    }
}
int main()
{
    //cout<<ossz(4);
    //cout<<hatvany(3,3);
    //cout<<euklidesz(12,18);
    //cout<<fibo(6);
    //szo(3);
    long int a;
    cin>>a;
    longos(a);
    return 0;
}
