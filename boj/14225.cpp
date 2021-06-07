#include <iostream>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

bool check[2000001];
int a[20];
int n;

void go(int idx, int sum) {
    if (idx == n) {
        check[sum] = true;
        return;
    }

    go(idx + 1, sum);           // a[idx] 선택안함
    go(idx + 1, sum + a[idx]);  // 선택함
}

// 10만 * 20 = 200만
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    go(0, 0);

    for (int i = 0; i < 2000001; ++i) {
        if (!check[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}
