#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int n;
int d[100][100];
vector<pair<int, int>> a;

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (i != j) d[i][j] = INF;
        }
    }

    for (int i = 0; i < n; ++i) {
        char u, v;
        string tmp;
        cin >> u >> tmp >> v;
        int s = u - 'A', e = v - 'A';
        d[s][e] = 1;
    }

    for (int k = 0; k < 100; ++k) {
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (d[i][j] != INF && i != j) a.push_back({i, j});
        }
    }
    sort(a.begin(), a.end());
    cout << a.size() << endl;
    for (auto &[from, to] : a) {
        cout << (char)(from + 'A') << " => " << (char)(to + 'A') << endl;
    }
    return 0;
}

// A 65 z 122