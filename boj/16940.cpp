#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
vector<int> a[100001];  // 정점 10만
bool check[100001];
int order[100001], input[100001];

bool isCorrectBfs() {
    queue<int> q;
    q.push(1);
    check[1] = true;

    int idx = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (input[idx++] != cur) return false;
        for (int u : a[cur]) {
            if (!check[u]) {
                q.push(u);
                check[u] = true;
            }
        }
    }
    return true;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> input[i];
        order[input[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        sort(a[i].begin(), a[i].end(), [](int a, int b) {
            return order[a] <= order[b];
        });
    }
    cout << isCorrectBfs();
    return 0;
}
