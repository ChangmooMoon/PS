#include <iostream>
using namespace std;

int a[4][4];
int n, m;
int ans = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }

    // 가로0, 세로1, 배열idx = i*m+j
    for (int s = 0; s < (1 << (n * m)); ++s) {
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            int now = 0;
            for (int j = 0; j < m; ++j) {
                int idx = i * m + j;
                if ((s & (1 << idx)) == 0) {
                    now = now * 10 + a[i][j];
                } else {
                    sum += now;
                    now = 0;
                }
            }
            sum += now;
        }

        for (int j = 0; j < m; ++j) {
            int now = 0;
            for (int i = 0; i < n; ++i) {
                int idx = i * m + j;
                if ((s & (1 << idx)) != 0) {
                    now = now * 10 + a[i][j];
                } else {
                    sum += now;
                    now = 0;
                }
            }
            sum += now;
        }

        if (ans < sum) ans = sum;
    }

    cout << ans;
    return 0;
}
