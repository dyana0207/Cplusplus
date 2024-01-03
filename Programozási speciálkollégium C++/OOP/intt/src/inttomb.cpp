#include "inttomb.h"

inttomb::inttomb()
{
    elemek = NULL;
    elemek_db=0;
}
inttomb:: inttomb(unsigned int db)
{
    if(db!=0){
        elemek_db=db;
        elemek=new int [db];
    }
    else{
        elemek=NULL;
        elemek_db=0;
    }
}
inttomb:: ~inttomb()
{
    delete [] elemek;
}
 inttomb & inttomb:: operator=(const inttomb & other){
    if(this== &other) return * this;
    elemek_db=other.elemek_db;
    delete [] elemek;
    if(elemek_db!=0)
    {
        elemek=new int [elemek_db];
        for(int i=0; i<elemek_db; i++)
        {
            elemek[i]=other.elemek[i];
        }
    }
    else{
        elemek=NULL;
    }
    return * this;
 }
  int inttomb::length()
  {
      return elemek_db;
  }
void inttomb::sort(bool novekvo)
   {
       if(novekvo==true)
       {
           for(int i=this->length()-1; i>0; i--)
           {
               for(int j=0; j<i; j++)
               {
                   if(elemek[j]>elemek[j+1])
                   {
                       int csere=elemek[j];
                       elemek[j]=elemek[j+1];
                       elemek[j+1]=elemek[j];

                   }
               }
           }
       }
       else{
            for(int i=this->length()-1; i>0; i--)
           {
               for(int j=0; j<i; j++)
               {
                   if(elemek[j]<elemek[j+1])
                   {
                       int csere=elemek[j];
                       elemek[j]=elemek[j+1];
                       elemek[j+1]=elemek[j];
                   }
               }
           }
       }
   }
inttomb inttomb:: kivalogat(bool (*kriterium)(int))
{
    inttomb a;
    for(int i=0; i<length(); i++)
    {
        if(kriterium(elemek[i]))
        {
            a.push(elemek[i]);
        }
    }
    return a;
}
int inttomb::megszamlal(bool(*kriterium)int)
{
    int db=0;
    for(int i=0; i<length(); i++)
    {
        if(kriterium(elemek[i]))
        {
           db++;
        }
    }
    return db;
}
bool inttomb::bennevan(int szam=6)
{
    bool megtalalhato=false;
    for(int i=0; i<length(); i++)
    {
        if(szam==elemek[i])
        {
           megtalalhato=true;
        }
    }
    return megtalalhato;
}
