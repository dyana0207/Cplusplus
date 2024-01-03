#ifndef IDO_H
#define IDO_H

class Ido
{
   unsigned int ora, perc, masodperc;
    public:
        Ido();
        Ido(unsigned int);
        Ido(unsigned int, unsigned int);
        Ido(unsigned int,unsigned int,unsigned int);

         bool setora(unsigned int);
         bool setperc(unsigned int);
         bool setmasodperc(unsigned int);
        unsigned int getora();
        unsigned int getperc();
        unsigned int getmasodperc();

Ido operator+(const Ido &);
Ido  & operator+=( const Ido&);
Ido operator-(const Ido&);
Ido  & operator-=(const Ido&);
};
#endif // IDO_H
