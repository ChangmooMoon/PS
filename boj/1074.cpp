#include <iostream>
using namespace std;

int findnth(int n, int i, int j) {  // 4,1,3,2사분면 순
    if (n == 0) return 0;

    int half = 1 << (n - 1);
    if (i < half && j < half)  // 1사분면 ++
        return findnth(n - 1, i, j);
    else if (i < half && j <= half)  // 3사분면 --
        return half * half + findnth(n - 1, i, j - half);
    else if (half <= i && j < half)  // 2사분면
        return 2 * half * half + findnth(n - 1, i - half, j);
    else  // 사사분면
        return 3 * half * half + findnth(n - 1, i - half, j - half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, r, c;  // 2^n*2^n 배열, (r,c) 몇번째
    cin >> n >> r >> c;

    int result = findnth(n, r, c);
    cout << result;
    return 0;
}
