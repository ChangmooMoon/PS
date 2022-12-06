#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {-1, 0, 1, 0}; // 위 오른 아래 왼
int dc[] = {0, 1, 0, -1};

int N, K, L;
int a[101][101];               // 사과 1, 뱀 2
unordered_map<int, char> umap; // 방향전환

bool outOfRange(int r, int c) { return 1 > r || 1 > c || N < r || N < c; }

int simulate() {
    int t = 0;
    deque<pair<int, int>> dq = {{1, 1}}; // 뱀 링크드리스트
    a[0][0] = 2;
    int dir = 1;

    while (++t) {
        int nr = dq.front().first + dr[dir];
        int nc = dq.front().second + dc[dir];
        int tail_r = dq.back().first;
        int tail_c = dq.back().second;

        if (outOfRange(nr, nc) || a[nr][nc] == 2) // 뱀에 닿으면 종료
            break;
        else {
            if (a[nr][nc] == 0) {
                dq.pop_back(); // 사과없으면 꼬리제거
                a[tail_r][tail_c] = 0;
            }
            dq.push_front({nr, nc}); // 다음칸 추가
            a[nr][nc] = 2;
        }

        if (umap.find(t) != umap.end()) { // 방향전환 함
            if (umap[t] == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
        }
    }

    return t;
}

int main() {
    FASTIO;
    cin >> N >> K;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        a[r][c] = 1;
    }

    cin >> L;
    for (int i = 0; i < L; ++i) {
        int t;
        char dir;
        cin >> t >> dir;
        umap[t] = dir;
    }

    cout << simulate();
    return 0;
}

// 1. 문제 읽기
// 2. 논리적 순서
// 3. 필요한 자료연산 리스트업
// 4. 자료형, 시간복잡도, 유리한 자료구조 선택
// 5. 구현
// 6. 엣지케이스

// N*N 정사각형 보드, 뱀
// 사과를 먹으면 사과가 없어지고, 꼬리는 움직이지 않음
// 사과를 못먹으면, 꼬리칸을 비워줌.
// 사과 위치, 뱀의 이동경로가 주어짐. 몸에 부딪히면 게임이 끝남

// 1. 맵에 사과위치, 뱀을 구현
// 2. 뱀의 이동 구현, 사과 먹으면 길어짐
// 3. 자기 몸에 부딪히면 종료되는 로직 추가
