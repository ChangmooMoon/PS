// 셔틀버스
#include <algorithm>
#include <cstdio>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 대기열 도착시간 중 가능한 제일 늦은 시간
// 9:00부터 n회10 t분60 간격으로 한 셔틀에 m45명 탑승, 크루 대기열 도착시각 timetable
string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> bus[10];     // 셔틀버스
    priority_queue<int> pq;  // 최소힙, 분단위로 담음

    for (string& s : timetable) {
        int h, m;
        char tmp;

        stringstream ss(s);
        ss >> h >> tmp >> m;
        m += h * 60;
        pq.push(-m);
    }

    int now_time = 9 * 60;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        while (!pq.empty() && cnt < m) {
            int crew_time = -pq.top();
            if (now_time < crew_time)
                break;
            else {
                bus[i].push_back(crew_time);
                pq.pop();
                ++cnt;
            }
        }

        now_time += t;
    }

    int ans;
    if (bus[n - 1].size() < m)
        ans = now_time - t;
    else
        ans = *bus[n - 1].rbegin() - 1;

    char buf[5];
    sprintf(buf, "%02d:%02d", ans / 60, ans % 60);
    string ansStr = buf;
    return ansStr;
}
