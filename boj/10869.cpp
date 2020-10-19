// library 'io.cpp'{{{
//
//////// ---- Source Code ---- ////////
#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int a,b;
  cin >> a >> b;
  cout << a+b << '\n' << a-b << '\n' << a*b << '\n' << a/b << '\n' << a%b;

  return 0;
}

//////// ---- Source Code ---- ////////}}}
