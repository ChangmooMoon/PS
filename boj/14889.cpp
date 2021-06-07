#include <algorithm>
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;

int n, ans = INF;  // 4~20
int a[21][21];     // 최대 100

// 두 팀의 능력차 최소로 20!/10!*10! = 18만
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> team(n, -1);
    fill(team.begin() + n / 2, team.end(), 1);
    do {
        int score = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (team[i - 1] == team[j - 1])
                    score += team[i - 1] * (a[i][j] + a[j][i]);
            }
        }
        ans = min(ans, abs(score));
    } while (next_permutation(team.begin(), team.end()));

    cout << ans;
    return 0;
}
