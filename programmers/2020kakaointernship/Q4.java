import java.util.*;

class Solution {
    final int INF = 0x3f3f3f3f;

    int[] dr = new int[] { -1, 0, 1, 0 };
    int[] dc = new int[] { 0, 1, 0, -1 };

    public int solution(int[][] board) {
        int N = board.length;

        int[][][] d = new int[25][25][4]; // r, c, dir;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (i == 0 && j == 0)
                        d[i][j][k] = 0;
                    else
                        d[i][j][k] = INF;
                }
            }
        }

        Queue<int[]> q = new LinkedList<>(); // r, c, dir, cost
        q.add(new int[] { 0, 0, -1, 0 });

        while (!q.isEmpty()) {
            int[] now = q.poll();
            int r = now[0], c = now[1], dir = now[2], cost = now[3];

            for (int nDir = 0; nDir < 4; ++nDir) {
                int nr = r + dr[nDir];
                int nc = c + dc[nDir];
                int nCost = cost + 100;

                if (0 > nr || 0 > nc || N <= nr || N <= nc || board[nr][nc] == 1)
                    continue;

                if ((dir == 0 || dir == 2) && (nDir == 1 || nDir == 3))
                    nCost += 500;
                if ((dir == 1 || dir == 3) && (nDir == 0 || nDir == 2))
                    nCost += 500;

                if (nCost < d[nr][nc][nDir]) {
                    d[nr][nc][nDir] = nCost;
                    q.add(new int[] { nr, nc, nDir, nCost });
                }
            }
        }

        int ans = INF;
        for (int k = 0; k < 4; ++k) {
            ans = Math.min(ans, d[N - 1][N - 1][k]);
        }
        return ans;
    }
}
