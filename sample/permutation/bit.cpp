#include <iostream>
#include <vector>
using namespace std;

int n = 4;
int nums[] = {1, 2, 3, 4};

void solve(int cnt, int check, int val) {
    if (cnt == 2) {
        cout << val << endl;
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (check & (1 << i)) continue;
        // // 방문한 비트에 대응되는 원소는 넘어감
        // 매개변수 visited 에 visited | (1 << i) 이 대입되는 과정에서 방문 체크. visited 에서 i 자리에 해당하는 비트를 1 로 만든다.
        // 방문 해제해줄 필요는 없음. 그냥 다음 재귀함수에 파라미터 넘겨준 것 뿐이며 현재 단계에서 visited 값은 변화가 없으므로
        solve(cnt + 1, check | (1 << i), val * 10 + nums[i]);
    }
}

int main() {
    solve(0, 0, 0);
}
