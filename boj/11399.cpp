#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& v){
    sort(v.begin(), v.end(), greater<>());
    int result = 0;
    for(size_t i = 0; i<v.size(); ++i){
        result += (i+1) * v[i];
    }
    return result;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i<N; ++i){
        cin >> v[i];
    }

    cout << solve(v) << endl;
    return 0;
}
