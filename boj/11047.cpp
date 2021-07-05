#include <iostream>
#include <vector>
using namespace std;

int n, k;
int a[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        cnt += (k / a[i]);
        k %= a[i];
    }

    cout << cnt;
    return 0;
}
