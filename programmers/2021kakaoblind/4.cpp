#include <string>
#include <vector>
#define INF 0x3f3f3f
using namespace std;

int d[201][201];

// 지점갯수n 200, 출발s,도착a,도착b, 요금벡터
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }
    for (vector<int> fare : fares) {
        int u, v, w;
        u = fare[0], v = fare[1], w = fare[2];
        d[u][v] = w, d[v][u] = w;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    int ans = INF;
    for (int k = 1; k <= n; ++k) {
        if (ans > d[s][k] + d[k][a] + d[k][b]) ans = d[s][k] + d[k][a] + d[k][b];
    }

    return ans;
}
