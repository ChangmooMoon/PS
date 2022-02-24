#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, k, mask;
int a[50];

int go(int alpha, int know) {
    int ans = 0;
    if (know == k) {
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if ((a[i] & mask) == a[i]) ++ans;
        }
        return ans;
    }

    for (int i = alpha; i < 26; ++i) {
        if (mask & (1 << i)) continue;
        mask |= 1 << i;
        ans = max(ans, go(i + 1, know + 1));
        mask &= ~(1 << i);
    }
    return ans;
}

int main() {
    FASTIO;
    string str = "antic";
    for (char ch : str) {
        mask |= 1 << (ch - 'a');
    }
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char ch : s) {
            a[i] |= 1 << (ch - 'a');
        }
    }
    if (k < 5)
        cout << 0;
    else if (k == 26)
        cout << n;
    else
        cout << go(0, 5);

    return 0;
}
