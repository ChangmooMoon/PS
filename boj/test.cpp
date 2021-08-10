#include <bits/stdc++.h>
using namespace std;

int main() {
    tuple<int, int, int> t = {1, 2, 3};
    const auto& [a, b, c] = t;
    cout << a << b << c << endl;
}
