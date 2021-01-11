#include <iostream>
#include <string>

using namespace std;

int a[50][50]; // original
int b[50][50]; // target

void flip(int x, int y){
    for(int i = x-1; i<=x+1; ++i){
        for(int j = y-1; j<=y+1; ++j){
            a[i][j] = 1-a[i][j];
        }
    }
}

int solve(int n, int m) {
    int result = 0;
    for(int i = 0; i<n-2; ++i){
        for(int j = 0; j<m-2; ++j){
            if(a[i][j] != b[i][j]){
                result++;
                flip(i+1, j+1); // 3*3 가운데기준
            }
        }
    }

    for(int i = 0; i<n; ++i){
        for(int j =0; j<m; ++j){
            if(a[i][j] != b[i][j]){
                return -1;
            }
        }
    }
    return result;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    cin.ignore();

    for(int i = 0; i<N; ++i){
        string s;
        getline(cin,s);
        for(int j = 0; j<M; ++j){
            a[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i<N; ++i){
        string s;
        getline(cin, s);
        for(int j = 0; j<M; ++j){
            b[i][j] = s[j] - '0';
        }
    }

    cout << solve(N,M) << endl;
    
    return 0;
}

