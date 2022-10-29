#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n, m, cnt, ans;
vector<int> a[501];
bool check[501];

void print(int num) {
	cout << "Case " << cnt << ": ";
	if(num == 0) cout << "No trees." << endl;
	else if(num == 1) cout << "There is one tree." << endl;
	else cout << "A forest of " << num << " trees." << endl;
	return;
}

int dfs(int now, int prev) {
	check[now] = true;

	for(int next: a[now]) {
		if(next == prev) continue;
		if(check[next]) return false;
		if(!dfs(next, now)) return false;
	}
	return true;
}

int main() { // 사이클이 없는 연결요소
	FASTIO;
	while(1) {
		cin >> n >> m; // 정점갯수, 간선갯수
		if(!n && !m) break;

		for(int i = 1; i <= n; ++i)
			a[i].clear();
		memset(check, false, sizeof(check));
		++cnt;
		ans = 0;

		for(int i = 0; i < m; ++i) {
			int from, to;
			cin >> from >> to;
			a[from].push_back(to);
			a[to].push_back(from);
		}

		for(int i = 1; i <= n; ++i) {
			if(check[i]) continue;
			if(dfs(i, 0)) ++ans;
		}

		print(ans);
	}
	return 0;
}
