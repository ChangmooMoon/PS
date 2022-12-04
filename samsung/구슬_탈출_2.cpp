// boj 13460
#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, M; // 10
string a[11];
pair<int, int> R, B;

int bfs() {
    queue<tuple<int, int, int, int>> q; // Rr, Rc, Br, Bc
    int d[11][11][11][11];
    memset(d, -1, sizeof(d));

    q.push({R.first, R.second, B.first, B.second});
    d[R.first][R.second][B.first][B.second] = 0;

    while (!q.empty()) {
        auto [curr_Rr, curr_Rc, curr_Br, curr_Bc] = q.front();
        q.pop();

        int &ret = d[curr_Rr][curr_Rc][curr_Br][curr_Bc];
        if (ret > 10) return -1;
        if (a[curr_Rr][curr_Rc] == 'O' && a[curr_Br][curr_Bc] != 'O') return ret;

        for (int dir = 0; dir < 4; ++dir) {
            int next_Rr = curr_Rr;
            int next_Rc = curr_Rc;
            int next_Br = curr_Br;
            int next_Bc = curr_Bc;

            while (1) {
                if (a[next_Rr][next_Rc] != '#' && a[next_Rr][next_Rc] != 'O') {
                    next_Rr += dr[dir];
                    next_Rc += dc[dir];
                } else { // 벽이거나 출구이면
                    if (a[next_Rr][next_Rc] == '#') {
                        next_Rr -= dr[dir];
                        next_Rc -= dc[dir];
                    }
                    break;
                }
            }

            while (1) {
                if (a[next_Br][next_Bc] != '#' && a[next_Br][next_Bc] != 'O') {
                    next_Br += dr[dir];
                    next_Bc += dc[dir];
                } else { // 벽이거나 출구이면
                    if (a[next_Br][next_Bc] == '#') {
                        next_Br -= dr[dir];
                        next_Bc -= dc[dir];
                    }
                    break;
                }
            }

            if (next_Rr == next_Br && next_Rc == next_Bc) { // 겹치면 안됨
                if (a[next_Rr][next_Rc] != 'O') {
                    int rDist = abs(next_Rr - curr_Rr) + abs(next_Rc - curr_Rc);
                    int bDist = abs(next_Br - curr_Br) + abs(next_Bc - curr_Bc);
                    if (rDist > bDist) {
                        next_Rr -= dr[dir];
                        next_Rc -= dc[dir];
                    } else {
                        next_Br -= dr[dir];
                        next_Bc -= dc[dir];
                    }
                }
            }

            if (d[next_Rr][next_Rc][next_Br][next_Bc] == -1) {
                d[next_Rr][next_Rc][next_Br][next_Bc] = ret + 1;
                q.push({next_Rr, next_Rc, next_Br, next_Bc});
            }
        }
    }

    return -1;
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        for (int j = 0; j < M; ++j) {
            if (a[i][j] == 'R') R = {i, j};
            if (a[i][j] == 'B') B = {i, j};
        }
    }

    cout << bfs();
    return 0;
}

// - 정리할 개념 - 상태공간 트리, dfs, bfs
// - 미처 고려하지 못했던 점:
//     - 상태 배열 초기화
//     - 최단 이동횟수를 구하니까 bfs로 풀 수 있다는 까
//     - 구슬이 충돌(겹친다) 라는 개념을 너무 어렵게 생각했던 점. 방향별로 접근했었는데, 그러지 말고 이동거리로 접근했으면 더 편하게 풀 수 있었을
//     것이다.
//     - 두 구슬의 상태값을 배열로 표현할 수 있었다는 점. (위치정보를 이용해서 i, j, i2, j2 로 표현할 수 있었음)
