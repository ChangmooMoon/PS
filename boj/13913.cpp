#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 200000;

int n, k;
int visit[MAX + 1];
int d[MAX + 1];
int before[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    visit[n] = 1;
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        if (0 <= pos - 1 && !visit[pos - 1]) {
            q.push(pos - 1);
            visit[pos - 1] = 1;
            d[pos - 1] = d[pos] + 1;
            before[pos - 1] = pos;
        }
        if (pos + 1 < MAX && !visit[pos + 1]) {
            q.push(pos + 1);
            visit[pos + 1] = 1;
            d[pos + 1] = d[pos] + 1;
            before[pos + 1] = pos;
        }
        if (pos * 2 < MAX && !visit[pos * 2]) {
            q.push(pos * 2);
            visit[pos * 2] = 1;
            d[pos * 2] = d[pos] + 1;
            before[pos * 2] = pos;
        }
    }

    cout << d[k] << '\n';

    stack<int> st;
    for (int i = k; i != n; i = before[i]) {
        st.push(i);
    }
    st.push(n);

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}
