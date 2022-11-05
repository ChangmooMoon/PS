#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string s;
vector<int> num, num2;
vector<char> op;

int main() {
	FASTIO;
	cin >> s;

	int curr = 0;
	for(char ch: s) {
		if('0' <= ch && ch <= '9') curr = curr * 10 + (ch - '0');
		else {
			op.push_back(ch); // +, -
			num.push_back(curr); // 피연산자
			curr = 0;
		}
	}
	num.push_back(curr);
	
	num2.push_back(num[0]);
	int p = 0;
	for(int i = 0; i < op.size(); ++i) {
		if(op[i] == '+') {
			num2[p] += num[i + 1];
		} else {
			++p;
			num2.push_back(num[i + 1]);
		}
	}

	int ans = num2[0];
	for(int i = 1; i < num2.size(); ++i) {
		ans -= num2[i];
	}
	
	cout << ans;
	return 0;
}
