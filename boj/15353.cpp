#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string a,b;
  string ans = "";
  cin >> a >> b;

  int n = a.length()-1;
  int m = b.length()-1;

  string tmp = "";
  if(n<m){
    for(int i = 0; i<m-n; i++){
      tmp += "0";
    }
    a+=tmp;
  } else if(n>m){
    for(int i = 0; i<n-m; i++){
      tmp += "0";
    }
    b += tmp;
  }



  return 0;
}
