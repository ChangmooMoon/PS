#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 진법

int n, b;
vector<int> v;

int main() {
    FASTIO;
    cin >> n >> b;
    while (n) {
        v.push_back(n % b);
        n /= b;
    }
    reverse(v.begin(), v.end());
    for (int i : v) {
        if (i < 10)
            cout << i;
        else
            cout << (char)(i - 10 + 'A');
    }

    return 0;
}
