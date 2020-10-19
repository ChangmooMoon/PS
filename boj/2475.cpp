#include <iostream>
#include <cmath>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  double a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;
  cout << (static_cast<int>(pow(a,2) + pow(b,2) + pow(c,2) + pow(d,2) + pow(e,2))) % 10;

  return 0;
}
