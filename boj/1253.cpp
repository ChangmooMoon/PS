#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// 투포인터를 이용하여 good인 수인지 체크하는 로직의 시간복잡도를 줄임

int n;
int a[2001];

int main() {
	FASTIO;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a, a + n);

	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		int target = a[i];
		int s = 0, e = n - 1;

		while(s < e) {
			int num = a[s] + a[e];
			if(num < target) ++s;
			else if(num > target) --e;
			else {
				if(s == i) ++s;
				else if(e == i) --e;
				else {
					++cnt;
					break;
				}
			}
		}
	}

	cout << cnt;
	return 0;
}
