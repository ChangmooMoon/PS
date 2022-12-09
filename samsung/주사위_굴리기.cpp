#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};

int N, M, x, y, K;
int a[21][21], d[4][3];

void preprocess() {
    cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
        }
    }
}

void move(int dir) {
    int nx = x + dr[dir];
    int ny = y + dc[dir];
    if (0 > nx || 0 > ny || N <= nx || M <= ny) return;

    x = nx, y = ny;
    if (dir == 1) { // 0동 1서 2북 3남
        int tmp = d[1][1];
        d[1][1] = d[1][2];
        d[1][2] = d[3][1];
        d[3][1] = d[1][0];
        d[1][0] = tmp;
    } else if (dir == 2) {
        int tmp = d[1][1];
        d[1][1] = d[1][0];
        d[1][0] = d[3][1];
        d[3][1] = d[1][2];
        d[1][2] = tmp;
    } else if (dir == 3) {
        int tmp = d[1][1];
        d[1][1] = d[0][1];
        d[0][1] = d[3][1];
        d[3][1] = d[2][1];
        d[2][1] = tmp;
    } else {
        int tmp = d[1][1];
        d[1][1] = d[2][1];
        d[2][1] = d[3][1];
        d[3][1] = d[0][1];
        d[0][1] = tmp;
    }

    // d[3][1]이 바닥
    if (a[x][y] == 0) {
        a[x][y] = d[3][1];
    } else {
        d[3][1] = a[x][y];
        a[x][y] = 0;
    }

    cout << d[1][1] << endl;
}

void simulate() {
    for (int i = 0; i < K; ++i) {
        int dir;
        cin >> dir;
        move(dir); // 여기서 print하자
    }
}

int main() {
    FASTIO;
    preprocess();
    simulate();

    return 0;
}

// N*M 지도가 있는데, (r,c) 0부터 시작하는 좌표
// 주사위가 있고 윗면이 1, 동쪽이 3, (x, y) 주사위는 모든면이 0 시작
// 지도 각 칸에 정수가 있고, 이동한 칸이 0이면, 주사위 바닥면이 칸에 복사됨
// 0이 아니면 칸에 쓰인수가 주사위 바닥에 복사되고 칸은 0이 됨
// 주사위 좌표, 이동명령이 주어짐 -> 주사위가 이동할 때마다 상단에 쓰인 값을 출력
// 주사위 벗어나면 안됨, 벗어난다면 무시하고 출력 x

// 지도, 주사위 구현
// 주사위가 굴러갈 때마다 지도, 주사위 상태 업데이트, 상단값 출력

// 주사위와 그 움직임을 어떻게 구현할까?
// 주사위 초기배치를 저장하고, 그걸 스왑하는 로직을 구현하자
