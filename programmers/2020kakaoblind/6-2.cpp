#include <algorithm>
#include <vector>
using namespace std;

int ans = -1, N;
vector<int> Weak, Dist;

void go(int cnt, int now, int visited) { // 2^15 = 3만
    if (cnt > Dist.size()) return;

    for (int i = 0; i < Weak.size(); ++i) {
        int nextIdx = (now + i) % Weak.size();
        int diff = Weak[nextIdx] - Weak[now];
        if (nextIdx < now) diff += N;
        if (diff > Dist[Dist.size() - cnt]) break;

        visited |= 1 << nextIdx;
    }

    if (visited == (1 << Weak.size()) - 1) {
        if (ans == -1 || ans > cnt) ans = cnt;
        return;
    }

    for (int i = 0; i < Weak.size(); ++i) {
        if (visited & (1 << i)) continue;
        go(cnt + 1, i, visited);
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end());
    N = n;
    Weak = weak;
    Dist = dist;

    for (int i = 0; i < Weak.size(); ++i) {
        go(1, i, 0);
    }

    return ans;
}
