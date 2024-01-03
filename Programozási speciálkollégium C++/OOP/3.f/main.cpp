#include <iostream>

using namespace std;
class ido{
    int ora, perc, mperc;
    int ev,honap,nap;
public:
    ido(int ora, int perc, int mperc)
    {
        this->ora=ora;
        this->perc=perc;
        this->mperc=mperc;
    }
    ido(int ev, int honap, int nap )
    {
        this->ev=ev;
        this->honap=honap;
        this->nap=nap;

    }
    int kulonbseg(int, int, int);
    int kulonbsegSec(int, int,int);
     int osszeg(int, int,int);
     int osszegSec(int, int,int);
     void kivon(int, int, int);
     void hozzaad(int,int,int);
     void print();
     int getev();
     int setev(int);
      int gethonap();
     int sethonap(int);
      int getnap();
     int setnap(int);
     string sethonapnev(string);
     string gethonapnev();

    };
int main()
{
    ido a(12,5,6);
    a.print();
    return 0;
}
 int ido::kulonbseg(int ora1, int perc1, int mperc1)
 {
     cin>>ora1>>perc1>>mperc1;
     int ora2=a.ora


 }
void ido::print()
{
    cout<<ora<<":"<<perc<<" :"<<mperc<<endl;
}
int ido::setev(int ev)
{
    cout<<"Add meg az evet: "<<endl;
    cin>>ev;
    this->ev=ev;

}
int ido::getev()
{
    return ev;
}
int ido::sethonap(int honap)
{
    cout<<"Add meg az honapot: "<<endl;
    cin>>honap;
    this->honap=honap;

}
int ido::gethonap()
{
    return honap;
}
int ido::setnap(int nap)
{
    cout<<"Add meg az napot: "<<endl;
    cin>>nap;
    this->nap=nap;

}
int ido::getnap()
{
    return nap;
}


