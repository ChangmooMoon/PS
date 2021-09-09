#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// U X : X칸 위 선택
// D X : X칸 아래 선택
// C: 현재 행 삭제 후 아래 행 선택, 마지막 행이면 바로 윗 행 선택
// Z: 가장 최근에 선택된 행 복구

// N: 표행갯수 100만, k: 선택된 행 위치, cmd
string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    stack<int> removed;
    set<int> rowset;
    for (int i = 0; i < n; ++i) {
        rowset.insert(i);
    }

    auto kIt = rowset.find(k);

    for (string& s : cmd) {
        stringstream ss(s);
        char action;
        int x;
        ss >> action >> x;

        if (action == 'U') {
            while (x--) {
                kIt = prev(kIt);
            }
        } else if (action == 'D') {
            while (x--) {
                kIt = next(kIt);
            }
        } else if (action == 'C') {
            removed.push(*kIt);
            kIt = rowset.erase(kIt);
            if (kIt == rowset.end()) {
                kIt = prev(kIt);
            }
        } else if (action == 'Z') {
            rowset.insert(removed.top());
            removed.pop();
        }
    }

    for (int n : rowset) {
        answer[n] = 'O';
    }

    return answer;
}
