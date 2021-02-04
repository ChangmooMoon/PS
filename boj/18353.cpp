#include <algorithm>
#include <iostream>
using namespace std;

int n;        // 2000
int a[2001];  // a[i] 10,000,000
int d[2001];  // 감소수열 길이
int rest = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    d[1] = 1;
    for (int i = 2; i <= n; ++i) {
        d[i] = 1;
        for (int j = 0; j < i; ++j) {              // a[j], a[i] 순으로 배치
            if (a[j] > a[i] && d[j] + 1 > d[i]) {  //a내림차순 배치,
                d[i] = d[j] + 1;
            }
        }
        rest = max(rest, d[i]);  // 만들어진 수열 길이
    }
    cout << n - rest;
}
