#include <iostream>
#include <vector>
using namespace std;

int n;
int a[20];
bool check[20 * 100000 + 1];

// 부분수열의 합 = 2^n * n가지;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += a[j];
            }
        }
        check[sum] = true;
    }

    for (int i = 1;; ++i) {
        if (!check[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}
