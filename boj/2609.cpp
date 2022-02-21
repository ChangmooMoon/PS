#include <iostream>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int a, b;
int gcd(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b) {
    int g = gcd(a, b);
    return (a / g) * (b / g) * g;
}
int main() {
    FASTIO;
    cin >> a >> b;
    cout << gcd(a, b) << endl << lcm(a, b);
    return 0;
}
