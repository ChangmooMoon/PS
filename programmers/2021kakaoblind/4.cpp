#include <vector>
#define INF 4000001
using namespace std;

int d[200][200];

void floyd(int n) {
    for (int k = 0; k < n; ++k) {  // 경유지 인덱스
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }

    for (auto& e : fares) {
        int u = e[0] - 1, v = e[1] - 1, w = e[2];
        d[u][v] = w;
        d[v][u] = w;
    }

    floyd(n);

    --s, --a, --b;
    int ans = INF;
    for (int k = 0; k < n; ++k) {
        if (ans > d[s][k] + d[k][a] + d[k][b]) {
            ans = d[s][k] + d[k][a] + d[k][b];
        }
    }

    return ans;
}
