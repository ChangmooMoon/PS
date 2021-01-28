#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int n, sum;     // n 200000
int a[200000];  //a[i] 100000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int mid = floor((n - 1) / 2);
    cout << a[mid];
    return 0;
}