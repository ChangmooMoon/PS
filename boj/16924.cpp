#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;
string a[100];
bool check[100][100];
vector<tuple<int, int, int>> ans;

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '*') {
                int size = 0;
                for (int k = 1;; ++k) {
                    if (i + k >= n || i - k < 0 || j + k >= m || j - k < 0) break;
                    if (a[i + k][j] != '*' || a[i - k][j] != '*' || a[i][j + k] != '*' || a[i][j - k] != '*') break;

                    size = k;
                }

                if (size > 0) {
                    ans.push_back({i + 1, j + 1, size});
                    check[i][j] = true;
                    for (int k = 1; k <= size; ++k) {
                        check[i - k][j] = true;
                        check[i + k][j] = true;
                        check[i][j - k] = true;
                        check[i][j + k] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '*' && !check[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << ans.size() << endl;
    for (auto& t : ans) {
        const auto& [a, b, c] = t;
        cout << a << ' ' << b << ' ' << c << endl;
    }

    return 0;
}
