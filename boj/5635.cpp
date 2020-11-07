#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct STDNT {
  int d,m,y;
  string s;
};

 int main(){
   ios_base::sync_with_stdio(nullptr);
   cin.tie(nullptr);

   int N;
   cin >> N;
   
   vector<STDNT> arr;
   for(int i = 0; i<N; i++){
     STDNT studnt;
     cin >> studnt.s >> studnt.d >> studnt.m >> studnt.y;
     arr[i] = studnt; 
   }

   STDNT min, max;
   do {
     min = vector[N];
     max = vector[N];
     N--;
   } while(N--){
     if(min. > arr[n].d)
   }
}

