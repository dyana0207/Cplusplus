#include "lista.h"
#include <iostream>
lista::lista()
{
/*if(Ures()){*/
    Elso=NULL;
    Utolso=NULL;
    Akt=NULL;

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
void lista::insertFirst(int ujAdat)
 {
     lElem * seged=new lElem;
     seged->adat=ujAdat;
     seged->elozo=NULL;
     if(Ures())
     {
        seged->kovetkezo=NULL;
         Utolso=seged;
         Akt=seged;
     }
     else{
        Elso->elozo=seged;
        seged->kovetkezo=Elso;
         Elso=seged;
     }
 }
void lista::insertLast(int ujAdat)
{
    if(Ures())
     {
         insertFirst(ujAdat);
     }
     else{
             lElem * seged=new lElem;
             seged->adat=ujAdat;
            seged->kovetkezo=NULL;
            seged->elozo=Utolso;
            Utolso->kovetkezo=seged;
            Utolso=seged;
     }
}
void lista::insertBefore(int ujAdat)
{
    if(Ures() || isFirst())
    {
        insertFirst(ujAdat);
    }
    else{
         lElem * seged=new lElem;
          lElem * seged2=Akt->elozo;
        seged->adat=ujAdat;
        seged->elozo=seged2;
        Akt->elozo=seged;
        seged2->kovetkezo=seged;
        seged->kovetkezo=Akt;
    }
}
void lista::insertAfter(int ujAdat)
{
    if(isLast() || Ures())
    {
       insertLast(ujAdat);
    }
    else{
         lElem * seged=new lElem;
         lElem * seged2=Akt->kovetkezo;
         seged->adat=ujAdat;
         seged->kovetkezo=seged2;
         Akt->kovetkezo=seged;
         seged->elozo=Akt;
         seged2->elozo=seged;
    }
}
bool lista::Ures()
{
    return Utolso=Elso=NULL;
}
bool lista:: removeFrist(int & torles)
{
    if(!Ures())
       {
          lElem* seged=Elso;
            if(isFirst())
            {
                Akt=Akt->kovetkezo;
            }
            Elso=elso->kovetkezo;
            if(Elso==NULL){
                Utolso=Elso;
            }
            else{
                Elso->elozo=NULL;
            }
            torles=seged->adat;
            delete seged;
       }
}
void lista::removeLast()
{
    delete Utolso;
}
bool lista::removeCurrent(int & torles)
{
    if(!Ures())
    {
        if(isFirst()) removeFrist(torles);
        if(isLast()) removeLast(torles);
        else{
            lElem * seged=Akt;
            Akt->elozo>kovetkezo=Akt->kovetkezo;
            Akt->kovetkezo->elozo=Akt->elozo;
            stepLast();
            torles=seged->adat;
            delete seged;
        }
    }
    lElem * seged=Utolso;
    while(seged!=NULL)
    {
        delete seged;
        seged=seged->elozo;
    }
}
 bool lista::isLast()
 {
    return Akt=Utolso;
 }
bool lista::isFirst()
{
    return Elso;
}
