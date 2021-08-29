#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define MOD 1000000007

// 색칠할 수 있는 모든 경우의 수.
// 완전순열 : n개의 원소로 이루어진 집합에서 나온 순열 A,B에서
// 같은 위치에 원소가 한가지도 없는 경우
// d[i] = (i-1) * (d[i-1] + d[i-2])

int n;
int d[1000001] = {0, 0, 2, 12};

int main() {
    FASTIO;
    cin >> n;
    for (int i = 4; i <= n; ++i) {
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % MOD;
    }
    cout << d[n];

    return 0;
}
