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

       void Verembe(double);
        int Verembol (double &);
        bool Televan()const;
        bool Ures()const;
        void Kiir()const;
        unsigned int getmax();
};

#endif // SOR_H
