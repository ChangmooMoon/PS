#include <bits/stdc++.h>
using namespace std;

// 최소 편집 거리 알고리즘

string a, b;
int N, M, d[1001][1001];

int main() {
    cin >> a >> b;
    N = a.length(), M = b.length();

    for (int i = 1; i <= N; ++i) {
        d[i][0] = i;
    }
    for (int j = 1; j <= M; ++j) {
        d[0][j] = j;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (a[i - 1] == b[j - 1])
                d[i][j] = d[i - 1][j - 1];
            else
                d[i][j] = min({d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]}) + 1;
        }
    }

    cout << d[N][M];
    return 0;
}
