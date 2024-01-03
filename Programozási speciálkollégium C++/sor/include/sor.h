#ifndef SOR_H
#define SOR_H

#include <iostream>
class sor
{
    int *s;
    unsigned int maxi, elso, utolso;
    public:
        sor(unsigned int);
        ~sor();
        sor(const sor& other);
        sor& operator=(const sor& other);

       bool Sorba(double);
        bool Sorbol (double &);
        bool Televan()const;
        bool Ures()const;
        unsigned int getmax();
};
ostream sor::operator<<(ostrem os, const sor & s);
#endif // SOR_H
