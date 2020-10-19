#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int T;
  cin >> T;

  int max = -1'000'001,min = 1'000'001;

  if(T == 1){
    int tmp;
    cin >> tmp;
    cout << tmp << " " << tmp;
    return 0;
  }

  while(T--){
    int tmp;
    cin >> tmp;
    if(tmp < min) min = tmp;
    if(tmp > max) max = tmp;
  }
  
  cout << min << " " << max;
  return 0;
}
