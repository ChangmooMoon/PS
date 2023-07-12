// 세그먼트트리 - 구간합 구하기
#include <bits/stdc++.h>
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
using namespace std;
typedef long long ll;

int n, m, k, h, treeSize;
vector<ll> a, tree;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(int node, int start, int end, int index, ll val) {
    if (index < start || index > end) { return; }
    if (start == end) {
        a[index] = val;
        tree[node] = val;
        return;
    }
    update(node * 2, start, (start + end) / 2, index, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    ll lsum = query(node * 2, start, (start + end) / 2, left, right);
    ll rsum = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return lsum + rsum;
}

int main() {
    FASTIO;
    cin >> n >> m >> k;
    a.resize(n);
    h = (int)ceil(log2(n));
    treeSize = (1 << (h + 1));
    tree.resize(treeSize);
    m += k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    init(1, 0, n - 1);

    while (m--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int index;
            ll val;
            cin >> index >> val;
            update(1, 0, n - 1, index - 1, val);
        } else if (cmd == 2) {
            int left, right;
            cin >> left >> right;
            cout << query(1, 0, n - 1, left - 1, right - 1) << endl;
        }
    }
    return 0;
}
