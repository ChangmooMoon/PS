#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

vector<vector<bool>> a(6, vector<bool>(4)); // x
vector<vector<bool>> b(6, vector<bool>(4)); // y
int n, score = 0, rest = 0;

int moving(vector<vector<bool>> &v, int t, int c) {
    // i == 0 블록있으면 i==5제거하고밀기, i == 1이 블록 있으면 i==5제거하고밀기
    // t1, a[i][c]
    // t2, a[i][c], a[i][c+1]
    // t3, a[i][c], a[i+1][c]
    int maxr = -1;
    for (int i = 0; i < 6; ++i) {
        if (v[i][c] == 0) {
            maxr = i;
        } else
            break;
    }

    if (t == 2) {
        int maxr2 = -1;
        for (int i = 0; i < 6; ++i) {
            if (v[i][c + 1] == 0) {
                maxr2 = i;
            } else
                break;
        }
        if (maxr > maxr2)
            maxr = maxr2;
    }
    v[maxr][c] = 1;
    if (t == 2) { // 가로
        v[maxr][c + 1] = 1;
    } else if (t == 3) { // 세로
        v[maxr - 1][c] = 1;
    }

    int broken = 0;
    int br = -1;
    for (int i = 0; i < 6; ++i) {
        bool flag = true;
        for (int j = 0; j < 4; ++j) {
            if (v[i][j] == 0)
                flag = false;
        }
        if (flag) {
            ++broken;
            for (int j = 0; j < 4; ++j) {
                v[i][j] = 0;
            }
            br = max(br, i);
        }
    }

    if (broken) {
        for (int i = br; i >= 0; --i) {
            for (int j = 0; j < 4; ++j) {
                v[i][j] = 0;
                if (i - broken >= 0) {
                    v[i][j] = v[i - broken][j];
                }
            }
        }
    }

    int sbroken = 0;
    for (int i = 0; i <= 1; ++i) {
        bool flag = false;
        for (int j = 0; j < 4; ++j) {
            if (v[i][j])
                flag = true;
        }
        if (flag)
            ++sbroken;
    }

    if (sbroken) {
        for (int i = 5; i >= 0; --i) {
            for (int j = 0; j < 4; ++j) {
                v[i][j] = 0;
                if (i - sbroken >= 0) {
                    v[i][j] = v[i - sbroken][j];
                }
            }
        }
    }
    return broken;
}

int main() {
    FASTIO;
    cin >> n;

    while (n--) {
        int t, r, c;
        cin >> t >> r >> c;
        if (t == 1) {
            score += moving(a, 1, c) + moving(b, 1, r);
        } else if (t == 2) {
            score += moving(a, 2, c) + moving(b, 3, r);
        } else {
            score += moving(a, 3, c) + moving(b, 2, r);
        }
    }

    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            rest += a[i][j] + b[i][j];
        }
    }
    cout << score << endl << rest;
    return 0;
}
