#include <iostream>
#include <fstream>
using namespace std;
struct prim{
    int k,v,el;
    };
bool mini(prim *,int ,int);
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
    prim * t=new prim [elek];
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
     int a=t[0].k;
     int b=t[0].v;
     cout<<a<<"->"<<b<<" Suly: "<<t[0].el<<endl;
      int cs[csucs];
    for(int i=0; i<csucs; i++)
    {
       if(cs[i]==a || cs[i]==b)
       {
           cs[i]=-1;
       }
    }
    int sz=1;
    int db=0,m1=100;
    while(db!=csucs)
     {
         for(int m=0; m<elek; m++)
         {
             if(t[m].k==a && t[m].el<m1 )
             {
                 for(int j=0; j<csucs; j++)
                 {
                     if(cs[t[m].v]!=-1)
                     {
                        m1=t[m].el;
                        a=t[m].v;
                     }
                 }
             }
             if(t[m].k==b && t[m].el<m1)
             {
                 for(int j=0; j<csucs; j++)
                 {
                      if(cs[t[m].v]!=-1)
                      {
                         {
                            m1=t[m].el;
                            b=t[m].v;
                         }
                     }
                 }
            }
         }
         cout<<a<<"->"<<b<<" Suly: "<<m1<<endl;
         cs[b-1]=-1;
         db++;
     }
    return 0;
}
bool mini(prim * t, int ke,int elek)
{
    int minii=100, mini_id=0;
    for(int i=0; i<elek; i++)
    {
        if(t[i].k==ke && t[i].el<minii)
        {
            minii=t[i].el;
            mini_id=t[i].v;
        }
    }
    return mini_id;
}
