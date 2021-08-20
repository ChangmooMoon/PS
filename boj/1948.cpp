#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, s, e;
vector<pii> a[10001], b[10001];         // 정방향, 역방향
int ind[10001], ind2[10001], d[10001];  // indegree, 도착시간d[i]
bool check[10001];

// DAG 가장 긴 경로
// 가장 긴 경로에 포함된 엣지 갯수
int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        b[v].push_back({u, w});
        ++ind[v];
        ++ind2[u];
    }
    cin >> s >> e;

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) q.push(i);
    }

    // indegree 0인 노드부터 차례대로 업데이트
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto& [y, w] : a[x]) {
            d[y] = max(d[y], d[x] + w);
            --ind[y];
            if (ind[y] == 0) q.push(y);
        }
    }
    cout << d[e] << endl;  // 순회 끝나는 시간

    for (int i = 1; i <= n; ++i) {
        if (ind2[i] == 0) q.push(i);
    }

    int cnt = 0;
    check[e] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto& [y, w] : b[x]) {
            if (check[x] && d[x] - d[y] == w) {
                check[y] = true;
                ++cnt;
            }

            --ind2[y];
            if (ind2[y] == 0) q.push(y);
        }
    }

    cout << cnt;
    return 0;
}
