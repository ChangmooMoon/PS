#include <iostream>

using namespace std;

int main(){
  cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int a,b;
  while(cin >> a >> b){
    if(a == 0 && b == 0) break;
    cout << a+b << '\n';
  }

  return 0;
}
