#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)

struct Station {
    string name;
    double pos;
    bool stop;
};

struct Pos {
    string name;
    int end;
    int start;
};

vector<Station> v{
    {"Seoul", 0, true},
    {"Yeongdeungpo", 9.1, true},
    {"Anyang", 23.9, false},
    {"Suwon", 41.5, true},
    {"Osan", 56.5, false},
    {"Seojeongri", 66.5, false},
    {"Pyeongtaek", 75, true},
    {"Seonghwan", 84.4, false},
    {"Cheonan", 96.6, true},
    {"Sojeongni", 107.4, false},
    {"Jeonui", 114.9, false},
    {"Jochiwon", 129.3, true},
    {"Bugang", 139.8, false},
    {"Sintanjin", 151.9, false},
    {"Daejeon", 166.3, true},
    {"Okcheon", 182.5, false},
    {"Iwon", 190.8, false},
    {"Jitan", 196.4, false},
    {"Simcheon", 200.8, false},
    {"Gakgye", 204.6, false},
    {"Yeongdong", 211.6, true},
    {"Hwanggan", 226.2, false},
    {"Chupungnyeong", 234.7, false},
    {"Gimcheon", 253.8, true},
    {"Gumi", 276.7, true},
    {"Sagok", 281.3, false},
    {"Yangmok", 289.5, false},
    {"Waegwan", 296, true},
    {"Sindong", 305.9, false},
    {"Daegu", 323.1, true},
    {"Dongdaegu", 326.3, true},
    {"Gyeongsan", 338.6, false},
    {"Namseonghyeon", 353.1, false},
    {"Cheongdo", 361.8, false},
    {"Sangdong", 372.2, false},
    {"Miryang", 381.6, true},
    {"Samnangjin", 394.1, false},
    {"Wondong", 403.2, false},
    {"Mulgeum", 412.4, false},
    {"Hwamyeong", 421.8, false},
    {"Gupo", 425.2, true},
    {"Sasang", 430.3, false},
    {"Busan", 441.7, true},
};

int n, q;
vector<Pos> route;

int getMin(string s) {
    if (s == "-:-") return -1;

    stringstream ss(s);
    int h, m;
    char ch;
    ss >> h >> ch >> m;
    return 60 * h + m;
}

void makeTable() {
    // 1. 이전역 출발시간이 전날, 이번역 도착시간이 다음날
    // route[i-1].start > et
    // 2. 이번역 도착시간이 전날, 이번역 출발시간이 다음날
    // et > st
    bool nextDay = false;
    for (int i = 0; i < n; ++i) {
        string name, e, s;
        cin >> name >> e >> s;
        int st, et;
        st = getMin(s), et = getMin(e);

        if (!nextDay) {
            if (i - 1 >= 0 && route[i - 1].start > et) nextDay = true;
        }
        et += 24 * 60 * nextDay;

        if (!nextDay) {
            if (i < n - 1 && et > st) nextDay = true;
        }
        if (i < n - 1) {
            st += 24 * 60 * nextDay;
        }

        route.push_back({name, et, st});
    }
}

double calc(string s, string e) {
    double sDist, eDist;
    double totalTime;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].name == s) sDist = v[i].pos;
        if (v[i].name == e) eDist = v[i].pos;
    }

    int sIdx, eIdx;
    for (int i = 0; i < n; ++i) {
        if (route[i].name == s) sIdx = i;
        if (route[i].name == e) eIdx = i;
    }

    for (int i = sIdx + 1; i <= eIdx; ++i) {
        // 걸린시간 = 이번역 도착시간 - 이전역 출발시간 + 쉬는시간
        totalTime += route[i].end - route[i - 1].start;
        if (i != eIdx) totalTime += route[i].start - route[i].end;
    }

    return abs(sDist - eDist) / totalTime * 60;
}

int main() {
    FASTIO;
    cout << fixed;
    cout.precision(7);

    cin >> n >> q;
    makeTable();
    while (q--) {
        string s, e;
        cin >> s >> e;
        cout << calc(s, e) << endl;
    }
    return 0;
}
