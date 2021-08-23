#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> foodCnt[11];  // 2~10길이의 코스요리
int maxCnt[11] = {0};

void getComb(string& order, int idx, string result) {  // 고려할 idx, 요리조합
    if (idx == order.length()) {
        int foodlen = result.length();
        if (foodlen >= 2) {
            ++foodCnt[foodlen][result];
            maxCnt[foodlen] = max(maxCnt[foodlen], foodCnt[foodlen][result]);
        }
        return;
    }

    getComb(order, idx + 1, result);               // order[idx] 주문
    getComb(order, idx + 1, result + order[idx]);  // order[idx] 주문 안함
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> ans;

    for (string& order : orders) {
        sort(order.begin(), order.end());
        getComb(order, 0, "");
    }

    for (int n : course) {
        for (auto& p : foodCnt[n]) {
            if (p.second >= 2 && p.second == maxCnt[n]) {
                ans.push_back(p.first);
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}
