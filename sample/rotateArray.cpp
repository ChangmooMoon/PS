#include <iostream>
#include <vector>
using namespace std;

// 1. degree 90 clockwise: (i,j) => (j, n-i-1)
// 2. axis x: (i,j) -> (n-i-1, j)
// 3. axis y: (i,j) -> (i, n-j-1)
// 4. point symetry: (i,j) -> (n-i-1, n-j-1)

void manipulate_array(vector<vector<int>> &v) {
    int n = v.size();
    vector<vector<int>> tmp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            tmp[j][n - i - 1] = v[i][j];
            // tmp[i][n-j-1] = v[i][j];
            // tmp[i][n-j-1] = v[i][j];
            // tmp[n-i-1][n-j-1] = v[i][j];
        }
    }
    v = tmp;
}

void inplace_rotate_array(vector<vector<int>> &v) {
    int n = v.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            int tmp = v[i][j];
            v[i][j] = v[n - 1 - j][i];
            v[n - 1 - j][i] = v[n - 1 - i][n - 1 - j];
            v[n - 1 - i][n - 1 - j] = v[j][n - 1 - j];
            v[j][n - 1 - i] = tmp;
        }
    }
}

void print_array(vector<vector<int>> &v) {
    for (vector<int> i : v) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> v = {{1, 1, 1, 1}, {0, 1, 1, 1}, {0, 0, 1, 1}, {0, 0, 0, 1}};
    print_array(v);
    manipulate_array(v);
    print_array(v);
    inplace_rotate_array(v);
    print_array(v);
}
