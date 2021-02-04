#include <iostream>
using namespace std;

int t;
int d[11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for (int i = 3; i < 11; ++i) {
        d[i] = d[i - 3] + d[i - 2] + d[i - 1];
    }

    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }

    return 0;
}
