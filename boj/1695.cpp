#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 팰린드롬, LCS

int n;
int a[5001], b[5001], d[5001][5001];
// d[i][j] = max(i~j를 팰린드롬 만드는 숫자갯수)

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[n - i + 1] = a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }

    cout << n - d[n][n];
    return 0;
}
