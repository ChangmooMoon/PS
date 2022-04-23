import java.util.*;

class Solution {
    final int INF = 0x3f3f3f3f;

    public int solution(int n, int s, int a, int b, int[][] fares) {
        int[][] d = new int[201][201];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j)
                    continue;
                d[i][j] = INF;
            }
        }

        for (int[] f : fares) {
            int u = f[0], v = f[1], w = f[2];
            d[u][v] = w;
            d[v][u] = w;
        }

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (d[i][j] > d[i][k] + d[k][j]) {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }

        int ans = INF; // s, a, b
        for (int k = 1; k <= n; ++k) {
            int r0 = d[s][k];
            int r1 = d[k][a];
            int r2 = d[k][b];
            if (r0 == INF || r1 == INF || r2 == INF)
                continue;

            ans = Math.min(ans, r0 + r1 + r2);
        }
        return ans;
    }
}
