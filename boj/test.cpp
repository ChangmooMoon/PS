#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    vector<int> a(8);
    a[0] = 1;
    rotate(a.begin(), a.end() - 3, a.end());
    for (int n : a) {
        cout << n << ' ';
    }
}
