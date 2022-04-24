import java.util.*;

class Solution {
    final int INF = 0x3f3f3f3f;
    int[] dr = {-1, 0, 1, 0};
    int[] dc = {0, 1, 0, -1};
    
    public int solution(int[][] board, int r, int c) {
        return go(board, new int[] {r, c});
    }
    
    int go(int[][] board, int[] src) {
        int ret = INF;
        
        for(int k = 1; k <= 6; ++k) {
            List<int[]> card = new ArrayList<>();
            
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j < 4; ++j) {
                    if(board[i][j] == k) card.add(new int[] {i, j});
                }
            }
            
            if(card.isEmpty()) continue;
            
            int[] card1 = card.get(0);
            int[] card2 = card.get(1);
            
            int ab = bfs(board, src, card1) + bfs(board, card1, card2) + 2;
            int ba = bfs(board, src, card2) + bfs(board, card2, card1) + 2;
            
            board[card1[0]][card1[1]] = board[card2[0]][card2[1]] = 0;
            int abRecursive = ab + go(board, card2);
            int baRecursive = ba + go(board, card1);
            ret = Math.min(ret, Math.min(abRecursive, baRecursive));
            
            board[card1[0]][card1[1]] = board[card2[0]][card2[1]] = k;
        }
        
        if(ret == INF) return 0;
        return ret;
    }
    
    int bfs(int[][] board, int[] src, int[] dest) {
        Queue<int[]> q = new LinkedList<>();
        int[][] d = new int[4][4];
        for(int i = 0; i < 4; ++i) {
            Arrays.fill(d[i], -1);
        }
        
        q.add(src);
        d[src[0]][src[1]] = 0;
        
        while(!q.isEmpty()) {
            int[] now = q.poll();
            int r = now[0], c = now[1];
            if(r == dest[0] && c == dest[1]) return d[r][c];
            
            for(int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(0 > nr || 0 > nc || 4 <= nr || 4 <= nc) continue;
                if(d[nr][nc] == -1) {
                    d[nr][nc] = d[r][c] + 1;
                    q.add(new int[] {nr, nc});   
                }
                
                for(int j = 0; j < 2; ++j) {
                    if(board[nr][nc] != 0) break;
                    int nnr = nr + dr[i];
                    int nnc = nc + dc[i];
                    if(0 > nnr || 0 > nnc || 4 <= nnr || 4 <= nnc) break;
                    
                    nr = nnr;
                    nc = nnc;
                }
                
                if(d[nr][nc] == -1) {
                    d[nr][nc] = d[r][c] + 1;
                    q.add(new int[] {nr, nc});   
                }
            }
        }
        
        return -1;
    }
}
