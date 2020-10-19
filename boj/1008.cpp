// library 'io.cpp'{{{
//
//////// ---- Source Code ---- ////////
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  double a,b;
  cin >> a >> b;
  cout << setprecision(10) << a/b << endl;
  return 0;
}

//////// ---- Source Code ---- ////////}}}
