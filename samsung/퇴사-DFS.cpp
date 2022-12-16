#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, t[16], p[16], ans;

void go(int day, int earn) {
    if (day > N + 1) return;
    if (day == N + 1) {
        ans = max(ans, earn);
        return;
    }

    go(day + t[day], earn + p[day]);
    go(day + 1, earn);
}

int main() {
    FASTIO;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> t[i] >> p[i];
    }
    go(1, 0);
    cout << ans;
    return 0;
}

// 1. 문제 읽기
// 2. 논리적 순서
// 3. 필요한 자료연산 리스트업
// 4. 자료형, 시간복잡도, 유리한 자료구조 선택
// 5. 구현
// 6. 엣지케이스

// N일 동안 상담 많이 하기 => 최대 수익 찾기
// 상담 N일동안 매일 1개씩 주어지고 시간 Ti, 금액 Pi
// N일 지나면 상담 못함
// 1. N의 범위가 1~15니까 한다? 안한다로 완전탐색이 가능함 2^15 = 32768
// 2. LIS? 이 방식은 고민

// DP 방식으로 푸는 방식이 있었음
