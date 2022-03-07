#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int num[10][5][3] = {
    {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}}, // 0
    {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}},
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
    {{1, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
};

int n;
int a[5][20001];

int check(int c) { // (0,c) 시작
    for (int k = 0; k < 10; ++k) {
        if (k == 1) continue;

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a[i][j + c] != num[k][i][j]) goto nxt;
            }
        }
        return k;

    nxt:
        continue;
    }

    return 1;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < n / 5; ++j) {
            char ch;
            cin >> ch;
            if (ch == '#') a[i][j] = 1;
        }
    }

    for (int j = 0; j < n / 5; ++j) {
        if (a[0][j] == 1) {
            int x = check(j);
            cout << x;
            if (x != 1) j += 2;
        }
    }

    return 0;
}
