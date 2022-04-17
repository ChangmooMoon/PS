import java.util.*;

class Solution {
    int[] dr = { -1, 0, 1, 0 };
    int[] dc = { 0, 1, 0, -1 };

    public int[] solution(String[][] places) { // P O X
        int N = places.length;
        int[] ans = new int[N];

        for (int k = 0; k < N; ++k) {
            String[] place = places[k];
            List<Pair> man = new ArrayList<>();
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (place[i].charAt(j) == 'P')
                        man.add(new Pair(i, j));
                }
            }

            boolean flag = true;
            for (Pair p : man) {
                if (!isOk(place, p)) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans[k] = 1;
        }

        return ans;
    }

    boolean isOk(String[] place, Pair p) { // P O X
        Queue<Pair> q = new LinkedList<>();
        int[][] d = new int[5][5];
        for (int i = 0; i < 5; ++i) {
            Arrays.fill(d[i], -1);
        }
        q.add(p);
        d[p.r][p.c] = 0;

        while (!q.isEmpty()) {
            Pair now = q.poll();
            int r = now.r;
            int c = now.c;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (0 > nr || 0 > nc || 5 <= nr || 5 <= nc)
                    continue;
                if (d[nr][nc] != -1 || place[nr].charAt(nc) == 'X')
                    continue;

                d[nr][nc] = d[r][c] + 1;
                if (place[nr].charAt(nc) == 'P' && d[nr][nc] <= 2)
                    return false;
                q.add(new Pair(nr, nc));
            }
        }
        return true;
    }

    class Pair {
        int r;
        int c;

        Pair(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}
