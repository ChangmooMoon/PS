#include <iostream>
#include <vector>
using namespace std;

int solve(int r, int c) {
    if (r == 1)
        return 1;
    else if (r == 2)
        return min(4, (c + 1) / 2);
    else {
        if (c >= 7)
            return c - 2;
        else
            return min(4, c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r, c;
    cin >> r >> c;  // 행, 열
    cout << solve(r, c);

    return 0;
}
