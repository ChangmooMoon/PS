#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int a[1001];
int main() {
    FASTIO;
    int num = 1, cnt = 1;
    for (int i = 1; i <= 1000; ++i) {
        a[i] = num;
        a[i] += a[i - 1];
        --cnt;
        if (!cnt) {
            ++num;
            cnt = num;
        }
    }
    int s, e;
    cin >> s >> e;
    cout << a[e] - a[s - 1];
    return 0;
}
