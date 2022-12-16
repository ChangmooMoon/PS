#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
enum type { BLANK, WALL, VIRUS };

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, M, a[8][8], acpy[8][8], ans;
bool visited[8][8];
vector<pair<int, int>> blank, virus;

void spreadVirus() {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    for (auto &[r, c] : virus) {
        visited[r][c] = true;
        q.push({r, c});
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || 0 > nc || N <= nr || M <= nc) continue;
            if (visited[nr][nc] || acpy[nr][nc] != 0) continue;

            visited[nr][nc] = true;
            acpy[nr][nc] = VIRUS;
            q.push({nr, nc});
        }
    }
}

int getScore() {
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (acpy[i][j] == BLANK) ++ret;
        }
    }
    return ret;
}

void simulate() {
    for (int i = 0; i < blank.size(); ++i) {
        for (int j = i + 1; j < blank.size(); ++j) {
            for (int k = j + 1; k < blank.size(); ++k) {
                memcpy(acpy, a, sizeof(acpy));
                acpy[blank[i].first][blank[i].second] = WALL;
                acpy[blank[j].first][blank[j].second] = WALL;
                acpy[blank[k].first][blank[k].second] = WALL;
                spreadVirus();
                ans = max(ans, getScore());
            }
        }
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
            if (a[i][j] == BLANK)
                blank.push_back({i, j});
            else if (a[i][j] == VIRUS)
                virus.push_back({i, j});
        }
    }

    simulate();
    cout << ans;
    return 0;
}

// 1. 문제 읽기
// 2. 논리적 순서
// 3. 필요한 자료연산 리스트업
// 4. 자료형, 시간복잡도, 유리한 자료구조 선택
// 5. 구현
// 6. 엣지케이스

// N*M 그리드 빈칸0 벽1 바이러스2, N M <= 8
// 바이러스는 모든 빈칸에 상하좌우로 빠진다.
// 벽을 꼭 3개 세워서 만들 수 있는 안전영역의 최대값

// 1. 빈칸에 대해서 64C3 완전탐색을 해서 벽을 세우고,
// 2. 만들어진 그리드에 대해서 바이러스 전파를 해서
// 3. 안전지대를 구해서 업데이트
// 4. ans 반환