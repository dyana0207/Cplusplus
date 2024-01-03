#include "sor.h"
#include <iostream>

using namespace std;
sor::sor(unsigned int db)
{
    maxi=db;
    if(maxi!=0)
    {
        s=new int [maxi];
    }
    else{
    elso=0;
    utolso=0;
    }
}

sor::~sor()
{
    delete [] s;
}

sor::sor(const sor& other)
{
    //copy ctor
}

sor& sor::operator=(const sor& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    maxi = rhs.maxi;
    delete [] s;
    s = new int[MAX_ELEM];
    if((rhs.utolso-1)  != 0){
        for(int i = 0; i < rhs.utolso - 1; i++){
            s[i] = rhs.s[i];
        }
    }
    return *this;
}
bool sor::Sorba(double ujAdat)
{
    if(!Televan()){
        this->s[utolso]=ujAdat;
        utolso++;
        db++;
        return true;
    }
    else utolso=0;
    return false;
}
bool sor::Sorbol (double & a)
{
    if(elso==maxi)
       {
           elso=0;
           a= this->s[elso];
       }
        else{
               a= this->s[elso];
            elso++;
            db--;
        }
        return a;
}
bool sor::Televan()const
{
    return db==maxi;
}
bool sor::Ures()const
{
    return db==0;
}
unsigned int sor::getmax()
{
    return maxi;
}
ostream sor::operator<<(ostrem os, const sor & s)
{
    sor seged=s;
    int a;
    while(seged.Sorbol(a))
    {
        os<<a;
    }
}
