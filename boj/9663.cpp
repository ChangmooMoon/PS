#include <iostream>
#include <vector>
using namespace std;

// 케이스: 행,열,대각에 각각 1개 -> n!
int n;
bool map[15][15];
bool col[15];
bool LtoR[30];
bool RtoL[30];

bool check(int r, int c) {
    if (col[c]) return false;
    if (LtoR[r + c]) return false;
    if (RtoL[r - c + n]) return false;

    return true;
}

int calc(int r) {
    if (r == n) return 1;

    int cnt = 0;
    for (int c = 0; c < n; ++c) {
        if (check(r, c)) {
            LtoR[r + c] = true;
            RtoL[r - c + n] = true;
            col[c] = true;
            cnt += calc(r + 1);

            LtoR[r + c] = false;
            RtoL[r - c + n] = false;
            col[c] = false;
            map[r][c] = false;
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cout << calc(0);

    return 0;
}
