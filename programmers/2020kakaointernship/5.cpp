#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> graph[200001];
unordered_map<int, int> reserve;
unordered_map<int, int> parent;
bool check[200001];

void bfs() {
    queue<int> q;
    check[0] = true;
    q.push(0);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = -0; i < graph[now].size(); ++i) {
            int next = graph[now][i];
            if (check[next]) continue;
            if (!check[parent[next]]) {
                reserve[parent[next]] = next;
                continue;
            }

            q.push(next);
            check[next] = true;
            if (reserve.find(next) != reserve.end()) {
                q.push(reserve[next]);
                check[reserve[next]] = true;
            }
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for (int i = 0; i < path.size(); ++i) {
        int u = path[i][0], v = path[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < order.size(); ++i) {
        int u = order[i][0], v = order[i][1];
        parent[v] = u;
    }

    if (parent[0] != 0) return false;

    bfs();

    for (int i = 0; i < n; ++i) {
        if (!check[i]) {
            return false;
        }
    }

    return true;
}
