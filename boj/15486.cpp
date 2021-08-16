#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f;

int n;
int t[1500001];
int p[1500001];
int d[1500001];

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> p[i];
    }

    for (int i = 1; i <= n; ++i) {
        int term = t[i];
        d[i + term] = max(d[i] + p[i], d[i + term]);
        d[i + 1] = max(d[i + 1], d[i]);
    }

    cout << d[n + 1];
    return 0;
}
