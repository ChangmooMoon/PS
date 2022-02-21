#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

char a[5][5];
unordered_set<string> uset;

void dfs(int r, int c, string s) {
    if (s.length() == 6) {
        uset.insert(s);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || 0 > nc || 5 <= nr || 5 <= nc)
            continue;
        dfs(nr, nc, s + a[nr][nc]);
    }
}

int main() {
    FASTIO;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            string str(1, a[i][j]);
            dfs(i, j, str);
        }
    }

    cout << uset.size();
    return 0;
}