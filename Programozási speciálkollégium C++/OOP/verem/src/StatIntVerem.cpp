#include "StatIntVerem.h"

StatIntVerem::StatIntVerem(): max_elem(10)
{
    felso=-1;
}
bool StatIntVerem::Verembe(int ujelem)
{
    if(!Televan())
    {
        felso++;
        verem[felso]=ujelem;
        return true;
    }
    return false;
}
int StatIntVerem::Verembol ()
{
    int kivett_elem=66666;
    if(!Ures())
    {
        kivett_elem=verem[felso];
        felso--;
    }
    return kivett_elem;
}
bool StatIntVerem:: Ures() const
{
    return felso==-1;
}
bool StatIntVerem::Televan() const
{
    return felso==max_elem-1;
}
 int StatIntVerem:: Elemszam() const
 {
     return max_elem;
 }

