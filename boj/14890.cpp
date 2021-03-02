#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N, L;  // 100, 경사로길이100
vector<vector<int>> v;

bool isPossible(vector<int>& a) {
    vector<bool> c(N);
    for (int i = 1; i < N; ++i) {
        if (a[i - 1] != a[i]) {                           // 차이가 나는 경우
            if (abs(a[i] - a[i - 1]) != 1) return false;  // 차이가 1이여야

            if (a[i - 1] < a[i]) {                           // 왼쪽에 놓는 경우
                for (int j = 1; j <= L; ++j) {               // 경사로 길이만큼 탐색
                    if (i - j < 0) return false;             // 경사로가 넘어가는 경우
                    if (a[i - 1] != a[i - j]) return false;  // 낮은 쪽 높이가 다르거나 L개가 연속이지 않은 경우
                    if (c[i - j]) return false;              // 경사로가 이미 있는 경우
                    c[i - j] = true;
                }
            } else {  // 오른쪽에 놓는 경우
                for (int j = 0; j < L; ++j) {
                    if (i + j >= N) return false;
                    if (a[i] != a[i + j]) return false;
                    if (c[i + j]) return false;
                    c[i + j] = true;
                }
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> L;
    v.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }

    int ans = 0;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[j] = v[i][j];
        }

        if (isPossible(a)) ans++;
    }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            a[i] = v[i][j];
        }
        if (isPossible(a)) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}
