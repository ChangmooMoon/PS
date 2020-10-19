// library 'io.cpp'{{{
//
//////// ---- Source Code ---- ////////
#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int a,b,c,d;

  cin >> a >> b;
  d = b;
  while(d != 0){
    c = d%10;
    cout << a*c << '\n';
    d /= 10;
  }

  cout << a*b << endl;

  return 0;
}

//////// ---- Source Code ---- ////////}}}
