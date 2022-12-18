#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, S[21][21];

int bf() {
    int ans = -1;
    for (int i = 0; i < (1 << N); ++i) {
        vector<int> t1, t2;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j))
                t1.push_back(j);
            else
                t2.push_back(j);
            if (t1.size() > N / 2 || t2.size() > N / 2) break;
        }
        if (t1.size() != N / 2 || t2.size() != N / 2) continue;

        int s1 = 0, s2 = 0;
        for (int i = 0; i < N / 2; ++i) {
            for (int j = 0; j < N / 2; ++j) {
                s1 += S[t1[i] + 1][t1[j] + 1];
                s2 += S[t2[i] + 1][t2[j] + 1];
            }
        }
        if (ans == -1 || ans > abs(s1 - s2)) ans = abs(s1 - s2);
    }

    return ans;
}

int main() {
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> S[i][j];
        }
    }
    cout << bf();
    return 0;
}

/*
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스
7. 푼 이후 피드백

1. 짝수 N명을 2로 나눠서 팀을 만든다
사람 1~N 에 대해서 같은 팀이 됬을 때 시너지합은 S(i, j은
팀 간에 능력치 차이의 최소값 구해라
N <= 20, S(i,j) <= 100

2. 2^10 = 1024니까 완전탐색을 해도 되겠다.
한 팀에 대한 모든 조합 T만 만들어서 T, T`에 대한 능력치 차를 구해보자
시간복잡도는 N 중에서 T팀이 될 N/2를 구하는거니까 O(N^2)

3. 생각해보니까 2^20 = 104만이라 비트마스킹으로 해도 될듯
모든 조합에 대해서 비트마스킹으로 완전탐색하자
-> 중간에 팀 성립이 안되는 조합이면 중단

7.nC(n/2) combination 함수를 dfs로 구현할 수도 있겠다. 미숙한 것 같아서 다시 연습
*/
