#include <algorithm>
#include <iostream>

using namespace std;

int n, m, r;
int a[300][300];

void rotate(int n) {
  while(n--) {
    
  }
}

int main() {
    cin >> n >> m >> r;
    r %= 4;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    rotate(r);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}