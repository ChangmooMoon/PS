#include <iostream>

using namespace std;

int main(){
  cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int T, c = 0, a,b;
  cin >> T;
  while(T--){
    c++;
    cin >> a >> b;
    cout << "Case #" << c << ": " << a + b << '\n';
  }

  return 0;
}
