#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

int n;
int a[20][20];

// 5번 이동해서 만들 수 있는 가장 큰 블록의 값
// 1. 게임판을 상하좌우로 기울이기, 2. 5번 기울이는 각각의 방향을 정하기
// 4^5 = 1024 = 2^10

int main() {
    FASTIO;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    return 0;
}
