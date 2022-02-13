#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 특이한 dp

int d[31][31][31][436];
char ans[31];
int n, k;
// d[i][a][b][p] = 길이가 i, A가 a개, B가 b개, s[i] < s[j] 쌍이 p개 있는 문자열

int go(int len, int a, int b, int p) {
    if (len == n) {
        if (p == k) return true;
        return false;
    }
    if (d[len][a][b][p]) return false;

    d[len][a][b][p] = 1;
    ans[len] = 'A';
    if (go(len + 1, a + 1, b, p)) return true;
    ans[len] = 'B';
    if (go(len + 1, a, b + 1, p + a)) return true;
    ans[len] = 'C';
    if (go(len + 1, a, b, p + a + b)) return true;

    return false;
}

int main() {
    FASTIO;
    cin >> n >> k;
    if (go(0, 0, 0, 0))
        cout << ans;
    else
        cout << -1;

    return 0;
}
