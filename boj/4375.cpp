#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int main() {
    FASTIO;

    while (cin >> n) {
        int num = 0;
        for (int d = 1;; ++d) {
            num = num * 10 + 1;  // 1, 11, 111...
            num %= n;

            if (num == 0) {
                cout << d << endl;
                break;
            }
        }
    }

    return 0;
}
