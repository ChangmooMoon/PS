#include <iostream>
#include <vector>
using namespace std;

int get_pisano_period(int m) {
    int prev = 0;
    int curr = 1;
    int res = prev + curr;

    for (int i = 0; i < m * m; i++) {
        res = (prev + curr) % m;
        prev = curr;
        curr = res;
        if (prev == 0 && curr == 1) return i + 1;
    }
    return 0;
}

int get_fibonacci_huge_modulo(long long n, int m) {
    int period = get_pisano_period(m);
    n %= period;
    long long prev = 0;
    long long curr = 1;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp = 0;
        tmp = curr;
        curr = (prev + curr) % m;
        prev = tmp;
    }
    return curr % m;
}

long long get_fibonacci_partial_sum(long long from, long long to) {
}

int main() {
    long long from, to;
    cin >> from >> to;
    cout << get_fibonacci_partial_sum(from, to);
    return 0;
}
