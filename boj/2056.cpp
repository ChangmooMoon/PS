#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
vector<int> a[10001];
int t[10001], ind[10001], d[10001];  // d[i] = min(i까지의 작업 완료 시간)

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        // 시간, 선행작업 갯수, (...선행작업 번호)
        int m;
        cin >> t[i] >> m;
        for (int j = 0; j < m; ++j) {
            int v;
            cin >> v;
            a[v].push_back(i);
            ++ind[i];
        }
    }

    queue<int> q;
    // ind가 0인 노드부터 시작
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
            d[i] = t[i];
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i];
            --ind[y];
            d[y] = max(d[x] + t[y], d[y]);
            if (ind[y] == 0) q.push(y);
        }
    }

    cout << *max_element(d + 1, d + n + 1);

    return 0;
}
