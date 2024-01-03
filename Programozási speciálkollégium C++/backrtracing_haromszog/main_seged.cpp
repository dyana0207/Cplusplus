#include <iostream>
#include <fstream>

using namespace std;

void haromszog1(int,int);
void haromszog2(int,int, int);

int t[101][101], x[101], x1[101];
int maxx, n;

int main()
{
    ifstream f("haromszog15.txt");
    f >> n;
    for(int i = 0; i < n; i++){
        cout.width(2*(n-i));
        for(int j = 0; j < (i+1); j++){
           f >> t[i][j];
           //cout << t[i][j];
           //cout.width(4);
        }
        //cout<<endl;
    }
    f.close();

    x[0] = t[0][0];
    haromszog2(0,0,t[0][0]);
    cout << endl << "Legnagyobb osszeg: " << maxx << endl;
    for(int i = 0; i < n; i++){
        cout << x1[i] << " ";
    }
}

int osszeg(int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s += x[i];
    }
    return s;
}

void haromszog1(int i,int j){
    if(i == n-1){
        int s = osszeg(n);
        if(s > maxx){
            maxx = s;
            for(int i = 0; i < n; i++){
                x1[i] = x[i];
            }
        }
    }else{
        x[i+1] = t[i+1][j];
        haromszog1(i+1,j);
        x[i+1] = t[i+1][j+1];
        haromszog1(i+1,j+1);
    }
}



void haromszog2(int i,int j, int s){
    if(i == n-1){
        if(s > maxx) maxx = s;
    }else{
        haromszog2(i+1,j,s+t[i+1][j]);
        haromszog2(i+1,j+1,s+t[i+1][j+1]);
    }
}



