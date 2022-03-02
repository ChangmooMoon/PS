#include <algorithm>
#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, ans;
string a[50];

int main() {
    FASTIO;
    cin >> n;
    ans = n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, [](string a, string b) { return a.length() < b.length(); });
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        for (int j = i + 1; j < n; ++j) {
            if (a[j].find(a[i]) == 0) {
                flag = true;
                break;
            }
        }
        if (flag) --ans;
    }

    cout << ans;
    return 0;
}
