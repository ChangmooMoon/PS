import java.util.*;

class Solution {
    final int INF = 0x3f3f3f3f;
    int[][] a = new int[1001][1001];
    
    public int solution(int n, int start, int end, int[][] roads, int[] traps) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j) continue;
                a[i][j] = INF;
            }
        }
        
        for(int[] r: roads) {
            int from = r[0], to = r[1], weight = r[2];
            if(weight < a[from][to]) a[from][to] = weight;
        }
                
        return dijkstra(n, start, end, traps);
    }
    
    int dijkstra(int n, int s, int e, int[] traps) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]); 
        boolean[][] check = new boolean[1001][1 << 10];
        pq.add(new int[] {0, s, 0}); // {cost, cur_pos, state};
        
        while(!pq.isEmpty()) {
            int[] cur = pq.poll();
            int cost = cur[0], cur_pos = cur[1], state = cur[2];
            
            if(cur_pos == e) return cost;
            
            if(check[cur_pos][state]) continue;
            check[cur_pos][state] = true;
            
            boolean trapFlag = false;
            Set<Integer> activeTrap = new HashSet<>();
            for(int i = 0; i < traps.length; ++i) {
                int bit = 1 << i;
                if((state & bit) != 0) {
                    if(traps[i] == cur_pos) {
                        state &= ~bit;
                    } else {
                        activeTrap.add(traps[i]);
                    }
                } else {
                    if (traps[i] == cur_pos) {
                        state |= bit;
                        activeTrap.add(traps[i]);
                        trapFlag = true;
                    }
                }
            }
            
            for(int next = 1; next <= n; ++next) {
                if(next == cur_pos) continue;
                if(trapFlag == activeTrap.contains(next)) {
                    if(a[cur_pos][next] != INF) {
                        pq.add(new int[] {cost + a[cur_pos][next], next, state});
                    }
                } else {
                    if(a[next][cur_pos] != INF) {
                        pq.add(new int[] {cost + a[next][cur_pos], next, state});
                    }
                }
            }
        }
        return INF;
    }
}
