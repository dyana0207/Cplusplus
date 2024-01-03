#include <iostream>

using namespace std;

void bejaras(int*, int, int);
void megoldas(int*, int);
int abs(int);
bool szabad(int*, int);

int main()
{
    int* tomb = NULL;
    int n;
    cout << "n: ";
    cin >> n;
    tomb = new int[n];
    megoldas(tomb, n);
    delete[] tomb;
    return 0;
}
int abs(int num){
    if(num < 0){
        return -num;
    }
    return num;
}
void megoldas(int* tomb, int n){
    bejaras(tomb, n, 0);
}
void bejaras(int* tomb, int n, int szint){
    for(int i=1; i<=n; i++){
        tomb[szint] = i;
        if(szabad(tomb, szint)){
            if(szint+1 == n){
                for(int l=0; l<n; l++){
                    cout << tomb[l] << " ";
                }
                cout << endl;
                break;
            }
            else{
                bejaras(tomb, n, szint+1);
            }
        }
    }
}
bool szabad(int* tomb, int szint){
    bool isSzabad = true;
    if(szint>0){
        for(int i=0; i<szint; i++){
            if(tomb[i] == tomb[szint] || abs(i-szint) == abs(tomb[i]-tomb[szint])){
                isSzabad = false;
                break;
            }
        }
    }
    return isSzabad;
}
