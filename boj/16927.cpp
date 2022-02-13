#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m, r;
vector<vector<int>> a;

void rotate(int r) {
    vector<vector<int>> groups;
    int layer = min(m, n) / 2;

    for (int k = 0; k < layer; ++k) {
        vector<int> v;
        for (int j = k; j < m - k; ++j) {
            v.push_back(a[k][j]);
        }
        for (int i = k + 1; i < n - 1 - k; ++i) {
            v.push_back(a[i][m - 1 - k]);
        }
        for (int j = m - 1 - k; j > k; --j) {
            v.push_back(a[n - 1 - k][j]);
        }
        for (int i = n - k - 1; i > k; --i) {
            v.push_back(a[i][k]);
        }
        groups.push_back(v);
    }

    for (int k = 0; k < layer; ++k) {
        vector<int>& v = groups[k];
        int len = v.size();
        int idx = r % len;

        for (int j = k; j < m - k; ++j, idx = (idx + 1) % len) {
            a[k][j] = v[idx];
        }
        for (int i = k + 1; i < n - k - 1; ++i, idx = (idx + 1) % len) {
            a[i][m - k - 1] = v[idx];
        }
        for (int j = m - k - 1; j > k; --j, idx = (idx + 1) % len) {
            a[n - k - 1][j] = v[idx];
        }
        for (int i = n - k - 1; i > k; --i, idx = (idx + 1) % len) {
            a[i][k] = v[idx];
        }
    }
}

int main() {
    FASTIO;
    cin >> n >> m >> r;
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    rotate(r);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
