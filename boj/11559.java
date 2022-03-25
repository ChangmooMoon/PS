import java.io.*;
import java.util.*;

public class Puyo_Puyo {
    static int[] dr = { -1, 0, 1, 0 };
    static int[] dc = { 0, 1, 0, -1 };

    static int ans = 0;
    static char[][] a = new char[12][6];
    static boolean[][] check = new boolean[12][6];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 12; ++i) {
            a[i] = br.readLine().toCharArray();
        }

        while (true) {
            for (boolean[] c : check) {
                Arrays.fill(c, false);
            }
            boolean go = false;
            for (int i = 0; i < 12; ++i) {
                for (int j = 0; j < 6; ++j) {
                    if (a[i][j] == '.')
                        continue;
                    boolean flag = bfs(i, j);
                    if (flag)
                        go = true;
                }
            }
            if (!go)
                break;

            ++ans;
            down();
        }
        System.out.println(ans);
    }

    static boolean bfs(int sr, int sc) {
        List<Pair> list = new ArrayList<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(sr, sc));
        check[sr][sc] = true;
        list.add(new Pair(sr, sc));

        while (!q.isEmpty()) {
            Pair p = q.poll();
            for (int i = 0; i < 4; ++i) {
                int nr = p.r + dr[i];
                int nc = p.c + dc[i];
                if (0 > nr || 0 > nc || 12 <= nr || 6 <= nc)
                    continue;
                if (check[nr][nc] || a[nr][nc] != a[sr][sc])
                    continue;

                q.add(new Pair(nr, nc));
                check[nr][nc] = true;
                list.add(new Pair(nr, nc));
            }
        }

        if (list.size() >= 4) {
            for (Pair p : list) {
                a[p.r][p.c] = '.';
            }
        }

        return list.size() >= 4;
    }

    static void down() {
        for (int i = 10; i >= 0; --i) {
            for (int j = 0; j < 6; ++j) {
                int r = i;
                while (r + 1 < 12 && a[r + 1][j] == '.') {
                    ++r;
                }
                if (r != i) {
                    a[r][j] = a[i][j];
                    a[i][j] = '.';
                }
            }
        }
    }

    static class Pair {
        int r, c;

        Pair(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}