#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

int n, m;
int a[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = INF;
        }
    }

    for (int i = 0; i < m; ++i) {
        int x, y, weight;
        cin >> x >> y >> weight;
        if (a[x][y] > weight) {
            a[x][y] = weight;
        }
    }  // 인접행렬 초기화

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }  // 최단경로 연산

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == INF) a[i][j] = 0;
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
