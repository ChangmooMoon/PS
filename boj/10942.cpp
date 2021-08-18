#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, m;  // 수열크기2천, 질문갯수100만
int a[2001];
bool d[2001][2001];  // start -> end 팰린드롬인지 true,false

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= n; ++i) {
        d[i][i] = true;                    // 길이 1
        d[i][i + 1] = (a[i] == a[i + 1]);  // 길이 2
    }

    for (int len = 3; len <= n; ++len) {  // 길이 3이상
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            if (a[i] == a[j] && d[i + 1][j - 1]) d[i][j] = 1;
        }
    }

    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << d[s][e] << endl;
    }

    return 0;
}
