#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, M, H, a[31][11], ans = 4;

bool isOK() {
    for (int i = 1; i <= N; ++i) {
        int cPos = i;
        for (int j = 0; j <= H; ++j) {
            if (a[j][cPos] == 1)
                ++cPos;
            else if (a[j][cPos - 1] == 1)
                --cPos;
        }
        if (cPos != i) return false;
    }
    return true;
}

void dfs(int r, int c, int cnt) {
    if (cnt >= ans) return;
    if (isOK()) {
        ans = cnt;
        return;
    }
    if (cnt == 3) return;
    for (int i = r; i <= H; ++i) {
        for (int j = c; j < N; ++j) {
            if (a[i][j] == 0 && a[i][j - 1] == 0 && a[i][j + 1] == 0) { // 가로선 긋는 조건
                a[i][j] = 1;
                dfs(i, j, cnt + 1);
                a[i][j] = 0;
            }
        }
        c = 1;
    }
}

int main() {
    FASTIO;
    cin >> N >> M >> H;
    for (int i = 0; i < M; ++i) {
        int r, c;
        cin >> r >> c;
        a[r][c] = 1;
    }
    dfs(1, 1, 0);
    if (ans == 4) ans = -1;
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

1. 세로선 N 2~10, 가로선 M, 가로선 넣을수있는 갯수H 1~30
a b => b~b+1 가로선을 a번 점선위치에서 연결함
추가할 수 있는 가로선이 최대 3개


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
