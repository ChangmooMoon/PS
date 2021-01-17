#include <iostream>

using namespace std;

int board[100][100] = {-1};

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int N, K, L;
    cin >> N >> K;

    for(int i = 0; i<K; ++i){
        int r,c;
        cin >> r >> c;
        board[r][c] = 1;
    }
    cin >> L;
    
    for(int i = 0; i<L; ++i){
        int x;
        char c;
        cin >> x >> c;
        retur check(x, c);
    }

    return 0;
}
