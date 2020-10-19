#include <iostream>
#include <string>

using namespace std;

struct Std {
  int d,m,y;
  string s;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n;
  cin >> n;
  std *c = new std[t];
  for(int i = 0; i<n; ++i){
    cin >> c[i].s >> c[i].d >> c[i].m >> c[i].y;
  }
  for(int: i = 0; i<t-1; i++){
    for(int j = 0; j<t-1; j++){

    }
  }

  return 0;
}
