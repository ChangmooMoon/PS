#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// dp memoization

int n;
int cnt[3];
string s;
int d[51][51][51][3][3];  // d[a][b][c][p1][p2] = a,b,c,p1,p2 조합이 가능?

int go(int a, int b, int c, int p1, int p2) {
    int& ans = d[a][b][c][p1][p2];
    if (a + b + c == n) return ans = 1;
    if (ans != -1) return ans;

    if (a + 1 <= cnt[0] && go(a + 1, b, c, 0, p1) == 1) return ans = 1;
    if (b + 1 <= cnt[1] && p1 != 1 && go(a, b + 1, c, 1, p1) == 1) return ans = 1;
    if (c + 1 <= cnt[2] && p1 != 2 && p2 != 2 && go(a, b, c + 1, 2, p1) == 1) return ans = 1;
    return ans = 0;
}

string print(int a, int b, int c, int p1, int p2) {
    if (a + b + c == n) return "";
    if (a + 1 <= cnt[0] && go(a + 1, b, c, 0, p1) == 1)
        return "A" + print(a + 1, b, c, 0, p1);
    if (b + 1 <= cnt[1] && p1 != 1 && go(a, b + 1, c, 1, p1) == 1)
        return "B" + print(a, b + 1, c, 1, p1);
    if (c + 1 <= cnt[2] && p1 != 2 && p2 != 2 && go(a, b, c + 1, 2, p1) == 1)
        return "C" + print(a, b, c + 1, 2, p1);
    return "";
}

int main() {
    FASTIO;
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'A'];
    }

    memset(d, -1, sizeof(d));
    if (go(0, 0, 0, 0, 0)) {
        cout << print(0, 0, 0, 0, 0);
    } else
        cout << -1;
    return 0;
}
