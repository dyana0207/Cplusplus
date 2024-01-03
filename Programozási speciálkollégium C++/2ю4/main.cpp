#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    int t[4][5];
    for(int i=0; i<4;i++)
        {
            for(int j=0; j<5;j++)
            {
                t[i][j]=rand() % 100;
                cout.width(3);
                cout<<t[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}
