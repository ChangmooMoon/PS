#include <iostream>
#include <string>

using namespace std;

string solve(int a, int b){
  if(a>b) return "-1";
  int sum = 0, min = 0;
  for(int i = 1; i<=100; i++){
    if(a <= i*i && i*i <=b){
      sum += i*i;
      if(min == 0) min = i*i;
    }
  }
  
  if(sum == 0) return "-1";
  return to_string(sum) + "\n" + to_string(min);  
}

int main(){
  int m,n;
  cin >> m >> n;

  cout << solve(m,n);
}
