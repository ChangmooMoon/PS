#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bSearch(vector<int>& card, int n){
    int left = 0;
    int right = card.size()-1;
    int pos = -1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(card[mid] == n){
            pos = mid;
            break;
        } else if(card[mid] > n){
            right = mid -1;
        } else {
            left = mid+1;
        }
    }

    return pos == -1 ? 0 : 1;
}

int main(){
    cin.sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N, M;
    cin >> N;
    vector<int> card(N);
    for(int i = 0; i<N; ++i){
        cin >> card[i];
    }
    sort(card.begin(), card.end());
    cin >> M;
    for(int i = 0; i<M; ++i){
        int n;
        cin >> n;
        cout << bSearch(card, n) << " ";
    }

    return 0;
}
