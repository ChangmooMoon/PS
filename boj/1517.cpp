#include <iostream>
using namespace std;

int n;
int a[500000];
int tmp[500000];

long long solve(int s, int e) {
    if (s == e) return 0;

    int mid = (s + e) / 2;
    long long ans = solve(s, mid) + solve(mid + 1, e);

    int i = s;
    int j = mid + 1;
    int k = 0;

    while (i <= mid || j <= e) {
        if (i <= mid && (j > e || a[i] <= a[j])) {
            tmp[k++] = a[i++];
        } else {
            ans += mid - i + 1;
            tmp[k++] = a[j++];
        }
    }

    for (int i = s; i <= e; ++i) {
        a[i] = tmp[i - s];
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << solve(0, n - 1);
    return 0;
}
