#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// MST - kruskal 알고리즘, union-find

struct Edge {
    int from, to, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<int> p(10001);
int Find(int x) {
    if (x == p[x])
        return x;
    else
        return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    p[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= v; ++i) {
        p[i] = i;
    }

    vector<Edge> edgeList(e);
    for (int i = 0; i < e; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        edgeList[i] = {x, y, c};
    }
    sort(edgeList.begin(), edgeList.end());  // 오름차순으로 간선 정렬

    int ans = 0;
    for (int i = 0; i < e; ++i) {
        Edge edge = edgeList[i];
        int x = Find(edge.from);
        int y = Find(edge.to);
        if (x != y) {
            Union(edge.from, edge.to);
            ans += edge.cost;
        }
    }

    cout << ans;
    return 0;
}
