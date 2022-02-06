#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int d[2001][2001];  // d[s][c] = t

int solve(int n) {
    queue<pii> q;
    q.push({1, 0});  // s, c
    d[1][0] = 0;

    while (!q.empty()) {
        int s, c;
        tie(s, c) = q.front();
        q.pop();

        if (s == n) return d[s][c];
        if (d[s][s] == -1) {
            q.push({s, s});
            d[s][s] = d[s][c] + 1;
        }
        if (s + c <= 2000 && d[s + c][c] == -1) {
            q.push({s + c, c});
            d[s + c][c] = d[s][c] + 1;
        }
        if (s - 1 >= 0 && d[s - 1][c] == -1) {
            q.push({s - 1, c});
            d[s - 1][c] = d[s][c] + 1;
        }
    }

    return -1;
}

int main() {
    FASTIO;
    cin >> n;
    memset(d, -1, sizeof(d));
    cout << solve(n);
    return 0;
}
