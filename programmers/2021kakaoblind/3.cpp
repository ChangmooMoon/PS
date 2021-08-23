#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> umap{
    {"-", 0},
    {"cpp", 1},
    {"java", 2},
    {"python", 3},
    {"backend", 1},
    {"frontend", 2},
    {"junior", 1},
    {"senior", 2},
    {"chicken", 1},
    {"pizza", 2}};
vector<int> parsedInfo[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query) {
    string lang, pos, exp, food, etc;
    int score;

    for (string& str : info) {
        stringstream ss(str);
        ss >> lang >> pos >> exp >> food >> score;
        vector<int> v = {umap[lang], umap[pos], umap[exp], umap[food]};
        for (int i = 0; i < (1 << 4); ++i) {
            int idx[4] = {0};
            for (int j = 0; j < 4; ++j) {
                if (i & (1 << j)) {
                    idx[j] = v[j];
                }
            }

            parsedInfo[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    sort(parsedInfo[i][j][k][l].begin(), parsedInfo[i][j][k][l].end());
                }
            }
        }
    }

    vector<int> ans;
    for (string& q : query) {
        stringstream ss(q);
        ss >> lang >> etc >> pos >> etc >> exp >> etc >> food >> score;

        vector<int>& v = parsedInfo[umap[lang]][umap[pos]][umap[exp]][umap[food]];
        int num = v.end() - lower_bound(v.begin(), v.end(), score);
        ans.push_back(num);
    }

    return ans;
}
