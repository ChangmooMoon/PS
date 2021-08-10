#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;
int a[1001];  // a[i]: i번 칸에서 할 수 있는 점프 범위
int d[1001];  // d[i]: i번 칸에 도착할 있는 최소 점프 횟수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // d[i] = min(d[j] + 1) , (j < i, i <= a[j] + j)
    d[0] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (d[j] != -1 && i - j <= a[j]) {
                if (d[i] == -1 || d[i] > d[j] + 1) {
                    d[i] = d[j] + 1;
                }
            }
        }
    }

    cout << d[n - 1] << endl;
    return 0;
}
