#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n, ans = 0;
vector<vector<int>> a(20, vector<int>(20));

void rotate(vector<vector<int>> &a) { // 오른쪽 90도 rotate
    vector<vector<int>> b(20, vector<int>(20));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[j][n - i - 1] = a[i][j];
        }
    }
    a = b;
}

void down(vector<vector<int>> &a) {
    bool isMerged[20][20];
    memset(isMerged, false, sizeof(isMerged));

    for (int i = 0; i < n; ++i) {
        for (int j = n - 2; j >= 0; --j) {
            int col = j;
            if (a[i][col] == 0) continue;

            while (col + 1 < n && a[i][col + 1] == 0) {
                swap(a[i][col], a[i][col + 1]);
                ++col;
            }
            if (col + 1 < n && a[i][col] == a[i][col + 1] && !isMerged[i][col + 1]) {
                isMerged[i][col + 1] = true;
                a[i][col + 1] *= 2;
                a[i][col] = 0;
            }
        }
    }
}

void simulate(vector<vector<int>> a, int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, a[i][j]);
            }
        }
        return;
    }

    for (int dir = 0; dir < 4; ++dir) { // 위 오른쪽 아래 왼쪽. 항상 오른쪽방향으로 이동하도록
        vector<vector<int>> b(a);
        if (dir == 0) {
            rotate(b);
        } else if (dir == 2) {
            rotate(b);
            rotate(b);
            rotate(b);
        } else if (dir == 3) {
            rotate(b);
            rotate(b);
        }

        down(b);

        if (dir == 0) {
            rotate(b);
            rotate(b);
            rotate(b);
        } else if (dir == 2) {
            rotate(b);
        } else if (dir == 3) {
            rotate(b);
            rotate(b);
        }

        simulate(b, cnt + 1);
    }
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    simulate(a, 0);
    cout << ans;
    return 0;
}

// 1. 문제 읽기
// 2. 논리적 순서
// 3. 필요한 자료연산 리스트업
// 4. 자료형, 시간복잡도, 유리한 자료구조 선택
// 5. 구현
// 6. 엣지케이스

// 한번의 이동은 전체블록을 상하좌우로 움직임
// 같은 값이 충돌하면 하나로 합쳐짐.
// 합쳐진 블록은 다른 블록과 합칠수있어도 안 합침

// 1. 블록 이동, 병합 로직
// 2. 이동 로직 복잡하니까 대신 배열을 돌려버리자. 배열 rotate

// 5번 이동시켜야되니까 4^5 = 1024 경우의 수. 완전탐색
