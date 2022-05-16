#include <iostream>
#include <vector>
using namespace std;

int alpGoal = 0, copGoal = 0, minTime = -1;

void go(int alp, int cop, int time,
        vector<vector<int>> &problems) { // {alp_req150, cop_req150, alp_rwd30, cop_rwd30, cost100}
    if (alp >= alpGoal && cop >= copGoal) {
        if (minTime == -1 || minTime > time) { minTime = time; }
        return;
    }

    if (alp < alpGoal) go(alp + 1, cop, time + 1, problems);
    if (cop < copGoal) go(alp, cop + 1, time + 1, problems); // 1

    for (vector<int> &v : problems) {
        int alp_req = v[0], cop_req = v[1], alp_rwd = v[2], cop_rwd = v[3], cost = v[4];

        if (alp_req <= alp && cop_req <= cop) {
            if (alp >= alpGoal && cop < copGoal && cop_rwd / (float)cost <= 1) continue;
            if (cop >= copGoal && alp < alpGoal && alp_rwd / (float)cost <= 1) continue;
            go(alp + v[2], cop + v[3], time + v[4], problems);
        }
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) { // 모든 문제를 풀 수 있는 최단시간
    for (vector<int> &v : problems) {
        if (alpGoal < v[0]) alpGoal = v[0];
        if (copGoal < v[1]) copGoal = v[1];
    }

    go(alp, cop, 0, problems);
    return minTime;
}

// 알고력150 코딩력150 문제N 100개 //
// 행위1 - 알고력 +1, 시간 +1
// 행위2 - 코딩력 +1, 시간 +1
// 행위3 - 문제풀기(코딩력 +rwd, 시간 +cost), 같은 문제 또 풀 수 있음, req에 미달하면 못푼다