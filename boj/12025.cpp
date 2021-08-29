#include <iostream>
#include <string>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

// 1 or 6, 2 or 7
// 6 -> 1로 바꾸고 7 -> 2로 바꾸고 사전순 나열해서 k번째가 원래 비밀번호
// 원래 비밀번호 출력
int main() {
    FASTIO;
    string s;       // s길이 60, 앞자리 0가능
    long long k;    // 2^63 -1
    cin >> s >> k;  //
    k -= 1;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '6' || s[i] == '7') {
            s[i] -= 5;
        }
    }

    // k = 4 = 0011
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '1' || s[i] == '2') {
            if (k & 1) s[i] += 5;
            k = (k >> 1);
        }
    }
    if (k > 0)
        cout << -1;
    else
        cout << s;
    return 0;
}
