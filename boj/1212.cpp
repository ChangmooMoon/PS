#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int main() {
    FASTIO;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        int d = s[i] - '0';
        int a[3];
        for (int j = 2; j >= 0; --j) {
            a[j] = d % 2;
            d /= 2;
        }
        if (i == 0) {
            if (!a[0] && !a[1])
                cout << a[2];
            else if (!a[0])
                cout << a[1] << a[2];
            else
                cout << a[0] << a[1] << a[2];
        } else {
            cout << a[0] << a[1] << a[2];
        }
    }
    return 0;
}
