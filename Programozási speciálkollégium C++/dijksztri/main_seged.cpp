#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

const unsigned int vegtelen = 100;

class Csomopont{
    public:
        bool bejartuk;
        int suly, honnan;
        Csomopont();
};

Csomopont::Csomopont(){
    bejartuk = false;
    honnan = -1;
    suly = vegtelen;
}

void Dijkstra(int **,int, Csomopont *);
int minSulyuCsomopont(Csomopont *, int);
void utvonalKiir(Csomopont *, int);

int main(){
    ifstream f;
    string sorszam;
    cout << "Feladat sorszama: ";
    cin >> sorszam;
    f.open(("Dijkstra"+sorszam+".txt").c_str());
    while(f.fail()){
        cout << "Nincs ilyen feladat" << endl;
        Sleep(1000);
        system("cls");
        cout << "Feladat sorszama: ";
        cin >> sorszam;
        f.open(("Dijkstra"+sorszam+".txt").c_str());
    }
    int cs_db = 0;
    f >> cs_db;
    int **SzM = new int *[cs_db];
    for(int i = 0; i < cs_db; i++){
        SzM[i] = new int[cs_db];
        for(int j = 0; j < cs_db; j++){
            f >> SzM[i][j];
        }
    }
    cout << "Csomopontok szama: " << cs_db << endl;
    cout << "Szomszedsagi matrix: " << endl;
    for(int i = 0; i < cs_db; i++){
        for(int j = 0; j < cs_db; j++){
            cout.width(5);
            cout << SzM[i][j];
        }
        cout << endl;
    }

    int k_cs;
    cout << endl << "Kiindulo csomopont: ";
    cin >> k_cs;

    Csomopont * csPont = new Csomopont[cs_db];
    csPont[k_cs-1].suly = 0;

    Dijkstra(SzM,cs_db,csPont);

    cout << endl;
    for(int i = 0; i < cs_db; i++){
        cout << k_cs << "-->" << i + 1 << " Utvonal: ";
        if(csPont[i].honnan != -1){
            cout << k_cs;
            utvonalKiir(csPont,i);
            cout <<"   Ut sulya: "<< csPont[i].suly << endl;
        }
        else cout << "Nincs ut!" << endl;
    }

    for(int i = 0; i < cs_db; i++){
        delete [] SzM[i];
    }
    delete [] SzM;
    delete [] csPont;

}

void Dijkstra(int **SzM, int cs_db, Csomopont * csPont){
    int kiv_cs = minSulyuCsomopont(csPont,cs_db);
    while(kiv_cs != -1){
        for(int i = 0; i < cs_db; i++){
            if(csPont[i].bejartuk) continue;
            if(csPont[kiv_cs].suly + SzM[kiv_cs][i] < csPont[i].suly){
                csPont[i].suly = csPont[kiv_cs].suly + SzM[kiv_cs][i];
                csPont[i].honnan = kiv_cs;
            }
        }
        csPont[kiv_cs].bejartuk = true;
        kiv_cs = minSulyuCsomopont(csPont, cs_db);
    }
}


int minSulyuCsomopont(Csomopont * csPont, int cs_db){
    int minimum = vegtelen;
    int min_ind = -1;
    for(int i = 0; i < cs_db; i++){
        if(!csPont[i].bejartuk && csPont[i].suly < minimum){
            minimum = csPont[i].suly;
            min_ind = i;
        }
    }
    return min_ind;
}













void utvonalKiir(Csomopont * csPont, int cs){
    if(csPont[cs].honnan != -1){
        utvonalKiir(csPont, csPont[cs].honnan);
        cout << "->" << cs + 1;
    }
}
