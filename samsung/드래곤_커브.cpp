#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int N, a[101][101], ans;
vector<int> curve; // 커브 방향 2^10 = 최대 1024

void simulate(int x, int y, int d, int g) {
    curve.clear();
    curve.push_back(d);
    a[y][x] = 1;

    for (int i = 0; i < g; ++i) {
        for (int j = curve.size() - 1; j >= 0; --j) {
            curve.push_back((curve[j] + 1) % 4);
        }
    }

    for (int i = 0; i < curve.size(); ++i) {
        y += dy[curve[i]];
        x += dx[curve[i]];
        if (0 > y || y > 100 || x < 0 || x > 100) return;
        a[y][x] = 1;
    }
}

int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y, d, g; // x,y시작점 d시작방향, g세대
        cin >> x >> y >> d >> g;
        simulate(x, y, d, g);
    }

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) ++ans;
        }
    }
    cout << ans;
    return 0;
}

/*
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 좌표정보 (x, y) 로 주어짐 [y][x]
K번째 드래곤 커브는 K-1세대 드래곤 커브를
'끝점'을 기준으로 90도 시계방향회전하고 끝점에 붙인 것이다
grid 100*100에 드래곤커브가 N개 있음
정사각형 네 꼭지점이 모두 드래곤 커브의 일부인 1*1정사각형의 갯수 구하기
드래곤커브 N개 1~20, x, y 0~100, d시작방향, g, 세대 0~10
g: 0 x+1, 1 y-1, 2 x-1, 3 y+1

2. 방향을 저장해서 그동안의 경로를 역으로 순회하면서 반시계방향으로 90도 이동한 좌표를 경로로 쌓자
방향벡터, 경로 담는 벡터, 이를 역으로 순회하면서 점을 찍으면 된다

2-1.
*/