#include <climits>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int t, n, m;
int A[101], B[101], d[101][101];

int solve(int idxa, int idxb) {
    int& ret = d[idxa + 1][idxb + 1];
    if (ret != -1) return ret;

    ret = 0;
    ll a = (idxa == -1 ? LLONG_MIN : A[idxa]);
    ll b = (idxb == -1 ? LLONG_MIN : B[idxb]);
    ll maxE = max(a, b);

    for (int i = idxa + 1; i < n; ++i) {
        if (maxE < A[i]) {
            ret = max(ret, solve(i, idxb) + 1);
        }
    }
    for (int i = idxb + 1; i < m; ++i) {
        if (maxE < B[i]) {
            ret = max(ret, solve(idxa, i) + 1);
        }
    }
    return ret;
}

int main() {
    FASTIO;
    cin >> t;
    while (t--) {
        memset(d, -1, sizeof(d));
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> B[i];
        }
        cout << solve(-1, -1) << endl;
    }

    return 0;
}
