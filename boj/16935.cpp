#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
// 배열돌리기

int n, m, r, f;

void f1(vector<vector<int>>& a) {
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = a[n - 1 - i][j];
        }
    }
    a = b;
}

void f2(vector<vector<int>>& a) {
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] = a[i][m - 1 - j];
        }
    }
    a = b;
}

void f3(vector<vector<int>>& a) {
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[n - 1 - j][i];
        }
    }
    a = b;
    swap(n, m);
}

void f4(vector<vector<int>>& a) {
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = a[j][m - 1 - i];
        }
    }
    a = b;
    swap(n, m);
}

void f5(vector<vector<int>>& a) {
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            b[i][j] = a[i + n / 2][j];
            b[i][j + m / 2] = a[i][j];
            b[i + n / 2][j + m / 2] = a[i][j + m / 2];
            b[i + n / 2][j] = a[i + n / 2][j + m / 2];
        }
    }
    a = b;
}

void f6(vector<vector<int>>& a) {
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m / 2; ++j) {
            b[i][j] = a[i][j + m / 2];
            b[i][j + m / 2] = a[i + n / 2][j + m / 2];
            b[i + n / 2][j + m / 2] = a[i + n / 2][j];
            b[i + n / 2][j] = a[i][j];
        }
    }
    a = b;
}

int main() {
    FASTIO;
    cin >> n >> m >> r;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    while (r--) {
        cin >> f;
        if (f == 1)
            f1(a);
        else if (f == 2)
            f2(a);
        else if (f == 3)
            f3(a);
        else if (f == 4)
            f4(a);
        else if (f == 5)
            f5(a);
        else
            f6(a);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
