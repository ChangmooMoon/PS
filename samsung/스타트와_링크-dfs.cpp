#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, S[21][21], ans = INT_MAX;
bool visited[21];

void get_diff() {
    vector<int> t1, t2;
    for (int i = 0; i < N; ++i) {
        if (visited[i])
            t1.push_back(i);
        else
            t2.push_back(i);
    }
    if (t1.size() != N / 2 || t2.size() != N / 2) return;

    int p1 = 0, p2 = 0;
    for (int i = 0; i < N / 2; ++i) {
        for (int j = 0; j < N / 2; ++j) {
            p1 += S[t1[i] + 1][t1[j] + 1];
            p2 += S[t2[i] + 1][t2[j] + 1];
        }
    }

    ans = min(ans, abs(p1 - p2));
}

void dfs(int cur, int pick_cnt) {
    if (pick_cnt == N / 2) {
        get_diff();
        return;
    }
    for (int i = cur; i < N; ++i) {
        visited[i] = true;
        dfs(i + 1, pick_cnt + 1);
        visited[i] = false;
    }
}

int main() {
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> S[i][j];
        }
    }

    dfs(0, 0);
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

2. nC(n/2)를 구현하는 combination을 만드는 재귀를 dfs로 구현하자
dfs(curr, pick_cnt) = curr까지 고려했을 때 지금 t1팀에 pick한 갯수
팀이 2개밖에 없으니까 true, false로 구분하면 될듯

*/
