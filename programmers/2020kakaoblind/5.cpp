#include <vector>
using namespace std;

bool col[102][102]; // 기둥
bool row[102][102]; // 보

bool buildCol(int x, int y) { // 기둥설치
    if(y == 0) return true;
    if(col[x][y - 1]) return true;
    if((x > 0 && row[x - 1][y]) || row[x][y]) return true;
    return false;
}

bool buildRow(int x, int y) { // 보설치
    if(col[x][y - 1] || col[x + 1][y - 1]) return true;
    if(x > 0 && row[x - 1][y] && row[x + 1][y]) return true;
    return false;
}

bool canDestroy(int x, int y) {
    for(int i = max(0, x - 1); i <= x + 1; ++i) {
        for(int j = y; j <= y + 1; ++j) {
            if(col[i][j] && !buildCol(i, j)) return false;
            if(row[i][j] && !buildRow(i, j)) return false;
        }
    }
    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for(vector<int> v: build_frame) {
        int x = v[0], y = v[1], block = v[2], action = v[3]; // 0기둥1보, 0삭제1설치
        
        if(action == 1) { // 건설
            if(block == 0 && buildCol(x, y)) col[x][y] = true;
            else if(block == 1 && buildRow(x, y)) row[x][y] = true;
        } else { // 파괴
            if(block == 0) col[x][y] = false;
            else row[x][y] = false;
            
            if(block == 0 && !canDestroy(x, y)) col[x][y] = true;
            else if(block == 1 && !canDestroy(x, y)) row[x][y] = true;
        }
    }
    
    vector<vector<int>> ans;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            if(col[i][j]) ans.push_back({i, j, 0});
            if(row[i][j]) ans.push_back({i, j, 1});
        }
    }
    return ans;
}
