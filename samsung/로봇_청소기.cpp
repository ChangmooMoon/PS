#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

enum type { BLANK, WALL };

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, M, r, c, dir, a[51][51], ans;
bool visited[51][51];

void simulate() {
    bool backward;

    while (1) {
        visited[r][c] = true;
        backward = true;
        for (int i = 0; i < 4; ++i) {
            dir = (dir - 1 + 4) % 4;
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if (!visited[nr][nc] && a[nr][nc] == BLANK) {
                r = nr;
                c = nc;
                backward = false;
                break;
            }
        }

        if (backward) {
            int nr = r + dr[(dir + 2) % 4];
            int nc = c + dc[(dir + 2) % 4];
            if (a[nr][nc] == WALL) return;
            r = nr;
            c = nc;
        }
    }
}

int main() {
    FASTIO;
    cin >> N >> M >> r >> c >> dir;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
        }
    }
    simulate();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (visited[i][j]) ++ans;
        }
    }
    cout << ans;
    return 0;
}

// 1. 문제 읽기
// 2. 논리적 순서
// 3. 필요한 자료연산 리스트업
// 4. 자료형, 시간복잡도, 유리한 자료구조 선택
// 5. 구현
// 6. 엣지케이스

// N*M 그리드, 청소기가 동서남북 움직임. 청소하는 칸의 갯수 출력
// 청소기 로직
// 1. 지금 위치 청소
// 2. 왼쪽부터 탐색, 왼쪽에 청소할 공간 있으면 왼쪽 회전, 다시 2번
// 3. 네 방향 다 되있거나 벽이면 방향 유지하고 후진, 2번
// 4. 네 방향 다 되있거나 벽이고, 뒤쪽도 벽이면 정지
// 이미 청소되있는 칸 청소 안함, 벽 못지나감
// N, M <= 50, d: 0북 1동 2남 3서, 빈칸0, 벽1