#include <iostream>
#include <fstream>
using namespace std;
enum Nem{ferfi, no};
class szemely{
    string vnev, knev, munkahely;
    unsigned int kor;
    Nem nem;
public:
    szemely()
    {
       vnev="";
       knev="";
       munkahely="";
       kor=0;
    }
    szemely(string vnev="Orosz", string knev="Diana", Nem nem=no )
    {
        this->vnev=vnev;
        this->knev=knev;
        this->nem=nem;
    }
    szemely(string vnev="Orosz", string knev="Diana",string munkahely="tanulo", Nem nem=no ) :kor(18)
    {
        this->vnev=vnev;
        this->knev=knev;
        this->nem=nem;
        this -> munkahely=munkahely;
    }
    bool munkanelkuli();
    bool nyugdijjas();
    bool setvnev(string);
    string getvnev();
    bool setknev(string);
    string getknev();
    bool setkor(unsigned int);
    unsigned int getkor();
    void setneme(Nem);
    void printname();
    string getneve();
    void setmunka(string);
    string getmunka();
    void printnev();
    void printalldata();
    };
int main()
{
    szemely a();
    a.printalldata();
    /*szemely t[5];
    ifstream be("fajl.txt");
    int db=0;
    string seged1;
    int seged2;
        for(int i=0; i<5; i++)
        {
            be>>seged1;
            t[i].setvnev(seged1);
            be>>seged1;
            t[i].setknev(seged1);
            be>>seged2;
            t[i].setkor(seged2);
            be>>seged2;
            if(seged2==0)
            {
                t[i].setneme(ferfi);
                }
            if(seged2!=0)
            {
                t[i].setneme(no);
            }
            be>>seged1;
            t[i].setmunka(seged1);
        }
     for(int i=0; i<5; i++)
        {
          t[i].printalldata();
          cout<<endl;
        }*/

    return 0;
}
bool szemely::setvnev(string vnev)
{
    bool ok=true;
    for(int i=0; i<vnev.length(); i++)
    {
        if(!isalpha(vnev[i]))
        {
            ok=false;
            break;
        }
    }
        if(islower(vnev[0]))
            ok=false;
        if(ok){
            this->vnev=vnev;
        }
    return ok;
}
string szemely::getvnev()
    {
        return vnev;
    }
bool szemely::setknev(string knev)
    {
        bool ok=true;
    for(int i=0; i<knev.length(); i++)
    {
        if(!isalpha(knev[i]))
        {
            ok=false;
            break;
        }
    }
        if(islower(knev[0]))
            ok=false;
        if(ok){
            this->knev=knev;
        }
    return ok;

 }
string szemely::getknev()
    {
        return knev;
    }
bool szemely::setkor(unsigned int kor)
{
    if(kor>=0 && kor<=120)
    {
        this->kor=kor;
        return true;
    }
    return false;
}
unsigned int szemely::getkor()
    {
        return kor;
    }
void szemely::setneme(Nem nem)
    {
        this->nem=nem;
    }
void szemely::printname()
{
    if(nem==ferfi)
    {
        cout<<"Feri"<<endl;
    }
    else{ cout<<"No"<<endl;}
}
string szemely::getneve()
{
    return vnev+ " " +knev;
}
void szemely::setmunka(string m)
{
    this->munkahely=m;
}
string szemely::getmunka()
{
    return munkahely;
}
void szemely::printnev()
{
    cout<<getneve()<<endl;
}
void szemely::printalldata()
{
    cout<<"Nev: "<<getneve()<<endl;
    cout<<"Kor: "<< kor<<endl;
    cout<<"Neme: ";
    printname();
    cout<<"Munkahely: "<<munkahely<<endl;
}
