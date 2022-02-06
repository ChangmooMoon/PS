#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define MOD 10007

string str;
int dp[1005][1005];

int go(int s, int e) {
    if (s > e) {
        return 0;
    }

    int& ret = dp[s][e];
    if (ret != -1) {
        return ret;
    }

    ret = go(s + 1, e) + go(s, e - 1) - go(s + 1, e - 1) + MOD;
    if (str[s] == str[e]) {
        ret += go(s + 1, e - 1) + 1;
    }

    return ret %= MOD;
}

int main() {
    FASTIO;
    cin >> str;
    memset(dp, -1, sizeof(dp));
    cout << go(0, str.size() - 1);

    return 0;
}
