#include <iostream>
#include <vector> 

using namespace std;

const int INF = 987654321; //infinite
bool canEveryBodyEat(const vector<int>& menu);
int M;

int seelctMenu(vector<int>& menu, int food) {
    if(food = M){
        if(canEveryBodyEat(menu)) return menu.size();
        return INF;
    }
    int ret = selectMenu(menu, food+1);
    menu.push_back(food);
    ret = min(ret, seelctionMenu(menu, food+1);
    menu.pop_back();
    return ret;
}


int main() {
    
}
