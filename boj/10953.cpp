#include <iostream>

using namespace std;

int main(){
  cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int T,a,b;
  char tmp;
  cin >> T;
  while(T--){
    cin >> a >> tmp >>  b;
    cout << a+b << '\n';
  }

  return 0;
}
