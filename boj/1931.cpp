#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int>& u, pair<int,int>& v){
    if(u.second == v.second){
        return u.first < v.first;
    }
    return u.second < v.second; // 끝나는 시간 오름차순
 }

int solve(vector<pair<int,int>>& v){
    sort(v.begin(), v.end(), compare);

    int axis = 0;
    int result = 0;
    for(size_t i = 0; i<v.size(); ++i){
        if(axis <= v[i].first){
            result++;
            axis = v[i].second;
        }
    }
    return result; 
}

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i = 0; i<N; i++){
        int start, end;
        cin >> start >> end;
        v[i] = make_pair(start,end);
    }
    cout << solve(v) << endl;
    return 0;
}
