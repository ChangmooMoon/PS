#include <algorithm>
#include <iostream>
using namespace std;

void permutation(char& data, int depth, int n, int r) {
    if (depth == r) {
        for (int i = 0; i < r; ++i) {
            cout << data[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = depth; i < n; ++i) {
        swap(data[depth], data[i]);
        permutation(data, depth + 1, n, r);
        swap(data[depth], data[i]);
    }
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd'};
    permutation(arr, 0, 4, 3);  // 4P3
    return 0;
}