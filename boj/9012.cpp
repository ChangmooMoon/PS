#include <iostream>
#include <string>
using namespace std;

string solve(string s){
  int count = 0;
  for(int i = 0; i<s.size(); ++i){
    if(s[i] == '(') count++;
    else count--;

    if(count < 0) return "NO";
  }

  if(count != 0) return "NO";
  return "YES";
}

int main(){
  cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int T;
  cin >> T;

  while(T--){
    string s;
    cin >> s;
    cout << solve(s) << '\n';
  }
  return 0;
}
