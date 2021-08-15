#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define union _union

int n, e;  // 정점1000개
vector<int> graph[1001];
vector<int> parent;

int find(int n) {
    if (parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}

void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

// disjoint-set 갯수 찾기
int main() {
    FASTIO;
    cin >> n >> e;
    parent.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
        for (int n : graph[i]) {
            union(i, n);
        }
    }

    sort(parent.begin(), parent.end());
    parent.erase(unique(parent.begin(), parent.end()), parent.end());
    cout << parent.size() - 2;  // idx 0 제외, 전체 노드갯수 - 1
    return 0;
}
