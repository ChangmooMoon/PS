#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int max = 0, idx = -1;
  for(int i = 0; i<9; ++i){
    int tmp;
    cin >> tmp;
    if(tmp > max) {
      max = tmp;
      idx = i;
    }
  }
  cout << max << '\n' << idx+1;
  return 0;
}

