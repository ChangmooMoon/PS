#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, M, a[51][51], ans = INT_MAX;
vector<pair<int, int>> chicken, home, pick; // r, c

void dfs(int idx) {
    if (pick.size() == M) {
        int ret = 0;
        for (int i = 0; i < home.size(); ++i) {
            int minDist = INT_MAX;
            for (int j = 0; j < pick.size(); ++j) {
                minDist = min(minDist, abs(home[i].first - pick[j].first) + abs(home[i].second - pick[j].second));
            }
            ret += minDist;
        }

        ans = min(ans, ret);
        return;
    }

    for (int i = idx; i < chicken.size(); ++i) {
        pick.push_back(chicken[i]);
        dfs(i + 1);
        pick.pop_back();
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 1)
                home.push_back({i, j});
            else if (a[i][j] == 2)
                chicken.push_back({i, j});
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

1. N*N 그리드, 빈칸, 치킨집, 집, r, c 1부터 시작
치킨거리: 집과 가장 가까운 치킨집 사이의 거리. 해밀턴거리
M개 빼고 나머지 치킨집 모두 폐업시킬 때 도시의 치킨거리가 가장 작게 만들어야됨
input: N 2~50, M 1~13, a[50][50], 0빈칸 1집 2치킨집, 집 갯수 1~2N, 치킨집 13~M
output: 폐업 시키지 않을 치킨집을 M개 골랐을 때 , 도시의 치킨 거리의 최솟값 반환

2.
1. 모든 치킨집 위치를 다 모우고, 이걸 가지고 전체갯수Cm 조합을 모두 만들어서
2. 각 조합에 대해서 치킨거리를 업데이트 하면서 최소값을 찾는다
- 치킨거리는 모든 집 위치에 대해서 bfs 탐색을 해야겠다.

3. 그러면 모든 치킨집 위치, 집 위치를 저장하고, 없어지는 치킨집에 대해서 업데이트를 해야됨
각 집에서 bfs탐색을 시작해서 모든 집에서의 치킨거리를 다 구해서 더해야됨

6. 메모리 초과가 남. 치킨집과의 거리를 bfs로 구하면 O(N^2)임. N = 50,
dfs * 모든 집 최대 2500 * bfs
N^2 * 2500 * N^2 = 2500^3 이러면 당연히 시간초과가 난다
치킨거리를 구하면 되니까 치킨 위치로 거리만 구하면 O(1)임


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
