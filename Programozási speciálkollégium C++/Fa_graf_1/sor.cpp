#include "sor.h"
using namespace std;
lsor::lsor()
{
    //db=0;
    elso=NULL;
    utolso=NULL;
}

lsor::~lsor()
{
    //dtor
}
lsor::lsor(const lsor& other)
{
    //copy ctor
}

lsor& lsor::operator=(const lsor& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    delete this;
    sElem * seged=rhs.elso;
    while(seged!=NULL)
    {
        Sorba(seged->adat);
        seged=seged->kovetkezo;
    }
    return *this;
}
bool lsor::Sorba(double ujAdat)
{
    sElem * ujelem=new sElem;
    ujelem->adat=ujAdat;
    ujelem->kovetkezo=NULL;
        if(!Ures())
        {
            utolso->kovetkezo=ujelem;
            utolso=ujelem;
            //db++;
        }
        else{
            elso=utolso=ujelem;
            //db++;
        }
}
bool lsor::Sorbol(double & kivett)
{
    if(!Ures())
    {
         sElem *seged=elso;
        kivett=elso->adat;
        elso=elso->kovetkezo;
        if(elso==NULL)
        {
            utolso==NULL;
        }
        delete seged;
        return true;
    }
    return false;
}
bool lsor:: Ures()
{
    return elso==NULL;
}
/*unsigned int lsor:: getmax()
{
    return db;
}*/
ostream & operator<<(ostream & os, const lsor & s)
{
    sElem *seged=s.elso;
    while(seged!=NULL)
    {
        double a=seged->adat;
        os<<a<<" ";
        seged=seged->kovetkezo;
    }
    return os;
}
