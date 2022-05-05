#include <algorithm>
#include <vector>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int N = weak.size(), M = dist.size();
    int ans = -1;

    for (int i = 0; i < N; ++i) {
        weak.push_back(weak[i] + n);
    }
    sort(dist.begin(), dist.end());

    do { // 8! * 200 = 800만
        for (int i = 0; i < N; ++i) {
            int cnt = 0;
            int s = weak[i], e = weak[i + N - 1];
            for (int j = 0; j < M; ++j) {
                ++cnt;
                s += dist[j];
                if (s >= e) {
                    if (ans == -1 || ans > cnt) ans = cnt;
                    break;
                }

                int nextIdx = upper_bound(weak.begin(), weak.end(), s) - weak.begin();
                s = weak[nextIdx];
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));

    return ans;
}
