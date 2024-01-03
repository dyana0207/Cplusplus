#include <iostream>

using namespace std;
void rendez(int*t, int els, int veg)
{
   if(e==v) t[e];
   else{

   }
}
int szetvalogat(int *t,int e,int v){
   int pivot = t[e];
   while(e < v){
      while(t[e] < pivot){
         e++;
      }
      while(t[v] > pivot){
         v--;
      }
      if(e < v){
         swap(t[e], t[v]);
      }
      if(t[e] == t[v] && e != v)
         e++;
   }
   return e;
}

int main()
{
   int t[10]={5,6,7,0,1,2,4,8,30,9};
   szetvalogat(t,0,9);
   for(int i=0; i<10; i++)
   {
       cout<<t[i]<<" ";
   }
    return 0;
}
