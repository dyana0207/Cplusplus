#include "StatIntVeremPointer.h"

StatIntVeremPointer::StatIntVeremPointer():max_elem(10)
{
    felso=NULL;
}
bool StatIntVeremPointer::Verembe(int ujelem)
{
    if(!Televan())
    {
        felso++;
        *felso=ujelem;
        return true;
    }
    return false;
}
int StatIntVeremPointer::Verembol ()
{
    int kivett_elem=66666;
    if(!Ures())
    {
        kivett_elem=*felso;
        felso--;
    }
    return kivett_elem;
}
bool StatIntVeremPointer:: Ures() const
{
    return felso==NULL;
}
bool StatIntVeremPointer::Televan() const
{
    return felso== &verem[max_elem-1];
}
 int StatIntVeremPointer:: Elemszam() const
 {
     return max_elem;
 }
