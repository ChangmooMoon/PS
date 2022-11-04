#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, l; // 500만
int a[5000001]; // d[i] = min(a[i - L + 1] ~ a[i]) 

int main() {
	FASTIO;
	cin >> n >> l;

	deque<pair<int, int>> dq;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];

		while(!dq.empty() && dq.back().first > a[i]) {
			dq.pop_back();
		}

		dq.push_back({a[i], i});
		if(dq.front().second < i - l + 1) dq.pop_front();
		cout << dq.front().first << ' ';
	}

	return 0;
}
