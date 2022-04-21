import java.util.*;

class Solution {
    int n;
    int[][] map;
    boolean[][] visit;

    int[] dx = { -1, 0, 1, 0 };
    int[] dy = { 0, 1, 0, -1 };

    int cost = Integer.MAX_VALUE;

    public int solution(int[][] board) {
        int answer = 0;
        n = board.length;

        map = board;
        visit = new boolean[n][n];

        bfs(0, 0, -1, 0);

        answer = cost;

        return answer;
    }

    void bfs(int x, int y, int dir, int price) {

        Queue<Road> q = new LinkedList();
        q.add(new Road(x, y, dir, price));
        visit[x][y] = true;

        while (!q.isEmpty()) {
            Road road = q.remove();

            int qx = road.x;
            int qy = road.y;
            int qDir = road.dir;
            int qPrice = road.cost;

            if (qx == n - 1 && qy == n - 1) {
                cost = Math.min(cost, qPrice);
            }

            for (int i = 0; i < dx.length; i++) {
                int nx = qx + dx[i];
                int ny = qy + dy[i];
                int nDir = i;
                int nPrice = qPrice;

                if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] == 1) {
                    continue;
                }

                if (qDir == -1) {
                    nPrice += 100;
                } else if (qDir == nDir) {
                    nPrice += 100;
                } else {
                    nPrice += 600;
                }

                if (!visit[nx][ny] || map[nx][ny] >= nPrice) {
                    visit[nx][ny] = true;
                    map[nx][ny] = nPrice;
                    q.add(new Road(nx, ny, nDir, nPrice));
                }

            }
        }

    }

}

class Road {
    int x, y, dir, cost;

    Road(int x, int y, int dir, int cost) {
        this.x = x;
        this.y = y;
        this.dir = dir;
        this.cost = cost;
    }
}