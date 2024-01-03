#ifndef INTTOMB_H
#define INTTOMB_H

#include <iostream>
class inttomb
{
    int elemek_db;
    public:
        int * elemek;
        inttomb();
        inttomb(unsigned int);

        ~inttomb();
        inttomb & operator=(const inttomb &);

};

#endif // INTTOMB_H
