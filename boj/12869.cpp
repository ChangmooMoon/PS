#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 987654321

// O(61^3) * 3! = 136만
int n;
int d[61][61][61];
// d[i][j][k] = min(체력이 i,j,k일때 모두 파괴하기 위해 공격해야되는 횟수)

int go(int i, int j, int k) {
    if (i == 0 && j == 0 && k == 0) return 0;
    if (i < 0) return go(0, j, k);
    if (j < 0) return go(i, 0, k);
    if (k < 0) return go(i, j, 0);

    int& ans = d[i][j][k];
    if (ans != -1) return ans;

    ans = INF;
    vector<int> permu = {1, 3, 9};
    do {
        ans = min(ans, go(i - permu[0], j - permu[1], k - permu[2]));
    } while (next_permutation(permu.begin(), permu.end()));
    ans += 1; // 이번턴 카운트

    return ans;
}

int main() {
    FASTIO;
    cin >> n;
    int x = 0, y = 0, z = 0;
    cin >> x >> y >> z;

    memset(d, -1, sizeof(d));
    cout << go(x, y, z);

    return 0;
}
