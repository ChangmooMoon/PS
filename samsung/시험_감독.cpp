#include <bits/stdc++.h>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int N, a[1000001], B, C;

int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    cin >> B >> C;

    for (int i = 0; i < N; ++i) {
        a[i] = max(a[i] - B, 0);
    }

    long long ans = N;
    for (int i = 0; i < N; ++i) {
        ans += (int)ceil((float)a[i] / C);
    }
    cout << ans;
    return 0;
}

// 1. 문제 읽기
// 2. 논리적 순서
// 3. 필요한 자료연산 리스트업
// 4. 자료형, 시간복잡도, 유리한 자료구조 선택
// 5. 구현
// 6. 엣지케이스

//  N개 시험장, a[i] = i번 시험장 응시자의 수
// 감독관 1명이 한 시험장에서 감시가능수 B, 부감독관 한 시험장에서 감시가능수 C
// 각 시험장에 총감독관1, 부감독관 X명
// 모든 감독관수의 최솟값
