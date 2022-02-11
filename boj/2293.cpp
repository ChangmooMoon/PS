#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, k;  // 동전종류100, 가치합10000
int a[101], d[10001];
// d[i] = min(i원 만드는데 필요한 동전 경우의 수)

int main() {
    FASTIO;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    d[0] = 1;
    for (int i = 0; i < n; ++i) {       // 동전
        for (int j = 1; j <= k; ++j) {  // 합
            int s = j - a[i];
            if (s >= 0) d[j] += d[s];
        }
    }
    cout << d[k];
}
