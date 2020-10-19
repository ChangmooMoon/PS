#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n,p;
  cin >> n;
  while(n--) {
    cin >> p;
    vector<pair<int,string>> v(p);
    int ans = 0, i = 0, ex = 0;
    while(p--){
      cin >> v[i].first >> v[i].second;
      if(v[i].first > ex){
        ex = v[i].first;
        ans = i;
      }
      i++;
    }
    cout << v[ans].second << '\n';
  }
}
