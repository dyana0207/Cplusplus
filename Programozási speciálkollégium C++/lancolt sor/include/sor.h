#ifndef SOR_H
#define SOR_H
#include <iostream>
using namespace std;
struct sElem{
    double adat;
    sElem * kovetkezo;
};
class sor
{
    sElem * elso=NULL;
    sElem * utolso=NULL;
    unsigned int db;
    public:
        sor();
        ~sor();
        sor(const sor& other);
        sor& operator=(const sor& rhs);

        bool Sorba(double);
        bool Sorbol(double &);
        bool Ures();
        bool Televan();
        unsigned int getmax();
        friend ostream & operator<<(ostream &, const sor & );
};
ostream & operator<<(ostream &, const sor & );
#endif // SOR_H
