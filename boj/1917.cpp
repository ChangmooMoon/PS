#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

vector<vector<int>> a(8, vector<int>(8));
int type[11][3][5] = {
    {{0, 0, 0, 1, 0}, {1, 1, 1, 1, 0}, {0, 0, 1, 0, 0}},
    {{0, 0, 0, 1, 0}, {1, 1, 1, 1, 0}, {0, 1, 0, 0, 0}},
    {{0, 0, 0, 1, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}},
    {{0, 0, 1, 0, 0}, {1, 1, 1, 1, 0}, {0, 0, 1, 0, 0}},
    {{0, 0, 1, 0, 0}, {1, 1, 1, 1, 0}, {0, 1, 0, 0, 0}},
    {{0, 0, 1, 1, 0}, {1, 1, 1, 0, 0}, {0, 1, 0, 0, 0}},
    {{0, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 0}},
    {{0, 0, 1, 1, 0}, {1, 1, 1, 0, 0}, {0, 0, 1, 0, 0}},
    {{0, 0, 1, 1, 0}, {1, 1, 1, 0, 0}, {1, 0, 0, 0, 0}},
    {{0, 0, 1, 1, 0}, {0, 1, 1, 0, 0}, {1, 1, 0, 0, 0}},
    {{0, 0, 0, 1, 0}, {1, 1, 1, 1, 0}, {0, 0, 0, 1, 0}},
};

void rotate(vector<vector<int>>& a) {
    vector<vector<int>> tmp(8, vector<int>(8));
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            tmp[i][j] = a[j][7 - i];
        }
    }
    a = tmp;
}

void flip(vector<vector<int>>& a) {  // 상하반전
    for (int i = 0; i < 4; ++i) {    // 0,1,2
        for (int j = 0; j < 8; ++j) {
            swap(a[i][j], a[7 - i][j]);
        }
    }
}

bool check(int k, int r, int c) {  // 블럭타입, 블럭시작좌표
    for (int i = 0, x = r; i < 3; ++i, ++x) {
        for (int j = 0, y = c; j < 5; ++j, ++y) {
            if (type[k][i][j] != a[x][y]) return false;
        }
    }
    return true;
}

bool can() {
    for (int t = 0; t < 4; ++t) {
        rotate(a);
        for (int u = 0; u < 2; ++u) {
            flip(a);
            for (int k = 0; k < 11; ++k) {
                for (int i = 0; i <= 5; ++i) {
                    for (int j = 0; j <= 3; ++j) {
                        if (check(k, i, j)) return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    FASTIO;
    for (int k = 0; k < 3; ++k) {
        for (int i = 1; i <= 6; ++i) {
            for (int j = 1; j <= 6; ++j) {
                cin >> a[i][j];
            }
        }
        if (can())
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
