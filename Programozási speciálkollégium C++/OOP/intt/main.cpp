 #include <iostream>
 #include "inttomb.h"
using namespace std;

int main()
{
    inttomb t1(3);
    t1.elemek[0]=1;
    t1.elemek[1]=2;
    t1.elemek[2]=3;
    cout<<"T1 elemei"<<endl;
    cout<<t1.elemek[0] <<  " " <<t1.elemek[1] <<  " " <<t1.elemek[2] <<  " " <<endl;
     inttomb t2(3);
     t2=t1;
    cout<<"T2 elemei"<<endl;
    cout<<t2.elemek[0] <<  " " <<t2.elemek[1] <<  " " <<t2.elemek[2] <<  " " <<endl;
    t1.elemek[0]=15;
    t1.elemek[1]=42;
    t1.elemek[2]=36;
      cout<<"T1 elemei"<<endl;
    cout<<t1.elemek[0] <<  " " <<t1.elemek[1] <<  " " <<t1.elemek[2] <<  " " <<endl;
       cout<<"T2 elemei"<<endl;
    cout<<t2.elemek[0] <<  " " <<t2.elemek[1] <<  " " <<t2.elemek[2] <<  " " <<endl;
    t1.length();
    return 0;
}
