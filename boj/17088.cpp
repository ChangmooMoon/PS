#include <cstring>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n;
int a[100000];

int cal[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int solve(int i) {
    int acpy[100000];
    memcpy(acpy, a, sizeof(a));
    acpy[0] += cal[i][0];
    acpy[1] += cal[i][1];
    int d = acpy[1] - acpy[0];

    int cnt = abs(cal[i][0]) + abs(cal[i][1]);
    for (int i = 2; i < n; ++i) {
        int d2 = acpy[i] - acpy[i - 1];
        if (d2 == d)
            continue;
        else if (d2 - d == 1) {
            --acpy[i];
            ++cnt;
        } else if (d2 - d == -1) {
            ++acpy[i];
            ++cnt;
        } else
            return -1;
    }
    return cnt;
}

int main() {
    FASTIO;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = INF;
    for (int i = 0; i < 9; ++i) {
        int res = solve(i);
        if (res != -1) ans = min(ans, res);
    }

    cout << (ans == INF ? -1 : ans);
    return 0;
}
