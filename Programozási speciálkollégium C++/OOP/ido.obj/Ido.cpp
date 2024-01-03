#include "Ido.h"

Ido::Ido()
{
    ora=0;
    perc=0;
    masodperc=0;
}
        Ido::Ido(unsigned int ora)
        {
            if(!setora(ora))
            {
                this->ora=0;
            }

            perc=0;
            masodperc=0;
        }
        Ido:: Ido(unsigned int ora, unsigned int perc)
        {
              if(!setora(ora))
            {
                this->ora=0;
            }

           if(!setperc(perc))
            {
                this->perc=0;
            }
            masodperc=0;
        }
        Ido::Ido(unsigned int ora,unsigned int perc,unsigned int masodperc)
        {
              if(!setora(ora))
            {
                this->ora=0;
            }
            if(!setperc(perc))
            {
                this->perc=0;
            }
            if(!setmasodperc(masodperc))
            {
                this->masodperc=0;
            }
        }

        bool Ido::setora(unsigned int ora)
        {
            if(ora>=0 && ora<24)
            {
                   this->ora=ora;
                return true;

            }
            return false;
        }

        bool Ido::setperc(unsigned int perc)
        {
             if(perc>=0 && perc<60)
            {
                 this->perc=perc;
                return true;
            }
            return false;
        }

        bool Ido:: setmasodperc(unsigned int masodperc)
        {
             if(masodperc>=0 &&  masodperc<60)
            {
                 this->masodperc=masodperc;
                return true;
            }
            return false;
        }
        unsigned int Ido::getora()
        {
            return ora;
        }
        unsigned int Ido::getperc()
        {
            return perc;
        }
       unsigned int Ido::getmasodperc()
        {
            return masodperc;
        }
    Ido operator+(Ido a, Ido b)
    {
        Ido c;
        unsigned int a_secBen=a.getora()*3600+a.getperc()*60+a.getmasodperc();
        unsigned int b_secBen=b.getora()*3600+b.getperc()*60+b.getmasodperc();
        unsigned int osszeg =(a_secBen+b_secBen)%86400;
          c.setora(osszeg/3600);
          c.setperc((osszeg%3600)/60);
          c.setmasodperc((osszeg%3600)%60);
          return c;
    }
    Ido & operator+=(Ido & a, Ido b)
    {
        a=a+b;
        return a;
    }
