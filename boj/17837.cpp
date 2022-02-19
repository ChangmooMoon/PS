#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};

int n, k;
int color[12][12];
vector<int> a[12][12]; // {idx1, idx2,...}
vector<tiii> pos;      // {r, c, d}

int redirect(int d) {
    if (d == 0)
        return 1;
    if (d == 1)
        return 0;
    if (d == 2)
        return 3;
    else
        return 2;
}

bool rangecheck(int r, int c) {
    if (0 > r || 0 > c || n <= r || n <= c || color[r][c] == 2)
        return false;
    return true;
}

bool move(int idx, int r, int c, int d) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (!rangecheck(nr, nc)) {
        d = redirect(d);
        nr = r + dr[d];
        nc = c + dc[d];
        if (!rangecheck(nr, nc)) {
            pos[idx] = {r, c, d};
            return false;
        }
    }

    get<2>(pos[idx]) = d;

    vector<int> v;
    int len = a[r][c].size();
    for (int i = len - 1; i >= 0; --i) {
        v.push_back(a[r][c][i]);
        a[r][c].pop_back();
        if (*v.rbegin() == idx) {
            break;
        }
    }

    if (color[nr][nc] == 0)
        reverse(v.begin(), v.end());

    for (int num : v) {
        a[nr][nc].push_back(num);
        get<0>(pos[num]) = nr;
        get<1>(pos[num]) = nc;
    }

    if (a[nr][nc].size() >= 4)
        return true;
    return false;
}

int solve() {
    int ret = 0;
    while (1000 > ret++) {
        for (int i = 0; i < k; ++i) {
            int r, c, d;
            tie(r, c, d) = pos[i];
            bool flag = move(i, r, c, d);
            if (flag)
                return ret;
        }
    }
    return -1;
}

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> color[i][j];
        }
    }
    for (int i = 0; i < k; ++i) {
        int r, c, d;
        cin >> r >> c >> d;
        --r, --c, --d;
        pos.push_back({r, c, d});
        a[r][c].push_back(i);
    }

    cout << solve();
    return 0;
}
