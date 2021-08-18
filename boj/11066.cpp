#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t;
int a[501];
int d[501][501];  // i부터 j까지 합치는 최소비용
// i ~ k ~ j
//d[i][j] =  min(d[i][k] + d[k+1][j]) + 전체비용, i <= k < j

int go(int s, int e) {
    if (s == e) return 0;  // 파일 1개
    if (d[s][e] != -1) return d[s][e];

    int sum = 0;
    int& ans = d[s][e];
    for (int i = s; i <= e; ++i) {
        sum += a[i];
    }

    for (int k = s; k <= e - 1; ++k) {
        int tmp = go(s, k) + go(k + 1, e) + sum;
        if (ans == -1 || ans > tmp) ans = tmp;
    }

    return ans;
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;  // 500장
        for (int i = 1; i <= k; ++i) {
            cin >> a[i];
        }

        memset(d, -1, sizeof(d));
        cout << go(1, k) << endl;
    }

    return 0;
}
