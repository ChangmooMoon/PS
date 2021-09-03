// 무지의 먹방라이브
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

// food_time20만, food_time[i]1억, 방송중단된시간k 20조
// 1~N 중 몇번 음식부터 다시 섭취해야되는지, 더 섭취할 음식이 없으면 -1 반환
// 어떤 음식이 없어지는 시간 = 전체 음식 갯수 * 해당음식 소요시간
// 최소 소요시간인 음식부터 없어짐
// 0:312 -> 1:212 -> 2:202 -> 3:201 -> 4:101 -> 5:100(중단) -> 6:000

int solution(vector<int> food_times, long long k) {
    priority_queue<pii> pq;  // 최소힙, {-필요식사시간, 음식idx}
    long long total = 0;

    for (int i = 0; i < food_times.size(); ++i) {
        total += food_times[i];
        pq.push({-food_times[i], i + 1});
    }

    if (total <= k) return -1;  // 총 식사시간보다 k가 더 길면 다 먹음

    long long beforeTime = 0;
    while (1) {
        auto& [foodtime, idx] = pq.top();
        foodtime *= -1;
        if ((foodtime - beforeTime) * pq.size() > k) break;

        k -= (foodtime - beforeTime) * pq.size();  // k -= (foodtime * pq.size() - beforeTime * pq.size(); // 최소로 걸리는 음식시간 * 전체 음식 도는 사이클길이 빼주기
        beforeTime = foodtime;                     // 이전 사이클에서의 최소 음식시간
        pq.pop();                                  // 최소 음식시간 드는 음식 다 먹고 소거
    }

    vector<pii> rest;      // idx, foodtime
    while (!pq.empty()) {  // 남은 음식시간들 번호순으로 정렬
        auto& [foodtime, idx] = pq.top();
        foodtime *= -1;
        rest.push_back({idx, foodtime});
        pq.pop();
    }
    sort(rest.begin(), rest.end());

    return rest[k % rest.size()].first;
}
