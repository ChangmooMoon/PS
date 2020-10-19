// library 'io.cpp'{{{
//
//////// ---- Source Code ---- ////////
#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int A,B,C;
  cin >> A >> B >> C;
  cout << (A+B)%C << '\n' << ((A%C) + (B%C))%C << '\n' << (A*B)%C << '\n' << ((A%C) *(B%C))%C;

  return 0;
}

//////// ---- Source Code ---- ////////}}}
