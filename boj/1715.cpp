#include <algorithm>
#include <iostream>
using namespace std;

int n;           // n 100000
int a[100'000];  // a[i] 1000
int b[100'000];

// Bn = 1*An + 2*A(n-1)+ ... + (n-2)*A3+ (n-1)(A1+A2)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    b[0] = a[0];
    b[1] = a[0] + a[1];
    for (int i = 2; i < n; ++i) {
        b[i] = a[i] + 
    }

    cout << b[n - 1] << endl;

    return 0;
}

// 10 20 30 40
// 10+20 30+30 60+40
// 210