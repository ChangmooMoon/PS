#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    string s = "0101";
    int len = 4;
    bitset<len> bset;
    for (int i = 0; i < 10; ++i) {
        bset[i] = 1;
    }

    for (int i = 0; i < bset.size(); ++i) {
        cout << bset[i] << endl;
    }
}
