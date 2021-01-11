#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> now(10);
vector<int> target(10);
int count = 0;

void toggle(int n){
    now[n] = 1 - now[n];
    ::count++;
}

int solve(int n){
    int count = 0;
    for(int i = 0; i<n; ++i){
        if(now[i] != target[i]){
            if(i-1 >= 0) toggle(i-1);
            toggle(i);
            if(i+1 <= n) toggle(i+1);
        }
    }

    if(now != target) return -1;
    return count;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    cin.ignore();

    string s;
    getline(cin, s);
    for(int i = 0; i<N; ++i){
        now[i] = s[i] - '0';
    }

    getline(cin, s);
    for(int i = 0; i<N; ++i){
        target[i] = s[i] - '0';
    }

    cout << solve(N) << endl;

    return 0;
}
