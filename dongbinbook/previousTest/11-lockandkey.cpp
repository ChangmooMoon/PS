#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> key{{0,0,0},{1,0,0},{1,0,1}};
vector<vector<int>> lock{{1,1,1},{1,1,0},{1,0,1}};

int solve(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
}

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cout << solve(key, lock) << endl;

    return 0;
}
