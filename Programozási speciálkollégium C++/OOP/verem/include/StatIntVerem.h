#ifndef STATINTVEREM_H
#define STATINTVEREM_H


class StatIntVerem
{
    const int max_elem;
    int verem[10];
    int felso;
    public:
        StatIntVerem();

        bool Verembe(int);
        int Verembol ();
        bool Ures() const;
        bool Televan() const;
        int Elemszam() const;


};

#endif // STATINTVEREM_H
