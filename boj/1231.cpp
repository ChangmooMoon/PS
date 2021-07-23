#include <algorithm>
#include <iostream>
using namespace std;

int c, d, m;    // 주식갯수, 기간, 초기자금
int a[50][10];  // 주식
int dp[50][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> d >> m;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < d; ++j) {
            cin >> a[i][j];
        }
    }
    

    return 0;
}
