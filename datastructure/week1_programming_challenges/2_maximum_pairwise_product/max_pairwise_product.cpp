#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long maxPairWiseProduct(const vector<long>& numbers){
    int idx1, idx2;
    int size = numbers.size();

    idx1 = 0;
    for(int i = 0; i<size; ++i){
        if(numbers[i] > numbers[idx1])
            idx1 = i;
    }
    if(idx1 == 0) idx2 = 1;
    else idx2 = 0;
    
    for(int i = 0; i<size; ++i){
        if(i != idx1 && numbers[i] > numbers[idx2]){
            idx2 = i;
        }
    }

    return numbers[idx1]*numbers[idx2];
}

int main() {
    int n;
    cin >> n;
    vector<long> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << maxPairWiseProduct(numbers) << "\n";
    return 0;
}
