#include <iostream>
#include <queue>
#include <vector>
#define next _next
using namespace std;

vector<int> dist(101, -1);
vector<int> next(101);
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= 100; ++i) {
        next[i] = i;
    }
    for (int i = 0; i < n + m; ++i) {
        int u, v;
        cin >> u >> v;
        next[u] = v;
    }

    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= 6; ++i) {
            int nx = x + i;
            if (nx > 100) continue;
            nx = next[nx];
            if (dist[nx] != -1) continue;
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }

    cout << dist[100];
    return 0;
}
