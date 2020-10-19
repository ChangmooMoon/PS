#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T,A,B;

  cin >> T;

  while(T-- > 0){
    cin >> A >> B;
    cout << A+B << "\n";
  }

  return 0;
}
