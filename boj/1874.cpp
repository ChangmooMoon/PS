#include <iostream>
#include <stack>

using namespace std;


int main(){
  cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int T;
  cin >> T;

  stack<char> s;
  int c = 0;

  while(T--){
    int a;
    cin >> a;
    if(a > c) {
      while(a > c){
        s.push(++c);
        ans += '+';
      }
    }
  }
  return 0;
}
