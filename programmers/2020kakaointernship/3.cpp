// 슬라이딩 윈도우, 이분탐색
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 진열된 모든 종류의 보석을 포함하는 가장 짧은 range 찾기
vector<int> solution(vector<string> gems) { // length 10만. 10만^2 = 100억
    vector<int> ans;
    
    unordered_set<string> uset;
    for(string& s: gems) {
        uset.insert(s);
    }

    int nType = uset.size(); // 보석 종류갯수
    int s = 0, e = 0, i = 0, range = 100000; //gem 배열10만
    unordered_map<string, int> umap; // 범위내 보석 카운트
    
    while(1) { // 슬라이딩 윈도우
        for(i = e; i < gems.size(); ++i) {
            ++umap[gems[i]];
            if(umap.size() == nType) { // 보석 종류 다 모았으면 종료
                e = i;
                break;
            }
        }
        
        if(i == gems.size()) break; // 범위 벗어남
        
        for(i = s; i < gems.size(); ++i) {
            if(umap[gems[i]] == 1) {
                s = i;
                break;
            } else {
                --umap[gems[i]];
            }
        }
        
        if(e - s < range) {
            ans = {s + 1, e + 1};
            range = e - s;
        }
        
        umap.erase(gems[s]);
        ++s, ++e;
    }
    
    return ans;
}
