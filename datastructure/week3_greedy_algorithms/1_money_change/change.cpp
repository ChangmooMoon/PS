#include <cmath>
#include <iostream>
using namespace std;

int get_change(int m) {
    int n = 0;
    int coin[] = {10, 5, 1};
    for (int i : coin) {
        int count = floor(m / i);
        n += count;
        m -= count * i;
    }
    return n;
}

int main() {
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
    return 0;
}
