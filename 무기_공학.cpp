#include <cstring>
#include <iostream>
using namespace std;
#define endl '\n'
#define FASTIO cin.tie(nullptr)->sync_with_stdio(false)
#define INF 0x3f3f3f3f

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int n, m, ans = 0, sum = 0;
int a[5][5];
bool check[5][5];

void go(int r, int c, int sum, int cnt) {
	if(cnt == 3) {
		
	}
}

int main() {
    FASTIO;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            go(i, j, 0, 0);
        }
    }

    return 0;
}
