#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int N, M, a[505][505], ans;
bool visited[505][505];

void placeBlock(int r, int c, int len, int sum) {
    if (len == 4) {
        ans = max(ans, sum);
        return;
    }
    if (r < 0 || c < 0 || r >= N || c >= M || visited[r][c]) return;
    visited[r][c] = true;
    for (int i = 0; i < 4; ++i) {
        placeBlock(r + dr[i], c + dc[i], len + 1, sum + a[r][c]);
    }
    visited[r][c] = false;
}

void TBlock(int r, int c) {
    if (r + 2 < N) { // 오른쪽으로 길게
        int part = a[r][c] + a[r + 1][c] + a[r + 2][c];
        if (c + 1 < M) { ans = max(ans, part + a[r + 1][c + 1]); }
        if (c - 1 >= 0) ans = max(ans, part + a[r + 1][c - 1]);
    }

    if (c + 2 < M) { // 아래로 긴 모양
        int part = a[r][c] + a[r][c + 1] + a[r][c + 2];
        if (r + 1 < N) ans = max(ans, part + a[r + 1][c + 1]);
        if (r - 1 >= 0) ans = max(ans, part + a[r - 1][c + 1]);
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            placeBlock(i, j, 0, 0);
            TBlock(i, j);
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

// 테트리스 모양 블록 5가지
// N * M 맵에 테트로미노를 놓았을 때 칸의 수의 최대 합

// 모든 케이스를 다 찾는 완전탐색을 해야겠다.
// 17개 블록 모양을 어떻게 표현해서 넣지? 다 그린다? 너무 노가다같은데
// dfs로 재귀적 처리를 하자 시작점에서 아래 오른쪽으로 전진하는 식으로
