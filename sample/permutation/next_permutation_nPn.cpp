#include <algorithm>
#include <iostream>
using namespace std;

void permutation(int a[], int n) {
    sort(a, a + n);
    do {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << endl;
    } while (next_permutation(a, a + n));
}

int main() {
    int a[] = {10, 20, 30, 40};
    int n = sizeof(a) / sizeof(a[0]);

    permutation(a, n);
    return 0;
}
