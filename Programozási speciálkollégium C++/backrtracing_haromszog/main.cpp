#include <iostream>
#include <fstream>
using namespace std;
int a, x[100],maxx, t[100][100];;
int osszeg(int a){
    int s = 0;
    for(int i = 0; i < a; i++){
        s += x[i];
    }
    return s;
}
void haromszog2(int i,int j, int s){
    if(i == a-1){
        if(s > maxx) maxx = s;
    }else{
        haromszog2(i+1,j,s+t[i+1][j]);
        haromszog2(i+1,j+1,s+t[i+1][j+1]);
    }
}
int main()
{
    cout << "Add meg a szamot!" << endl;
    string n;
    cin>>n;
    ifstream be;
    string f="haromszog";
    f+=n;
    f+=".txt";
    be.open(f.c_str());
    be>>a;
    int db=0,db1=0;
    while(!be.eof())
    {
       be>>t[db][db1];
       if(db1==db)
       {
           db1=-1;
            db++;
       }
        db1++;
    }
       for(int i=0; i<a; i++)
    {
        for(int j=0; j<i+1; j++)
        {
           cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
       x[0] = t[0][0];
    haromszog2(0,0,t[0][0]);
    cout << endl << "Legnagyobb osszeg: " << maxx << endl;
    for(int i = 0; i < a; i++){
        cout << x[i] << " ";
    }
}
    return 0;
}
