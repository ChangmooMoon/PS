#include <iostream>
using namespace std;

int d[1000001];
int go(int n) {  // d[n] = min(d[n/3]+d[n/2]+d[n-1])+1
    if (n == 1) return 0;
    if (d[n] > 0) return d[n]; // memorization

    d[n] = go(n - 1) + 1;

    if (n % 2 == 0) {
        int tmp = go(n / 2) + 1;
        if (d[n] > tmp) d[n] = tmp; // 최적값 대입
    }
    if (n % 3 == 0) {
        int tmp = go(n / 3) + 1;
        if (d[n] > tmp) d[n] = tmp;
    }
    return d[n];
}

int main() {
    int n;
    cin >> n;
    cout << go(n) << endl;
}
