#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 987654321

// 두 선거구 인구차이의 최솟값, 못나누면 -1
int n, ans = INF;  // 도시갯수10
int p[11];         //  인구100
vector<int> graph[11];
bool check[11];  // 방문여부
int which[11];   // team0, team1 구분

pii dfs(int now, int team) {
    check[now] = true;

    pii ret = {1, p[now]};
    for (int n : graph[now]) {
        if (which[n] != team || check[n]) continue;

        pii next = dfs(n, team);
        ret.first += next.first;
        ret.second += next.second;
    }

    return ret;
}

int main() {
    FASTIO;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    for (int u = 1; u <= n; ++u) {
        int n, v;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    for (int i = 1; i < (1 << n) - 1; ++i) {  // 000001~111110 까지 체크
        memset(check, false, sizeof(check));
        memset(which, 0, sizeof(which));

        int s1, s2;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                which[j + 1] = 1;
                s1 = j + 1;
            } else {
                s2 = j + 1;
            }
        }

        pii team1 = dfs(s1, 1);
        pii team2 = dfs(s2, 0);
        if (team1.first + team2.first == n) {
            ans = min(ans, abs(team1.second - team2.second));
        }
    }

    cout << (ans == INF ? -1 : ans);
    return 0;
}
