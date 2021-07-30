#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5};
    int n = v.size();
    int r = 2;

    do {
        for (int i = 0; i < r; ++i) {
            cout << v[i] << ' ';
        }
        cout << endl;
        reverse(v.begin() + r, v.end());
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
