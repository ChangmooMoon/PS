import java.util.*;

class Solution {
    List<Integer>[] a = new ArrayList[200001];
    boolean[] check = new boolean[200001];
    int[] parent = new int[200001];
    int[] prevMustGo = new int[200001];

    public boolean solution(int n, int[][] path, int[][] order) {
        for (int i = 0; i < n; ++i) {
            a[i] = new ArrayList<>();
        }

        for (int[] p : path) {
            int u = p[0], v = p[1];
            a[u].add(v);
            a[v].add(u);
        }

        for (int[] ord : order) {
            int u = ord[0], v = ord[1];
            parent[v] = u;
        }

        if (parent[0] != 0)
            return false;
        bfs(0);

        for (int i = 0; i < n; ++i) {
            if (!check[i])
                return false;
        }
        return true;
    }

    void bfs(int s) {
        Queue<Integer> q = new LinkedList<>();
        check[0] = true;
        for (int next : a[0]) {
            q.add(next);
        }

        while (!q.isEmpty()) {
            int now = q.poll();
            if (check[now])
                continue;
            if (!check[parent[now]]) {
                prevMustGo[parent[now]] = now;
                continue;
            }

            check[now] = true;
            for (int next : a[now]) {
                q.add(next);
            }
            q.add(prevMustGo[now]);
        }
    }
}
