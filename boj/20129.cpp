#include <iostream>
#include <stack>
using namespace std;

int op[4];  // 우선순위 + - * /

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 4; ++i) {
        cin >> op[i];
    }

    return 0;
}
