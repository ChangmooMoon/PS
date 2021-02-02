#include <iostream>
#include <string>
using namespace std;

int n;
long long k;

long long calcLen(int n) {
    long long result = 0;
    for (int start = 1, len = 1; start <= n; start *= 10, len++) {
        int end = start * 10 - 1;  // 1~9, 10~99, 100~999, ...
        if (end > n) end = n;
        result += (long long)(end - start + 1) * len;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    if (calcLen(n) < k) {
        cout << -1;
        return 0;
    }

    int left = 1;  // 1~N
    int right = n;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (calcLen(mid) < k)  // mid까지 이어쓴 길이가 k보다 작으면
            left = mid + 1;
        else {
            right = mid - 1;
            ans = mid;
        }
    }

    string s = to_string(ans);
    long long N = calcLen(ans);
    cout << s[s.length() - 1 - (N - k)] << endl;
    return 0;
}
