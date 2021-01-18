#include <iomanip>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(2);

    int n;
    string expr;
    int val[26];
    cin >> n >> expr;
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    stack<double> st;
    for (int i = 0; i < expr.length(); ++i) {
        if ('A' <= expr[i] && expr[i] <= 'Z') {
            st.push(val[expr[i] - 'A']);
        } else if (expr[i] == '+') {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(b + a);
        } else if (expr[i] == '-') {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(b - a);
        } else if (expr[i] == '*') {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(b * a);
        } else {
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(b / a);
        }
    }
    cout << st.top() << endl;
    return 0;
}
