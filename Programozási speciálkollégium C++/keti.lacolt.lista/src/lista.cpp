#include "lista.h"

lista::lista()
{
    Elso=NULL;
    Utolso=NULL;
    Akt=NULL;
}

lista::~lista()
{
    Torol();
}

lista::lista(const lista& other)
{
    *this=other;
}

lista& lista::operator=(const lista& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    Torol();
    lElem * seged=rhs.Elso;
    while(seged->kovetkezo!=NULL)
    {
        insertLast(seged->adat);
        if(seged==rhs.Akt)
        {
            Akt=Utolso;
        }
        seged=seged->kovetkezo;
    }
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
            Elso=Elso->kovetkezo;
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
bool lista::removeLast(int & torles)
{
    if(!Ures())
    {
        lElem* seged=Utolso;
            if(isLast())
            {
                Akt=Akt->elozo;
            }
            Utolso=Utolso->elozo;
            if(Utolso==NULL){
                Elso=Utolso;
            }
            else{
                Utolso->kovetkezo=NULL;
            }
            torles=seged->adat;
            delete seged;
    }

}
bool lista::removeCurrent(int & torles)
{
    if(!Ures())
    {
        if(isFirst()) removeFrist(torles);
        if(isLast()) removeLast(torles);
        else{
            lElem * seged=Akt;
            Akt->elozo->kovetkezo=Akt->kovetkezo;
            Akt->kovetkezo->elozo=Akt->elozo;
            stepLast();
            torles=seged->adat;
            delete seged;
        }
    }
}
 bool lista::isLast()
 {
    return Akt=Utolso;
 }
bool lista::isFirst()
{
    return Akt=Elso;
}
void  lista::stepFirst()
{
    while(!isFirst())
    {
       Akt=Akt->elozo;
    }
}
void  lista::stepLast()
{
   while(!isLast())
    {
       Akt=Akt->kovetkezo;
    }
}
bool  lista::stepForwand()
{
    bool u=false;
    if(Akt->kovetkezo!=NULL){
     Akt=Akt->kovetkezo;
     u=true;
    }
    return u;
}
bool  lista::stepBackward()
{
     bool u=false;
   if(Akt->elozo!=NULL){
     Akt=Akt->elozo;
     u=true;
    }
    return u;
}
void lista::setValue(int ujertek)
{
    if(!Ures()){
    Akt->adat=ujertek;
    }
}
int  lista::getValue()
{
    if(!Ures()){
    return Akt->adat;
    }
}
void lista::Torol()
{
    lElem * seged=Elso;
    if(!Ures())
    {
        while(Elso->kovetkezo!=NULL)
        {
            delete seged;
            seged=seged->kovetkezo;
        }
    }
}
