#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

// 최단경로 찾기 - 다익스트라 + 경로

struct Edge {
    int to, weight;
};

int n, m;  // 도시1000, 버스100000
vector<Edge> a[1001];
vector<int> dist(1001, INF);
vector<bool> check(1001);
vector<int> path(1001);

void print(int x, int cnt) {
    if (path[x] == -1) {
        cout << cnt << '\n';
        cout << x << ' ';
        return;
    }
    print(path[x], cnt + 1);
    cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        a[from].push_back({to, weight});
    }

    int start, end;
    cin >> start >> end;
    dist[start] = 0;
    path[start] = -1;
    for (int k = 0; k < n - 1; ++k) {
        int d = INF + 1;
        int x = -1;
        for (int i = 1; i <= n; ++i) {
            if (!check[i] && d > dist[i]) {
                d = dist[i];
                x = i;
            }
        }

        check[x] = true;
        for (int i = 0; i < a[x].size(); ++i) {
            int y = a[x][i].to;
            if (dist[y] > dist[x] + a[x][i].weight) {
                dist[y] = dist[x] + a[x][i].weight;
                path[y] = x;
            }
        }
    }

    cout << dist[end] << '\n';
    print(end, 1);

    // stack<int> st;
    // int x = end;
    // while (x != -1) {
    //     st.push(x);
    //     x = path[x];
    // }
    // cout << st.size() << '\n';
    // while (!st.empty()) {
    //     cout << st.top() << ' ';
    //     st.pop();
    // }

    return 0;
}
