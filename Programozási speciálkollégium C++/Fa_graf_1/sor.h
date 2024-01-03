#ifndef SOR_H
#define SOR_H
#include <iostream>
using namespace std;
struct sElem{
    double adat;
    sElem * kovetkezo;
};
class lsor{
    sElem * elso=NULL;
    sElem * utolso=NULL;
    //unsigned int db;
    public:
        lsor();
        ~lsor();
        lsor(const lsor& other);
        lsor& operator=(const lsor& rhs);

        bool Sorba(double);
        bool Sorbol(double &);
        bool Ures();
        bool Televan();
        unsigned int getmax();
        friend ostream & operator<<(ostream &, const lsor & );
};
ostream & operator<<(ostream &, const lsor & );
#endif // SOR_H
