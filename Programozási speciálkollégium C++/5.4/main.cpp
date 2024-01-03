#include <iostream>

using namespace std;
void fugg(int [][5], int n);
void fugg(void * m, int a, int b);
int main()
{
    int t[3][5]={{1,2,3,4,4},  {5,6,7,8,1},{4,5,6,2,3}};
    fugg(t, 3);
    int t1[2][3]={{1,2,3},{5,6,7}};
    fugg(t1,2,3);
    return 0;
}
void fugg(int t[][5], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout.width(3);
            cout<<t[i][j];
        }
        cout<<endl;
    }
}
void fugg(void * m, int a, int b)
{
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            cout.width(3);
            cout<<*((int *)m+ i*b+j);
        }
        cout<<endl;
    }

}

