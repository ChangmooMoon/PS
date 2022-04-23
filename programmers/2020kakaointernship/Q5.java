import java.util.*;

class Solution {
    final int N = (int) 2e5 + 1;

    List<Integer>[] a = new ArrayList[N];
    boolean[] check = new boolean[N];
    int[] parent = new int[N];
    int[] prev = new int[N];

    void go(int now) {
        if (check[now])
            return;
        if (!check[parent[now]]) {
            prev[parent[now]] = now;
            return;
        }

        check[now] = true;
        go(prev[now]);
        for (int next : a[now])
            go(next);
    }

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

        check[0] = true;
        for (int next : a[0]) {
            go(next);
        }

        for (int i = 0; i < n; ++i) {
            if (!check[i])
                return false;
        }
        return true;
    }
}
