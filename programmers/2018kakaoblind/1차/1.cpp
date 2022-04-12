// 추석트래픽
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 로그데이터에 대해서 초당 최대 처리량 리턴, 응답 완료 여부와 상관없이 임시시간부터 1초간 처리하는 요청의 최대갯수
int solution(vector<string> lines) {
    int N = lines.size();
    vector<pair<int, int>> ranges;

    // 2016-09-15 hh:mm:ss.sss
    // 응답완료시간 S, 처리시간 T
    for (string& str : lines) {
        str = str.substr(11);

        stringstream ss(str);
        int h, m, s, ms;
        float duration;
        char tmp;

        ss >> h >> tmp >> m >> tmp >> s >> tmp >> ms >> duration;
        h *= 60 * 60 * 1000;
        m *= 60 * 1000;
        s *= 1000;
        duration *= 1000;

        int end = h + m + s + ms;
        int start = end - duration + 1;
        ranges.push_back({start, end});
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        int e = ranges[i].second + 1000;

        for (int j = i; j < N; ++j) {
            int s = ranges[j].first;
            if (s < e) ++cnt;
        }

        if (ans < cnt) ans = cnt;
    }

    return ans;
}
