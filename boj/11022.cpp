#include <iostream>

using namespace std;

int main(){
  cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int T,a,b,c=0;
  cin >> T;
  while(T--){
    cin >> a >> b;
    c++;
    cout << "Case #" << c << ": " << a << " + " << b << " = " << a+b << '\n'; 
  }

  return 0;
}
