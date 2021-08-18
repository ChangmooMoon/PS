#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t;
int d[10001];
int nums[] = {0, 1, 2, 3};

int main() {
    FASTIO;
    d[0] = 1;
    for (int i = 1; i <= 3; ++i) { // i로 시작하는 모든 조합 탐색
        for (int j = 1; j <= 10001; ++j) {
            int k = j - nums[i];       // 3= 4 - 1
            if (k >= 0) d[j] += d[k];  // d[4] += d[1]
        }
    }
    // d[3] = 4 : 1111, 211, 22, 31
    // 1~, 2~, 3~

    cin >> t;
    while (t--) {
        int n;  // 1만
        cin >> n;
        cout << d[n] << endl;
    }

    return 0;
}
