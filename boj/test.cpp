#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    // int a[] = {1, 2, 4, 5};
    // cout << *lower_bound(a, a + 3, 3) << endl;
    // cout << *upper_bound(a, a + 3, 4);

    vector<int> v{-3, -1, -5, 0};
    sort(v.begin(), v.end());
    for (int a : v) {
        cout << a << ' ';
    }
    return 0;
}