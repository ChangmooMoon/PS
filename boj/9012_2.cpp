#include <iostream>
#include <stack>

using namespace std;

int main(){
  cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int T;
  cin >> T;
  cin.ignore();

  while(T--){
    string str = getline();
    cout << str << endl;
  }

  return 0;
}
