#include <iostream>
#include <vector>
using namespace std;

int n;
int d[101][101];

// all-to-all 경로찾기 - 플로이드
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> d[i][j];
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (d[i][k] && d[k][j]) {
                    d[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
