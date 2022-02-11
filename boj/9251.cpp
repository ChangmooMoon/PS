#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

string s1, s2;
int d[1001][1001];

int main() {
    FASTIO;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i] == s2[j])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    cout << d[n][m];
    return 0;
}
