#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int card[500000], N, M;

int solve(int target){
    int* l = lower_bound(card, card+N, target);
    int* r = upper_bound(card, card+N, target);
    return r - l;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0;i <N; ++i){
        cin >> card[i];
    }
    sort(card, card+N);
    cin >> M;

    for(int i = 0; i<M; ++i){
        int target;
        cin >> target;
        cout << solve(target) << " ";
    }

    return 0;
}
