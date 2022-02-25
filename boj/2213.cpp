#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n;
int w[10001];
int d[10001][2];
vector<int> a[10001], tree[10001];
bool check[10001];
vector<int> ans;

// tree dp
void dfs(int now, int prev) {
    for (int next : a[now]) {
        if (next != prev) {
            tree[now].push_back(next);
            dfs(next, now);
        }
    }
}

int dp(int now, bool b) { // 집합에 포함, 비포함
    int &res = d[now][b];
    if (res != -1) return res;

    int ans = 0;
    if (b) {
        for (int next : tree[now]) {
            ans += dp(next, false);
        }
        return res = ans + w[now];
    } else {
        for (int next : tree[now]) {
            int t1 = dp(next, false);
            int t2 = dp(next, true);
            if (t1 < t2) check[next] = true;
            ans += max(t1, t2);
        }
        return res = ans;
    }
}

void traversal(int now, bool b) {
    if (b) {
        ans.push_back(now);
        for (int next : tree[now]) {
            traversal(next, false);
        }
    } else {
        for (int next : tree[now]) {
            traversal(next, check[next]);
        }
    }
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v), a[v].push_back(u);
    }
    memset(d, -1, sizeof(d));

    dfs(1, 1);
    int t1 = dp(1, false), t2 = dp(1, true);
    if (t1 < t2) {
        check[1] = true;
        cout << t2 << endl;
    } else
        cout << t1 << endl;

    traversal(1, check[1]);
    sort(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << ' ';
    return 0;
}
