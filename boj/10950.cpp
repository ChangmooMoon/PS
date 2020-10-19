#include <iostream>

using namespace std;

int main(){
  cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int T;
  cin >> T;
  while(T--){
    int a,b;
    cin >> a >> b;
    cout << a+b << '\n';
  }

  return 0;
}
