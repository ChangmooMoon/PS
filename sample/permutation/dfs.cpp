#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<bool> check, vector<char> v, vector<char> perm, int depth) {
    if (depth == perm.size()) {
        for (int i = 0; i < perm.size(); ++i) {
            cout << perm[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < v.size(); ++i) {
        if (check[i] == true) continue;

        check[i] = true;
        perm[depth] = v[i];
        permutation(check, v, perm, depth + 1);
        check[i] = false;
    }
}

int main() {
    int n = 4, r = 2;
    vector<char> v = {'a', 'b', 'c', 'd'};
    vector<char> perm(r);
    vector<bool> check(n);

    permutation(check, v, perm, 0);  // 4P2
    return 0;
}
