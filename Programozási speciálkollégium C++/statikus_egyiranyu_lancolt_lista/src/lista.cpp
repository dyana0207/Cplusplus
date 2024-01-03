#include "lista.h"

lista::lista(int n)
{
    maxi=n;
    t=new lElem[maxi];
    Elso=Utolso=Akt=-1;
    SzH=0;
    for(int i=0; i<maxi; i++)
    {
        if(i==maxi-1)
        {
           t[i].kovetkezo=-1;
        }
        else{
            t[i].kovetkezo=i+1;
        }
    }
}

lista::~lista()
{
    delete t;
}

lista::lista(const lista& other)
{
    Elso=Utolso=Akt=-1;
    SzH=0;
    *this=other;
}

lista& lista::operator=(const lista& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    lElem *t1=new lElem[maxi];
    delete[] this;
    int seged=Elso;
    while(seged!=Utolso)
    {
        insertLast(t[seged].adat);
        if(seged==rhs.Akt)
        {
            Akt=Utolso;
        }
        seged=t[seged].kovetkezo;
    }
    return *this;
}
bool lista::Ures()
{
    return Elso==-1;
}
bool lista::Tele()
 {
     return Utolso==maxi-1;
 }
void lista::insertFirst(int ujAdat)
{
    if(Ures())
    {
        t[SzH].adat=ujAdat;
        Elso+=1;
        Utolso+=1;
        Akt=Utolso;
        SzH++;
        t[Utolso].kovetkezo=-1;

    }
    else{
        t[SzH].adat=ujAdat;
        int seged=Elso;
        Elso=SzH;
        SzH=t[Elso].kovetkezo;
        t[Elso].kovetkezo=seged;
}
}
void lista::insertLast(int ujAdat)
{
    if(Ures())
    {
        insertFirst(ujAdat);
    }
    else{
            t[SzH].adat=ujAdat;
            int seged=Utolso;
            Utolso=SzH;
            SzH=t[Utolso].kovetkezo;
            t[Utolso].kovetkezo=t[seged].kovetkezo;
            t[seged].kovetkezo=Utolso;
    }

}
/*void lista::insertAfter(int ujAdat)
{
    if(Ures() || isFirst())
    {
        insertLast(ujAdat);
    }
    else{
            int seged;
    }
}*/
bool lista::removeFirst()
{
    if(!Ures())
    {
        SzH=Elso;
        Elso=t[Elso].kovetkezo;
        return true;
    }
    return false;
}
bool lista::removeLast()
{
    if(!Ures())
    {
        int i=0;
        SzH=Utolso;
        while(i!=maxi)
        {
            if(Utolso==t[i].kovetkezo)
            {
                Utolso=i;
                t[i].kovetkezo=-1;
            }
            i++;
        }
        return true;
    }
    return false;
}
bool lista::removeCurrent()
{

}
bool lista::isFirst()
{
    return Akt==Elso;
}
bool lista::isLast()
{
    return Akt=Utolso;
}
void lista::Kiir()
{
    for(int i=0; i<maxi; i++)
    {
        cout<<t[i].adat<<" "<<t[i].kovetkezo;
        cout<<endl;
    }
}
void lista::stepFirst()
{
    Akt=Elso;
}
void lista::stepLast()
{
    Akt=Utolso;
}
void lista::stepForwand()
{
    if(!Ures() && !isLast())
    {
        Akt=t[Akt].kovetkezo;
    }
}
void lista::setValue(int uj)
{
    if(!Ures())
    {
        t[Akt].adat=uj;
    }
}
bool lista::getValue(int & vissza)
{
    if(!Ures())
    {
        vissza=t[Akt].adat;
    }
}
