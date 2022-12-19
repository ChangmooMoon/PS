#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, M, a[8][8], ans = INT_MAX;
bool visited[8][8];
vector<pair<int, int>> cctvs;
vector<int> dir; // K개의 CCTV의 방향

void visit(int sr, int sc, int d) {
    int i = sr, j = sc;
    if (d == 0) { // 상
        for (i = sr; i >= 0; --i) {
            visited[i][j] = true;
            if (a[i][j] == 6) break;
        }
    } else if (d == 1) { // 우
        for (int j = sc; j < M; ++j) {
            visited[i][j] = true;
            if (a[i][j] == 6) break;
        }
    } else if (d == 2) { // 하
        for (int i = sr; i < N; ++i) {
            visited[i][j] = true;
            if (a[i][j] == 6) break;
        }
    } else { // 좌
        for (int j = sc; j >= 0; --j) {
            visited[i][j] = true;
            if (a[i][j] == 6) break;
        }
    }
}

void simulate() {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < cctvs.size(); ++i) {
        int sr = cctvs[i].first;
        int sc = cctvs[i].second;
        int type = a[sr][sc];
        int d = dir[i]; // 정방향, 시계방향으로 90도 방향 고려하자

        if (type == 1) {
            visit(sr, sc, d);
        } else if (type == 2) {
            visit(sr, sc, d);
            visit(sr, sc, (d + 2) % 4);
        } else if (type == 3) {
            visit(sr, sc, d);
            visit(sr, sc, (d + 1) % 4);
        } else if (type == 4) {
            visit(sr, sc, d);
            visit(sr, sc, (d + 1) % 4);
            visit(sr, sc, (d + 2) % 4);
        } else if (type == 5) {
            visit(sr, sc, d);
            visit(sr, sc, (d + 1) % 4);
            visit(sr, sc, (d + 2) % 4);
            visit(sr, sc, (d + 3) % 4);
        }
    }
}

int getScore() {
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j] && a[i][j] != 6) ++ret;
        }
    }
    return ret;
}

void dfs(int idx) {
    if (idx == cctvs.size()) {
        simulate();
        ans = min(ans, getScore());
        return;
    }

    for (int i = 0; i < 4; ++i) {
        dir.push_back(i);
        dfs(idx + 1);
        dir.pop_back();
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> a[i][j];
            if (1 <= a[i][j] && a[i][j] <= 5) cctvs.push_back({i, j});
        }
    }

    dfs(0);
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

1. N*M grid에 K개의 CCTV가 있는데 5종류임
1: 한쪽방향
2: 두방향- 반대방향
3: 두방향 - 직각방향
4: 세방향
5. 네방향
벽이 있어서 사각지대가 있음. CCTV 90 회전할 수 있음. 바로 밑은 못봄
시야가 CCTV는 통과할 수 있음
사각지대의 최소크기를 구하라
N, M <= 8, 0빈칸 12345CCTV, 6벽, K<=8

2. CCTV가 90도 회전할 수 있음
그래서 CCTV종류마다 최대 시야 전략이 다름
1번: 제일 많이 볼 수 있는 수직 2방향의 시야
2번: 5번과 같음
3번: 제일 적게보는 방향 1개 뺴고 전부
4번: 5번과 같음
5번: 다봄

이건 그리디로 풀 수 가 없겠다. 완전탐색을 할 수밖에 없음.
안좋은 위치의 타입5CCTV를 먼저 고려하면 좋은 위치의 타입1이 묻힐수있음
만약 완전탐색으로 풀게 되면 시간복잡도는?
모든 CCTV를 4방향으로 고려함
O(4^K) * N^2 = 6만*64 = 400만
모든 4^K 순열을 만들어서 그거대로 CCTV 방향을 잡아서 모든 시야를 다 잡고
사각지대를 업데이트해나간다







A. 정확히 이해하고 넘어가자
1. 질문을 정리하다보니 해결되는 경우가 많음

2. 짝에게 서로 설명해주는 방식으로 이해하자
Ex) 관찰을 해보니 ~~라는 특성이 있습니다. 이걸 이용해서 ~~ 접근을 시도했습니다. 여기까지 궁금하신 점이 있으까요?
-> 네 잘 이해했습니다. Or 이 부분이 이해가 안갑니다.

3. 주석을 열심히 달면서 풀어보기
주석을 문장 형태를 이뤄서 작성하다 보면 어색한 부분은 전부 제대로 이해하지 못한 것이다. 변수들은 의미를 설명하기 함수들은 입출력, 시간복잡도를
설명하기. 각 줄마다 문장으로 설명하기

B. 시간을 정해놓고 풀자
- 삼성기출, 골드: 2시간, 실버: 1시간
- 시간이 지나면 빠르게 해설보고 이해한 뒤, 코드를 전부 지우고 다시 처음부터 반복한다.
다시 풀었을 때
1. 막히던 부분이 해결되는지 확인
2. 실수가 줄어드는지 확인
시간이 줄어드는지 확인

C. 복잡도, 어려웠던 부분 체크
1. 시간복잡도는? -> step마다 계산하고 설명
2. 공간복잡도는? -> 사용한 자료구조마다 계산, 설명
3. 어려웠던 부분은? -> 어떻게 해결했는지 설명하기
*/