#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n;  // n100000
struct S {
    string name;
    int ko, en, math;
};
S a[100'000];

bool cmp(S& s1, S& s2) {
    if (s1.ko == s2.ko && s1.en == s2.en && s1.math == s2.math)
        return s1.name < s2.name;
    if (s1.ko == s2.ko && s1.en == s2.en)
        return s1.math > s2.math;
    if (s1.ko == s2.ko)
        return s1.en < s2.en;
    return s1.ko > s2.ko;
}
// ko 내림차순, en 오름차순, math 내림차순, name 오름차순

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].name >> a[i].ko >> a[i].en >> a[i].math;
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; ++i) {
        cout << a[i].name << '\n';
    }

    return 0;
}
