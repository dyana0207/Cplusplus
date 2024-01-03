#include "verem.h"
using namespace std;
verem::verem()
{
    felso=NULL;
}

verem::~verem()
{
    while(felso->elozo!=NULL)
    {
        vElem *seged=felso;
        felso=seged->elozo;
        delete seged;
    }
}

verem::verem(const verem& other)
{
         felso=NULL;
        *this=other;

}

verem& verem::operator=(const verem& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    vElem *seged1=rhs.felso;
    verem * seged=new verem;
    vElem *seged2;
    while(seged1!=NULL)
    {
        double a=seged1->adat;
        seged->Verembe(a);
        seged1=seged1->elozo;
    }
    seged2=seged->felso;
    while(seged2!=NULL)
    {
        double a=seged2->adat;
        this->Verembe(a);
        seged2=seged2->elozo;
    }
    return *this;
}
void verem::Verembe(double ujAdat)
{
     vElem * seged=new vElem;
      seged->adat=ujAdat;
      seged->elozo=felso;
      felso=seged;
}
bool verem::Verembol (double &kivett)
{
        if(!Ures())
    {
        vElem* seged=felso;
        kivett=seged->adat;
        felso=seged->elozo;
        delete seged;
        return true;
    }
    return false;
}
void verem::Kiir()const
{
    vElem* seged=this->felso;

    while(seged!=NULL)
    {
      cout<<seged->adat<<" ";
        seged=seged->elozo;
    }

}
bool verem::Ures()const
{
    return felso==NULL;
}
int verem::operator[](unsigned int i) const
{
    unsigned int db=0;
    vElem* seged=this->felso;
    vElem* seged1=new vElem;
    while(seged!=NULL )
    {
        if(db==i)
        {
            seged1->adat=seged->adat;
        }
        seged=seged->elozo;
        db++;

    }
    cout<<seged1->adat<<endl;

}
 int verem::veremfelso()
 {
     return felso->adat;
 }

/*ostream & operator<<(ostream & os, const verem & )
{

}*/
