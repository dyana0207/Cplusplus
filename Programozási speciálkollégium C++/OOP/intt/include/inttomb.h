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
        int length();
        void sort(bool);
        inttomb kivalogat(bool (*)(int));
        int megszamlal(bool(*)int);
        bool bennevan(int);
        };

#endif // INTTOMB_H
