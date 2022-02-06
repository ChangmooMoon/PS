#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 에라스토테네스의 체, 소수

int n;
vector<int> prime;
bool check[4000005];

int solve() {
    if (n == 1) return 0;
    int l = 0, r = 0, sum = prime[0], ans = 0;
    while (l <= r & r < prime.size()) {
        if (sum < n) {
            sum += prime[++r];
        } else if (sum > n) {
            sum -= prime[l++];
        } else {
            ++ans;
            sum += prime[++r];
        }
    }

    return ans;
}

int main() {
    FASTIO;
    cin >> n;  // 2000^2 = 400만
    for (int i = 2; i <= n; ++i) {
        if (!check[i]) {
            prime.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                check[j] = true;
            }
        }
    }

    cout << solve();
    return 0;
}
