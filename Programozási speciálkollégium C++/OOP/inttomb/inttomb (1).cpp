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
