#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<pair<char, bool>> check, vector<char> perm, int depth) {
    if (depth == perm.size()) {
        for (int i = 0; i < perm.size(); ++i) {
            cout << perm[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < check.size(); ++i) {
        if (check[i].second == true)
            continue;
        else {
            check[i].second = true;
            perm[depth] = check[i].first;
            permutation(check, perm, depth + 1);
            check[i].second = false;
        }
    }
}

int main() {
    vector<char> v = {'a', 'b', 'c', 'd'};
    vector<char> perm(2);
    vector<pair<char, bool>> check(4);

    for (int i = 0; i < check.size(); ++i) {
        check[i] = {v[i], false};
    }

    permutation(check, perm, 0);  // 4P2
    return 0;
}
