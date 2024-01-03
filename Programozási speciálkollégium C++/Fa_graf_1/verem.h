#ifndef VEREM_H
#define VEREM_H
#include <iostream>
using namespace std;
struct vElem{
    double adat;
    vElem * elozo;
    };

class verem
{
    vElem *felso;
    public:
        verem();
        ~verem();
        verem(const verem& other);
        verem& operator=(const verem& other);

        void Verembe(double);
        bool Verembol (double &);
        void Kiir()const;
        bool Ures()const;
        int operator[](unsigned int) const;
        int veremfelso();
};
ostream & operator<<(ostream & os, const verem &);
#endif // VEREM_H
