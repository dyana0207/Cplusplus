#include "lista.h"

lista::lista()
{
    if(Ures())
    {
        Elso=Utolso=Akt=NULL;
    }
}

lista::~lista()
{
    //dtor
}

lista::lista(const lista& other)
{
    //copy ctor
}

lista& lista::operator=(const lista& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
bool lista::Ures()
{
    return Elso==NULL;
}
void lista::insertFirst(int ujAdat)
{
    lElem * seged=new lElem;
    seged->adat=ujAdat;
    if(Ures())
    {
        Elso=Utolso=Akt=seged;
        Elso->kovetkezo=NULL;
    }
    else{
        seged->kovetkezo=Elso;
        Elso=seged;
    }
}
void lista::insertLast(int ujAdat)
{
    lElem * seged=new lElem;
    seged->adat=ujAdat;
    if(Ures())
       {
            insertFirst(ujAdat);
       }
        else{
            Utolso->kovetkezo=seged;
            seged->kovetkezo=NULL;
        }
}
void lista:insertAfter(int ujAdat)
{
    if(Ures() || isLast())
    {
        insertLast(ujAdat);
    }
    else{
        lElem * seged=new lElem;
        seged->adat=ujAdat;
        seged->kovetkezo=Akt->kovetkezo;
        Akt->kovetkezo=seged;
    }
}
bool lista:removeFrist()
{
    bool k=false;
    if(!Ures())
    {
        lElem * seged=Elso;
        Elso=Elso->kovetkezo
        if(isFirs())
        {
            Akt=Akt->kovetkezo;
        }
        if(Elso->kovetkezo==NULL)
        {
            delete Elso;
            Elso=Utolso=Akt=NULL;
            k=true;
        }
        else{
            delete seged;
             k=true;
        }
    }
    return k;
}
bool lista:removeLast(int & kivett)
{

}
bool lista:removeCurrent(int & kivett)
{

}
bool lista:isFirst()
{
    return Akt==Elso;
}
bool lista:isLast()
{
     return Akt==Utolso;
}
