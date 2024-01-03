#include <iostream>
#include <fstream>
using namespace std;
struct kruska{
    int k,v,el;
    };
int main()
{
     cout << "Add meg a szamot!" << endl;
    string n;
    cin>>n;
    ifstream be;
    string f="KruskalElmatrix";
    f+=n;
    f+=".txt";
    int csucs, elek;
    be.open(f.c_str());
    be>>csucs;
    be>>elek;
    kruska t[elek];
    int i=0;
    while(!be.eof())
    {
        be>>t[i].k>>t[i].v>>t[i].el;
        i++;
    }
    for(int i=0; i<elek; i++)
    {
        cout<<t[i].k<<" "<<t[i].v<<" "<<t[i].el;
        cout<<endl;
    }
    cout<<endl;
     for(int i=0; i<elek-1; i++)
    {
        for(int j=i+1; j<elek; j++)
        {
            if(t[i].el>t[j].el)
            {
                swap(t[i],t[j]);
            }
        }
    }
      for(int i=0; i<elek; i++)
    {
        cout<<t[i].k<<" "<<t[i].v<<" "<<t[i].el;
        cout<<endl;
    }
    int cs[csucs];
    for(int i=0; i<csucs; i++)
    {
       cs[i]=i+1;
       cout<<cs[i]<<" ";
    }
     cout<<endl;
     for(int i=0; i<elek; i++)
     {
         int a=t[i].k;
         int b=t[i].v;
        int sz=t[i].k;
             if(cs[a-1]!=cs[b-1])
             {
                 int cs_a=cs[a-1], cs_b=cs[b-1];
                 cout<<a<<"->"<<b<<" Suly: "<<t[i].el<<endl;
                 for(int m=0; m<csucs; m++)
                 {
                     if(cs[m]==cs_a || cs[m]==cs_b)
                     {
                         cs[m]=sz;
                     }
                 }
             }
     }
      for(int i=0; i<csucs; i++)
    {
       cout<<cs[i]<<" ";
    }
    return 0;
}
