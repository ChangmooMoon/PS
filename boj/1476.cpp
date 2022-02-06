#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int e, s, m;  // 15, 28, 19

int main() {
    FASTIO;
    cin >> e >> s >> m;
    --e;
    --s;
    --m;

    int i = 0;
    do {
        if (i % 15 == e && i % 28 == s && i % 19 == m) {
            cout << i + 1;
            break;
        }
    } while (++i);

    return 0;
}
