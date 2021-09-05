// 블록게임(배열 관리, 구현)
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> Board;

bool canFill(int r, int c) { // 행 검사
    for(int i = 0; i < r; ++i) {
        if(Board[i][c] != 0) return false; // 위에 모두 빈칸이여야
    }
    
    return true;
}

bool find(int sr, int sc, int h, int w) {
    int empty = 0;
    int lastBlock = -1;
    for(int i = sr; i < sr + h; ++i) { // 행
        for(int j = sc; j < sc + w; ++j) { // 열
            if(Board[i][j] == 0) {
                if(!canFill(i, j)) return false;
                if(++empty > 2) return false;
            } else {
                if(lastBlock != -1 && lastBlock != Board[i][j]) return false; // 
                lastBlock = Board[i][j];
            }
        }
    }
    
    for(int i = sr; i < sr + h; ++i) {
        for(int j = sc; j < sc + w; ++j) {
            Board[i][j] = 0;
        }
    }
    
    return true;
}

int solution(vector<vector<int>> board) {
    int ans = 0;
    int n = board.size(); // 정사각형
    Board = board;
    
    int cnt = 0;
    do {
        cnt = 0;
        for(int i = 0; i< n; ++i) {
            for(int j = 0; j< n; ++j) {
                if (i <= n - 2 && j <= n - 3 && find(i, j, 2, 3)) ++cnt;
                else if (i <= n - 3 && j <= n - 2 && find(i, j, 3, 2)) ++cnt;
            }
        }
        
        ans += cnt;
    } while(cnt != 0);
    
    return ans;
}
