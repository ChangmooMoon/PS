#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, a[11], op[4];
vector<int> ansList;

void simulate(int ret, int idx, int pl, int mi, int mul, int div) {
    if (idx == N) {
        ansList.push_back(ret);
        return;
    }

    if (pl != 0) simulate(ret + a[idx], idx + 1, pl - 1, mi, mul, div);
    if (mi != 0) simulate(ret - a[idx], idx + 1, pl, mi - 1, mul, div);
    if (mul != 0) simulate(ret * a[idx], idx + 1, pl, mi, mul - 1, div);
    if (div != 0) simulate(ret / a[idx], idx + 1, pl, mi, mul, div - 1);
}

int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; ++i) {
        cin >> op[i];
    }

    simulate(a[0], 1, op[0], op[1], op[2], op[3]);
    sort(ansList.begin(), ansList.end());
    cout << ansList[ansList.size() - 1] << endl << ansList[0];
    return 0;
}

// 1. 문제 읽기
// 2. 논리적 순서
// 3. 필요한 자료연산 리스트업
// 4. 자료형, 시간복잡도, 유리한 자료구조 선택
// 5. 구현
// 6. 엣지케이스

// N개의 수열, N-1개의 연산자 +, -, *, /
// 수열 사이에 연산자 넣어서 계산, 최대값, 최소값 찾기
// N <= 11, 결과값 +-10억
// 연산자의 각 갯수를 알려줌. 이걸 이용해서 완전탐색하는 식으로 풀자
// 재귀적으로 풀어보면 쉬울 것 같음