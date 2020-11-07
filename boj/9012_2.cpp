#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solve(string str){
  stack<bool> s;
  
  for(int i = 0; i<str.length(); i++){
    if(str[i] == '('){
      s.push(true);
    } else {
      if(!s.empty()){
        s.pop();
      } else {
        return false;
      }
    }
  }
  return s.empty();
}

int main(){
  int T;
  cin >> T;
  while(T--){
    string s;
    cin >> s;
    if(solve(s)) cout << "YES";
    else cout << "NO";

    cout << "\n";
  }
  return 0;
}
