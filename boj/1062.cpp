#include <iostream>
#include <vector>
using namespace std;

// 비트마스크 테크닉
int n, k;
int alpha;             // 아는 알파벳 비트마스크의 정수값
vector<int> words(50); // 단어 리스트

int go(int start, int know) {
    int ans = 0;
    if (know == k) { // 글자 k개를 아는 비트값에 도달
        for (int i = 0; i < n; ++i) {
            if ((words[i] & alpha) == words[i])
                ans++;
        }

        return ans;
    }

    for (int i = start; i < 26; ++i) {
        if ((alpha & (1 << i)) == 0) { // 아는 글자가 아닌 경우
            alpha |= (1 << i); // 이 글자를 배운 케이스로 탐색
            ans = max(ans, go(i + 1, know + 1));
            alpha &= ~(1 << i); // 안배운 케이스로 다시 탐색
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    alpha |= 1 << ('a' - 'a');
    alpha |= 1 << ('c' - 'a');
    alpha |= 1 << ('i' - 'a');
    alpha |= 1 << ('n' - 'a');
    alpha |= 1 << ('t' - 'a');
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char ch : s) {
            words[i] |= (1 << (ch - 'a'));
        }
    }

    if (k < 5) // 아는 알파벳이 5개 미만
        cout << 0;
    else if (k == 26) // 알파벳 다 알면
        cout << n;
    else
        cout << go(0, 5);

    return 0;
}
