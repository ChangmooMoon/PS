#include <algorithm>
#include <iostream>
using namespace std;

int n, m, r;
int a[100][100];
int tmp[100][100] = {0};

void xAxis() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            tmp[i][j] = a[n - 1 - i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = tmp[i][j];
}
void yAxis() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            tmp[i][j] = a[i][m - 1 - j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = tmp[i][j];
}
void rotate90() {
    int h = n;
    swap(n, m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            tmp[i][j] = a[h - 1 - j][i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = tmp[i][j];
}

void rotate90_reversed() {
    int w = m;

    swap(n, m);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            tmp[i][j] = a[j][w - 1 - i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = tmp[i][j];
}

void rotate_quadrant() {
    int N = n / 2;
    int M = m / 2;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            tmp[i][j + M] = a[i][j];
        }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            tmp[i + N][j + M] = a[i][j + M];
        }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            tmp[i + N][j] = a[i + N][j + M];
        }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            tmp[i][j] = a[i + N][j];
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = tmp[i][j];
}

void rotate_quadrant_reversed() {
    int N = n / 2;
    int M = m / 2;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            tmp[i + N][j + M] = a[i + N][j];
        }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            tmp[i][j + M] = a[i + N][j + M];
        }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            tmp[i + N][j] = a[i][j];
        }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            tmp[i][j] = a[i][j + M];
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = tmp[i][j];
}
int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }

    for (int i = 0; i < r; ++i) {
        int f;
        cin >> f;
        if (f == 1)
            xAxis();
        else if (f == 2)
            yAxis();
        else if (f == 3)
            rotate90();
        else if (f == 4)
            rotate90_reversed();
        else if (f == 5)
            rotate_quadrant();
        else if (f == 6)
            rotate_quadrant_reversed();
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}