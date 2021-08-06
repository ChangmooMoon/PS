#include <iostream>
#include <vector>
using namespace std;

int n;      // 50
int v[50];  // 절대값 100이하

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (n == 1)
        cout << 'B';
    else if (n == 2)
        cout << 'A';
    else {
        if (v[1] - v[0] == 0) {
            cout << 0;
        } else {
            int a = (v[2] - v[1]) / (v[1] - v[0]);
            int b = v[1] - v[0] * a;
            cout << v[n - 1] * a + b;
        }
    }
    return 0;
}

// v[1] = v[0] * a + b
// v[2] = v[1] * a + b
// v[2] - v[1] = (v[1] - v[0]) * a
// a = (v[2] - v[1]) / (v[1] - v[0])
// b= v[1] - (v[0] * a)