#include "sor.h"

sor::sor(unsigned int db)
{
    maxi=db;
    s=new int [maxi];
    elso=0;
    utolso=0;
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
    //assignment operator
    return *this;
}
void sor::Verembe(double)
{

}
int sor::Verembol (double &)
{

}
bool sor::Televan()const
{

}
bool sor::Ures()const
{
    return db==0;
}
unsigned int sor::getmax()
{
    return maxi;
}
void sor::Kiir()const
{
    for(int i=0; i<sr.getmax(); i++)
    {
        double a=rand() % 100-50;
        sr[i]=a;
        cout<<sr[i]<<" ";
    }
}
