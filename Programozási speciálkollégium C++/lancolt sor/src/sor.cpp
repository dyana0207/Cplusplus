#include "sor.h"
using namespace std;
sor::sor()
{
    db=0;
    elso=NULL;
    utolso=NULL;
}

sor::~sor()
{
    //dtor
}
sor::sor(const sor& other)
{
    //copy ctor
}

sor& sor::operator=(const sor& rhs)
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
bool sor::Sorba(double ujAdat)
{
    sElem * ujelem=new (nothrow) sElem;
    if(ujelem!=NULL)
    {
        ujelem->adat=ujAdat;
        ujelem->kovetkezo=NULL;
        if(utolso!=NULL)
        {
            utolso->kovetkezo=ujelem;
            utolso=ujelem;
            db++;
        }
        else{
            elso=utolso=ujelem;
            db++;
        }
    return true;
    }
}
bool sor::Sorbol(double & kivett)
{
    sElem *seged=elso;
    if(!Ures())
    {
        kivett=elso->adat;
        elso=elso->kovetkezo;
        delete seged;
        return true;
    }
    return false;
}
bool sor:: Ures()
{
    return db==0;
}
unsigned int sor:: getmax()
{
    return db;
}
ostream & operator<<(ostream & os, const sor & s)
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
