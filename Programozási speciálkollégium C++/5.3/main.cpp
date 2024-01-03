#include <iostream>

using namespace std;
void fugg(int [4][5]);
int main()
{
    int t[4][5]={{1,2,3,4,4},  {5,6,7,8,1},{4,5,6,2,3}, {4,2,6,8,9}};
    fugg(t);
    return 0;
}
void fugg(int t[4][5])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout.width(3);
            cout<<t[i][j];
        }
        cout<<endl;
    }
}
