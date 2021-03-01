#include <algorithm>
#include <iostream>
#include <queue>
#define INF 987654321

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n;
int a[20][20];
int visit[20][20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int x, y;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                x = i;
                y = j;
                a[i][j] = 0;
            }
        }
    }

    int time = 0;
    int size = 2;
    int eat = 0;

    while (true) {
        int nx, ny, dist;
        }

    return 0;
}

// 아기상어 시작크기 = 2
// 자신의 크기보다 작은 물고기만 먹는다
// 크기가 큰 물고기칸은 못지나감
// 크기가 같은 물고기칸은 지나감
// 거리가 가장 가까운 물고기부터 먹는다
// 동점일 시 가장 위, 왼쪽부터 먹는다
// 자신의 크기와 같은 수의 물고기 먹으면 크기 1증가
// 공간 0,1,2,3,4,5,6 - 상어9