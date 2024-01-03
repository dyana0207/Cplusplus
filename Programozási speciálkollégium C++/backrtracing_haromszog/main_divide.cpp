#include <iostream>
#include <fstream>

using namespace std;

int haromszog1(int,int);

int t[101][101], x[101];
int maxx, n;

int main()
{
    ifstream f("haromszog100.txt");
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

    maxx = haromszog1(0,0);
    cout << endl << "Legnagyobb osszeg: " << maxx << endl;
}

int haromszog1(int i,int j){
    if(i == n-1){
        return t[i][j];
    }else{
        int a = haromszog1(i+1,j);
        int b = haromszog1(i+1,j+1);
        return max(a,b) + t[i][j];
    }
}
