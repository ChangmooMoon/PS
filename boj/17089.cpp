#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, ans = -1;
vector<int> a[4001]; // 3명 친구 사이클

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) { // 식자
        for (int j : a[i]) {
            for (int k : a[j]) {
                for (int l : a[k]) {
                    if (l == i) {
                        int ret = a[i].size() + a[j].size() + a[k].size() - 6;
                        if (ans == -1 || ans > ret) {
                            ans = ret;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
