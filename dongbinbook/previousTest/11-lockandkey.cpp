#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> key{{1,0,0},{1,0,0},{1,0,1}};
vector<vector<int>> lock{{2,1,1},{1,1,0},{1,0,1}};

void match(int& arr[58][58], vector<vector<int>> key, int rot, int row, int col){
    int n = key.size();
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            if(rot == 0){
                arr[row+i][col+j] += key[i][j];
            }
            else if(rot == 1){
                arr[row+i][col+j] += key[j][n-1-i];
            }
            else if(rot == 2){
                arr[row+i][col+j] += key[n-1-i][n-1-j];
            }
            else if(rot == 3){
                arr[row+i][col+j] += 
            }
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // 2. move m+n-1, 2. rotate 3. check
    int m = key.size();
    int n = lock.size();

    for(int i = 1; i< m+n-1; ++i){
        for(int j = 1; j<m+n-1; ++j){
            for(int k = 1; k<4; ++k){
                int range[58][58] = {0};
                for(int x = 1; x<lock.size(); ++x){
                    for(int y = 1; y<lock.size(); ++y){
                        range[key.size()0 + x][key.size()-1 + y] = lock[x][y];
                    }
                }

                match(range, key, k, x, y);
                if(check(arr, i, lock.size()){
                    return true;
                }
            }
        }
    }
    return false;
}   

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cout << solution(key, lock) << endl;

    return 1;
}
