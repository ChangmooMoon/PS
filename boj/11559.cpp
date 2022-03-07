#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

string a[12];
bool check[12][6];
int ans = 0;

void go(char ch, int r, int c, vector<pii> &v) {
    if (0 > r || 0 > c || r >= 12 || c >= 6 || check[r][c] || a[r][c] != ch) return;
    v.push_back({r, c});
    check[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        go(ch, r + dr[i], c + dc[i], v);
    }
}

void down() {
    for (int i = 10; i >= 0; --i) {
        for (int j = 0; j < 6; ++j) {
            if (a[i][j] != '.') {
                int r = i;
                while (1) {
                    if (r == 11 || a[r + 1][j] != '.') break;
                    ++r;
                }
                swap(a[r][j], a[i][j]);
            }
        }
    }
}

int main() {
    FASTIO;
    for (int i = 0; i < 12; ++i) {
        cin >> a[i];
    }
    while (1) {
        memset(check, false, sizeof(check));
        bool stop = true;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                vector<pii> v;
                if (a[i][j] != '.' && !check[i][j]) go(a[i][j], i, j, v);
                if (v.size() >= 4) {
                    stop = false;
                    for (auto &[r, c] : v) {
                        a[r][c] = '.';
                    }
                }
            }
        }
        if (stop) break;
        ++ans;
        down();
    }

    cout << ans;
    return 0;
}
