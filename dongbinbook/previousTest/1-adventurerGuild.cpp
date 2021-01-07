#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &v){
    int result = 0;
    int count = 0;
    int size = v.size();
    sort(v.begin(), v.end());

    for(int i = 0; i<size; ++i){
        count += 1;
        if(count >= v[i]){
            result +=1;
            count = 0;
        }
    }
    return result;
};

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    vector<int> v;

    cin >> n;

    while(n-- > 0) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << solve(v) << endl;
    return 0;
}


